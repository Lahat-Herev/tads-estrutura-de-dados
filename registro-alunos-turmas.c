#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno
{
    char nome[40];
    char situacao[20];
    int matricula;
    int faltas;
    double prova1;
    double prova2;
    double media;
};

struct Turma
{
    struct Aluno aluno[40];
    int contagem;
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

struct Aluno cadastrarAluno()
{
    struct Aluno aluno;
    char buffer[100];

    printf("Informe o nome do aluno: ");
    scanf("%s", aluno.nome);
    lerPalavra(aluno.nome, sizeof(aluno.nome));

    printf("\nInforme a matricula do aluno: ");
    lerPalavra(buffer, sizeof(buffer));
    sscanf(buffer, "%d", &aluno.matricula);

    printf("\nInforme a quantidade de faltas do aluno: ");
    lerPalavra(buffer, sizeof(buffer));
    sscanf(buffer, "%d", &aluno.faltas);

    printf("\nInforme a 1 prova do aluno: ");
    lerPalavra(buffer, sizeof(buffer));
    sscanf(buffer, "%lf", &aluno.prova1);

    printf("\nInforme a 2 nota do aluno: ");
    lerPalavra(buffer, sizeof(buffer));
    sscanf(buffer, "%lf", &aluno.prova2);

    aluno.media = (aluno.prova1 + aluno.prova2) / 2;
    if (aluno.media >= 6 && aluno.faltas <= 20)
    {
        strcpy(aluno.situacao, "Aprovado");
    }
    else
    {
        strcpy(aluno.situacao, "Reprovado");
    }

    return aluno;
}

int salvarCadastroNoArquivo(int iterador)
{
    FILE *arquivo;
    arquivo = fopen("turma.txt", "a");

    if (arquivo == NULL)
    {
        fprintf(stderr, "\nErro ao abrir arquivo turma.txt");
        return (1);
    }
    else
    {
        fwrite(&turma.aluno[0], sizeof(struct Aluno), iterador, arquivo);
        fclose(arquivo);
    }

    return 0;
}

int visualizarAlunosCadastradosNaTurma()
{
    char buffer[100];
    char continua;
    int i = 0;

    do
    {
        turma.aluno[i] = cadastrarAluno();
        printf("\nJá foram lidos %d alunos. Deseja continuar (s/n):", i + 1);
        lerPalavra(buffer, sizeof(buffer));
        continua = buffer[0];
        i++;
    } while ((continua == 's') && (i < 40));

    return i;
}

int carregarDadosDoArquivo()
{
    FILE *arquivo;
    int j, lido;

    arquivo = fopen("turma.txt", "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "\nErro ao abrir arquivo arquivo.txt");
        return (-1);
    }
    else
    {
        j = 0;
        do
        {
            lido = fread(&turma.aluno[j], sizeof(struct Aluno), 1, arquivo);
            j++;
        } while (lido == 1);
        fclose(arquivo);
    }
    return (j - 1);
}

void visualizarDadosDeTodosOsAlunos(int i)
{
    int j;

    for (j = 0; j < i; j++)
    {
        printf("\nMatricula(%d) - Nome(%s) - Faltas(%d) - Media (%lf) - Situacao: (%s)",
               turma.aluno[j].matricula,
               turma.aluno[j].nome,
               turma.aluno[j].faltas,
               turma.aluno[j].media,
               turma.aluno[j].situacao);
    }
}

void menu()
{
    printf("O que gostaria de fazer?");
    printf("\n1 - Inserir alunos");
    printf("\n2 - Listar alunos");
    printf("\n3 - Salvar dados no arquivo");
    printf("\n4 - Carregar dados do arquivo");
    printf("\n5 - Sair\n");
}

int main()
{
    int numeroAlunos, codigo, opcao;

    numeroAlunos = 0;
    do
    {
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            numeroAlunos = visualizarAlunosCadastradosNaTurma();
            break;
        case 2:
            visualizarDadosDeTodosOsAlunos(numeroAlunos);
            break;
        case 3:
            codigo = salvarCadastroNoArquivo(numeroAlunos);
            if (codigo == 0)
                printf("\nCadastro salvo com sucesso");
            break;
        case 4:
            carregarDadosDoArquivo();
            break;
        }
    } while ((opcao > 0) && (opcao < 5));
    return codigo;
}

/**
 * @brief
 * leString - lerPalavra
 * tiraf - tirarEspaco
 * leAluno - cadastrarAluno
 * salvaCadastro - salvarCadastroNoArquivo
 * leCadastro - visualizarAlunosCadastradosNaTurma
 * carregaCadastro - carregarDadosDoArquivo
 * listaCadastro - visualizarDadosDeTodosOsAlunos
 */