#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"
#include "hotel.h"

struct quarto{
    char tipo[20];
    float preco;
    int disp;
    int num;
    int qntd;
};

struct list{
  Quarto *info;
  struct list *next;
};
	
Quarto* insereq(void){
	int qntd, i;
	printf("Informe quantos quartos deseja adicionar no hotel: ");
	scanf("%d", &qntd);
	Quarto* new = (Quarto*)malloc(qntd * sizeof(Quarto));
	
	for(i=0;i<qntd;i++){
		printf("Tipo do quarto: ");
		scanf("%s", new[i].tipo);
		printf("Preco do quarto: ");
		scanf("%f", &new[i].preco);
		printf("Disponibilidade do quarto: ");
		scanf("%d", &new[i].disp);
		printf("numero do quarto: ");
		scanf("%d", &new[i].num);
	}
	FILE* arq_quarto = fopen("quarto.txt", "a"); 
	if(arq_quarto == NULL){ 
		 
		printf("Erro ao abrir o arquivo: "); 
		return 0; 
	}
	fprintf(arq_quarto,"tipo:%s\npreco:%f\ndisponibilidade:%d\nnumero:%d\n", new->tipo, new->preco, new->disp, new->num); //salvando os dados do usuario dentro do arquivo        
	printf("\n");
	fclose(arq_quarto); 
    return new;
}
	
Listaq* lst_criaq(void){
	return NULL;
}


int vaziaq(Listaq *list){
	return (list==NULL);
}

Listaq* excluirq(Listaq* list){
	int numq;
	Listaq* ant = NULL;
	Listaq* prox = list;
	printf("Digite o numero do  que deseja excluir\n");
    scanf("%d", &numq);
	while ((prox->info->num)!= 0){
		if(prox == NULL){
			return list;
		}
		ant = prox;
			prox = prox->next;
	}
	if(ant == NULL){
		list = prox-> next;
	}
	else{
		ant->next = prox-> next;
	}
	free(prox);
	return list;
}


Listaq * buscarq( Listaq * list){
	int nume;
	Listaq * cont;
	printf("Qual quarto deseja excluir:\n");
	scanf("%d",&nume);
	
	for(cont = list; cont!=NULL; cont=cont->next){
	    if (cont-> info->num == nume){
		    return cont;
	    }
    }
	return NULL ;
}

Listaq *editaq(Listaq *list){
	int edit = 0;
	printf("Qual quarto: \n\n");
	scanf("%d", &edit);
	printf("\n");
	Listaq*cont;
	for(cont=list; cont!=NULL; cont=cont->next){
		if(cont->info->num ==edit){				
			printf("Qual a nova Disponibilidade: ");
			scanf(" %d\n", &cont->info->disp);
			printf("Qual o Preco do quarto: ");
			scanf(" %f\n", &cont->info->preco);
			printf("Qual o Tipo do quarto: ");
			scanf(" %s\n", cont->info->tipo);
		}
	}
	return cont;
}
	
void quantitativoq(Listaq * list){
    Listaq *percorre;
	int  cont= 0;

	for(percorre=list; percorre!=NULL; percorre = percorre -> next){
      cont++;
	}

	printf("Quartidade de quarto e : %d\n", cont);

}

void listarq(Listaq *list){
	Listaq *cont;

	for(cont=list; cont!=NULL; cont=cont->next){
		printf("|Tipo: %s |Numero: %d | Preco: %f | Disponibilidade: %d |\n", cont->info->tipo, cont->info->num, cont->info->preco, cont->info->disp);
		printf("\n");
	}
}

void quantitativa_quartos(Listah *list){
    Listah *percorre;
    int cont;
    char nome_hotel[50];
    printf("Digite o nome do hotel que deseja consultar: ");
    scanf("%s", nome_hotel);
    
    for(percorre=list; percorre!=NULL; percorre = percorre->next){
        if(strcmp(percorre->info->nome, nome_hotel) == 0){
            if(percorre->info->room!=NULL){
                cont++;
            }
        }
    }
    printf("Quantitativa de quartos no hotel %s: %d", nome_hotel, cont);
}