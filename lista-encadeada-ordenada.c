#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Lista anterior, proximo, novo;
    anterior = lista;
    novo = malloc(sizeof(struct elemento));
    novo->dado = elemento;
    proximo = lista;
    while ((proximo != NULL) && (elemento > proximo->dado))
    {
        anterior = proximo;
        proximo = proximo->proximo;
    }
    if (proximo != anterior)
    {
        anterior->proximo = novo;
    }
    else
    {
        lista = novo;
    }
    novo->proximo = proximo;
    return (lista);
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

void menu()
{
    printf("\nDigite o numero equivalente ao que deseja fazer: \n");
    printf("\n1 - Inserir elemento\n");
    printf("\n2 - Retirar elemento \n");
    printf("\n3 - Buscar elemento na lista \n");
    printf("\n4 - Exibir o conteúdo da lista \n");
    printf("\n5 - Contar elementos da lista \n");
}

int main()
{
    int elemento;
    int operacao;
    Lista lista;
    Lista auxiliar;
    lista = criaLista();
    do
    {
        menu();
        scanf("%d", &operacao);
        fflush(stdin);
        switch (operacao)
        {
        case 1:
            printf("Entre com o item: ");
            scanf("%d", &elemento);
            lista = insereLista(lista, elemento);
            break;
        case 2:
            printf("Digite o item que gostaria de remover: ");
            scanf("%d", &elemento);
            lista = retiraLista(lista, elemento);
            break;
        case 3:
            printf("Digite o item que gostaria de buscar na lista: ");
            scanf("%d", &elemento);
            auxiliar = buscaLista(lista, elemento);
            if (auxiliar == NULL)
            {
                printf("Nao existe. \n");
            }
            printf("Elemento %d encontrado. \n", elemento);
            break;
        case 4:
            imprimeLista(lista);
            break;
        case 5:
            printf("A lista tem %d elementos", contaLista(lista));
            break;
        default:
            printf("Essa opção não existe.");
            break;
        }
    } while ((operacao > 0) && (operacao < 6));
    return 0;
}