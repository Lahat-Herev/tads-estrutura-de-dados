#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TAluno
{
    char nome[40];
    char situacao[20];
    int matricula; 
    int faltas;
    double prova1;
    double prova2;
}

struct TTurma
{
    struct TAluno aluno[40];
}

int main()
{
    FILE *arquivo;
    arquivo = fopen("turma.txt", "w");
    
    if(arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
}