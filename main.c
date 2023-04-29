#include <stdio.h>
#include <stdlib.h>
#include "hotel.c"
#include "quarto.c"

int main(){
    Hotel *h;
    Lista *lista;
    int op, saida;
    printf(" ====================\n");
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
                lista = excluir_hotel(lista);
                printf("Hotel excluido com sucesso!");
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
                buscar_hotel(lista);
                printf("\n");
                break;

            case 5:
                printf("\n===============================\n");
                printf("        Editar hotel      \n");
                printf("===============================\n");

            case 8:
                saida = 1;
                printf("Obrigado por usar este programa!\n");
                break;
        
            default:
                printf("Opcao invalida!\n");
                return 1;   
        }
    }while(!saida);

    return 0;
}