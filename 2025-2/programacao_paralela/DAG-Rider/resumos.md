# Reaching Consensus in the Byzantine Empire: A Comprehensive Review of BFT Conseunsus Algorithms

## DAG-Rider: All You Need is DAG
Aplicam transações paralelas e constroem grafos direcionados acíclicos em cada nó.

Os grafos encapsulam toda a história das mensagens, incluindo seus caminhos e as relações entre as mensagens

Não necessitam de um servidor líder

Os algoritmos baseados em DAG possuem um pipeline paralelo usando a estrutura de dados DAG e podem, facilmente, separar as fases de distribuição e consenso. Isso faz o algoritmo ser mais escalável e eficiente.

Na fase de disseminação da mensagem, não se necessita de um líder, mas ele se faz necessário na fase de consenso, necessário para cada consenso. 

Ao invés de enfileirar mensagens sendo bloqueado por consensos anteriores, os nós disseminam e fazem um pipeline das mensagens de uma forma não bloqueante, independente do consenso atual. O consenso do commit da mensagem opera em um processo separado.

Possuem uma melhor transferÊncia de informação, mas sofrem de alta latência, uma vez que o consenso deve esperar a transação do pipeline.

### System model and service properties
DAG-Rider é um protocolo assíncrono com boa segurança e complexidade ótima para tempo e mensagens

É feito em duas camadas:
1. Rodada em turnos para a disseminação confiável de mensagens
2. Protocolo de consenso sem overhead que permide os nós a determinarem, de forma independente, o total de mensagens de ordem para commitar sem uma comunicação extra

Utiliza o Bracha Broadcast e tolera *f* nós faltosos com, pelo menos, $3f+1$ nós

### The DAG pipeline
Cada nó mantém o seu próprio DAG, representando a interpretação do nó da topologia da disseminação da mensagem para todos os nós

O DAG é montado em rodadas incrementais, começando com a formação do DAG na rodada *r* e adicionando os nós nas rodadas *r+1* 

Cada nó possui um vetor denominado por [], que armazena informações do DAG, como o número de vértices *v* e o número da rodada atual *r*. Cada vértice armazena informações como remetente da mensagem, conhecido como "fonte", o número da rodada e um bloco de transações.

Em cada rodada, o vértice se conecta àqueles com quem vai se comunicar

Em uma rodada *r*, uma aresta forte referencia os vértices que estão diretamente ligados na rodada anterior, enquanto uma aresta fraca referencia vertices que não estão diretamente conectados na rodada anterior

Quando os clientes propõem uma transação, os nós recebem vértices, armazenam em buffer e, constantemente, monitoram o status dos vertices. Os nós realizam verificações periódicas para verificar se os vértices dentro de um buffer receberam, com sucesso, todos os seus predecessores.

Quando os predecessores estão incluídos, os nós integram os vertices no vetor do DAG, organizando-os pela quantidade respectiva do número de rodadas

Após inserir *2f+1* vértices da rodada atual, o nó pode passar para a próxima rodada.

Na nova rodada, o nó gera um novo vértice com o número da rodada atual, arestas fortes e fracas e o bloco de transações. O vértice é enviado para todas as réplicas da rede.

Os nós podem receber diferentes DAGs devido à operação interna do próprio protocolo. Mas à medida que os nós aderem ao protocolo AB, os DAGs vão se convergindo.

### Consensus in DAGs


### Pros and cons
O DAG-Rider serve dois rósitos: disseminar a propagação de mensagens e facilitar o acordo de votação




====================================================================================================
# All You Need is DAG
## Model and Building Blocks
O sistema consiste em um conjunto de $\Pi=\{p_{1}, \dots, p_{n}\}$ de $n$ processos com $f<n/3$ (número de faltosos deve ser menor que um terço da quantidade de processos), Logo, $n = 3f + 1$.

A conexão entre dois links são corretas. Ou seja, quando um processo correto envia a informação para o outro, ela eventualmente chega e o recepetor pode verificar a origem.

O protocolo é assíncrono, logo, não há limite de tempo para a entrega da mensagem

Considera um adversário que pode, dinamicamente, corromper **até** $f$ processos durante a execução. Quando o adversário corrompe um processo, ele pode apagar mensagens antigas que aquele processo ainda não enviou para os outros. O adversário controla o tempo de chegada das mensagens

### Reliable broadcast
O Reliable Broadcast garante que todos os processos honests vão receber as mesmas mensagens, sem duplicatas, e sem aceitar mensagens falsas, mesmo com um nó bizantino

