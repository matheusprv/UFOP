#include "relogio.h"
Relogio :: Relogio(int h, int m, int s) : h(h), m(m), s(s){};
Relogio :: ~Relogio(){
    cout << "Última hora marcada antes de destruir: " ;
    this->printHora();
}
void Relogio :: setHora(int h, int m, int s){
    this->h = h;
    this->m = m;
    this->s = s;
}

void Relogio :: printHora(){
    cout << this->h << ":" << this->m << ":" << this->s << "\n";;
}

void alteraHMS(Relogio &r){
    r.h = r.h + 1;
    r.m = r.m + 1;
    r.s = r.s + 1;
}

Relogio duplicaRelogio(Relogio &r){
    Relogio temp = Relogio();
    temp.h = r.h;
    temp.m = r.m;
    temp.s = r.s;

    return temp;
}
