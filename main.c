#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int main () {
	FILE *arq;
	int i=0,j=0,id=0;
	int usuario=0;
    u dados; //nome da struct usuario utilizada
    TipoLista lista;
    char asteriscos[4];
    
    fLVazia(&lista);
    arq=fopen("arquivoentrada.txt","r");
    
    if (arq == NULL){
		printf ("Houve um erro ao abrir o arquivo.\n");
       return 1;
    } //verificação para saber se está com erro para abrir o arquivo
    
	fscanf(arq,"%d",&usuario); //leitura da primeira linha do arquivo que contém o número de usuários do arquivo
	for(i=0;i<usuario;i++) {
		 dados.id = id;
		 fscanf(arq,"%s", asteriscos);
		 fscanf(arq,"%s",dados.nome);
		 fscanf(arq,"%s",dados.estado);
		 fscanf(arq,"%s",dados.sexo);
		 fscanf(arq,"%s",dados.sexo_int);
		 fscanf(arq,"%d",&dados.numeroareas);
		 id++;
		 for(j=0;j<dados.numeroareas;j++) { //de acordo com o número de áreas de cada pessoa, haverá a leitura de seus interesses
			 fscanf(arq,"%d",&dados.like[j].interesses);
		 }
		insere(dados,&lista); //inserção dos dados lidos no arquivo na lista
	}
	 
	
	percorre(&lista);

	 int loop = 1;
	 int opcao = 0;
	 int k = 0;
	 
	 
	 //Menu de opções para o usuário
	 
	 while(loop){
		 printf("\tAgência de relacionamentos PAR PERFEITO\n");
		 printf("\tMenu de opções para o acesso do site.\n");
		 printf("\n");
		 printf("Digite 1 para imprimir o numero e a lista dos nomes de potenciais companheiros.\n");
		 printf("Digite 2 para imprimir os nomes dos k usuarios com maior numero de potenciais companheiros.\n");
		 printf("Digite 3 para imprimir os nomes dos usuarios que nao possuem potenciais companheiros.\n");
		 printf("Digite 4 para imprimir o numero e os nomes de usuarios com interesse em uma determinada area\n");
		 printf("Digite 5 para imprimir o numero e os nomes de usuarios que residem em um determinado estado\n");
		 printf("Digite 6 para sair\n");
		 
		 scanf("%d",&opcao);
		 
		 switch (opcao) {
		
		 case 1:
			printf("Digite o id\n");
			scanf("%d", &k);
			achar_pessoa(&lista, k);
			printf("\n");
		 	break;
		 case 2:
			printf("Digite os k usuarios que deseja ver\n");
			scanf("%d", &k);
			insertionSort(&lista,k);
			printf("\n"); 
			break;
		 case 3:
			printf("Lista dos usuarios sem nenhum potencial companheiro:\n");
			sem_companheiro(&lista);
			printf("\n");
			break;
		 case 4:
			printf("Escolha a área(1 a 8):\n");
			int cod;
			scanf("%d",&cod);
			Tem_interesse (&lista,cod);
			printf("\n");
			break;
		 case 5:
			printf("Digite o estado que deseja verificar\n");
			char estado[2];
			scanf("%s",estado);
			Reside(&lista,estado);
			printf("\n");
			break;
		 case 6:
			loop=0;
			break;
	}
 }

	 fclose(arq);
	 return 0;
 }

