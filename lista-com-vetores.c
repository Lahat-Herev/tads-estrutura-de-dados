#include <stdio.h>
#include <string.h>

#define MaxItens 10
#define TamItem 20

typedef char Lista[MaxItens][TamItem];

void criaLista(Lista l)
{
    int i;
    for (i=0;i<MaxItens;i++)
    l[i][0] = '\0';
}

void imprimeLista(Lista l)
{
    int i;
    printf("\nItens da lista\n");
    for(i=0; i<MaxItens && strlen(l[i])>0; i++)
    printf("\n%s",l[i]);
    printf("\n");
}

int contaLista(Lista l)
{
    int i;
    for (i = 0; i<MaxItens && strlen(l[i])>0; i++);
    return(i);
}

void insereLista(Lista l, char *item)
{
    int i;
    for(i=0; i<MaxItens && strlen(l[i])>0; i++);

    if (i<MaxItens)
    {
        strcpy(l[i],item); 
        printf("\nItem (%s) inserido com sucesso",item);
    }
    else 
        printf("\nLista cheia, não pode inserir");
}

void retiraLista(Lista l, char *item)
{
    int i;

    for(i=0; i<MaxItens && strlen(l[i])>0 && (strcmp(l[i],item) != 0); i++);
    if (i<MaxItens && (strcmp(l[i],item) == 0))
    { 
        printf("\nItem (%s) encontrado, removendo",item);
        if (i < (MaxItens-1))
        { 
            for (;i<(MaxItens-1) && strlen(l[i])>0;i++)
            strcpy(l[i],l[i+1]);
        }
            l[MaxItens-1][0] = '\0';
    }
    else 
        printf("\nItem (%s) não encontrado",item);
}

void menu()
{
    printf("\nDigite o numero equivalente ao que deseja fazer: \n");
    printf("1 - Inserir elemento\n");
    printf("\n2 - Retirar elemento \n");
    printf("\n3 - Criar lista \n");
    printf("\n4 - Contar elementos da lista \n");
    printf("\n5 - Exibir o conteúdo da lista \n");
}   


int main()
{
    menu();
    int operacao;
    char elemento[20];
    scanf("%d", &operacao);
    Lista l;
    do
    {
        switch (operacao)
        {
        case 1:
            insereLista(l, elemento);
            break;
        case 2:
            retiraLista(l, elemento);
            break;
        case 3:
            criaLista(l);
            break;
        case 4:
            contaLista(l);
            break;
        case 5:
            imprimeLista(l);
            break;

        default:
            printf("Essa opção não existe.");
            break;
        }
    } while ((operacao > 0) && (operacao < 6));
    return 0;
}