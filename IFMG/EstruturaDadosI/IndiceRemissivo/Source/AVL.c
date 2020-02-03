//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019


#include <stdlib.h>
#include "AVL.h"
#include "TratamentoString.h"
#include "Palavra.h"

NoAVL *IniciaNoAVL(char *palavra);
NoAVL *InserirPalavraAVL(NoAVL *raiz, char *palavra, int linha);
NoAVL * _InserirPalavraAVL(NoAVL *aux, char *palavra, int linha, int *flagCresceu);
NoAVL * _RotacaoDireita(NoAVL *raiz);
NoAVL * _RotacaoEsquerda(NoAVL *raiz);
NoAVL * _RotacaoEsquerdaDireita (NoAVL *raiz);
NoAVL * _RotacaoDireitaEsquerda(NoAVL *raiz);



NoAVL *IniciaNoAVL(char *palavra){
    //Aloca um NoAVL 'Raiz'
    NoAVL *Instancia = malloc(sizeof(NoAVL));
    //Seta Filhos como NULL ou seja é uma folha
    Instancia->esquerda = NULL;
    Instancia->direita = NULL;
    //Aloca a Palavra
    Instancia->elemento = NULL;
    Instancia->elemento = initPalavra(palavra);
    //Seta valor balanceamento
    Instancia->balanceamento = 0;
    return Instancia;
}


//Insere uma PalavraNaAVL
NoAVL *InserirPalavraAVL(NoAVL *raiz, char *palavra, int linha){
    if(raiz != NULL){
        int *flag = malloc(sizeof(int));
        *flag = 0;
        raiz = _InserirPalavraAVL(raiz, palavra, linha, flag);
        flag=NULL;
        free(flag);
    }else{
        raiz = IniciaNoAVL(palavra);
    }    
    return raiz;
}


NoAVL *_InserirPalavraAVL(NoAVL *aux, char *palavra, int linha, int *flagCresceu){
    //Baseado em http://wiki.icmc.usp.br/images/f/fa/%C3%81rvores_AVL.pdf

    //Verifica a precedencia das palavras
    int indiceLado = ordemAlfabetica(palavra, aux->elemento->palavra);
    //São Iguais logo a palavra ja esta inserida
    if(indiceLado == IGUAL){
        //Verifica se a linha é valida 
        if(linha >= 1){
            //Adiciona pagina ao indice
            aux->elemento->paginas = addIndice(aux->elemento->paginas, linha);
        }else{
            //Esta Alocando apenas as palavras
            //Palavra ja foi adicionada
        }
    }
    //Esquerda
    if(indiceLado == MENOR){
        if(aux->esquerda != NULL){
            //vai para esquerda
            aux->esquerda = _InserirPalavraAVL(aux->esquerda, palavra, linha, flagCresceu);
        }else{
            if(linha < 1){

                //Cria um novo no
                aux->esquerda = IniciaNoAVL(palavra);
                //Ativa Flag afirmando que um no foi adicionado a arvore
                *flagCresceu = 1;
            }
        }
        //Se inseriu Esquerda Verifica Balanceamento
        if(*flagCresceu) { 
            switch (aux->balanceamento) {

                //Se era -1 vai virar -2 e tem que fazer rotação
                case -1: 
                    //Sinais iguais [Rotação simples]
                    if(aux->esquerda != NULL){
                        if(aux->esquerda->balanceamento == -1){
                            aux = _RotacaoDireita(aux);
                        }
                    //Sinais trocados: rotação dupla
                    }else {
                        aux = _RotacaoEsquerdaDireita(aux);

                        //interrompe propagação
                        *flagCresceu=0; 
                    }
                    break;

                //Ficou maior à esq.
                case 0:
                    aux->balanceamento = -1;

                    //propaga verificação
                    *flagCresceu = 1;
                    break;

                //Era maior à direita porem balanceou
                case 1: 
                    aux->balanceamento = 0; // balanceou o no
                    *flagCresceu = 0; //interrompe propagação
                    break;
            }
        }
    }
    //Direita
    if(indiceLado == MAIOR){
        if(aux->direita != NULL){
            //vai para direita
            aux->direita = _InserirPalavraAVL(aux->direita, palavra, linha, flagCresceu);
        }else{
            if(linha < 1){
                
                aux->direita = IniciaNoAVL(palavra);
                //Ativa Flag afirmando que um no foi adicionado a arvore
                *flagCresceu = 1;
            }
        }
        if (*flagCresceu){//Se inseriu a Direita Verifica Balanceamento
            switch (aux->balanceamento){

                //Era mais alto a esquerda porem balanceou
                case -1: 
                    aux->balanceamento=0;

                    //interrompe propagação
                    *flagCresceu=0; 
                    break;

                //Direita fica maior
                case 0:
                    aux->balanceamento=1;
                    *flagCresceu=1; // propaga verificação
                    break;
                
                //Se era 1 vai virar 2 e tem que fazer rotação
                case 1:
                    //Sinais iguais [Rotação simples]
                    if (aux->direita->balanceamento==1){ // sinais iguais – pendem para mesmo lado

                        aux = _RotacaoEsquerda(aux);
                    
                    //Sinais trocados: rotação dupla
                    }else {
                        aux = _RotacaoDireitaEsquerda(aux);
                        *flagCresceu=0; //interrompe propagação
                    }
                    break;
            }
        }
    }
    //Retorna o ponteiro
    return aux;
}





