#include <stdio.h>
#include <locale.h>
#include "pilha-dinamica.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    PilhaDinamica* pd;
    pd = cria_pd();
    if(pd == NULL) {
        printf("Ocorreu algum erro na cria��o da pilha! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_pd(pd, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                if(remover_pd(pd)) printf("Primeiro da pilha removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("\n");
                listar_pd(pd);
                if(getch()) system("cls"); break;
            case 4:
                if((aux = tamanho_pd(pd)) == 0) printf("Pilha vazia! \n");
                else printf("Quantidade atual de elementos na pilha: %d", aux);
                if(getch()) system("cls"); break;
            case 5:
                if(topo_pd(pd, &aux)) printf("Primeiro elemento da pilha: %d", aux);
                else printf("Pilha vazia! \n");
                if(getch()) system("cls"); break;
            case 6: break;
            default: printf("Op��o inv�lida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 6);
    libera_pd(pd);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir novo elemento\n");
    printf("[2] - Remover elemento\n");
    printf("[3] - Mostrar pilha\n");
    printf("[4] - Quantidade de elementos na pilha\n");
    printf("[5] - Primeiro da pilha\n");
    printf("[6] - Sair\n");
    printf("================================= \n");
    printf("Op��o escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

