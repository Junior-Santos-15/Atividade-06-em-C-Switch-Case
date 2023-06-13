#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void mostrarSituacao(char disciplinas[][250], float media[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%iª disciplina: %s \n", i + 1, disciplinas[i]);

        if (media[i] >= 7) {
           printf("Situação: Aprovado. \n\n");
        } else if (media[i] >= 5) {
           printf("Situação: Recuperação. \n\n");
        } else {
            printf("Situação: Reprovado. \n\n");
        }        
    }
}

void mostrarMedia(char disciplinas[][250], float media[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%iª disciplina: %s \n", i + 1, disciplinas[i]);
        printf("Media: %.1f \n\n", media[i]);
    }
}

void todasInformacoes(char disciplinas[][250], float media[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%iª disciplina: %s \n", i + 1, disciplinas[i]);

        if (media[i] >= 7) {
           printf("Situação: Aprovado. \n");
        } else if (media[i] >= 5) {
           printf("Situação: Recuperação. \n");
        } else {
            printf("Situação: Reprovado. \n");
        }      

        printf("Media: %.1f \n\n", media[i]);
    }
}

int main()
{
    // Aceitando caracteres com acento.
    setlocale(LC_ALL, "Portuguese");

    // Declarando variáveis.
    char disciplinas[3][250];
    float notas[3][2], media[3], somaNotas;
    int i, j, opcao;

    // Solicitando notas ao usuário.
    for (i = 0; i < 3; i++)
    {
        printf("Digite a %dª disciplina: ", i + 1);
        gets(disciplinas[i]);
        fflush(stdin);

        for (j = 0; j < 2; j++)
        {
            do // Repetindo comando se a nota informada é menor que 0 ou maior que 10.
            {
                printf("Digite a %dª nota: ", j + 1);
                scanf("%f", &notas[i][j]);

            } while (notas[i][j] < 0 || notas[i][j] > 10);
           
            somaNotas += notas[i][j];
        }

        media[i] = somaNotas / j;
        somaNotas = 0;
        fflush(stdin);
        printf("\n");
    }

    system("cls"); // Limpa tela.

    // Exibindo menu.
    do {
        printf("1 - Mostrar nome da disciplina e media: \n");
        printf("2 - Mostrar o nome da disciplina e situação (Aprovado - Reprovado ou Recuperação): \n");
        printf("3 - Exibir todas as informações: \n");
        printf("0 - Sair do programa: \n");

        printf("Informe a opção desejada: ");
        scanf("%d", &opcao);

        printf("\n");

        // Exibindo notas e média para o usuário.
        switch (opcao) {
        case 1:
            mostrarMedia(disciplinas, media);
            break;
        case 2:
            mostrarSituacao(disciplinas, media);
            break;
        case 3:
            todasInformacoes(disciplinas, media);
            break;
        case 0:
            printf("Saindo do programa... \n");
            break;
        default:
            printf("Opção incorreta.\n");
            break;
        }

        sleep(5); // Esperando 5 segundo antes do próximo comando.
        system("cls"); // Limpa o terminal do Windows.
    } while (opcao != 0); // Enquanto a opção for diferente de 0, ocorrerá o laço.

    return 0;
}