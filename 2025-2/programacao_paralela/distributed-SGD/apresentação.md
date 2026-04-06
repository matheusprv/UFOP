# Background On Distributed Machine Learning
Matheus Peixoto Ribeiro Vieira

Programação Paralela - BCC447

## Gradiente e otimização
$Z = WX + b$ é uma rede neural e o objetivo é encontrar os melhores parâmetros $W$ e $b$. 

Para isso, calculamos o erro de uma predição e aplicamos o gradiente em relação aos parâmetros para saber qual direção irá minimizar.

Com o gradiente calculado, aplicamos a descida do gradiente: $\theta_{t+1} = \theta_{t} - \alpha \^{g}_t $

Cada pequeno conjunto de dado pode levar a uma região diferente: 
![](/images/sgd.jpg)

# Acelerando o processo
No caso apresentado, todos os três gradientes são calculados pela mesma máquina. Podemos colocar cada máquina para calcular um dos gradientes, e, depois, juntá-los para definir a direção dos pesos. Esse processo é conhecido como Distributed SGD (D-SGD).

O D-SGD é composto por três fases: 
1. Computação local
2. Comunicação
3. Atualização global

Existem dois tipos de comunicação de arquitetura:
- Baseada em servidor
- Peer-to-Peer

# Baseada em servidor 
Os gradientes computados localmente são enviados para um servidor central que realizará uma agregação dos mesmos

![](/images/Federated%20averaging.png)

Na agregação média convencional, o bizantino pode simplesmente enviar um valor que alterará a direção do gradiente e tacar para uma direção que não vai convergir
![](/images2/agregacao_media_erro.png)

Os gradientes bons são:
- ruidosos: cada mini-batch dá um gradiente diferente
- mas próximos: perto de um gradiente verdadeiro
 
O atacante pode enviar um gradiente:
- de alta magnitude
- com direção oposta
- conjunto de vetores coordenados para parecer convincente

Surge o algoritmo de Krum cujo objetivo é: (i) não ser enganado por outliers e (ii) não jogar fora dados reais

O agregador precisa apontar para uma direção correta, com um gradiente g positivo e não muito pequeno: $\langle \mathbb{E}[F], g\rangle \ge (1-\sin\alpha)|g|^2$; além de que ele não pode explodir em magnitude

Não combina os vetores como média
Escolhe o vetor que parece o mais consistente com um grupo de tamanho $n - f -2$

Dado vetores $V_i,...,V_n$
1. Distância de todos para todos: $|V_i - V_j|^2 \quad \forall j\neq i$
2. Para cada $i$, selecione os $n-f-2$ vizinhos mais próximos de $V_i$ e chame esse grupo de $N_i$
3. Calcula o score $s(i) = \sum_{j\in N_i} |V_i - V_j|^2$ que é a soma quadrática de todas as distâncias dos vizinhos confiáveis
4. $argmin\ s(i)$ - Seleciona o menor score, ou seja, aquele que os dados estão mais próximos

Custo $O(n^2 \cdot d)$, onde $n$ é o número de nós e d é o número de distâncias calculadas


A escolha de um único gradiente pode desacelerar o processo.
Por isso, a versão Multi-Krum permite a escolha de até $m$ vetores com os menores scores. A média deles é tirada
Se m=1, vira Krum; Se m=n, vira média


O Krum resolve problemas de ataques de vetores aleatórios e de grande magnitude que tentam puxar a média, mas não verifica se o gradiente é bom para treinamento, somente sua consistência geométrica

A ideia do ataque é garantir que o nó infectado tenha uma boa vizinhança 

Função objetivo: Maximizar o desvio do modelo global na direção oposta à atualização correta

O atacante cria modelos com gradientes próximos entre si
Os gradientes estão próximos de alguns vetores honestos
Apontam para direções opostas
O Krum vê um vetor central com boa vizinhança e com um bom score
O algoritmo seleciona esse vetor para ser usado

O vetor malicioso:
- Não é um outlier extremo
- Fica dentro da nuvem de gradientes honestos
- Explora o ruído natural do SGD
- O cluster malicioso é muito compacto

# Peer-to-Peer
A conexão dos nós da rede é definida por um grafo direcionado

Cada nó inicia um modelo local que é modificado iterativamente ao interagir com os nós vizinhos

Pasos:
1. Atualização local dos pesos
2. Envia os parâmetros atualizados para todos os nós que conhece
3. Faz uma média com todos os dados recebidos para atualizar o modelo 


Principais problemas do P2P:
- Falta de confiança nos outros
- Nós bizantinos
- Privacidade (gradientes podem vazar informações)

SPDL resolve tudo junto: descentralização + privacidade + tolerância a bizantinos + auditabilidade

Treinamento:
**Inicialização**:
- Cada nó cria chaves PK (pública) e SK (privada) e um id de 256 bit
- Cria um bloco gênesis com informações do nó que iniciou a blockchain
- Um novo nó só entra na rede se houver uma transação registrando os seus dados (pk, id, IP, etc).
- Todos os nós inciam com a mesma popularidade
- Todos os nós iniciam com um learning rate, quantidade de rodadas T e um valor de variancia gaussiana

**Decisão do líder**
- Cada nó executa o algoritmo de seleçãode líder
- A partir da chave primária e de uma seed aleatória, cada nó gera uma hash e uma prova $\pi$. Envia h e $\pi$ para a rede e recebe os valores dos peers.
- Cada nó possui um valor de reputação r. Somente nós com $r>0$ podem se tornar líderes
- O nó com maior $h$ e $r$ é considerado o líder responsaável pelo consenso naquela rodada.
- Se por um acaso mais de um líder for selecionado, roda o algoritmo de novo

Está protegido contra nós bizantinos serem líderes porque não é possível forjar os valores da função para outros nós 

**Cálculo do gradiente**
- Cada nó calcula localmente o SGD
- Adiciona um ruído gaussiano no gradiente 
- Transmite o gradiente ruidoso pela rede e recebe o dos outros

**Consenso de blockchain**
Realiza um consenso BFT e não um Proof-of-Work ou Proof-of-stack
É dividido em quatro fases

PRE-PREPARE: O líder executa o algoritmo de Krum e envia um bloco assinado para todos. 

PREPARE: Verifica se os gradientes recebidos fazem sentido de acordo com a assinatura e a perturbação do gradiente, verificando se está dentro de uma margem tolerável de modificação. Se passar, manda o voto. Se o líder for bizantino, os outros nós vão barrar, porque o gradiente não bate com o que eles computaram

COMMIT: Se um nó recebe 2f+1 PREPARE válidos, ele envia o COMMIT

DECIDE: Adiciona o bloco à blockchain local, atualiza o modelo (SGD) e atualiza as reputações

**Vantagens da Blockchain**
Só entra nos registros de transações uma atualização que recebeu quorum suficiente e foi verificada
Uma vez verificada, ninguém volta no tempo
O histórico permite auditar e punir os nós suspeitos diminuindo sua reputação

Ser um líder garante menos dependencia dos outros para avançar nas rodadas, menos risco de ficar pra trás no treinamento e maior controle do ritmo de treino, Além disso, garante que o nó é confiável