NoAVL *_RotacaoDireita(NoAVL *raiz){
    NoAVL *aux = raiz->esquerda;
    raiz->esquerda = aux->direita;    
    aux->direita = raiz;

    raiz->balanceamento = 0;
    aux->balanceamento = 0;

    raiz = aux;
    return raiz;
}

NoAVL * _RotacaoEsquerda(NoAVL *raiz){
    NoAVL *aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;


    raiz->balanceamento = 0;
    aux->balanceamento = 0;

    raiz = aux;
    return raiz;
}

NoAVL * _RotacaoEsquerdaDireita (NoAVL *raiz) {
    //Rotaciona Parte Inferior para a Esquerda
    NoAVL *auxPe = raiz->esquerda->direita;
    raiz->esquerda->direita = auxPe->esquerda;
    auxPe->esquerda = raiz->esquerda;
    raiz->esquerda = auxPe;

    //Rotaciona Parte Superior para esquerda
    NoAVL *aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->direita = raiz;
       
    raiz = aux;

    switch (raiz->balanceamento ) {
        case -1:
            raiz->esquerda->balanceamento = 0;
            raiz->direita->balanceamento = 1; 
            break;
        case 0:
            raiz->esquerda->balanceamento = 0;
            raiz->direita->balanceamento = 0; 
            break;
        case 1:
            raiz->esquerda->balanceamento = -1;
            raiz->direita ->balanceamento = 0; 
            break;
    }
    raiz->balanceamento = 0;
    return raiz;
}

NoAVL *_RotacaoDireitaEsquerda(NoAVL *raiz){
    //Rotaciona Parte Inferior para a Direita
    NoAVL *auxPe = raiz->direita->esquerda;
    raiz->direita->esquerda = auxPe->direita;
    auxPe->direita = raiz->direita;
    raiz->direita = auxPe;

    //Rotaciona Parte Superior para Esquerda
    NoAVL *aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;
       
    raiz = aux;
    switch (raiz->balanceamento){
        case -1:
            raiz->esquerda->balanceamento = 1;
            raiz->direita->balanceamento = 0;
            break;
        case 0:
            raiz->esquerda->balanceamento = 0;
            raiz->direita->balanceamento = 0;
            break;
        case 1:
            raiz->esquerda->balanceamento = -1;
            raiz->direita->balanceamento = -1;
            break;
    }
    raiz->balanceamento = 0;
    return raiz;
}
