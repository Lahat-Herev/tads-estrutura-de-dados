#include <stdio.h>
#include <string.h>

struct elemento
{
    int dado;
    struct elemento *proximo;
};

typedef struct elemento Nodo;

typedef Nodo *Lista;

Lista criaLista()
{
    return NULL;
}

void imprimeLista(Lista lista)
{
    Lista auxiliar;
    printf("\nItens da lista\n");
    auxiliar = lista;
    while (auxiliar != NULL)
    {
        printf("%d - ", auxiliar->dado);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

int contaLista(Lista lista)
{
    Lista auxiliar;
    int contador = 0;
    auxiliar = lista;
    while (auxiliar != NULL)
    {
        contador++;
        auxiliar = auxiliar->proximo;
    }
    return contador;
}

Lista buscaLista(Lista lista, int elemento)
{
    Lista auxiliar;
    auxiliar = lista;
    while ((auxiliar != NULL) && (auxiliar->dado != elemento))
    {
        auxiliar = auxiliar->proximo;
    }
    return (auxiliar);
}

Lista insereLista(Lista lista, int elemento)
{
    Lista novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = elemento;
    novo->proximo = lista;
    return (novo);
}

Lista retiraLista(Lista lista, int elemento)
{
    Lista elementoAtual,
        elementoAnterior;
    elementoAnterior = lista;
    elementoAtual = lista;

    while ((elementoAtual != NULL) && (elementoAtual->dado != elemento))
    {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }
    if (elementoAtual != NULL)
    {
        if (elementoAtual == elementoAnterior)
        {
            lista = elementoAtual->proximo;
            free(elementoAtual);
        }
        else
        {
            elementoAnterior->proximo = elementoAtual->proximo;
            free(elementoAtual);
        }
    }
    return (lista);
}

int main()
{
    Lista lista;
    lista = criaLista();
    return 0;
}