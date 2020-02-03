#include <stdio.h>
#include <stdlib.h>
#include "tad_abb.h"



void Menu(No *root){
    int menu = 0;
    while(!(menu>=1 && menu<=6)){
        printf("\n______________________________________________\n");
        printf("Menu:");
        scanf("%d",&menu);
        system("clear");
        printf("\n\n1 - Inicia ABB\n");
        printf("2 - Insere elemento na ABB\n");
        printf("3 - Pesquisa elemento na ABB\n");
        printf("4 - Balanceia ABB\n");
        printf("5 - Mostra elementos por nível da ABB\n");
        printf("6 - Mostra o numero de elementos dentro da ABB\n");
        printf("______________________________________________\n");
    }
    switch (menu)
    {
        case 1:
            free(root);
            No *root = malloc(sizeof(No));
            IniciaABB(root);
            break;
        case 2:
            InsereABB(root);
            break;
        case 3:
            PesquisaABB(root);
            break;
        case 4:
            root = BalanceiaABB(root);
            break;
        case 5:
            NiveisABB(root);
            break;
        case 6:
            TamanhoABB(root);
            break;
        
        default:
            break;
    }
}

int main(){
    No *root = malloc(sizeof(No));
    while(1){
        Menu(root);
    }

    return 0;
}