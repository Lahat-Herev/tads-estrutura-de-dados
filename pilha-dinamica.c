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

typedef struct elemento *Pilha;

Pilha criaPilha()
{
    return NULL;
}

int pilhaVazia(Pilha pilha)
{
    if (pilha == NULL)
        return (TRUE);
    else
        return (FALSE);
}

void imprimePilha(Pilha pilha)
{
    Pilha auxiliar;
    printf("\nItens da pilha\n");
    auxiliar = pilha;
    while (auxiliar != NULL)
    {
        printf("%d - ", auxiliar->dado);
        auxiliar = auxiliar->proximoRegistro;
    }
    printf("\n");
}

Pilha empilha(Pilha pilha, int elemento)
{
    Pilha novo;
    novo = malloc(sizeof(struct elemento));
    novo->dado = elemento;
    novo->proximoRegistro = pilha;
    return (novo);
}

Pilha desempilha(Pilha pilha, int *elemento)
{
    Pilha auxiliar;
    if (!pilhaVazia(pilha))
    {
        *elemento = pilha->dado;
        auxiliar = pilha;
        pilha = pilha->proximoRegistro;
        free(auxiliar);
    }
    else
    {
        *elemento = -1;
        printf("\nPilha Vazia");
    }
    return (pilha);
}

void menu()
{
    printf("\nDigite o numero equivalente ao que deseja fazer: \n");
    printf("\n1 - Empilhar um elemento\n");
    printf("\n2 - Desempilhar um elemento \n");
    printf("\n3 - Mostrar todos os elementos da pilha \n");
    printf("\n4 - Sair \n");
}

int main()
{
    Pilha pilha;
    int item = 0;
    int valor;
    int opcao;
    pilha = criaPilha();
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
            pilha = empilha(pilha, valor);
            break;

        case 2:
            pilha = desempilha(pilha, &item);
            break;

        case 3:
            imprimePilha(pilha);
            break;

        default:
            break;
        }
    }

    return 0;
}