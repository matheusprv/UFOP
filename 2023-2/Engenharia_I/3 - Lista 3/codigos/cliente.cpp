// Sistema: Gerenciamento de Concessionaria de Automoveis - AutoMananger
// Modulo: Administracao de Clientes
// Autor: Tiago Garcia de Senna Carneiro
// Ultima alteracao:15/12/2006
// Responsavel: Tiago G. S. Carneiro
//
// Descri��o:  Mant�m cadastro de clientes da concessionaria. Os clientes sao
// identificados pelo nome.
//             
// Servi�os (API): 
//           - Cria novo cliente
//           - Remove cliente
//           - Edita cliente
// Requisitos:
//           -
#include "cliente.h"

#include <cstring>
#include <iostream>

using namespace std;
Cliente::Cliente(char *n) { nome = n; }
Cliente::~Cliente(){delete[] nome;}
void Cliente::setNome( char* n  ){ nome = n; } 
char* Cliente::getNome( void ) { return nome; }

Cliente & Cliente :: operator = (const Cliente & c){
    if(this == &c) return *this;

    strcpy(this->nome, c.nome);

    return *this;
}

