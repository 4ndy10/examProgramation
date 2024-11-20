#include <stdio.h>
#include <cs50.h>

int par(int num);
int impar(int num);
void MostrarPares(int start, int end);
void MostrarImpares(int start, int end);
void MostrarAmbos(int start, int end);
void Opciones(int start, int end);
void Rango(int *start, int *end);
int repetir();

int main()
{
    int start, end;
    int repeat;

    do {
        Rango(&start, &end);

        Opciones(start, end);

        repeat = repetir();
    } while (repeat);

    printf("Gracias por todo lo que hace por nosotros profe, lo queremos!\n");
}

int par(int num)
{
    return num % 2 == 0;
}

int impar(int num)
{
    return num % 2 != 0;
}

void MostrarPares(int start, int end)
{
    int sum = 0;
    printf("Numeros pares en el rango: ");

    for (int i = start; i <= end; i++)
    {
        if(par(i))
        {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\n");
    printf("Suma de numeros pares: %d\n", sum);
}

void MostrarImpares(int start, int end) {
    int sum = 0;
    printf("Numeros impares en el rango: ");
    for (int i = start; i <= end; i++) {
        if (impar(i)) {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\n");
    printf("Suma de numeros impares: %d\n", sum);
}

void MostrarAmbos(int start, int end)
{
    int sum = 0;

    for (int i = start; i <= end; i++)
    {
        if(par(i))
        {
            sum += i;
        }
    }
    for (int i = start; i <= end; i++) {
        if (impar(i))
        {
            sum += i;
        }
    }
    printf("\n");
    printf("Suma de numeros pares e impares: %d\n", sum);
}

void Opciones(int start, int end) {
    int option;

    printf("Elige una de las siguientes opciones:\n");
    printf("1. Muestra todos los numeros pares en el rango y calcúla la suma.\n");
    printf("2. Muestra todos los numeros impares en el rango y calcúla la suma.\n");
    printf("3. Muestra todos los numeros pares e impares y calcúla la suma.\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            MostrarPares(start, end);
            break;
        case 2:
            MostrarImpares(start, end);
            break;
        case 3:
            MostrarPares(start, end);
            MostrarImpares(start, end);
            MostrarAmbos(start, end);
            break;
        default:
            printf("Opción invalida! Intentalo otra vez.\n");
            Opciones(start, end);
            break;
    }
}

void Rango(int *start, int *end) {
    do {
        printf("Ingresa el primer valor del rango: ");
        scanf("%d", start);
        printf("Ingresa el valor final del rango: ");
        scanf("%d", end);

        if (*start > *end) {
            printf("Rango no válido, intenta otra vez.\n");
        }
    } while (*start > *end);
}

int repetir() {
    char respuesta = get_char("Quieres volver a empezar? (y/n): ");

    if (respuesta == 'y' || respuesta == 'Y') {
        return 1;
    } else {
        return 0;
    }
}
