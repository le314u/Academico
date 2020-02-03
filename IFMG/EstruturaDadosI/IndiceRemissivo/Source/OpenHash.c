//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Palavra.h"
#include "TratamentoString.h"
#include "OpenHash.h"

float _proporcaoPreenchimento(TabelaHash *openHash);
void _setNullOpenHash(TabelaHash *openHash, int inicio, int fim);
void _ResizeOpenHash(TabelaHash *openHash);

int hash1(char *palavra){
    //Pega o tamanho da palavra
    int tamanho = strlen(palavra);
    int valor = 0;
    //Gera um Hash
    for(int i = 0 ; i < tamanho; i++){
        valor += (int) palavra[i]-'0';
    }
    //Padroniza para caber no vetor original
    int valorHash = valor +(valor << 1);

    //1010 1010 1010 1010
    int mascara1 = valorHash & 43690;
    
    //1001 1001 1001 1001
    int mascara2 = valorHash & 39321;

    //0101 0101 0101 0101
    int mascara3 = valorHash & 1365;

    //0110 0110 0110 0110
    int mascara4 = valorHash & 26214;

    //1000 1000 1000 1000
    int mascara5 = valorHash & 34952;

    //0001 0001 0001 0001
    int mascara6 = valorHash & 4369;

    int hash = (mascara1 - mascara2 + (mascara5 - (mascara3 + mascara4)) + mascara6);

    return abs(hash % TAMANHO_VETOR);
}

TabelaHash *IniciaOpenHash(){
    //Cria uma tabela open hash
    TabelaHash *openHash = malloc(sizeof(TabelaHash));
    openHash->tabela = malloc(TAMANHO_VETOR * sizeof(Palavra*));
    openHash->tamanho = TAMANHO_VETOR;
    //Seta todas as palavras como Nulas
    openHash->nInsercao = 0;
    _setNullOpenHash(openHash, 0, TAMANHO_VETOR-1);
    return openHash;
}

void InserirPalavraOpenHash(TabelaHash *openHash, char *palavra, int linha){
    //Redimensiona a Tabela caso necessário
    if(_proporcaoPreenchimento(openHash) >= 0.75){
        _ResizeOpenHash(openHash);
    }
    //Faz o Hash do elemento
    int indice = hash1(palavra);
    //Fase de Treinamento
    if(linha < 1){
        //Cria o elemento a ser inserido na tabela
        Palavra *elemento = initPalavra(palavra);
        //Tenta colocar no indice adequado
        if(openHash->tabela[indice] == NULL){
            openHash->tabela[indice] = elemento;
            openHash->nInsercao++;
        //Se sofreu colisao vai tentar todos os vetores
        }else{ 
            for(int i = indice+1; i != indice; i=(i+1)%openHash->tamanho){
                //printf("hash =%d i=%d nIsercao %d\n",indice,i,openHash->nInsercao);
                if(openHash->tabela[i] == NULL){
                    openHash->tabela[i] = elemento;
                    openHash->nInsercao++;
                    break;
                }else{
                    int celula = ordemAlfabetica(palavra, openHash->tabela[i]->palavra);
                    if(celula == IGUAL){
                        break;
                    }
                }
            }
        }
    //Add indices
    }else{
        int flagAchou = 0;
        //PrimeiraPosição
        if(openHash->tabela[indice] != NULL){
            int flag = ordemAlfabetica(palavra, openHash->tabela[indice]->palavra);
            if(flag == IGUAL){
                flagAchou = 1;
                //add o indice a palavra  
                openHash->tabela[indice]->paginas = addIndice(openHash->tabela[indice]->paginas , linha);
            //Se sofreu colisao vai tentar todos os vetores
        }
        //Demais posições
        if(!flagAchou){
            //Percorre  a tabela procurando o elemento
                for(int i = indice+1; i != indice; (i= (i+1) % openHash->tamanho)){
                    if(openHash->tabela[i] != NULL){
                        int flag = ordemAlfabetica(palavra, openHash->tabela[i]->palavra);
                        if(flag == IGUAL){
                            openHash->tabela[i]->paginas = addIndice(openHash->tabela[i]->paginas , linha);
                            break;
                        }
                    }
                }
            }
        }
    }
}

float _proporcaoPreenchimento(TabelaHash *openHash){
    return ((float) openHash->nInsercao / openHash->tamanho);
}

void _setNullOpenHash(TabelaHash *openHash, int inicio, int fim){
    //Seta as palavras como invalidas
    for (int i = inicio; i <= fim; i++)
    {
        openHash->tabela[i] = NULL;
    }
}

//Dobra o tamanho da tabela open hash a fim de diminuir o numero de colisões
void _ResizeOpenHash(TabelaHash *openHash){
    printf("Resize....");
    //Guarda o tamnho da tabela OpenHash
    int oldTamanho = openHash->tamanho;
    int newTamanho = openHash->tamanho * 2;
    //Altera o tamanho do vetor
    openHash->tamanho = newTamanho;
    openHash->tabela = (Palavra**) realloc(openHash->tabela, newTamanho * (sizeof(Palavra*)));
    //Preenche as novas posições com palavras invalidas
    _setNullOpenHash(openHash, oldTamanho, newTamanho-1);
    printf("OK");

}


void PrintaOpenHash(TabelaHash *tabelaHash){
    //Cria um vetor auxiliar
    Palavra **newTabela = malloc(tabelaHash->tamanho * sizeof(Palavra*));
    //Seta tudo como NULL
    for (int i = 0; i < tabelaHash->tamanho; i++)
    {
        newTabela[i] = NULL;
    }
    
    //Primeiro elemento usado como base
    newTabela[0] = tabelaHash->tabela[0];
    int flag = 0;

    //Insertion Sort
    for (int i = 1; i < tabelaHash->tamanho; i++){
        
        //Aloca a palavra atual no final parcial do vetor
        newTabela[i] = tabelaHash->tabela[i];
        for (int j = i; j > 0; j--){
            //Prepara a flag para fazer as trocas
            if(newTabela[j] == NULL){
                //Atual = NULL
                flag = MAIOR;
            }else{
                if(newTabela[j-1] == NULL){
                    //Atual  diferente de NULL anterior = NULL
                    flag = MENOR;
                }else{
                    //Ambos diferentes de NULL
                    flag = ordemAlfabetica(newTabela[j]->palavra, newTabela[j-1]->palavra);
                }    
            }
            //Faz a troca se necessário
            if(flag == MENOR){
                Palavra *auxAntes = newTabela[j-1];
                Palavra *auxAtual = newTabela[j];
                newTabela[j] = auxAntes;
                newTabela[j-1] = auxAtual;
            }else{
                break;
            }
        }
    }

    //Printa o vetor
    for (int i = 0; i < tabelaHash->tamanho; i++){
        if(newTabela[i] != NULL){
            //Printa Palavra
            printf("\n%s",newTabela[i]->palavra);
            //Printa os indice
            percorreLista(*(newTabela[i]));
        }
    }

    free(newTabela);
}