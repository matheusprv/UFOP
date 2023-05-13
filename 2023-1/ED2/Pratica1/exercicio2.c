#include "struct.h"

int main(){

    //Abrindo os arquivos necessários
    FILE * arquivo = abrirArquivo("alunos.txt", "r");
    FILE * arquivoBinario = abrirArquivo("alunos.bin", "wb");
    if(arquivoBinario == NULL || arquivo == NULL)
        return 0;

    Aluno aluno;

    while(fscanf(arquivo, "%d %[A-z a-z] %f %f %f %d", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.faltas) != EOF){
        
        trim_string(aluno.nome);
        
        fwrite(&aluno, sizeof(Aluno), 1, arquivoBinario);

    }
    
    fclose(arquivo);
    fclose(arquivoBinario);

    return 0;
}