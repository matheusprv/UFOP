#include "struct.h"

int main(){

    FILE * arquivo = abrirArquivo("alunos.bin", "rb");
    FILE * arquivoConceito = abrirArquivo("conceitos.bin", "wb");
    
    if(arquivo == NULL || arquivoConceito == NULL)
        return 0;

    Aluno * alunos = malloc(NUM_ALUNOS * sizeof(Aluno));

    fread(alunos, sizeof(Aluno), NUM_ALUNOS, arquivo);

    for(int i = 0; i < NUM_ALUNOS; i++){
        alunos[i].notaMedia = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if(alunos[i].faltas >= 18){
            alunos[i].conceito = 'F';
        }
        else{
            if(alunos[i].notaMedia < 6.0)
                alunos[i].conceito = 'R';
            
            else if(alunos[i].notaMedia < 7.5)
                alunos[i].conceito = 'C';

            else if(alunos[i].notaMedia < 9.0)
                alunos[i].conceito = 'B';

            else
                alunos[i].conceito = 'A';
        }

        fwrite(&alunos[i].matricula, sizeof(int), 1, arquivoConceito);
        fwrite(alunos[i].nome, sizeof(char), 1, arquivoConceito);
        fwrite(&alunos[i].conceito, sizeof(char), 1, arquivoConceito);
    }
   

    fclose(arquivo);
    fclose(arquivoConceito);

    free(alunos);

    return 0;
}