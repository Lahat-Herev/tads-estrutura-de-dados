#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct elemento
{
    int dado;
    struct elemento *proximoRegistro;
};

typedef struct elemento *ApontaParaElemento;

typedef struct
{
    ApontaParaElemento inicio;
    ApontaParaElemento fim;
} Fila;

Fila criaFila()
{
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    return (fila);
}

int filaVazia(Fila fila)
{
    if (fila.inicio == NULL)
        return (TRUE);
    else
        return (FALSE);
}

void imprimeFila(Fila fila)
{
    ApontaParaElemento elementoApontado;
    printf("\nItens da lista\n");
    elementoApontado = fila.inicio;
    while (elementoApontado != NULL)
    {
        printf("%d - ", elementoApontado->dado);
        elementoApontado = elementoApontado->proximoRegistro;
    }
    printf("\n");
}

Fila insereFila(Fila fila, int elemento)
{
    ApontaParaElemento novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = elemento;
    novo->proximoRegistro = NULL;
    if (filaVazia(fila))
    {
        fila.inicio = novo;
        fila.fim = novo;
    }
    else
    {
        fila.fim->proximoRegistro = novo;
        fila.fim = novo;
    }
    return (fila);
}

Fila retiraFila(Fila fila, int *elemento)
{
    ApontaParaElemento elementoApontado;
    if (!filaVazia(fila))
    {
        *elemento = fila.inicio->dado;
        elementoApontado = fila.inicio;
        fila.inicio = fila.inicio->proximoRegistro;
        free(elementoApontado);
        if (filaVazia(fila))
            fila.fim = NULL;
    }
    else
    {
        *elemento = -1;
        printf("\nFila Vazia");
    }
    return (fila);
}

void menu()
{
    printf("\nDigite o numero equivalente ao que deseja fazer: \n");
    printf("\n1 - Inserir um elemento no final da fila\n");
    printf("\n2 - Retirar um elemento do início da fila \n");
    printf("\n3 - Imprimir o conteúdo da fila. \n");
    printf("\n4 - Sair \n");
}

int main(int argc, char const *argv[])
{
    Fila fila;
    int opcao;
    int valor;
    fila = criaFila();
    while (opcao != 4)
    {
        menu();
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor para empilhá-lo na pilha: ");
            scanf("%d", &valor);
            fila = insereFila(fila, valor);
            break;

        case 2:
            fila = retiraFila(fila, &valor);
            break;

        case 3:
            imprimeFila(fila);
            break;

        default:
            break;
        }
    }
    return 0;
}
