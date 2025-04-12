from gerar_grafico import *

# Pij
p = [
    [4, 5],
    [5, 6],
    [4, 4],
    [6, 5],
    [5, 4],
]


# Di
d = [18, 20, 16, 22, 19]


# Cij 
Cij =[
    [18, 11],
    [30, 30],
    [14, 15],
    [24, 24],
    [10, 19],
]

gerar_graficos(p, d, Cij)

"""
data;

param n := 5;
param m := 2;

param p : 1   2 :=
         1   4   5
         2   5   6
         3   4   4
         4   6   5
         5   5   4;

param d :=
  1   18
  2   20
  3   16
  4   22
  5   19;

  



Problem:    tp
Rows:       126
Columns:    130 (50 integer, 50 binary)
Non-zeros:  545
Status:     INTEGER OPTIMAL
Objective:  Total_Cost = 43 (MINimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 Total_Cost                 43                             
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
     8 Um_pedido_por_maquina[4,1]
                                   1             1             = 
     9 Um_pedido_por_maquina[4,2]
                                   1             1             = 
    10 Um_pedido_por_maquina[5,1]
                                   1             1             = 
    11 Um_pedido_por_maquina[5,2]
                                   1             1             = 
    12 Uma_tarefa_por_posicao[1,1]
                                   1             1             = 
    13 Uma_tarefa_por_posicao[1,2]
                                   1             1             = 
    14 Uma_tarefa_por_posicao[2,1]
                                   1             1             = 
    15 Uma_tarefa_por_posicao[2,2]
                                   1             1             = 
    16 Uma_tarefa_por_posicao[3,1]
                                   1             1             = 
    17 Uma_tarefa_por_posicao[3,2]
                                   1             1             = 
    18 Uma_tarefa_por_posicao[4,1]
                                   1             1             = 
    19 Uma_tarefa_por_posicao[4,2]
                                   1             1             = 
    20 Uma_tarefa_por_posicao[5,1]
                                   1             1             = 
    21 Uma_tarefa_por_posicao[5,2]
                                   1             1             = 
    22 Restricao_de_sequencia[2,1]
                                   0                          -0 
    23 Restricao_de_sequencia[2,2]
                                   0                          -0 
    24 Restricao_de_sequencia[3,1]
                                   0                          -0 
    25 Restricao_de_sequencia[3,2]
                                   0                          -0 
    26 Restricao_de_sequencia[4,1]
                                   0                          -0 
    27 Restricao_de_sequencia[4,2]
                                   0                          -0 
    28 Restricao_de_sequencia[5,1]
                                  -1                          -0 
    29 Restricao_de_sequencia[5,2]
                                   0                          -0 
    30 Inicio_primeira_tarefa[1]
                                  -5                          -0 
    31 Inicio_primeira_tarefa[2]
                                  -6                          -0 
    32 tempo_finalizacao_z[1,1,1]
                                  18                        1000 
    33 tempo_finalizacao_z[1,1,2]
                                  18                        1000 
    34 tempo_finalizacao_z[1,1,3]
                                1000                        1000 
    35 tempo_finalizacao_z[1,1,4]
                                  18                        1000 
    36 tempo_finalizacao_z[1,1,5]
                                  18                        1000 
    37 tempo_finalizacao_z[1,2,1]
                                1000                        1000 
    38 tempo_finalizacao_z[1,2,2]
                                  11                        1000 
    39 tempo_finalizacao_z[1,2,3]
                                  11                        1000 
    40 tempo_finalizacao_z[1,2,4]
                                  11                        1000 
    41 tempo_finalizacao_z[1,2,5]
                                  11                        1000 
    42 tempo_finalizacao_z[2,1,1]
                                  30                        1000 
    43 tempo_finalizacao_z[2,1,2]
                                  30                        1000 
    44 tempo_finalizacao_z[2,1,3]
                                  30                        1000 
    45 tempo_finalizacao_z[2,1,4]
                                  30                        1000 
    46 tempo_finalizacao_z[2,1,5]
                                1000                        1000 
    47 tempo_finalizacao_z[2,2,1]
                                  30                        1000 
    48 tempo_finalizacao_z[2,2,2]
                                  30                        1000 
    49 tempo_finalizacao_z[2,2,3]
                                  30                        1000 
    50 tempo_finalizacao_z[2,2,4]
                                  30                        1000 
    51 tempo_finalizacao_z[2,2,5]
                                1000                        1000 
    52 tempo_finalizacao_z[3,1,1]
                                  14                        1000 
    53 tempo_finalizacao_z[3,1,2]
                                1000                        1000 
    54 tempo_finalizacao_z[3,1,3]
                                  14                        1000 
    55 tempo_finalizacao_z[3,1,4]
                                  14                        1000 
    56 tempo_finalizacao_z[3,1,5]
                                  14                        1000 
    57 tempo_finalizacao_z[3,2,1]
                                  15                        1000 
    58 tempo_finalizacao_z[3,2,2]
                                1000                        1000 
    59 tempo_finalizacao_z[3,2,3]
                                  15                        1000 
    60 tempo_finalizacao_z[3,2,4]
                                  15                        1000 
    61 tempo_finalizacao_z[3,2,5]
                                  15                        1000 
    62 tempo_finalizacao_z[4,1,1]
                                  24                        1000 
    63 tempo_finalizacao_z[4,1,2]
                                  24                        1000 
    64 tempo_finalizacao_z[4,1,3]
                                  24                        1000 
    65 tempo_finalizacao_z[4,1,4]
                                1000                        1000 
    66 tempo_finalizacao_z[4,1,5]
                                  24                        1000 
    67 tempo_finalizacao_z[4,2,1]
                                  24                        1000 
    68 tempo_finalizacao_z[4,2,2]
                                  24                        1000 
    69 tempo_finalizacao_z[4,2,3]
                                  24                        1000 
    70 tempo_finalizacao_z[4,2,4]
                                1000                        1000 
    71 tempo_finalizacao_z[4,2,5]
                                  24                        1000 
    72 tempo_finalizacao_z[5,1,1]
                                1000                        1000 
    73 tempo_finalizacao_z[5,1,2]
                                  10                        1000 
    74 tempo_finalizacao_z[5,1,3]
                                  10                        1000 
    75 tempo_finalizacao_z[5,1,4]
                                  10                        1000 
    76 tempo_finalizacao_z[5,1,5]
                                  10                        1000 
    77 tempo_finalizacao_z[5,2,1]
                                  19                        1000 
    78 tempo_finalizacao_z[5,2,2]
                                  19                        1000 
    79 tempo_finalizacao_z[5,2,3]
                                1000                        1000 
    80 tempo_finalizacao_z[5,2,4]
                                  19                        1000 
    81 tempo_finalizacao_z[5,2,5]
                                  19                        1000 
    82 z_completude_unica[1,1]
                                   0                          -0 
    83 z_completude_unica[1,2]
                                   0                          -0 
    84 z_completude_unica[2,1]
                                   0                          -0 
    85 z_completude_unica[2,2]
                                   0                          -0 
    86 z_completude_unica[3,1]
                                   0                          -0 
    87 z_completude_unica[3,2]
                                   0                          -0 
    88 z_completude_unica[4,1]
                                   0                          -0 
    89 z_completude_unica[4,2]
                                   0                          -0 
    90 z_completude_unica[5,1]
                                   0                          -0 
    91 z_completude_unica[5,2]
                                   0                          -0 
    92 Restricao_tempo_conclusao_tarefa[1,1]
                                   0                          -0 
    93 Restricao_tempo_conclusao_tarefa[1,2]
                                  -7                          -0 
    94 Restricao_tempo_conclusao_tarefa[2,1]
                                   0                          -0 
    95 Restricao_tempo_conclusao_tarefa[2,2]
                                   0                          -0 
    96 Restricao_tempo_conclusao_tarefa[3,1]
                                  -1                          -0 
    97 Restricao_tempo_conclusao_tarefa[3,2]
                                   0                          -0 
    98 Restricao_tempo_conclusao_tarefa[4,1]
                                   0                          -0 
    99 Restricao_tempo_conclusao_tarefa[4,2]
                                   0                          -0 
   100 Restricao_tempo_conclusao_tarefa[5,1]
                                  -9                          -0 
   101 Restricao_tempo_conclusao_tarefa[5,2]
                                   0                          -0 
   102 Restricao_de_atraso[1]
                                  18                          18 
   103 Restricao_de_atraso[2]
                                  20                          20 
   104 Restricao_de_atraso[3]
                                  15                          16 
   105 Restricao_de_atraso[4]
                                  22                          22 
   106 Restricao_de_atraso[5]
                                  19                          19 
   107 Restricao_de_antecipacao[1,1]
                                 -18                         -18 
   108 Restricao_de_antecipacao[1,2]
                                 -18                         -18 
   109 Restricao_de_antecipacao[2,1]
                                 -30                         -20 
   110 Restricao_de_antecipacao[2,2]
                                 -30                         -20 
   111 Restricao_de_antecipacao[3,1]
                                 -16                         -16 
   112 Restricao_de_antecipacao[3,2]
                                 -16                         -16 
   113 Restricao_de_antecipacao[4,1]
                                 -24                         -22 
   114 Restricao_de_antecipacao[4,2]
                                 -24                         -22 
   115 Restricao_de_antecipacao[5,1]
                                 -19                         -19 
   116 Restricao_de_antecipacao[5,2]
                                 -19                         -19 
   117 Restricao_de_antecipacao2[1,1]
                                   0                          -0 
   118 Restricao_de_antecipacao2[1,2]
                                   0                          -0 
   119 Restricao_de_antecipacao2[2,1]
                                   0                          -0 
   120 Restricao_de_antecipacao2[2,2]
                                   0                          -0 
   121 Restricao_de_antecipacao2[3,1]
                                  -1                          -0 
   122 Restricao_de_antecipacao2[3,2]
                                  -1                          -0 
   123 Restricao_de_antecipacao2[4,1]
                                   0                          -0 
   124 Restricao_de_antecipacao2[4,2]
                                   0                          -0 
   125 Restricao_de_antecipacao2[5,1]
                                   0                          -0 
   126 Restricao_de_antecipacao2[5,2]
                                   0                          -0 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 x[1,1,1]     *              0             0             1 
     2 x[1,1,2]     *              0             0             1 
     3 x[1,1,3]     *              1             0             1 
     4 x[1,1,4]     *              0             0             1 
     5 x[1,1,5]     *              0             0             1 
     6 x[1,2,1]     *              1             0             1 
     7 x[1,2,2]     *              0             0             1 
     8 x[1,2,3]     *              0             0             1 
     9 x[1,2,4]     *              0             0             1 
    10 x[1,2,5]     *              0             0             1 
    11 x[2,1,1]     *              0             0             1 
    12 x[2,1,2]     *              0             0             1 
    13 x[2,1,3]     *              0             0             1 
    14 x[2,1,4]     *              0             0             1 
    15 x[2,1,5]     *              1             0             1 
    16 x[2,2,1]     *              0             0             1 
    17 x[2,2,2]     *              0             0             1 
    18 x[2,2,3]     *              0             0             1 
    19 x[2,2,4]     *              0             0             1 
    20 x[2,2,5]     *              1             0             1 
    21 x[3,1,1]     *              0             0             1 
    22 x[3,1,2]     *              1             0             1 
    23 x[3,1,3]     *              0             0             1 
    24 x[3,1,4]     *              0             0             1 
    25 x[3,1,5]     *              0             0             1 
    26 x[3,2,1]     *              0             0             1 
    27 x[3,2,2]     *              1             0             1 
    28 x[3,2,3]     *              0             0             1 
    29 x[3,2,4]     *              0             0             1 
    30 x[3,2,5]     *              0             0             1 
    31 x[4,1,1]     *              0             0             1 
    32 x[4,1,2]     *              0             0             1 
    33 x[4,1,3]     *              0             0             1 
    34 x[4,1,4]     *              1             0             1 
    35 x[4,1,5]     *              0             0             1 
    36 x[4,2,1]     *              0             0             1 
    37 x[4,2,2]     *              0             0             1 
    38 x[4,2,3]     *              0             0             1 
    39 x[4,2,4]     *              1             0             1 
    40 x[4,2,5]     *              0             0             1 
    41 x[5,1,1]     *              1             0             1 
    42 x[5,1,2]     *              0             0             1 
    43 x[5,1,3]     *              0             0             1 
    44 x[5,1,4]     *              0             0             1 
    45 x[5,1,5]     *              0             0             1 
    46 x[5,2,1]     *              0             0             1 
    47 x[5,2,2]     *              0             0             1 
    48 x[5,2,3]     *              1             0             1 
    49 x[5,2,4]     *              0             0             1 
    50 x[5,2,5]     *              0             0             1 
    51 z[1,1,1]                    0             0               
    52 z[2,1,1]                    0             0               
    53 z[3,1,1]                    0             0               
    54 z[4,1,1]                    0             0               
    55 z[5,1,1]                   10             0               
    56 z[1,1,2]                    0             0               
    57 z[2,1,2]                    0             0               
    58 z[3,1,2]                   14             0               
    59 z[4,1,2]                    0             0               
    60 z[5,1,2]                    0             0               
    61 z[1,2,1]                   11             0               
    62 z[2,2,1]                    0             0               
    63 z[3,2,1]                    0             0               
    64 z[4,2,1]                    0             0               
    65 z[5,2,1]                    0             0               
    66 z[1,2,2]                    0             0               
    67 z[2,2,2]                    0             0               
    68 z[3,2,2]                   15             0               
    69 z[4,2,2]                    0             0               
    70 z[5,2,2]                    0             0               
    71 z[1,1,3]                   18             0               
    72 z[2,1,3]                    0             0               
    73 z[3,1,3]                    0             0               
    74 z[4,1,3]                    0             0               
    75 z[5,1,3]                    0             0               
    76 z[1,2,3]                    0             0               
    77 z[2,2,3]                    0             0               
    78 z[3,2,3]                    0             0               
    79 z[4,2,3]                    0             0               
    80 z[5,2,3]                   19             0               
    81 z[1,1,4]                    0             0               
    82 z[2,1,4]                    0             0               
    83 z[3,1,4]                    0             0               
    84 z[4,1,4]                   24             0               
    85 z[5,1,4]                    0             0               
    86 z[1,2,4]                    0             0               
    87 z[2,2,4]                    0             0               
    88 z[3,2,4]                    0             0               
    89 z[4,2,4]                   24             0               
    90 z[5,2,4]                    0             0               
    91 z[1,1,5]                    0             0               
    92 z[2,1,5]                   30             0               
    93 z[3,1,5]                    0             0               
    94 z[4,1,5]                    0             0               
    95 z[5,1,5]                    0             0               
    96 z[1,2,5]                    0             0               
    97 z[2,2,5]                   30             0               
    98 z[3,2,5]                    0             0               
    99 z[4,2,5]                    0             0               
   100 z[5,2,5]                    0             0               
   101 Conclusao_Tarefa[1,1]
                                  18             0               
   102 Conclusao_Tarefa[1,2]
                                  11             0               
   103 Conclusao_Tarefa[2,1]
                                  30             0               
   104 Conclusao_Tarefa[2,2]
                                  30             0               
   105 Conclusao_Tarefa[3,1]
                                  14             0               
   106 Conclusao_Tarefa[3,2]
                                  15             0               
   107 Conclusao_Tarefa[4,1]
                                  24             0               
   108 Conclusao_Tarefa[4,2]
                                  24             0               
   109 Conclusao_Tarefa[5,1]
                                  10             0               
   110 Conclusao_Tarefa[5,2]
                                  19             0               
   111 Conclusao_Pedido[1]
                                  18             0               
   112 Conclusao_Pedido[2]
                                  30             0               
   113 Conclusao_Pedido[3]
                                  15             0               
   114 Conclusao_Pedido[4]
                                  24             0               
   115 Conclusao_Pedido[5]
                                  19             0               
   116 Antecipacao[1,1]
                                   0             0               
   117 Antecipacao[1,2]
                                   7             0               
   118 Antecipacao[2,1]
                                   0             0               
   119 Antecipacao[2,2]
                                   0             0               
   120 Antecipacao[3,1]
                                   2             0               
   121 Antecipacao[3,2]
                                   1             0               
   122 Antecipacao[4,1]
                                   0             0               
   123 Antecipacao[4,2]
                                   0             0               
   124 Antecipacao[5,1]
                                   9             0               
   125 Antecipacao[5,2]
                                   0             0               
   126 Atraso[1]                   0             0               
   127 Atraso[2]                  10             0               
   128 Atraso[3]                   0             0               
   129 Atraso[4]                   2             0               
   130 Atraso[5]                   0             0               

Integer feasibility conditions:

KKT.PE: max.abs.err = 7.11e-15 on row 1
        max.rel.err = 8.17e-17 on row 1
        High quality

KKT.PB: max.abs.err = 4.09e-14 on row 125
        max.rel.err = 4.09e-14 on row 125
        High quality

End of output


"""