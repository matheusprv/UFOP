# The class imbalance in deep learning

## Introdução
Em classificações binárias, o desbalanceamento ocorre quando uma classe tem a maioria das instâncias e a outra tem a minoria.

O problema se estende para multi-classes, multi-labels, multi-instanciase também em problemas de regressão.

## 2. Revisão da literatura I: O efeito do desbalanceamento de classes em sistemas de aprendizado em profundiade
### 2.2 Desbalanceamento de classes e aprendizado em profundidade
Anand et al. (1993) descobriram que o vetor gradiente para a classe minoritária é menor do que o da classe majoritária. Assim, a classe com mais dados domina a atualização dos pesos e, enquanto o seu erro abaixa rapidamente, o da classe minoritária aumenta.

Murphey et al. (2004) descobriram que a performance da rede neural em dados desbalanceados está ligado a arquitetura da rede e a separabilidade das classes.

Lee et al. (2016) estudou um dataset com 103 classes. As classes mais representativas tinham 73,2%, 10,6%, 3,5%, 1,9% e 1,3%. A performance para essas classes foi alta, mas foi muito baixa para as minoritárias.

Ya-Guan et al. (2020) mostrou que não há combinação muito efetiva de funções de ativação. funções de custo e algoritmos de descida de gradiente mostraram resultados efetivos para lidar com os impactos negativos do desbalancemaneto dos dados

### 2.3 Concept complexity and deep learning
A complexidade de cada dataset também é um fator a se levar em consideração par aa queda de resultados

Há três grupos de medidas complexidades de datasets:
- Sobreposição das features
- Separabilidade das classes
- Medidas de geometria, topologia e densidade

Barella et al. (2021) mostrou que essas medidas não são tão úteis para casos reais. Mas mostraram possíveis adaptações para classificações binárias

Murphey et al. (2004) propos tres métodos para medir o nível de ruído em um dataset usando suas características. (i) usa o nível de ruído intra e inter classe; (ii) calcula a separabilidade linear do dataset; (iii) mede o número de exemplos da outra classe que cai nos limites de cada classe. Redes neurais mostraram uma forte dependência da separabilidade das classes

## 3 Experiments set up
Nenhum dos estudos apresentados estudou sobre a relação do desbalanceamento de classes, complexidade e escassez dos dados

Perguntas de pesquisa:
1. Deep learning sofre com o desbalanceamento de classes de forma normal ou alivia alguns fatores, como a complexidade?
2. Qual o papel da profundidade da rede no desbalanceamento/complexidade/escassez
3. Regularização ajuda em algo?

### 3.1 Perceptrons multicamadas profundos
#### 3.1.1 Domínios artificiais
Objetivo de criar uma família de domínios para estabelecer uma relação entre performance de predição, desbalanceamento de dados, complexidade do domínio e escassez de dados. Foi utilizado um método que varia (s) o tamanho dos dados; (c) complexidade estrutural; e (b) o grau de desbalanceamento das classes.

Foram gerados 50 domínios uni-dimensionais no intervalo $[0, 1]$ associados com as classes 1 (+) ou 0 (-).

O domínio é dividido em sub-intervalos de tamanhos iguais, cada um com classe 0 ou 1, onde intervalos sequenciais são de classes opostas.

O nível de complexidade (c) pode ter valores entre 1 e 5, influenciando na quantidade de subintervalos

O número de subgrupos é calculado por $2^{c}$, e a largura de cada grupo é definida por $\frac{1}{2^{c}}$

Uma vez que as subdivisões (backbones) estão prontas, pontos em cada sub-intervalo são gerados aleatoriamente, com a quantidade dependendo do tamanho do domínio e no grau de desbalanceamento

Os tamanhos s de cada dataset foram definidos como s=1 e s=5, sendo o número total de itens definido por $\frac{1000 \times s}{32} \times 2$

Diminui o tamanho da classe minoritária 0 de acordo com o grau de balanceamento b, e o tamanho de cada su brupo é dado por $\frac{\frac{\frac{1000 \times c }{32} \times 2}{2^{c}}}{\frac{32}{2^{b}}}$

Quando $b=1$, o dataset está muito desbalanceado e quando $b=5$ o dataset está equilibrado

#### 3.1.2 Domínios reais
Foram considerados dois datasets reais e textuais: 20NewsGroup e Job Classification. 

