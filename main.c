#include <stdio.h>
#include <stdlib.h>
#include "hotel.c"

int main(){
    Hotel *h;
    Lista *lista;
    int op, saida;
    char nome_hotel[50];
    printf("\n====================\n");
    printf("\n        Menu:       \n");
    printf("\n====================\n");
    printf("1- Adicionar hotel\n");
    printf("2- Excluir hotel\n");
    printf("3- Listar hoteis\n");
    printf("4- Buscar hoteis\n");
    printf("5- Editar cadastro\n");
    printf("6- Consultar quartos\n");
    printf("7- Consultar quantitativo de quartos\n");
    printf("8- Sair\n");
    printf("Digite uma das opcoes acima: ");
    scanf("%d", &op);
    do{
        switch(op){
            case 1:
                printf("\n===============================\n");
                printf("       Adicionar Hotel        \n");
                printf("===============================\n");
                printf("\n");
                h = add_hotel();
                lista = insere_hotel(lista, h);
                break;

            case 2:
                printf("\n===============================\n");
                printf("       Excluir Hotel         \n");
                printf("===============================\n");
                printf("Digite o nome do hotel: ");
                scanf(" %[^\n]", nome_hotel);
                lista = excluir_hotel(lista, nome_hotel);
                printf("Excluido com Sucesso!\n");
                printf("\n");
                break;
                
            case 3:
                printf("\n===============================\n");
                printf("        Listar Hotel        \n");
                printf("===============================\n");
                printf("Hoteis:\n");
                listar_hotel(lista);
                printf("\n");
                listartxt(lista);
                break;

            case 4:
                printf("\n===============================\n");
                printf("        Buscar Hotel        \n");
                printf("===============================\n");
                printf("Informe o nome do hotel: ");
                scanf(" %[^\n]", nome_hotel);
                buscar_hotel(nome_hotel, lista);
                printf("\n");
                break;

            case 8:
                saida = 1;
                printf("Obrigado por usar este programa\n");
                break;
        
            default:
                printf("Opcao invalida!\n");
                return 1;   
        }
    }while(!saida);

    return 0;
}