#include <stdio.h>

void menu();

int diferencaNumeros(int firstNumber, int secondNumber)
{
    return (firstNumber - secondNumber);
}

float divisaoNumeros(int firstNumber, int secondNumber)
{
    if (secondNumber == 0) return -1.00;
    return (firstNumber / secondNumber);
}

int produtoNumeros(int firstNumber, int secondNumber)
{
    return (firstNumber * secondNumber);
}    


int somaNumeros(int firstNumber, int secondNumber)
{
    return (firstNumber + secondNumber);
}

int calcula(int firstNumber, int secondNumber, char operation)
{
    int result;
    switch (operation)
    {
    case '+':
        result = somaNumeros(firstNumber, secondNumber);
        break;

    case '*':
        result = produtoNumeros(firstNumber, secondNumber);
        break;
    
    case '-': 
        result = diferencaNumeros(firstNumber, secondNumber);
        break;

    case '/': 
        result = divisaoNumeros(firstNumber, secondNumber);
    
    default:
        printf("Esse caractere nao aponta para nenhuma funcao!");
        break;
    }

    return result;
}


void menu()
{
    printf("Digite um dos seguintes caracteres para realizar a sua respectiva operacao: \n");
    printf("+ para somar \n");
    printf("- para subtrair \n");
    printf("* para multiplicar \n");
    printf("/ para dividir \n");
}


int main()
{
    int numberOne, numberTwo;
    char operation;
    printf("Number one: \n");
    scanf("%d", &numberOne);
    printf("Number two: \n");
    scanf("%d", &numberTwo);
    menu();
    fflush(stdin);
    scanf(" %c", &operation);
    printf("Resultado %d", calcula(numberOne, numberTwo, operation));

    return 0;
}