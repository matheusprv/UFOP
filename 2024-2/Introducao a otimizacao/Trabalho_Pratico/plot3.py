import matplotlib.pyplot as plt
import matplotlib.cm as cm
from gerar_grafico import *

# Pij
p = [
    [4, 5, 4],
    [5, 6, 5],
    [4, 4, 5],
    [6, 5, 4],
    [5, 4, 6],
]

# Di
d = [20, 22, 19, 23, 21]


# Cij 
Cij = [
    [20, 11, 20],
    [25, 25, 25],
    [16, 19, 16],
    [31, 31, 31],
    [12, 15, 11],
]

gerar_graficos(p, d, Cij)



"""
param n := 5;
param m := 3;

param p : 1   2   3 :=
         1   4   5   4
         2   5   6   5
         3   4   4   5
         4   6   5   4
         5   5   4   6;


param d :=
  1   20
  2   22
  3   19
  4   23
  5   21;


Problem:    tp
Rows:       186
Columns:    190 (75 integer, 75 binary)
Non-zeros:  810
Status:     INTEGER OPTIMAL
Objective:  Total_Cost = 73 (MINimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 Total_Cost                 73                             
     2 Um_pedido_por_maquina[1,1]
                                   1             1             = 
     3 Um_pedido_por_maquina[1,2]
                                   1             1             = 
     4 Um_pedido_por_maquina[1,3]
                                   1             1             = 
     5 Um_pedido_por_maquina[2,1]
                                   1             1             = 
     6 Um_pedido_por_maquina[2,2]
                                   1             1             = 
     7 Um_pedido_por_maquina[2,3]
                                   1             1             = 
     8 Um_pedido_por_maquina[3,1]
                                   1             1             = 
     9 Um_pedido_por_maquina[3,2]
                                   1             1             = 
    10 Um_pedido_por_maquina[3,3]
                                   1             1             = 
    11 Um_pedido_por_maquina[4,1]
                                   1             1             = 
    12 Um_pedido_por_maquina[4,2]
                                   1             1             = 
    13 Um_pedido_por_maquina[4,3]
                                   1             1             = 
    14 Um_pedido_por_maquina[5,1]
                                   1             1             = 
    15 Um_pedido_por_maquina[5,2]
                                   1             1             = 
    16 Um_pedido_por_maquina[5,3]
                                   1             1             = 
    17 Uma_tarefa_por_posicao[1,1]
                                   1             1             = 
    18 Uma_tarefa_por_posicao[1,2]
                                   1             1             = 
    19 Uma_tarefa_por_posicao[1,3]
                                   1             1             = 
    20 Uma_tarefa_por_posicao[2,1]
                                   1             1             = 
    21 Uma_tarefa_por_posicao[2,2]
                                   1             1             = 
    22 Uma_tarefa_por_posicao[2,3]
                                   1             1             = 
    23 Uma_tarefa_por_posicao[3,1]
                                   1             1             = 
    24 Uma_tarefa_por_posicao[3,2]
                                   1             1             = 
    25 Uma_tarefa_por_posicao[3,3]
                                   1             1             = 
    26 Uma_tarefa_por_posicao[4,1]
                                   1             1             = 
    27 Uma_tarefa_por_posicao[4,2]
                                   1             1             = 
    28 Uma_tarefa_por_posicao[4,3]
                                   1             1             = 
    29 Uma_tarefa_por_posicao[5,1]
                                   1             1             = 
    30 Uma_tarefa_por_posicao[5,2]
                                   1             1             = 
    31 Uma_tarefa_por_posicao[5,3]
                                   1             1             = 
    32 Restricao_de_sequencia[2,1]
                                   0                          -0 
    33 Restricao_de_sequencia[2,2]
                                   0                          -0 
    34 Restricao_de_sequencia[2,3]
                                   0                          -0 
    35 Restricao_de_sequencia[3,1]
                                   0                          -0 
    36 Restricao_de_sequencia[3,2]
                                   0                          -0 
    37 Restricao_de_sequencia[3,3]
                                   0                          -0 
    38 Restricao_de_sequencia[4,1]
                                   0                          -0 
    39 Restricao_de_sequencia[4,2]
                                   0                          -0 
    40 Restricao_de_sequencia[4,3]
                                   0                          -0 
    41 Restricao_de_sequencia[5,1]
                                   0                          -0 
    42 Restricao_de_sequencia[5,2]
                                  -1                          -0 
    43 Restricao_de_sequencia[5,3]
                                  -2                          -0 
    44 Inicio_primeira_tarefa[1]
                                  -7                          -0 
    45 Inicio_primeira_tarefa[2]
                                  -6                          -0 
    46 Inicio_primeira_tarefa[3]
                                  -5                          -0 
    47 tempo_finalizacao_z[1,1,1]
                                  20                        1000 
    48 tempo_finalizacao_z[1,1,2]
                                  20                        1000 
    49 tempo_finalizacao_z[1,1,3]
                                1000                        1000 
    50 tempo_finalizacao_z[1,1,4]
                                  20                        1000 
    51 tempo_finalizacao_z[1,1,5]
                                  20                        1000 
    52 tempo_finalizacao_z[1,2,1]
                                1000                        1000 
    53 tempo_finalizacao_z[1,2,2]
                                  11                        1000 
    54 tempo_finalizacao_z[1,2,3]
                                  11                        1000 
    55 tempo_finalizacao_z[1,2,4]
                                  11                        1000 
    56 tempo_finalizacao_z[1,2,5]
                                  11                        1000 
    57 tempo_finalizacao_z[1,3,1]
                                  20                        1000 
    58 tempo_finalizacao_z[1,3,2]
                                  20                        1000 
    59 tempo_finalizacao_z[1,3,3]
                                1000                        1000 
    60 tempo_finalizacao_z[1,3,4]
                                  20                        1000 
    61 tempo_finalizacao_z[1,3,5]
                                  20                        1000 
    62 tempo_finalizacao_z[2,1,1]
                                  25                        1000 
    63 tempo_finalizacao_z[2,1,2]
                                  25                        1000 
    64 tempo_finalizacao_z[2,1,3]
                                  25                        1000 
    65 tempo_finalizacao_z[2,1,4]
                                1000                        1000 
    66 tempo_finalizacao_z[2,1,5]
                                  25                        1000 
    67 tempo_finalizacao_z[2,2,1]
                                  25                        1000 
    68 tempo_finalizacao_z[2,2,2]
                                  25                        1000 
    69 tempo_finalizacao_z[2,2,3]
                                  25                        1000 
    70 tempo_finalizacao_z[2,2,4]
                                1000                        1000 
    71 tempo_finalizacao_z[2,2,5]
                                  25                        1000 
    72 tempo_finalizacao_z[2,3,1]
                                  25                        1000 
    73 tempo_finalizacao_z[2,3,2]
                                  25                        1000 
    74 tempo_finalizacao_z[2,3,3]
                                  25                        1000 
    75 tempo_finalizacao_z[2,3,4]
                                1000                        1000 
    76 tempo_finalizacao_z[2,3,5]
                                  25                        1000 
    77 tempo_finalizacao_z[3,1,1]
                                  16                        1000 
    78 tempo_finalizacao_z[3,1,2]
                                1000                        1000 
    79 tempo_finalizacao_z[3,1,3]
                                  16                        1000 
    80 tempo_finalizacao_z[3,1,4]
                                  16                        1000 
    81 tempo_finalizacao_z[3,1,5]
                                  16                        1000 
    82 tempo_finalizacao_z[3,2,1]
                                  19                        1000 
    83 tempo_finalizacao_z[3,2,2]
                                  19                        1000 
    84 tempo_finalizacao_z[3,2,3]
                                1000                        1000 
    85 tempo_finalizacao_z[3,2,4]
                                  19                        1000 
    86 tempo_finalizacao_z[3,2,5]
                                  19                        1000 
    87 tempo_finalizacao_z[3,3,1]
                                  16                        1000 
    88 tempo_finalizacao_z[3,3,2]
                                1000                        1000 
    89 tempo_finalizacao_z[3,3,3]
                                  16                        1000 
    90 tempo_finalizacao_z[3,3,4]
                                  16                        1000 
    91 tempo_finalizacao_z[3,3,5]
                                  16                        1000 
    92 tempo_finalizacao_z[4,1,1]
                                  31                        1000 
    93 tempo_finalizacao_z[4,1,2]
                                  31                        1000 
    94 tempo_finalizacao_z[4,1,3]
                                  31                        1000 
    95 tempo_finalizacao_z[4,1,4]
                                  31                        1000 
    96 tempo_finalizacao_z[4,1,5]
                                1000                        1000 
    97 tempo_finalizacao_z[4,2,1]
                                  31                        1000 
    98 tempo_finalizacao_z[4,2,2]
                                  31                        1000 
    99 tempo_finalizacao_z[4,2,3]
                                  31                        1000 
   100 tempo_finalizacao_z[4,2,4]
                                  31                        1000 
   101 tempo_finalizacao_z[4,2,5]
                                1000                        1000 
   102 tempo_finalizacao_z[4,3,1]
                                  31                        1000 
   103 tempo_finalizacao_z[4,3,2]
                                  31                        1000 
   104 tempo_finalizacao_z[4,3,3]
                                  31                        1000 
   105 tempo_finalizacao_z[4,3,4]
                                  31                        1000 
   106 tempo_finalizacao_z[4,3,5]
                                1000                        1000 
   107 tempo_finalizacao_z[5,1,1]
                                1000                        1000 
   108 tempo_finalizacao_z[5,1,2]
                                  12                        1000 
   109 tempo_finalizacao_z[5,1,3]
                                  12                        1000 
   110 tempo_finalizacao_z[5,1,4]
                                  12                        1000 
   111 tempo_finalizacao_z[5,1,5]
                                  12                        1000 
   112 tempo_finalizacao_z[5,2,1]
                                  15                        1000 
   113 tempo_finalizacao_z[5,2,2]
                                1000                        1000 
   114 tempo_finalizacao_z[5,2,3]
                                  15                        1000 
   115 tempo_finalizacao_z[5,2,4]
                                  15                        1000 
   116 tempo_finalizacao_z[5,2,5]
                                  15                        1000 
   117 tempo_finalizacao_z[5,3,1]
                                1000                        1000 
   118 tempo_finalizacao_z[5,3,2]
                                  11                        1000 
   119 tempo_finalizacao_z[5,3,3]
                                  11                        1000 
   120 tempo_finalizacao_z[5,3,4]
                                  11                        1000 
   121 tempo_finalizacao_z[5,3,5]
                                  11                        1000 
   122 z_completude_unica[1,1]
                                   0                          -0 
   123 z_completude_unica[1,2]
                                   0                          -0 
   124 z_completude_unica[1,3]
                                   0                          -0 
   125 z_completude_unica[2,1]
                                   0                          -0 
   126 z_completude_unica[2,2]
                                   0                          -0 
   127 z_completude_unica[2,3]
                                   0                          -0 
   128 z_completude_unica[3,1]
                                   0                          -0 
   129 z_completude_unica[3,2]
                                   0                          -0 
   130 z_completude_unica[3,3]
                                   0                          -0 
   131 z_completude_unica[4,1]
                                   0                          -0 
   132 z_completude_unica[4,2]
                                   0                          -0 
   133 z_completude_unica[4,3]
                                   0                          -0 
   134 z_completude_unica[5,1]
                                   0                          -0 
   135 z_completude_unica[5,2]
                                   0                          -0 
   136 z_completude_unica[5,3]
                                   0                          -0 
   137 Restricao_tempo_conclusao_tarefa[1,1]
                                   0                          -0 
   138 Restricao_tempo_conclusao_tarefa[1,2]
                                  -9                          -0 
   139 Restricao_tempo_conclusao_tarefa[1,3]
                                   0                          -0 
   140 Restricao_tempo_conclusao_tarefa[2,1]
                                   0                          -0 
   141 Restricao_tempo_conclusao_tarefa[2,2]
                                   0                          -0 
   142 Restricao_tempo_conclusao_tarefa[2,3]
                                   0                          -0 
   143 Restricao_tempo_conclusao_tarefa[3,1]
                                  -3                          -0 
   144 Restricao_tempo_conclusao_tarefa[3,2]
                                   0                          -0 
   145 Restricao_tempo_conclusao_tarefa[3,3]
                                  -3                          -0 
   146 Restricao_tempo_conclusao_tarefa[4,1]
                                   0                          -0 
   147 Restricao_tempo_conclusao_tarefa[4,2]
                                   0                          -0 
   148 Restricao_tempo_conclusao_tarefa[4,3]
                                   0                          -0 
   149 Restricao_tempo_conclusao_tarefa[5,1]
                                  -3                          -0 
   150 Restricao_tempo_conclusao_tarefa[5,2]
                                   0                          -0 
   151 Restricao_tempo_conclusao_tarefa[5,3]
                                  -4                          -0 
   152 Restricao_de_atraso[1]
                                  20                          20 
   153 Restricao_de_atraso[2]
                                  22                          22 
   154 Restricao_de_atraso[3]
                                  19                          19 
   155 Restricao_de_atraso[4]
                                  23                          23 
   156 Restricao_de_atraso[5]
                                  15                          21 
   157 Restricao_de_antecipacao[1,1]
                                 -20                         -20 
   158 Restricao_de_antecipacao[1,2]
                                 -20                         -20 
   159 Restricao_de_antecipacao[1,3]
                                 -20                         -20 
   160 Restricao_de_antecipacao[2,1]
                                 -25                         -22 
   161 Restricao_de_antecipacao[2,2]
                                 -25                         -22 
   162 Restricao_de_antecipacao[2,3]
                                 -25                         -22 
   163 Restricao_de_antecipacao[3,1]
                                 -19                         -19 
   164 Restricao_de_antecipacao[3,2]
                                 -19                         -19 
   165 Restricao_de_antecipacao[3,3]
                                 -19                         -19 
   166 Restricao_de_antecipacao[4,1]
                                 -31                         -23 
   167 Restricao_de_antecipacao[4,2]
                                 -31                         -23 
   168 Restricao_de_antecipacao[4,3]
                                 -31                         -23 
   169 Restricao_de_antecipacao[5,1]
                                 -21                         -21 
   170 Restricao_de_antecipacao[5,2]
                                 -21                         -21 
   171 Restricao_de_antecipacao[5,3]
                                 -21                         -21 
   172 Restricao_de_antecipacao2[1,1]
                                   0                          -0 
   173 Restricao_de_antecipacao2[1,2]
                                   0                          -0 
   174 Restricao_de_antecipacao2[1,3]
                                   0                          -0 
   175 Restricao_de_antecipacao2[2,1]
                                   0                          -0 
   176 Restricao_de_antecipacao2[2,2]
                                   0                          -0 
   177 Restricao_de_antecipacao2[2,3]
                                   0                          -0 
   178 Restricao_de_antecipacao2[3,1]
                                   0                          -0 
   179 Restricao_de_antecipacao2[3,2]
                                   0                          -0 
   180 Restricao_de_antecipacao2[3,3]
                                   0                          -0 
   181 Restricao_de_antecipacao2[4,1]
                                   0                          -0 
   182 Restricao_de_antecipacao2[4,2]
                                   0                          -0 
   183 Restricao_de_antecipacao2[4,3]
                                   0                          -0 
   184 Restricao_de_antecipacao2[5,1]
                                  -6                          -0 
   185 Restricao_de_antecipacao2[5,2]
                                  -6                          -0 
   186 Restricao_de_antecipacao2[5,3]
                                  -6                          -0 

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
    11 x[1,3,1]     *              0             0             1 
    12 x[1,3,2]     *              0             0             1 
    13 x[1,3,3]     *              1             0             1 
    14 x[1,3,4]     *              0             0             1 
    15 x[1,3,5]     *              0             0             1 
    16 x[2,1,1]     *              0             0             1 
    17 x[2,1,2]     *              0             0             1 
    18 x[2,1,3]     *              0             0             1 
    19 x[2,1,4]     *              1             0             1 
    20 x[2,1,5]     *              0             0             1 
    21 x[2,2,1]     *              0             0             1 
    22 x[2,2,2]     *              0             0             1 
    23 x[2,2,3]     *              0             0             1 
    24 x[2,2,4]     *              1             0             1 
    25 x[2,2,5]     *              0             0             1 
    26 x[2,3,1]     *              0             0             1 
    27 x[2,3,2]     *              0             0             1 
    28 x[2,3,3]     *              0             0             1 
    29 x[2,3,4]     *              1             0             1 
    30 x[2,3,5]     *              0             0             1 
    31 x[3,1,1]     *              0             0             1 
    32 x[3,1,2]     *              1             0             1 
    33 x[3,1,3]     *              0             0             1 
    34 x[3,1,4]     *              0             0             1 
    35 x[3,1,5]     *              0             0             1 
    36 x[3,2,1]     *              0             0             1 
    37 x[3,2,2]     *              0             0             1 
    38 x[3,2,3]     *              1             0             1 
    39 x[3,2,4]     *              0             0             1 
    40 x[3,2,5]     *              0             0             1 
    41 x[3,3,1]     *              0             0             1 
    42 x[3,3,2]     *              1             0             1 
    43 x[3,3,3]     *              0             0             1 
    44 x[3,3,4]     *              0             0             1 
    45 x[3,3,5]     *              0             0             1 
    46 x[4,1,1]     *              0             0             1 
    47 x[4,1,2]     *              0             0             1 
    48 x[4,1,3]     *              0             0             1 
    49 x[4,1,4]     *              0             0             1 
    50 x[4,1,5]     *              1             0             1 
    51 x[4,2,1]     *              0             0             1 
    52 x[4,2,2]     *              0             0             1 
    53 x[4,2,3]     *              0             0             1 
    54 x[4,2,4]     *              0             0             1 
    55 x[4,2,5]     *              1             0             1 
    56 x[4,3,1]     *              0             0             1 
    57 x[4,3,2]     *              0             0             1 
    58 x[4,3,3]     *              0             0             1 
    59 x[4,3,4]     *              0             0             1 
    60 x[4,3,5]     *              1             0             1 
    61 x[5,1,1]     *              1             0             1 
    62 x[5,1,2]     *              0             0             1 
    63 x[5,1,3]     *              0             0             1 
    64 x[5,1,4]     *              0             0             1 
    65 x[5,1,5]     *              0             0             1 
    66 x[5,2,1]     *              0             0             1 
    67 x[5,2,2]     *              1             0             1 
    68 x[5,2,3]     *              0             0             1 
    69 x[5,2,4]     *              0             0             1 
    70 x[5,2,5]     *              0             0             1 
    71 x[5,3,1]     *              1             0             1 
    72 x[5,3,2]     *              0             0             1 
    73 x[5,3,3]     *              0             0             1 
    74 x[5,3,4]     *              0             0             1 
    75 x[5,3,5]     *              0             0             1 
    76 z[1,1,1]                    0             0               
    77 z[2,1,1]                    0             0               
    78 z[3,1,1]                    0             0               
    79 z[4,1,1]                    0             0               
    80 z[5,1,1]                   12             0               
    81 z[1,1,2]                    0             0               
    82 z[2,1,2]                    0             0               
    83 z[3,1,2]                   16             0               
    84 z[4,1,2]                    0             0               
    85 z[5,1,2]                    0             0               
    86 z[1,2,1]                   11             0               
    87 z[2,2,1]                    0             0               
    88 z[3,2,1]                    0             0               
    89 z[4,2,1]                    0             0               
    90 z[5,2,1]                    0             0               
    91 z[1,2,2]                    0             0               
    92 z[2,2,2]                    0             0               
    93 z[3,2,2]                    0             0               
    94 z[4,2,2]                    0             0               
    95 z[5,2,2]                   15             0               
    96 z[1,3,1]                    0             0               
    97 z[2,3,1]                    0             0               
    98 z[3,3,1]                    0             0               
    99 z[4,3,1]                    0             0               
   100 z[5,3,1]                   11             0               
   101 z[1,3,2]                    0             0               
   102 z[2,3,2]                    0             0               
   103 z[3,3,2]                   16             0               
   104 z[4,3,2]                    0             0               
   105 z[5,3,2]                    0             0               
   106 z[1,1,3]                   20             0               
   107 z[2,1,3]                    0             0               
   108 z[3,1,3]                    0             0               
   109 z[4,1,3]                    0             0               
   110 z[5,1,3]                    0             0               
   111 z[1,2,3]                    0             0               
   112 z[2,2,3]                    0             0               
   113 z[3,2,3]                   19             0               
   114 z[4,2,3]                    0             0               
   115 z[5,2,3]                    0             0               
   116 z[1,3,3]                   20             0               
   117 z[2,3,3]                    0             0               
   118 z[3,3,3]                    0             0               
   119 z[4,3,3]                    0             0               
   120 z[5,3,3]                    0             0               
   121 z[1,1,4]                    0             0               
   122 z[2,1,4]                   25             0               
   123 z[3,1,4]                    0             0               
   124 z[4,1,4]                    0             0               
   125 z[5,1,4]                    0             0               
   126 z[1,2,4]                    0             0               
   127 z[2,2,4]                   25             0               
   128 z[3,2,4]                    0             0               
   129 z[4,2,4]                    0             0               
   130 z[5,2,4]                    0             0               
   131 z[1,3,4]                    0             0               
   132 z[2,3,4]                   25             0               
   133 z[3,3,4]                    0             0               
   134 z[4,3,4]                    0             0               
   135 z[5,3,4]                    0             0               
   136 z[1,1,5]                    0             0               
   137 z[2,1,5]                    0             0               
   138 z[3,1,5]                    0             0               
   139 z[4,1,5]                   31             0               
   140 z[5,1,5]                    0             0               
   141 z[1,2,5]                    0             0               
   142 z[2,2,5]                    0             0               
   143 z[3,2,5]                    0             0               
   144 z[4,2,5]                   31             0               
   145 z[5,2,5]                    0             0               
   146 z[1,3,5]                    0             0               
   147 z[2,3,5]                    0             0               
   148 z[3,3,5]                    0             0               
   149 z[4,3,5]                   31             0               
   150 z[5,3,5]                    0             0               
   151 Conclusao_Tarefa[1,1]
                                  20             0               
   152 Conclusao_Tarefa[1,2]
                                  11             0               
   153 Conclusao_Tarefa[1,3]
                                  20             0               
   154 Conclusao_Tarefa[2,1]
                                  25             0               
   155 Conclusao_Tarefa[2,2]
                                  25             0               
   156 Conclusao_Tarefa[2,3]
                                  25             0               
   157 Conclusao_Tarefa[3,1]
                                  16             0               
   158 Conclusao_Tarefa[3,2]
                                  19             0               
   159 Conclusao_Tarefa[3,3]
                                  16             0               
   160 Conclusao_Tarefa[4,1]
                                  31             0               
   161 Conclusao_Tarefa[4,2]
                                  31             0               
   162 Conclusao_Tarefa[4,3]
                                  31             0               
   163 Conclusao_Tarefa[5,1]
                                  12             0               
   164 Conclusao_Tarefa[5,2]
                                  15             0               
   165 Conclusao_Tarefa[5,3]
                                  11             0               
   166 Conclusao_Pedido[1]
                                  20             0               
   167 Conclusao_Pedido[2]
                                  25             0               
   168 Conclusao_Pedido[3]
                                  19             0               
   169 Conclusao_Pedido[4]
                                  31             0               
   170 Conclusao_Pedido[5]
                                  15             0               
   171 Antecipacao[1,1]
                                   0             0               
   172 Antecipacao[1,2]
                                   9             0               
   173 Antecipacao[1,3]
                                   0             0               
   174 Antecipacao[2,1]
                                   0             0               
   175 Antecipacao[2,2]
                                   0             0               
   176 Antecipacao[2,3]
                                   0             0               
   177 Antecipacao[3,1]
                                   3             0               
   178 Antecipacao[3,2]
                                   0             0               
   179 Antecipacao[3,3]
                                   3             0               
   180 Antecipacao[4,1]
                                   0             0               
   181 Antecipacao[4,2]
                                   0             0               
   182 Antecipacao[4,3]
                                   0             0               
   183 Antecipacao[5,1]
                                   9             0               
   184 Antecipacao[5,2]
                                   6             0               
   185 Antecipacao[5,3]
                                  10             0               
   186 Atraso[1]                   0             0               
   187 Atraso[2]                   3             0               
   188 Atraso[3]                   0             0               
   189 Atraso[4]                   8             0               
   190 Atraso[5]                   0             0               

Integer feasibility conditions:

KKT.PE: max.abs.err = 3.55e-15 on row 43
        max.rel.err = 5.64e-17 on row 43
        High quality

KKT.PB: max.abs.err = 2.13e-14 on row 169
        max.rel.err = 1.78e-14 on column 140
        High quality

End of output

"""


"""
Time used:   98.3 secs
"""