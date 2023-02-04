#include "pilha.h"

bool PilhaInicia(Pilha* pPilha) {
    return ListaInicia(pPilha);
}

bool PilhaPush(Pilha* pPilha, Item item) {
    return ListaInsereInicio(pPilha, item);
}

bool PilhaPop(Pilha* pPilha, Item* pItem) {
    return ListaRetiraPrimeiro(pPilha, pItem);
 }

bool PilhaEhVazia(Pilha* pPilha) {
    return ListaEhVazia(pPilha);
}

void PilhaLibera(Pilha* pPilha) {
    ListaLibera(pPilha);
}