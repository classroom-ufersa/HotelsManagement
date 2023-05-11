#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>
#include "hotel.c"
#include "quarto.c"

#define TITULO_OPCAO1 " Adicionar Hotel "
#define TITULO_OPCAO2 " Remover Hotel "
#define TITULO_OPCAO3 " Listar Hoteis Cadastrados "
#define TITULO_OPCAO4 " Buscar Hoteis "
#define TITULO_OPCAO5 " Editar Cadastro "
#define TITULO_OPCAO6 " Consultar quartos disponiveis em um dada Hotel "
#define TITULO_OPCAO7 " Consultar quantitativo de quartos por Hoteis "
#define TITULO_OPCAO8 " Sair "

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao() {
    int r, ret2, n1, letra;
    r = 0;
    while (r != 1){
        printf("\nDigite sua opcao: ");
        ret2 = scanf("%d", &n1);
        if (n1 >= 1 && n1 <= 8){
            r = ret2;
        }
        if (r == 0){
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre 1 e 8. \n");
        }
        letra = 0;
        while (letra != '\n'){
            letra = getchar();
        }
        printf("\n");
    }
    return n1;
}

void ApresentaMenu(int nItens, int menorOpcao, ...){
    int i;
    va_list argumentos;
    va_start(argumentos, menorOpcao);
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);
}

int main (void){
    unsigned char op;
    unsigned int saida = 0;
    Listah * hoteis = lst_criah();
    Listaq * quartos = lst_criaq();
    printf("\n=================================\n");
    printf("              MENU               \n");
    printf("=================================\n");
    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                    TITULO_OPCAO1, TITULO_OPCAO2,
                    TITULO_OPCAO3, TITULO_OPCAO4,TITULO_OPCAO5, TITULO_OPCAO6,TITULO_OPCAO7,TITULO_OPCAO8);
            
        op = LeOpcao();
        switch(op) {
            case 1:
                printf("\n=================================\n");
                printf("         Adicionar Hotel         \n");
                printf("=================================\n");
                printf("\n");
                hoteis = insereh(hoteis);
                printf("\n");
                hoteis->info->room = insereq();
                printf("\n");
                break;
                
            case 2:  
                printf("\n=================================\n");                   
                printf("         Excluir Hotel           \n");
                printf("=================================\n");
                printf("\n");
                hoteis = excluirh(hoteis);              
                printf("\n");
                break;

            case 3:       
                printf("\n=================================\n");            
                printf("         Listar Hotel            \n");
                printf("=================================\n");
                printf("\n");
                listarh(hoteis); 
                printf("\n");
                break;
                    
            case 4:
                printf("\n=================================\n");
                printf("           Buscar Hotel          \n");
                printf("=================================\n");
                printf("\n");
                buscarh(hoteis);
                printf("\n");
                quartos = buscarq(quartos);
                printf("\n");
                break;

            case 5:
                printf("\n=================================\n");
                printf("         Editar cadastro         \n");     
                printf("=================================\n");   
                printf("\n");
                hoteis = editarh(hoteis);
                printf("\n");
                quartos = editaq(quartos);
                printf("\n");
                break;

             case 6:
                printf("\n=================================\n");
                printf("       Consultar quartos         \n");
                printf("=================================\n");
                printf("\n");
                consultar_quartos(hoteis);           
                printf("\n");
                break;

            case 7:
                Beep(1000,500);
                printf("\n=================================\n");
                printf("      Quantidade de Quartos      \n");
                printf("=================================\n");
                printf("\n");
                quantitativa_quartos(hoteis);
                printf("\n");
                break;

            case 8:
                Beep(1000,500);
                printf("\n=================================\n");
                printf("              Sair               \n");
                printf("=================================\n");
                printf("\n");
                listarh(hoteis);
                printf("\n");
                saida = 1;
                printf("\n");
                break;

            default:
                printf("Opcao invalida");
                return 1;
        }
            
    }while(!saida);

    return 0;
}
