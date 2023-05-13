#include "struct.h"

int main(int argc, char const *argv[]){
    
    //Abrindo os arquivos necessários
    FILE * arquivo = abrirArquivo("alunos.txt", "r");
    FILE * arquivoConceitos = abrirArquivo("conceitos.txt", "w");
    if(arquivoConceitos == NULL || arquivo == NULL)
        return 0;

    Aluno aluno;

    while(fscanf(arquivo, "%d %[A-z a-z] %f %f %f %d", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.faltas) != EOF){
        
        trim_string(aluno.nome);
        
        aluno.notaMedia = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;

        if(aluno.faltas >= 18){
            aluno.conceito = 'F';
        }
        else{
            if(aluno.notaMedia < 6.0)
                aluno.conceito = 'R';
            
            else if(aluno.notaMedia < 7.5)
                aluno.conceito = 'C';

            else if(aluno.notaMedia < 9.0)
                aluno.conceito = 'B';

            else
                aluno.conceito = 'A';
        }


        fprintf(arquivoConceitos, "%4d %29s %c\n", aluno.matricula, aluno.nome, aluno.conceito );
    }
    
    fclose(arquivo);
    fclose(arquivoConceitos);

    return 0;
}
