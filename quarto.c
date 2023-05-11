#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"
#include "hotel.h"

struct quarto{
    char tipo[20];
    float preco;
    char disp[3];
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
		scanf("%s", new[i].disp);
		printf("numero do quarto: ");
		scanf("%d", &new[i].num);
	}
	FILE* arq_quarto = fopen("quarto.txt", "a"); 
	if(arq_quarto == NULL){ 
		printf("Erro ao abrir o arquivo: "); 
		return 0; 
	}
	fprintf(arq_quarto,"tipo:%s\npreco:%f\ndisponibilidade:%s\nnumero:%d\n", new->tipo, new->preco, new->disp, new->num);       
	printf("\nDados adicionados no arquivo!\n");
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

Listaq * buscarq( Listaq * list){
	int nume;
	Listaq * cont;
	printf("Qual quarto deseja buscar:\n");
	scanf("%d",&nume);
	
	for(cont = list; cont!=NULL; cont=cont->next){
	    if (cont-> info->num == nume){
		    return cont;
	    }
    }
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
			scanf(" %s\n", cont->info->disp);
			printf("Qual o Preco do quarto: ");
			scanf(" %f\n", &cont->info->preco);
			printf("Qual o Tipo do quarto: ");
			scanf(" %s\n", cont->info->tipo);
		}
	}
	return cont;
}

void quantitativa_quartos(Listah *list){
    Listah *percorre;
    int aux;
    char nome_hotel[50];
    printf("Digite o nome do hotel que deseja consultar: ");
    scanf("%s", nome_hotel);
    
    for(percorre=list; percorre!=NULL; percorre = percorre->next){
        if(strcmp(percorre->info->nome, nome_hotel) == 0){
            if(percorre->info->room!=NULL){
                aux++;
            }
        }
    }
    printf("Quantitativa de quartos no hotel %s: %d", nome_hotel, aux);
}

void consultar_quartos(Listah *list){
	Listah *percorre;
    char nome_hotel[50];
    printf("Digite o nome do hotel que deseja consultar: ");
    scanf("%s", nome_hotel);
	for(percorre=list; percorre!=NULL; percorre=percorre->next){
		if(strcmp(percorre->info->nome, nome_hotel) == 0){
            if((percorre->info->room->disp) == 'Sim' || (percorre->info->room->disp) =="sim"){
                printf("Localidade: %s\n", percorre->info->local);
                printf("Avaliacao: %s", percorre->info->avali);
                printf("Numero do quarto: %d\n", percorre->info->room->num);
                printf("Tipo do quarto: %s\n", percorre->info->room->tipo);
                printf("Preco: %f\n", &percorre->info->room->preco);
            }
            else{
                printf("Quarto indisponivel!\n");
            }    
		}
        else{
            printf("Hotel nao encontrado!\n");
        }
	}
}
