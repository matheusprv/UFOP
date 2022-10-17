#include <stdio.h>

int calculaMinutos(int horaInicio, int minutoIncio, int horaTermino, int minutotermino); 

int main(){
	int horaInicio, minutoIncio, horaTermino, minutotermino;
	
	printf("Entre com o horário de início:");
	scanf("%d%d", &horaInicio, &minutoIncio);
	
	printf("Entre com o horário de término: ");
	scanf("%d%d", &horaTermino, &minutotermino);
	
	printf("Duração: %d minutos", calculaMinutos(horaInicio, minutoIncio, horaTermino, minutotermino));
	
	return 0;
}

int calculaMinutos(int horaInicio, int minutoIncio, int horaTermino, int minutotermino){
	
	int minutosDuracao;
	
	if(horaTermino >= horaInicio){
		minutosDuracao = (horaTermino - horaInicio) * 60 + minutotermino - minutoIncio;
	}
	else{
		minutosDuracao = (24 + horaTermino - horaInicio) * 60 + minutotermino - minutoIncio;
	}
	
	return minutosDuracao;
}
