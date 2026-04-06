# Grafo Acíclico Direcionado
Representa de forma abstrata a camada de comunicação dos processos 

Os vértices representam o conteúdo das mensagens, possuindo informações como o número da rodada em que ele foi criado, qual o processo que o gerou, seu bloco de transações, ou seja, as informações úteis para a aplicação, e suas arestas, que podem ser fortes e fracas.

As arestas representam o histórico das mensagens trocadas entre os processos e indicam que o vértice filho conhecia e dependia do vértice pai no momento em que foi criado. Assim, quando um vértice é criado, o processo reconhece que tudo que veio antes dele já faz parte de um conhecimento coletivo.

Cada vértice tem que possuir pelo menos 2f + 1 arestas referenciando vértices da rodada anterior, gerando uma aresta forte. Isso garante que, mesmo com f processos bizantinos, pelo menos f+1 vértices corretos estão mantendo a história correta e não esquecendo informações

Como o protocolo é assíncrono, então vocÊ não tem todas as informações no momento exato. Então alguém pode receber um vértice bem depois. Assim vai ser incluído no grafo como uma aresta fraca. O avanço do grafo já foi garantido com as arestas fortes, mas isso garante a completude do grafo e permite que os grafos convirjam 




Cada processo vai possuir a sua própria versão do DAG, uma vez que ele é assíncrono e as mensagens podem chegar em ordens diferentes. Porém como estamos trabalhando com o Reliable Broadcast, isso significa que em algum momento todas as mensagens vão chegar e os grafos irão convergir

O DAG é um vetor onde cada índice indica uma rodada do protocolo. Como cada rodada pode possuir mais de uma mensagem, então o DAG é um vetor bidimensional onde a segunda dimensão representa as mensagens e pode ter tamanho de, no máximo, N


# DAG-Rider
É a parte de ordenação do protocolo, onde os consensos são feitos. Ele não utiliza nenhuma comunicação a mais, somente as informações presentes no próprio DAG, olhando as referências fortes e fracas e decide quais transações devem ser commitadas e em qual ordem, usando o caminho deles e uma moeda aleatória


As rodadas são divididas em ondas, onde cada onda possui quatro rodadas, e termina quando processa a quarta rodada

Na primeira rodada, um processo líder é escolhido pela moeda para ter o seu vértice commitado 

O vértice só vai poder ser commitado se, na rodada quatro, houver 2f+1 caminhos que liguem até ele. Isso acontece porque os vértices vão acumulando conhecimento das rodadas anteriores, e se muitos processos conhecem o líder, então todos vão ter suas informações no DAG, garantindo um acordo entre os participantes

Se o líder escolhido não possui nenhum vértice ou não existe um quorum suficiente, então ignora essa wave e passa para a próxima. Se não, as próximas linhas fazem um commit retroativo e com a ordenação dos vértices


Na figura 2, v2 e v3 são os líderes de suas ondas. Mas, no fim da onda 2, o v2 não pode ser committado, porque ele não possui 2f+1 arestas fortes que chegam nele. Mas, para o v3, ele possui as condições mínimas, então ele pode ser committado. Como a informação é mantida e os vértices vão acumulando conhecimento, então v2 será committado quando v3 também for

Se foi committado, então para que serve a aresta fraca? A aresta fraca serve para garantir a estrutura correta do DAG e a convergÊncia dele. Isso acontece porque, como o algoritmo é assíncrono, uma mensagem pode chegar mais tarde. Então, isso garante que os vértices ainda entrarão no DAG

# Lidando com dados bizantinos
O DAG-Rider não verifica o conteúdo das mensagens, isso fica para a camada de aplicação . O protocolo garante a ordem das mensagens e assegura que os processos tenham o mesmo DAG

Supondo que o processo líder é um bizantino, então duas coisas podem acontecer


**O malicioso criou um vértice válido e tenta agir normalmente**
Ele ainda assim vai ter somente um vértice por round, precisa das arestas fortes e uma posição legítima no DAG. Então, ele pode ser committado normalmente. O responsável pela verificação do conteúdo da mensagem é a camada de aplicação, então ela deve verificar se o que chegou faz sentido, para, assim, colocar o vértice no grafo

**O líder malicioso tenta agir maliciosamente**
- Não enviar o vértice no round 1: Falha, porque o algoritmo para decidir o líder vai perceber que não tem nenhuma informação ali
- Arestas fortes insuficientes: O vértice precisaria ser validado para entrar nos outros DAGs, mas como isso não ocorre, ele nunca será committado, ainda mais que ele não consegue convencer 2f+1 processos honestos

Nesses casos, não haverá commits por parte de outros processos, então meio que se perde a onda, e a próxima é feita com um novo líder



# COmunicação e complexidade de tempo
cada processo faz um broadcast com custo O(n² log n) e são feitos n broadcasts por rodada