#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void fLVazia(TipoLista *lista) {
	lista->primeiro = inicioArranjo;
	lista->ultimo = lista->primeiro;
}

int vazia(TipoLista *lista) {
	return (lista->primeiro == lista->ultimo);
}

void insere(u x, TipoLista *lista) { 		
	
	if (lista->ultimo > maxTam){ 			//verificação se a lista estourou seu tamanho máximo 
		printf("Lista esta cheia\n");
	}
	else{
		lista->item->i++;
		lista->item[lista->ultimo - 1] = x;
		lista->ultimo++;
	}
}

void imprime(TipoLista *lista) { 				
	int aux;

	for (aux = lista->primeiro - 1; aux <= (lista->ultimo-2); aux++) {
		 printf("pessoa -> %s\n", lista->item[aux].nome);
		 Imprime_Numero_Companheiros(lista->item[aux]);
		 Imprime_Lista_Companheiros(lista->item[aux]);
	}
}


void achar_pessoa(TipoLista *lista, int a) { 	
	int i;
	
	for (i = lista->primeiro - 1; i <= (lista->ultimo-2); i++) {
		if (lista->item[i].id == a){ 
			printf("\n%s\n", lista->item[i].nome);
			Imprime_Lista_Companheiros(lista->item[i]);
			if(lista->item[i].numerocompanheiros==0) { //caso a pessoa procurada não tenha nenhum possível companheiro, é exibido
				printf("%s não tem nenhum companheiro\n",lista->item[i].nome);
			}
		}
	}
}



int Verifica_Potencial_Companheiro(u a, u b){ 
	int k,n,t,cont2=0,cont3=0,cont4=0,somaint=0;
	float match,aux;
    k = strcmp(a.estado,b.estado);
    n = strcmp(a.sexo_int,b.sexo);
    t = strcmp(a.sexo,b.sexo_int);
    if((n == 0) && (k == 0) && (t == 0)) {
              for(k=0;k<a.numeroareas;k++){
				for(n=0;n<b.numeroareas;n++){
					if(((a.like[k].interesses == 1) && (b.like[n].interesses == 1)) || ((a.like[k].interesses == 3) && (b.like[n].interesses == 3)) || ((a.like[k].interesses == 4) && (b.like[n].interesses == 4)))  
					   cont2++;	
					if(((a.like[k].interesses == 2) && (b.like[n].interesses == 2)) || ((a.like[k].interesses == 6) && (b.like[n].interesses == 6)) || ((a.like[k].interesses == 7) && (b.like[n].interesses == 7)))  
                       cont3++;
                    if(((a.like[k].interesses == 5) && (b.like[n].interesses == 5)) || ((a.like[k].interesses == 8) && (b.like[n].interesses == 8)))  
                       cont4++;
                      }
                }
     }
        
    somaint=a.numeroareas+b.numeroareas; //total de interesses dos dois usuários juntos
    cont3=(cont3*2); //multiplicador do peso
    cont4=(cont4*3); //multiplicador do peso
    aux=(cont2+cont3+cont4);
    match=(aux/somaint);
    int teste;
    if(match > 0.45) { //condição se o grau de interesse for maior que 0,45
        teste=1;
	}
	
    else {
        teste=0;
	}
	return teste;
}

void Insere_Potencial_Companheiro (u a, u b, TipoLista *lista) { 
	int potencial,i;
	potencial=Verifica_Potencial_Companheiro(a,b); //ela recebe a função de verificação e se atender as condições 
	if(potencial==1) { //se os usuários forem potenciais companheiros um receberá o id do outro 
	

	   	for (i = lista->primeiro - 1; i <= (lista->ultimo-2); i++) {
			if (lista->item[i].id == a.id){
				lista->item[i].potencial_companheiro[lista->item[i].numerocompanheiros++].id = b.id;
			

			} 
		}	
	}	
}



void Reside (TipoLista *lista, char sigla[]) { 
	int aux,teste;

	for (aux = lista->primeiro - 1; aux <= (lista->ultimo-2); aux++) {
		
	teste=strcmp(lista->item[aux].estado,sigla);
		 if (teste==0) 
		printf("%d - %s\n",lista->item[aux].id,lista->item[aux].nome);
	} 
	}

	
void Tem_interesse (TipoLista *lista, int cod) { 
	int aux,j;
for (aux = lista->primeiro - 1; aux <= (lista->ultimo-2); aux++) {
	for(j= 0;j<lista->item[aux].numeroareas; j++) {
		if (lista->item[aux].like[j].interesses == cod) {
			printf("%d - %s\n",lista->item[aux].id,lista->item[aux].nome);
		}
}
}
}
void Imprime_Lista_Companheiros(u d) { 
	int i;
	for(i=0;i<d.numerocompanheiros;i++) {
		printf("ID do potencial companheiro: %d \n",d.potencial_companheiro[i].id);
	}	
}

void Imprime_Numero_Companheiros(u d) { 
	 printf("%s tem %d companheiros\n",d.nome,d.numerocompanheiros);
}
void percorre(TipoLista *lista) {
	int i,j;

	for (i = lista->primeiro - 1; i <= (lista->ultimo-2); i++) {
		for (j = lista->primeiro -1; j <= (lista->ultimo-1); j++) {
			if(lista->item[i].id != lista->item[j].id) {
				Insere_Potencial_Companheiro(lista->item[i],lista->item[j], lista);
			}
		}
	}
}

void sem_companheiro (TipoLista *lista) { 
	int i;
	for(i=lista->primeiro-1; i<=(lista->ultimo-2); i++) {
		if(lista->item[i].numerocompanheiros==0) {
				printf("%s não tem nenhum companheiro\n",lista->item[i].nome);
		}
	}
}

void insertionSort(TipoLista *lista, int k)
{
   int i, j;
   u vetorDesordenado[maxTam], valorAtual;
	for (i = lista->primeiro - 1; i <= (lista->ultimo-2); i++) {
	   vetorDesordenado[i]=lista->item[i];
   }
   i = 0;
   for( j=0; j < maxTam; j++ ) {
	 
      valorAtual = vetorDesordenado[j];
      i = j-1;
      
      while(i >= 0 && vetorDesordenado[i].numerocompanheiros < valorAtual.numerocompanheiros)
      {
        vetorDesordenado[i+1] = vetorDesordenado[i];
        i--;
      } 
              
      vetorDesordenado[i+1] = valorAtual;
   }
   
    for( j=1; j < k+1; j++ ) {
		
		
		printf("%s tem %d companheiros\n", vetorDesordenado[j].nome,vetorDesordenado[j].numerocompanheiros);
   }
   
}

