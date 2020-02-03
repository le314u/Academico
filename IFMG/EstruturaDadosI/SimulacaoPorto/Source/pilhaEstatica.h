#ifndef pilhaEstatica_h
#define pilhaEstatica_h
// Structs
typedef struct PilhaStatica{
   int tamanho;
   int topo;
   int *elemento;
}Pilha;

// Prototipos
void GeraPilha(Pilha *Instancia, int Tamanho);
int Empilha(Pilha *Instancia, int Elemento);
int Desempilha(Pilha *Instancia);
int ResetaPilha(Pilha *Instancia);

#endif