A complexidade foi observada pela inspeção dos dados usando a redução dimensional T-SNE e com experimentos de validação cruzada

Para selecionar os domínios, foram amostrados 500 publicações de cada classe e plotou as combinações de pares de classes

#### 3.1.3 Setup experimental
Tabela 4 mostra qual a separação dos dados para o treinamento da 20NewsGroup. Para a Job Classification, como tinha que separar em pares, não foi possível uma sumarização dos dados.

Os experimentos foram conduzidos em MLPs com 5 números distintos de camadas, denominados MLP-X, com X variando de 1 a 5 e sendo o número de camadas. O número de unidades ocultas em cada camada eram 2, 4, 8 e 16.

Os modelos foram treinados por 300 épocas, learning rate de 0.001 e usando o otimizador Adam.

### 3.2 Redes convolucionais
#### 3.2.1  Domínio Artificial
Cada imagem possu tamanho $200 \times 200 \times 3$, com objetos e fundos com cores sólidas, mas aleatórias, assim como os tamanhos, orientação e localização das formas

Cinco tarefas diferentes, onde comparava duplas de objetos

A complexidade é baseada na semelhança das formas

O dataset foi artificialmente modificado para adicionar níveis de balanceamento (b)

#### 3.2.2 Domínio real
Uso dos datasets MNIST e CIFAR10

A classe minoritária sofreu um undersampling aleatório

Os desafios foram escolhidos com base nas cinco dificuldades existentes

#### 3.2.3 Setup experimental
Variação dos modelos com a quantidade de camadas convolucionais: 1 (8), 2 (8-16), 3 (8-16-32), 4 (8-16-32-64), 5 (8-16-32-64-64)

## 6 Resultados no caso do percepetron em multi camadas
Análise das características do domínio dos problemas

Modelos MLP profundos são afetados da mesma forma como os modelos mais rasos.

O aumento da profundidade do modelo gera uma maior robustez e poder preditivo

Não foram observados ganhos com a aplicação de técnicas de regularização

### 6.1 Pergunta de pesquisa 1
**Observação 1:** Em abordagens tradicionais de aprendizado, domínios linearmente separáveis não são sensíveis ao desbalanceamento das classes. 

**Observação 2:** As classificações erradas aumentam junto com o aumento do desbalanceamento

**Observação 3:** O desbalanceamento da classe é agravado pela complexidade da mesma

**Pergunta de pesquisa 1:** As redes neurais com aprendizado em profundaidade sofre os mesmos problemas que outros métodos de aprendizado de máquina em relação ao desbalanceamento de classes.

### 6.2 Pergunta de pesquisa 2
Aumentar a profunidade pode ser benéfico em cenários mais difíceis, ou seja, quando há alta complexidade, escassez de dados e forte desbalanceamento de classes

A profundidade não resolve o problema completamente, pois pode ocorrer overfitting 

Profundidades muito altas ou muito baixas prejudicaram o modelo

### 6.3 Pergunta de pesquisa 3
As técnicas de regularização tradicionais não oferecem ganhos significativos frente ao triângulo desequilíbrio–complexidade–tamanho dos dados em MLPs: elas podem estabilizar ligeiramente o aprendizado, mas não mitigam os efeitos centrais do desbalanceamento

## 7 Resultados no caso de redes neurais convolucionais
### 7.1 Pergunta de pesquisa 1
Desequilíbrio de classes continua afetando o desempenho, mas menos intensamente do que nas MLPs

A complexidade dos dados não agrava claramente os efeitos do desbalanceamento. Em muitos casos, quanto mais complexa a tarefa, menor parece o impacto adicional do desequilíbrio, porque o desempenho da rede já era baixo desde o começo

Independente do grau de desequilíbrio, a escassez de dados apresenta uma forte degradação dos resultados

Nas imagens reais, CIFAR-10 e MNIST, a escassez de dados afeta mais do que o desequilíbrio

As CNNs são mais resilientes ao desequilíbrio do que as MLPs, mas são mais sensíveis à quantidade de dados de treinamento

### 7.2 Pergunta de pesquisa 2
Quanto mais profunda a rede, mais instável ela se torna

A rede pode ter sofrido de overfitting ou sua capacidade é muito grande e necessita de mais dados

A profundidade não ajuda o desbalanceamento de classes, complexidade do problema ou escassez dos dados. Os experimentos mostram que uma rede muito profunda pode ser, na verdade, perigosa.

