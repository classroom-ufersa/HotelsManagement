#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#include "quarto.h"

struct hotel{
	char nome[50];
	char local[100];
	char avalia[5];
	Quarto *room;
};

struct lista{
	Hotel *info;
	Lista *prox;
};

Hotel *add_hotel(void){

	Hotel *novo_hotel = (Hotel*) malloc(sizeof(Hotel));

	printf("Informe o nome: \n");
	scanf(" %s", novo_hotel->nome);
	printf("Informe a localidade: \n");
	scanf(" %s", novo_hotel->local);
	printf("Informe a avaliacao do hotel: \n");
	scanf(" %s", novo_hotel->avalia);
	
	if(novo_hotel != NULL){
		printf("Hotel Adicionado!\n");
		printf("Nome: %s\nLocalidade: %s\nAvaliacao: %s\n", novo_hotel->nome, novo_hotel->local, novo_hotel->avalia);
	}
	return (novo_hotel);
}	

Lista *insere_hotel(Lista *lista, Hotel *cont){
    
	Lista *novo_hotel = (Lista*) malloc (sizeof(Lista));
  	novo_hotel->info = cont;
  	novo_hotel->prox = lista;

  	return (novo_hotel);
}

Lista *excluir_hotel(Lista *lista){
	char nome_hotel[50];
	Lista *anterior= NULL;
	Lista *percorre = lista;
	printf("Digite o nome do hotel: ");
    scanf(" %[^\n]", nome_hotel);
	while((strcmp(nome_hotel, percorre->info->nome)) != 0){
		if(percorre == NULL){
			printf("Nao foi encontrado nenhum hotel!");
			return (lista);
		}
		anterior = percorre;
        percorre = percorre->prox;
	}
	
	if(anterior == NULL){
		lista = percorre->prox;
	}
	else{
		anterior->prox = percorre->prox;
	}
	free(percorre);
	return (lista);	
}

void listar_hotel(Lista *lista){
	Lista *percorre;

	for(percorre=lista; percorre!=NULL; percorre=percorre->prox){
		printf("Nome = %s \n", percorre->info->nome);
    	printf("Localidade = %s \n", percorre->info->local);
		printf("Avaliacao = %s \n", percorre->info->avalia);
	}
}

void listartxt(Lista *lista){
	Lista *percorre;

	FILE *arquivo_hotel;
	arquivo_hotel = fopen("ListarHotel.txt", "a"); 
	
	if(arquivo_hotel == NULL){
	    printf("Erro ao abrir arquivo\n");
	} 
	else{
	    printf("Salvo com sucesso!\n");

        for(percorre=lista; percorre !=NULL; percorre=percorre->prox){
		    fprintf(arquivo_hotel,"Nome: %s\nLocalidade:%s\nAvaliacao: %s\n", percorre->info->nome, percorre->info->local, percorre->info->avalia);
            fclose(arquivo_hotel);
	    }
	}
            		
}

void buscar_hotel(Lista* lista){
	char nome_hotel[50];
	Lista * percorre;
	printf("Digite o nome do hotel: ");
    scanf(" %[^\n]", nome_hotel);
	for(percorre = lista; percorre != NULL; percorre = percorre->prox){
		if(strcmp(percorre->info->nome, nome_hotel) == 0){
			printf("Nome: %s\n", percorre->info->nome);
			printf("Localidade: %s\n", percorre->info->local);
			printf("Avaliacao: %s\n", percorre->info->avalia);
		}
	}
}