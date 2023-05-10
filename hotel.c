#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#include "quarto.h"

struct hotel { 
	char nome[50]; /*  */
	Quarto *room; /*  */
	char local[100]; /*  */
	char avali[5]; /*  */
};

struct lista{
	Hotel *info;
	struct lista *next;
};

Hotel *realizarh(void){
	int qntd, i;
	printf("Quantos hoteis deseja adicionar? ");
	scanf("%d", &qntd);
	Hotel *novo_hotel = (Hotel*) malloc(qntd * sizeof(Hotel));
	for(i=0;i<qntd;i++){
		printf("Informe o nome: \n");
		scanf(" %s", novo_hotel[i].nome);
		printf("Informe a localidade: \n");
		scanf(" %s", novo_hotel[i].local);
		printf("Informe a avaliacao do hotel: \n");
		scanf(" %s", novo_hotel[i].avali);

		if(novo_hotel != NULL){
			printf("Hotel Adicionado!\n");
			printf("Nome: %s\nLocalidade: %s\nAvaliacao: %s\n", novo_hotel[i].nome, novo_hotel[i].local, novo_hotel[i].avali);
		}
	}
	return (novo_hotel);
}	

Listah* lst_criah(void){
	return NULL;
}

Listah *insereh(Listah *list){

	Hotel *add = realizarh();
	Listah *novo = (Listah*)malloc(sizeof(Listah));
	novo -> info = add;
	novo -> next = list;
	return novo;
}

int l_vaziah(Listah *list){
	return (list==NULL);
}

Listah * excluirh(Listah *list){
	char Nome[50];
	Listah *anterior= NULL;
	Listah *percorre = list;
	printf("Digite o nome do hotel: ");
	scanf(" %[^\n]", Nome);
	while((strcmp (Nome, percorre->info->nome)) != 0){
		percorre = percorre->next;
		if(percorre == NULL){
			printf("Nao foi encontrado nenhum hotel!");
			return (list);
		}
		anterior = percorre;
		percorre = percorre->next;
	}
		
	if(anterior == NULL){
		list = percorre->next;
	}
	else{
		anterior->next = percorre->next;
	}
	free(percorre);
	return (list);	
}

void listarh(Listah *list){
	Listah*percorre;

	for(percorre=list; percorre!=NULL; percorre=percorre->next){

	printf("|Hotel: %s | Localidade: %s | Avaliacao: %s |\n",percorre->info->nome, percorre->info->local, percorre->info->avali);
    printf("\n");
	}
}

void buscarh(Listah *list){
	char nome_hotel[50];
	Listah * percorre;
	printf("Digite o nome do hotel: ");
	scanf(" %[^\n]", nome_hotel);
	for(percorre = list; percorre != NULL; percorre = percorre->next){
		if(strcmp(percorre->info->nome, nome_hotel) == 0){
			printf("Nome: %s\n", percorre->info->nome);
			printf("Localidade: %s\n", percorre->info->local);
			printf("Avaliacao: %s\n", percorre->info->avali);
		}
	}
}



Listah *editarh(Listah *list){
	Listah *p;
	char novo_hotel[50];
	printf("Digite o nome do hotel que deseja editar: ");
	scanf("%s", novo_hotel);
	for(p = list; p != NULL; p = p->next){
		if(strcmp(p->info->nome, novo_hotel) == 0){
			printf("Novo nome: \n");
			scanf("%s", p->info->nome);
			printf("Nova localizacao: \n");
			scanf("%s", p->info->local);
			printf("Nova avaliacao: \n");
			scanf("%s", p->info->avali);
		}
	}
	return(p);
}