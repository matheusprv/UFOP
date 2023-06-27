#include "relogio.h"

int main(){
    Relogio relogio = Relogio(12, 8, 50);
    
    relogio.printHora();
    
    alteraHMS(relogio);

    return 0;

}