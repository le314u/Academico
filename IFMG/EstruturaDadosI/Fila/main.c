#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *data;
    int indice_inicio;
    int indice_fim;
    size_t tamanho;
} lista_t;

int lista_add(lista_t *lista, int valor);
int lista_remove(lista_t *lista);
int lista_get(lista_t *lista, int indice);
lista_t *lista_inverte(lista_t *lista);

void lista_init(lista_t *lista, int tamanho)
{
    printf("\nInicializando lista");
    lista->tamanho = tamanho;
    lista->data = calloc(lista->tamanho, sizeof(int));

    lista->indice_inicio = 0;
    lista->indice_fim = 0;
}

int lista_add(lista_t *lista, int valor)
{
    printf("\nAdicionando valor a lista");
    if (lista->indice_fim - lista->indice_inicio < lista->tamanho - 1)
    {
        lista->data[lista->indice_fim] = valor;
        lista->indice_fim++;

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

int lista_remove(lista_t *lista)
{
    printf("\nRemovendo valor da lista");
    if (lista->indice_fim != lista->indice_inicio)
    {
        int val = lista_get(lista, lista->indice_fim - 1);
        lista->data[--(lista->indice_fim)] = 0;

        return val;
    }

    return 0; // TODO:
}

int lista_get(lista_t *lista, int indice)
{
    printf("\nProcessando indice do vetor");
    if (indice <= lista->indice_fim && indice >= lista->indice_inicio)
    {
        return lista->data[indice];
    }

    return 0; // TODO:
}

lista_t *lista_inverte(lista_t *lista)
{
    printf("\nInvertendo a lista ");
    lista_t *lista_retorno = malloc(sizeof(lista_t));
    lista_init(lista_retorno, lista->tamanho);

    for (int i = lista->indice_fim; i >= 0; i--)
    {
        lista_retorno->data[lista->indice_fim - i] = lista_get(lista, i);
    }

    return lista_retorno;
}

lista_t *lista_concatena(lista_t *original, lista_t *appendice)
{
    for (size_t i = 0; i < appendice->indice_fim; i++)
    {
        lista_add(original, lista_get(appendice, i));
    }
}

lista_t *lista_intercala(lista_t *lista1, lista_t *lista2)
{
    lista_t *lista_retorno = calloc(1, sizeof(lista_t));
    lista_init(lista_retorno, lista1->indice_fim + lista2->indice_fim + 2);

    int indice_lista1 = 0;
    int indice_lista2 = 0;

    for (int i = 0; i < lista_retorno->tamanho; i++)
    {

        if (indice_lista1 <= lista1->indice_fim)
        {
            lista_add(lista_retorno, lista1->data[indice_lista1]);
            indice_lista1++;
        }
        if (indice_lista2 <= lista2->indice_fim)
        {
            lista_add(lista_retorno, lista2->data[indice_lista2]);
            indice_lista2++;
        }
    }

    return lista_retorno;
}

int main(int argc, char **argv)
{

    lista_t *lista_retorno; //= calloc(1, sizeof (lista_t));
    lista_init(lista_retorno, 10);
    printf("m: %d\n", lista_retorno->indice_inicio);

    return EXIT_SUCCESS;
}