//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <stdio.h>
#include <stdlib.h>
#include "Palavra.h"
#include "TratamentoString.h"
#include "Lista.h"
#define INVALIDO -1

void _setaProxima(CelulaP *atual, char *palavra);
void _setaAnterior(CelulaP *atual, char *palavra);

void teste(ListaP *lista){
    CelulaP *aux = lista->inicio;
    while(aux != NULL){
        printf("\t%s[%d]",aux->elemento->palavra,aux->elemento->paginas->tamanho);
        aux = aux->proxima;
    }
}




CelulaP *_InserirPalavraLista(CelulaP *cel, char *palavra, int linha);
    
CelulaP *IniciaCelulaP(char *palavra){
    CelulaP *celula = malloc(sizeof(CelulaP));
    celula->elemento = initPalavra(palavra);
    celula->proxima = NULL;
    celula->anterior = NULL;
    return celula;
}

ListaP *IniciaListaP(){
    ListaP *lista = malloc(sizeof(ListaP));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

//Insere uma Palavra ordenadamente na lista
ListaP *InserirPalavraLista(ListaP *lista, char *palavra, int linha){
    //Caso a Raiz ja tenha sido alocada
    if(lista != NULL){
        //Lista esta teoricamente instaciada corretamente
        if(lista->inicio != NULL){
            int flagCont = 1;
            CelulaP *atual = lista->inicio;
            while(flagCont){
                //Verifica a precedencia da palavra com a celula
                int precedencia = ordemAlfabetica(atual->elemento->palavra, palavra);
                int precedenciaPosterior = INVALIDO;
                int precedenciaAnterior = INVALIDO;
                if(atual->proxima != NULL){
                    precedenciaPosterior = ordemAlfabetica(atual->proxima->elemento->palavra, palavra);
                }
                if(atual->anterior!= NULL){
                    precedenciaAnterior = ordemAlfabetica(atual->anterior->elemento->palavra, palavra);
                }

                //Treinamento
                if(linha < 1){
                    if(precedencia == MENOR){
                        if(precedenciaPosterior == MAIOR){
                            //Aloca entre a atual e a proxima
                            _setaProxima(atual, palavra);
                            lista->tamanho++;
                            flagCont = 0;
                        }else if(precedenciaPosterior == INVALIDO){
                            //Aloca no proximo elemento
                            _setaProxima(atual, palavra);
                            lista->tamanho++;
                            flagCont = 0;
                        }else{
                            //Troca o contexto para o proximo elemento
                            atual = atual->proxima;
                        }
                    }else if(precedencia == IGUAL){
                        //Não faz Nada pois a palavra ja esta presente 
                        flagCont = 0;
                    }else if(precedencia == MAIOR){
                       if(precedenciaAnterior == MENOR){
                            //Aloca entre a atual e a anterior
                            _setaAnterior(atual, palavra);
                            lista->tamanho++;
                            flagCont = 0;
                        }else if(precedenciaAnterior == INVALIDO){
                            //Aloca no elemento anterior
                            _setaAnterior(atual, palavra);
                            lista->tamanho++;
                            //Muda o inicio do vetor
                            lista->inicio = lista->inicio->anterior;
                            flagCont = 0;
                        }else{
                            //Troca o contexto para o elemento anterior
                            atual = atual->anterior;
                        }
                    }

                //Processamento
                }else{
                    if(precedencia == MENOR){
                        if(precedenciaPosterior == MAIOR){
                            //Palavra não ja alocada
                            flagCont = 0;
                        }else if(precedenciaPosterior == INVALIDO){
                            //Palavra não ja alocada
                            flagCont = 0;
                        }else{
                            //Troca o contexto para o proximo elemento
                            atual = atual->proxima;
                        }
                    }else if(precedencia == IGUAL){
                        //Add indice a palavra
                        atual->elemento->paginas = addIndice(atual->elemento->paginas, linha);
                        flagCont = 0;
                    }else if(precedencia == MAIOR){
                       if(precedenciaAnterior == MENOR){
                            //Palavra não ja alocada
                            flagCont = 0;
                        }else if(precedenciaAnterior == INVALIDO){
                            //Palavra não ja alocada
                            flagCont = 0;
                        }else{
                            //Troca o contexto para o elemento anterior
                            atual = atual->anterior;
                        }
                    }
                }
            }
        }
    //Caso a Lista não esteja alocada
    }else{
        //Treinamento
        if(linha < 1){
            //Caso a raiz não tenha sido alocada
            lista = IniciaListaP();
            lista->inicio = IniciaCelulaP(palavra);
            lista->tamanho++;
        //Processamento
        }else{
            //Não é para ser alocada
        }
    }
    return lista;
}

void _setaProxima(CelulaP *atual, char *palavra){
    //Aloca entre a atual e a proxima
    //Salva a referencia para não perder o proximo elemento
    CelulaP *aux = atual->proxima;
    //Cria um novo elemento entre atual e o proximo
    atual->proxima = IniciaCelulaP(palavra);
    //Seta volta
    atual->proxima->anterior = atual;
    //Volta a referencia
    atual->proxima->proxima = aux;
    //Seta ponteiro de volta da referencia
    if(atual->proxima->proxima != NULL){
        atual->proxima->proxima->anterior = atual->proxima;
    }
}

void _setaAnterior(CelulaP *atual, char *palavra){
    //Aloca entre a atual e a anterior
    //Salva a referencia para não perder o elemento anterior
    CelulaP *aux = atual->anterior;
    //Cria um novo elemento entre atual e o anterior
    atual->anterior = IniciaCelulaP(palavra);
    //Seta volta
    atual->anterior->proxima = atual;
    //Volta a referencia
    atual->anterior->anterior = aux;
    //Seta ponteiro de volta da referencia
    if(atual->anterior->anterior != NULL){
        atual->anterior->anterior->proxima = atual->anterior;
    }
}