Uso da abstração do reliable rebroadcast para a implementação de um protocolo da fofoca (Cada nó começa com um valor e vai "fofocando" com nós aleatórios da rede sobre o seu status. O valor é atualizado por meio de uma média ponderada com os outros valores, até que os dados convirjam)


Cada processo remetente $p_{k}$ pode enviar mensagens confiáveis chamando `reliable rebroadcast` ($r\_bcast_{k}(m, r)$), com $m$ sendo a mensagem e $r$ sendo o número da rodada atual.

Quando uma mensagem é recebida corretamente, o processo $p_{i}$ executa $r_deliver_{i}(m, r, p_{k})$, onde $m$ é uma mensagem, $r$ é o número da rodada e $p_{k}$ é o remetente

Isso garante as três propriedades do reliable broadcast:
1. **Agreement (acordo)**: Se um processo correto entrega uma mensagem, então todos os outros processos vão, eventualmente, receber a mesma mensagem
2. **Integrity (Integridade)**: Um processo correto entrega no máximo uma vez a mensagem de um remetente em uma rodada
3. **Validity (Validade)**: Se um processo correto $p_{k}$ chama o $r\_bcast_{k}(m, r)$, então todos os processos corretos $p_{i}$ chamarão $r_deliver_{i}(m, r, p_{k})$

### Global perfect coin
É impossível atingir consenso determinístico em um sistema assíncrono com uma única falha possível (teorema FLP).

A Global Perfect Coin é um mecanismo aleatorio que o protocolo usa para quebrar empates e garantir que o sistema eventualmente progrida

É uma abstração aleatória compartilhada entre todos os prcoessos corretos. É uma moeda virtual que todos lançam juntos e sempre dá o mesmo resultado para todos os processos honestos

É uma função que retorna um valor aleatório imprevisível, mas idêntico para todos os nós corretos, e é imprevisível para o adversário

Uma instância $w, w \in \mathbb{N}$, da moeda é invocada pelo processo $p_{i}$ chamando a $choose_leader_{i}(w)$, que retorna um processo que será o líder da instância $w$

A global perfect coin tem as seguintes garantias:
1. **Agreement (acordo)**: Se dois processos chamarem o `choose_leader(w)` na mesma rodada, ele terão o mesmo resultado
2. **Termination (Terminação)**: Se, pelo menos, $f+1$ processos chamarem `choose_leader(w)`, então todos receberão um resultado, eventualmente
3. **Unpredictability (Imprevisibilidade)**: Contanto que menos de $f+1$ processos chamem `choose_leader(w)`, o valor é completamente aleatório, exceto por uma pequena probabilidade $\varepsilon$
4. **Fairness (Justiça)**: Todos os processos têm a mesma chance $1/n$ de serem escolhidos líderes

## 3 Definição do problema
O problema a ser resolvido é o Byzantine Atomic Broadcast (BAB), que permite processos a concordarem em uma sequência de mensagens.

Segundo o FLP, um BAB não pode ser assíncrono, porque pode ocorrer uma falaha e o sistema travat. Por isso, utilizam a global perfect coin

BAB broadcast: `a_bcast(m, r)`
BAB deliver: `a_deliver(m,r,k)`

Definição de Byzantine Atomic Broadcast: Cada processo correto chama `a_bcast` e `a_deliver`, e isso já satisfaz o reliable broadcast. Mas também garante a ordem total. Se $p_{i}$ chama `a_deliver(m,r,k)`antes de `a_deliver(m',r',k')`, então nenhum processo correto pode chamar `a_deliver(m, r, k)`antes de `a_deliver(m,r,k)`. Ou seja, a ordem das mensagens devem ser a mesma


## 4 Abstração do DAG
O grafo direcionado acíclico representa a camada de comunicação do protocolo

Cada vértice representa a transmissão de mensagens de um processo, e cada mensagem contém referências para para vértices transmitidos anteriormente.

Cada processo correto tem sua versão do DAG, mas elas vão convergindo à medida em que as mesangens vão chegando

Cada processo $p_{i}$ tem uma visão $DAG_i$, armazenado em um arrat $DAG_i []$

Cada vértice está associado com um número de rodada e uma fonte (seu processo de origem). 

Na rodada $r$, todos os vértices que $p_i$ conhece estão em $DAG_i[r]$.

Cada rodada tem, no máximo, $n$ vértices, cada um com uma fonte diferente

Cada vértice em uma rodada possui dois tipos de arestas: pelo menos, $2f+1$ arestas fortes, que apontam para vértices da rodada r-1, e até $f$ arestas fracas que apontam para vértices mais antigos, $r<r-1$

Arestas fortes são usadas para acordos e arestas fracas são usadas para ter certeza de incluir todos os vértices em algum momento


