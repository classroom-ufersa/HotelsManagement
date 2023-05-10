#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#include "quarto.h"

struct hotel { 
	char nome[50]; /*  */
	Quarto *room; /*  */
	char local[5]; /*  */
	char avali[5]; /*  */
};

struct lista{
	Hotel *info;
	struct lista *next;
};

Hotel *realizarh(void){
	int i, j, r, n; 
	char temp[100];
	printf("Digite quantos hoteis deseja adicionar: ");
	scanf("%d", &n);
	Hotel *add = (Hotel*)malloc(n *sizeof(Hotel));
	if (add == NULL){
		printf("Erro alocar a memoria \n");
		exit (1);
	}
	for(i=0;i<=n;i++){	
		printf("Nome do hotel: \n");
		scanf(" %[^\n]", add[i].nome);
		printf("Quantidade de quartos: \n");
		scanf("%d", &add[i].room->qntd);
		printf("Localizacao do hotel: \n");
		scanf(" %[^\n]", add[i].local);
		printf("Avaliacao do hotel: \n");
		scanf(" %[^\n]", add[i].avali);
	}
   	for (i = 0; i < n; i++){ 
		for (j = i + 1; j < n; j++){ 				
			r = strcmp(add[i].nome, add[j].nome);

			if (r > 0){ 
				strcpy(temp, add[i].nome);
				strcpy(add[i].nome, add[j].nome);
				strcpy(add[j].nome, temp);
			}
		}
	}

	FILE* arq_hotel = fopen("hotel.txt", "a"); 
	if(arq_hotel == NULL){  
		printf("Erro ao abrir o arquivo: "); 
		return 0; 
	}
	fprintf(arq_hotel, "Hotel :%[^\n]\nQuantidade de quartos :%d\nLocalizacao:%[^\n]\n Avaliacao :%[^\n]\n", add->nome, add->room->qntd, add->local, add->avali); //salvando os dados do usuario dentro do arquivo
		
	printf("Dados guardados com sucesso no arquivo hotel.txt !\n");
	printf("\n");
	fclose(arq_hotel); 
	return add; 
}

Listah* lst_criah(void){
	return NULL;
}

Listah *insereh(Listah *list){

	Hotel *add = realizar();
	Listah *novo = (Listah*)malloc(sizeof(Listah));
	novo -> info = add;
	novo -> next = list;
	return novo;
}

int l_vaziah(Listah *list){
	return (list==NULL);
}

Listah * excluirh(Listah *list, char nome){
	Listah *anterior= NULL;
	Listah *percorre = list;
	printf("Digite o nome do hotel: ");
	scanf(" %[^\n]", nome);
	while((strcmp (nome, percorre->info->nome)) != 0){
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

	printf("|Hotel: %d |Quartos: %d | Local: %s | Avali: %s |\n",percorre->info->nome, percorre->info->room->qntd, percorre->info->local, percorre->info->avali);
    printf("\n");
	}
}

Listah *buscarh(Listah *list){
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



void editarh(Listah *list){
	char name;
		
	printf("Digite o codigo para busca: ");
	scanf("%s", &name);
    printf("\n");

	Listah *cont;

	for(cont=list; cont!=NULL; cont=cont->next){
			
		if(cont->info->nome == name){

			printf("hotel encontrado!\n");
			printf("Novo hotel: ");
			scanf(" %s", &cont->info->nome);
			printf("Novos quarto: ");
			scanf(" %d", &cont->info->room->qntd);
			printf("Nova localizacao: ");
			scanf(" %s\n", cont->info->local);
			printf("Nova avaliacao:  ");
			scanf(" %s\n", cont->info->avali);
		}
	}
}

void disponibilidadeh(Listah *list){

	Listah *cont;

	char nome[100];
	char strucnome[100];
	char local[100];
	int struclocal[100];
	int retorno;
	int retorno2;

	printf("Digite o hotel desejado: ");
	scanf(" %s", nome);
	printf("Digite o local desejado: ");
	scanf(" %d", local);

	for(cont=list; cont!=NULL; cont=cont->next){

		strcpy(struclocal, cont -> info -> local);
		retorno2 = strcmp(local, struclocal);
		strcpy(strucnome, cont -> info -> nome);
		retorno = strcmp(nome, strucnome);

		if(retorno == 0 && retorno2 == 0){
			printf("Total de vagas disponiveis no quarto: %d\n", cont->info->room->disp);
		}
	}
}