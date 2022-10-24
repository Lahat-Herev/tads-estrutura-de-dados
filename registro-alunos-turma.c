#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[40];
    char situacao[20];
    int faltas;
    int matricula;
    double media;
    double prova1;
    double prova2;
};

struct Turma
{
    struct Aluno aluno[40];
} turma;

void tirarEspaco(char *palavra)
{
    palavra[strlen(palavra) - 1] = '\0';
}

void lerPalavra(char *palavra, int tamanho)
{
    fgets(palavra, tamanho, stdin);
    tirarEspaco(palavra);
}

void cadastrarAluno(int quantidadeAlunos)
{
    if (quantidadeAlunos > 40)
        return;
    char buffer[100];
    for (int iterador = 0; iterador < quantidadeAlunos; iterador++)
    {
        printf("Informe o nome do aluno: ");
        scanf("%s", turma.aluno[iterador].nome);
        lerPalavra(turma.aluno[iterador].nome, sizeof(turma.aluno[iterador].nome));

        printf("\nInforme a matricula do aluno: ");
        lerPalavra(buffer, sizeof(buffer));
        sscanf(buffer, "%d", &turma.aluno[iterador].matricula);

        printf("\nInforme a quantidade de faltas do aluno: ");
        lerPalavra(buffer, sizeof(buffer));
        sscanf(buffer, "%d", &turma.aluno[iterador].faltas);

        printf("\nInforme a 1 prova do aluno: ");
        lerPalavra(buffer, sizeof(buffer));
        sscanf(buffer, "%lf", &turma.aluno[iterador].prova1);

        printf("\nInforme a 2 nota do aluno: ");
        lerPalavra(buffer, sizeof(buffer));
        sscanf(buffer, "%lf", &turma.aluno[iterador].prova2);

        turma.aluno[iterador].media = (turma.aluno[iterador].prova1 + turma.aluno[iterador].prova2) / 2;
        if (turma.aluno[iterador].media >= 6 && turma.aluno[iterador].faltas <= 20)
        {
            strcpy(turma.aluno[iterador].situacao, "Aprovado");
        }
        else
        {
            strcpy(turma.aluno[iterador].situacao, "Reprovado");
        }
    }
}

void editarAluno(int quantidadeAlunos, int matricula)
{
    char dado[15];
    int posicao = -1;
    int sair = 1;
    for (int i = 0; i < quantidadeAlunos; i++)
    {
        if (matricula == turma.aluno[i].matricula)
        {
            posicao = i;
        }
    }
    if (posicao != -1)
    {
        while (sair == 1)
        {
            printf("Digite o dado que deseja alterar: \n");
            printf("1 - Nome\n");
            printf("2 - Faltas\n");
            printf("3 - Situacao\n");
            printf("4 - Prova 1\n");
            printf("5 - Prova 2\n");
            scanf("%s", dado);
            if (strcmp("1", dado) == 0)
            {
                char nome[40];
                printf("Digite o nome: \n");
                scanf("%s", nome);
                strcpy(nome, turma.aluno[posicao].nome);
            }
            if (strcmp("2", dado) == 0)
            {
                int faltas;
                printf("\nDigite o quantidade de faltas: \n");
                scanf("%d", faltas);
                strcpy(faltas, turma.aluno[posicao].faltas);
            }
            if (strcmp("3", dado) == 0)
            {
                char situacao[20];
                printf("\nDigite a situação [Aprovado ou Reprovado]: \n");
                scanf("%s", situacao);
                strcpy(situacao, turma.aluno[posicao].situacao);
            }
            if (strcmp("4", dado) == 0)
            {
                double prova1;
                printf("\nDigite a nota da primeira prova: \n");
                scanf("%lf", &prova1);
                turma.aluno[posicao].prova1 = prova1;
            }
            if (strcmp("5", dado) == 0)
            {
                double prova2;
                printf("\nDigite a nota da segunda prova: \n");
                scanf("%lf", &prova2);
                turma.aluno[posicao].prova2 = prova2;
            }
        }
    }
}

void menu()
{
    printf("\nDigite o numero equivalente ao que deseja fazer: \n");
    printf("1 - Cadastrar aluno(s)\n");
    printf("\n2 - Alterar os dados de uma pessoa \n");
    printf("\n3 - Excluir uma pessoa \n");
    printf("\n4 - Mostrar os dados de apenas uma pessoa \n");
    printf("\n5 - Mostrar os dados de todas as pessoas \n");
}

int main()
{
    int operacao;
    int matricula;
    int quantidadeAlunos;

    printf("Digite a quantidade de pessoas: \n");
    scanf("%d", &quantidadeAlunos);

    menu();

    scanf("%d", &operacao);
    do
    {
        switch (operacao)
        {
        case 1:
            cadastrarAluno(quantidadeAlunos);
            break;
        case 2:
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matricula);
            editarAluno(quantidadeAlunos, matricula);
            break;
        case 3:
            excluirAluno();
            break;
        case 4:
            mostrarAluno();
            break;
        case 5:
            mostrarTodosOsAlunos();
            break;

        default:
            printf("Essa opção não existe.");
            break;
        }
    } while ((operacao > 0) && (operacao < 6));

    return 0;
}
