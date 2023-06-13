#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para uso do sleep(5);
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[250] = "Junior";
    int idade = 25;
    int opcao;

    do {
        printf("1 - Mostrar nome: \n");
        printf("2 - Mostrar idade: \n");
        printf("3 - Mostrar nome e idade: \n");
        printf("0 - Sair do programa: \n");

        printf("Informe a opção desejada :");
        scanf("%d", &opcao);


        switch (opcao) {
        case 1:
            printf("Nome: %s \n", nome);
            break;
        case 2:
            printf("Idade: %d \n", idade);
            break;
        case 3:
            printf("Nome: %s \n", nome);
            printf("Idade: %d \n", idade);
            break;
        case 0:
            printf("Saindo do programa... \n");
            break;
        default:
            printf("Opção incorreta.\n");
        }

        sleep(5); // Espera 5 segundos.
        system("cls"); // Limpa a tela.

    } while (opcao != 0);

    return 0;
}