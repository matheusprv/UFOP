param n; # Numero de pedidos
param m; # Numero de maquinas

# Sets
set Pedidos := {1 .. n};   # Pedidos
set Maquinas := {1 .. m};  # Maquinas
set Posicoes := Pedidos;   # Numero de posicoes igual ao numero de pedidos

# Parametros
param p{i in Pedidos, j in Maquinas};  # Tempo de processamento
param d{i in Pedidos};                 # Deadline definido previamente
param M := 1000;                       # Constante grande

# Atribucao da tareja j do pedido i a posicao h (1 se a tarefa j do pedido i esta na posicao h, 0 caso contrario)
var x{i in Pedidos, j in Maquinas, h in Posicoes}, binary; 
# Tempo de finalizacao da tarefa j do pedido i quando atribuida a posicao h (Conclusao_Tarefa[i,j] caso xijh = 1, 0 caso xihj = 0)
var z{i in Pedidos, j in Maquinas, h in Posicoes} >= 0; 
# Tempo de finalizacao da tarefa j do pedido i
var Conclusao_Tarefa{i in Pedidos, j in Maquinas} >= 0; 
# Tempo de finalizacao do pedido i
var Conclusao_Pedido{i in Pedidos} >= 0; 
# Tempo de antecipacao da tarefa j do pedido i
var Antecipacao{i in Pedidos, j in Maquinas} >= 0; 
# Tempo de atraso do pedido
var Atraso{i in Pedidos} >= 0; 

# Funcao objetivo
minimize Total_Cost: 
  sum{i in Pedidos} (sum{j in Maquinas} Antecipacao[i,j] + m * Atraso[i]);

# Restricoes
# Garante que so tenha 1 tarefa do pedido i por maquina
Um_pedido_por_maquina {i in Pedidos, j in Maquinas}: 
  sum{h in Posicoes} x[i,j,h] = 1;

# Garante que so tenha 1 tarefa por posicao na maquina j
Uma_tarefa_por_posicao {h in Posicoes, j in Maquinas}: 
  sum{i in Pedidos} x[i,j,h] = 1;




# Garantem que uma tarefa so pode iniciar apos o fim da que esta na posicao anterior
Restricao_de_sequencia {h in Posicoes, j in Maquinas: h > 1}:
    sum{i in Pedidos} z[i,j,h-1] <= sum{i in Pedidos} (z[i,j,h] - x[i,j,h]*p[i,j]);
Inicio_primeira_tarefa {j in Maquinas}: 
  0 <= sum{i in Pedidos} (z[i,j,1] - x[i,j,1]*p[i,j]);




# Garantem que z[i,j,h] (tempo de finalizacao da tarefa j do pedido i na posicao h) tenha o mesmo valor de Conclusao_Tarefa[i,j] quando essa tarefa tiver sido atribuida a posicao h (ou seja, quando x[i,j,h] = 1), e tenha valor 0 caso contrario
tempo_finalizacao_z{i in Pedidos, j in Maquinas, h in Posicoes}: 
  Conclusao_Tarefa[i,j] - M * (1 - x[i,j,h]) <= z[i,j,h];
z_completude_unica{i in Pedidos, j in Maquinas}: 
  sum{h in Posicoes} z[i,j,h] <= Conclusao_Tarefa[i,j];



# Garante que nenhuma tarefa do pedido i tenha um tempo de conclusao maior que o proprio pedido
Restricao_tempo_conclusao_tarefa{i in Pedidos, j in Maquinas}: 
  Conclusao_Tarefa[i,j] <= Conclusao_Pedido[i];



# Garante que o tempo de atraso do pedido i seja o valor maximo entre 0 e a subtracao do seu tempo de conclusao - seu Deadline
Restricao_de_atraso{i in Pedidos}: 
  Conclusao_Pedido[i] - d[i] <= Atraso[i];



# Garantem que o tempo de antecipacao da tarefa j do pedido i seja a subtracao do valor maximo entre o Deadline do pedido e seu tempo de conclusao - o tempo de conclusao daquela tarefa
Restricao_de_antecipacao{i in Pedidos, j in Maquinas}: 
  d[i] - Conclusao_Tarefa[i,j] <= Antecipacao[i,j];
Restricao_de_antecipacao2{i in Pedidos, j in Maquinas}: 
  Conclusao_Pedido[i] - Conclusao_Tarefa[i,j] <= Antecipacao[i,j];



data;

param n := 3;
param m := 2;

param p : 1 2 :=
1   2 1
2   1 1
3   1 6;

param d := 
1   7
2   8
3   9;

end;


