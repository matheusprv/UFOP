from gerar_grafico import *

NUM_PEDIDOS = 3
NUM_MAQUINAS = 2


# Pij
p = [
    [2, 1],
    [1, 1],
    [1, 6]
]


# Di
d = [7, 8, 9]

# Cij 
Cij = [
    [7, 7], 
    [8, 8],
    [9, 6]
]

gerar_graficos(p, d, Cij)





"""
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



Problem:    tp
Rows:       64
Columns:    54 (18 integer, 18 binary)
Non-zeros:  219
Status:     INTEGER OPTIMAL
Objective:  Total_Cost = 3 (MINimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 Total_Cost                  3                             
     2 Um_pedido_por_maquina[1,1]
                                   1             1             = 
     3 Um_pedido_por_maquina[1,2]
                                   1             1             = 
     4 Um_pedido_por_maquina[2,1]
                                   1             1             = 
     5 Um_pedido_por_maquina[2,2]
                                   1             1             = 
     6 Um_pedido_por_maquina[3,1]
                                   1             1             = 
     7 Um_pedido_por_maquina[3,2]
                                   1             1             = 
     8 Uma_tarefa_por_posicao[1,1]
                                   1             1             = 
     9 Uma_tarefa_por_posicao[1,2]
                                   1             1             = 
    10 Uma_tarefa_por_posicao[2,1]
                                   1             1             = 
    11 Uma_tarefa_por_posicao[2,2]
                                   1             1             = 
    12 Uma_tarefa_por_posicao[3,1]
                                   1             1             = 
    13 Uma_tarefa_por_posicao[3,2]
                                   1             1             = 
    14 Restricao_de_sequencia[2,1]
                                   0                          -0 
    15 Restricao_de_sequencia[2,2]
                                   0                          -0 
    16 Restricao_de_sequencia[3,1]
                                   0                          -0 
    17 Restricao_de_sequencia[3,2]
                                   0                          -0 
    18 Inicio_primeira_tarefa[1]
                                  -5                          -0 
    19 Inicio_primeira_tarefa[2]
                                   0                          -0 
    20 tempo_finalizacao_z[1,1,1]
                                1000                        1000 
    21 tempo_finalizacao_z[1,1,2]
                                   7                        1000 
    22 tempo_finalizacao_z[1,1,3]
                                   7                        1000 
    23 tempo_finalizacao_z[1,2,1]
                                   7                        1000 
    24 tempo_finalizacao_z[1,2,2]
                                1000                        1000 
    25 tempo_finalizacao_z[1,2,3]
                                   7                        1000 
    26 tempo_finalizacao_z[2,1,1]
                                   8                        1000 
    27 tempo_finalizacao_z[2,1,2]
                                1000                        1000 
    28 tempo_finalizacao_z[2,1,3]
                                   8                        1000 
    29 tempo_finalizacao_z[2,2,1]
                                   8                        1000 
    30 tempo_finalizacao_z[2,2,2]
                                   8                        1000 
    31 tempo_finalizacao_z[2,2,3]
                                1000                        1000 
    32 tempo_finalizacao_z[3,1,1]
                                   9                        1000 
    33 tempo_finalizacao_z[3,1,2]
                                   9                        1000 
    34 tempo_finalizacao_z[3,1,3]
                                1000                        1000 
    35 tempo_finalizacao_z[3,2,1]
                                1000                        1000 
    36 tempo_finalizacao_z[3,2,2]
                                   6                        1000 
    37 tempo_finalizacao_z[3,2,3]
                                   6                        1000 
    38 z_completude_unica[1,1]
                                   0                          -0 
    39 z_completude_unica[1,2]
                                   0                          -0 
    40 z_completude_unica[2,1]
                                   0                          -0 
    41 z_completude_unica[2,2]
                                   0                          -0 
    42 z_completude_unica[3,1]
                                   0                          -0 
    43 z_completude_unica[3,2]
                                   0                          -0 
    44 Restricao_tempo_conclusao_tarefa[1,1]
                                   0                          -0 
    45 Restricao_tempo_conclusao_tarefa[1,2]
                                   0                          -0 
    46 Restricao_tempo_conclusao_tarefa[2,1]
                                   0                          -0 
    47 Restricao_tempo_conclusao_tarefa[2,2]
                                   0                          -0 
    48 Restricao_tempo_conclusao_tarefa[3,1]
                                   0                          -0 
    49 Restricao_tempo_conclusao_tarefa[3,2]
                                  -3                          -0 
    50 Restricao_de_atraso[1]
                                   7                           7 
    51 Restricao_de_atraso[2]
                                   8                           8 
    52 Restricao_de_atraso[3]
                                   9                           9 
    53 Restricao_de_antecipacao[1,1]
                                  -7                          -7 
    54 Restricao_de_antecipacao[1,2]
                                  -7                          -7 
    55 Restricao_de_antecipacao[2,1]
                                  -8                          -8 
    56 Restricao_de_antecipacao[2,2]
                                  -8                          -8 
    57 Restricao_de_antecipacao[3,1]
                                  -9                          -9 
    58 Restricao_de_antecipacao[3,2]
                                  -9                          -9 
    59 Restricao_de_antecipacao2[1,1]
                                   0                          -0 
    60 Restricao_de_antecipacao2[1,2]
                                   0                          -0 
    61 Restricao_de_antecipacao2[2,1]
                                   0                          -0 
    62 Restricao_de_antecipacao2[2,2]
                                   0                          -0 
    63 Restricao_de_antecipacao2[3,1]
                                   0                          -0 
    64 Restricao_de_antecipacao2[3,2]
                                   0                          -0 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 x[1,1,1]     *              1             0             1 
     2 x[1,1,2]     *              0             0             1 
     3 x[1,1,3]     *              0             0             1 
     4 x[1,2,1]     *              0             0             1 
     5 x[1,2,2]     *              1             0             1 
     6 x[1,2,3]     *              0             0             1 
     7 x[2,1,1]     *              0             0             1 
     8 x[2,1,2]     *              1             0             1 
     9 x[2,1,3]     *              0             0             1 
    10 x[2,2,1]     *              0             0             1 
    11 x[2,2,2]     *              0             0             1 
    12 x[2,2,3]     *              1             0             1 
    13 x[3,1,1]     *              0             0             1 
    14 x[3,1,2]     *              0             0             1 
    15 x[3,1,3]     *              1             0             1 
    16 x[3,2,1]     *              1             0             1 
    17 x[3,2,2]     *              0             0             1 
    18 x[3,2,3]     *              0             0             1 
    19 z[1,1,1]                    7             0               
    20 z[2,1,1]                    0             0               
    21 z[3,1,1]                    0             0               
    22 z[1,1,2]                    0             0               
    23 z[2,1,2]                    8             0               
    24 z[3,1,2]                    0             0               
    25 z[1,2,1]                    0             0               
    26 z[2,2,1]                    0             0               
    27 z[3,2,1]                    6             0               
    28 z[1,2,2]                    7             0               
    29 z[2,2,2]                    0             0               
    30 z[3,2,2]                    0             0               
    31 z[1,1,3]                    0             0               
    32 z[2,1,3]                    0             0               
    33 z[3,1,3]                    9             0               
    34 z[1,2,3]                    0             0               
    35 z[2,2,3]                    8             0               
    36 z[3,2,3]                    0             0               
    37 Conclusao_Tarefa[1,1]
                                   7             0               
    38 Conclusao_Tarefa[1,2]
                                   7             0               
    39 Conclusao_Tarefa[2,1]
                                   8             0               
    40 Conclusao_Tarefa[2,2]
                                   8             0               
    41 Conclusao_Tarefa[3,1]
                                   9             0               
    42 Conclusao_Tarefa[3,2]
                                   6             0               
    43 Conclusao_Pedido[1]
                                   7             0               
    44 Conclusao_Pedido[2]
                                   8             0               
    45 Conclusao_Pedido[3]
                                   9             0               
    46 Antecipacao[1,1]
                                   0             0               
    47 Antecipacao[1,2]
                                   0             0               
    48 Antecipacao[2,1]
                                   0             0               
    49 Antecipacao[2,2]
                                   0             0               
    50 Antecipacao[3,1]
                                   0             0               
    51 Antecipacao[3,2]
                                   3             0               
    52 Atraso[1]                   0             0               
    53 Atraso[2]                   0             0               
    54 Atraso[3]                   0             0               

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 8.88e-16 on row 43
        max.rel.err = 8.88e-16 on row 43
        High quality

End of output


"""