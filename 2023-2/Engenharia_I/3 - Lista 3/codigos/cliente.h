// Sistema: Gerenciamento de Concessionaria de Automoveis - AutoMananger
// Interface: Administracao de Clientes
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
//
          
#if ! defined( CLIENTE_H ) 
#define CLIENTE_H

class Cliente {
      char *nome;
public:
	
      Cliente( char* );
      ~Cliente();
      void setNome( char*  );
      char* getNome( void );
      Cliente& operator=(const Cliente &);
};
#endif
