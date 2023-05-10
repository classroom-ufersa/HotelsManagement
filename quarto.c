#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

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
	int i, j, r;
	char temp[100];
	printf("Informe quantos quartos deseja adicionar no hotel: ");
	scanf("%d", room->qntd);
	if(room->qntd<=0){
		printf("Valor invalido!");
		return(NULL);
	}
	Quarto* new = (Quarto*)malloc(room->qntd * sizeof(Quarto));
	for(i=0;i<=room->qntd;i++){
		printf("Tipo do quarto: ");
		scanf(" %s\n", new[i].tipo);
		printf("Preco do quarto: ");
		scanf(" %f\n", new[i].preco);
		printf("Disponibilidade do quarto: ");
		scanf(" %d\n", new[i].disp);
		printf("numero do quarto: ");
		scanf("%d", &new[i].num);
	}
	FILE* arq_quarto = fopen("quarto.txt", "a"); 
	if(arq_quarto == NULL){ 
		 
		printf("Erro ao abrir o arquivo: "); 
		return 0; 
	}
	fprintf(arq_quarto,"tipo:%s\npreco:%s\ndisponibilidade:%s\nnumero:%d\n", new->tipo, new->preco, new->disp, new->num); //salvando os dados do usuario dentro do arquivo        
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

Listaq* excluirq(Listaq* list, int num_q){
	Listaq* ant = NULL;
	Listaq* prox = list;
		while ((num_q, prox->info->num)!= 0){
			if(prox == NULL){
				return list;
			}
			ant = prox;
				prox = prox->next;
		}
		if(ant == NULL){
			list = prox-> next;
		}
		else
		{
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

void editaq(Listaq *list){
	int edit = 0;
	
	printf("Qual quarto: \n\n");
	scanf("%d", edit);
	printf("\n");
	Listaq*cont;
	for(cont=list; cont!=NULL; cont=cont->next){
		if(cont->info->num ==edit){				
			printf("Qual a nova Disponibilidade: ");
			scanf(" %d\n", cont->info->disp);
			printf("Qual o Preco do quarto: ");
			scanf(" %f\n", cont->info->preco);
			printf("Qual o Tipo do quarto: ");
			scanf(" %s\n", cont->info->tipo);
		}
	} 
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
	printf("|Tipo: %d |Numero: %d | Preco: %s | Disponibilidade: %s |\n",cont->info->tipo, cont->info->num, cont->info->preco, cont->info->disp);
   printf("\n");
	}
}