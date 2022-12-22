//Matheus Peixoto Ribeiro Vieira - 22.1.4104
#include <stdio.h>
#include "duende.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 4;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times);

    return 0; //nao remova

    /*
        Complexidade das funções:
            escalarTimes = 4 * n/4 *2n = 2n²

            proximoMaisVelho = 2n, pois em um if dentro do for há duas verificações
    */
}