### 7.3 Pergunta de pesquisa 3
Não foram mostrados melhorias significativas

## 8 Lições aprendidas pelas investigações experimentais
Lições aprendidas para MLP
- Modelos de MLP profundos são afetados pela complexidade, desbalanceamento e quantidade de dados
- Redes com profundidades baixas podem não ser o suficiente para o problema, há uma faixa onde se atinge um platô e, depois disso, redes muito profundas começam a ter piores resultados.
- Técnicas de regularização não possuem grande impacto nos resultados de datasets desbalanceados. Sendo mais úteis para melhorar resultados que já são mais relevantes

Lições aprendidas para CNN:
- O desbalanceamento é muito mais prejudicial para as CNNs do que para as MLPs
- O tamanho do dataset afeta mais do que o balanceamento de dados
- Não é sempre claro que os efeitos negativos do desbalanceamento é mais perceptível em problemas mais ou menos complexos
- Técnicas de regularização também não ajudaram 

## 9 Lidando com o problema de desbalanceamento de classes
As soluções para dados desbalanceados podem ser divididas em trÊs cateogiras: pré-processamento, pós-processamento e algoritmos de propóstios especiais.

Muitos desses métodos são feitos para trabalhar com imagens, e não com dados tabulares

### Pós processamento
Mudar o limiar de decisão utilizando as probabilidades de classes pode ser usado com imagens. Pode ser facilmente implementado sem precisar treinar novamente o modelo. O método ajuda a determinar o modelo da rede que reduz a probabilidade de errar a classificação de classes minoritárias.

O método pode ser hibridizado com o pré-processamento aplicando técnicas de de under/over-sample 

Para as MLPs, em cenários binarizados, a mudança do limiar de ativação pode ser melhor do que o padrão de 0.5

Resultados obtidos a partir de over-sampling são melhores do que os obtidos por under-sampling (Buda et al., 2018; Johnson & Khoshgoftaar, 2020)

Recentemente foi proposto o algoritmo DeepSMOTE para gerar dados aritificiais, tanto tabulares quanto imagens

Lee et al. (2016) treinou uma rede com under-sampling normalizado e, depois, aplicaou fin-tune (retreinou) usando os dados originais.

Murphey et al. (2004) faz um treinamento bola de neve: Primeiro treina somente com os dados da classe minoritária. Depois, vai dinamicamente aumentando a quantidade de dados da classe majoritaria 

CRL (Class Rectification Loss) é projetada para melhorar o aprendizado das classes minoritárias em cada batch balanceado

A Weighted Cross Entropy adiciona um maior peso para as modificações de classes minoritárias e um menor peso para as majoritárias

Focal loss modifica a Cross Entropy reduzindo o impacto que exemplos fáceis possuem. Ela multiplica a Cross Entropy por um fator e mantém as propriedades da WCE

A PF-Loss (Parameter Free Loss) não utiliza hiper-parâmetros e se ajusta dinamicamente para dar mais atenção às classes minoritárias

Sensibilidade ao custo pode ser feita adicionando uma matriz de custo à Cross Entropy loss, forçando o foco na classe minoritária a fim de minimizar o custo da classificação errada

Kang et al. (2019) perceberam que o desbalanceamento afeta, principalmente, o classificador, e nem tanto o aprendizado de características. Então, com representações de qualidade, basta re-balancear o classificador

O método inspirou ensambles profundos, que separam representação e classificação, onde uma parte da rede aprende padrões gerais enquanto a outra aprende das classes minoritárias. Com um aprendizado cumulativo, a atenção da rede é deslocada da classe majoritária para as minoritárias.

## Conclusão
O artigo apresentou duas contribuições prioncipais:
1. Ampla revisão da literatura mostrando que as redes profundas continuam vulneráveis ao desbalanceamento, e que avaliar a complexidade das tarefas ainda é um desafio pouco explorado.
2. Os experimentos controlados mostraram que:
    - MLPs se comportam de forma semelhante aos modelos tradicionais — o desempenho piora com maior desbalanceamento, complexidade e escassez de dados. A profundidade ajuda em alguns casos, mas não resolve o problema, e a regularização oferece ganhos mínimos.
    - CNNs são menos sensíveis ao desbalanceamento, mas muito afetadas pela falta de dados. Nem aumentar a profundidade nem aplicar regularização mostrou-se suficiente para eliminar esses efeitos.