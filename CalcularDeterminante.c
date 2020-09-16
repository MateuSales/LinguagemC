//JOSE MATEUS SALES LIMA - ENGENHARIA DE COMPUTACAO 2020.1
//EXIBIR MATRIZ E CALCULAR DETERMINANTE

#include <stdio.h>
#include <windows.h>

int matriz[3][3]; //Variavel Global, para ser acessada por todo o programa.

int main()
{
    int linhas=3, colunas=3, i, j, det, escolha;
    printf("\nSeja bem vindo(a) ao Menu Inicial\n\n");

    do{
    printf("________________________________\n");
    printf("\n");
    printf("         MENU PRINCIPAL         \n");
    printf("________________________________\n\n");
    printf("Escolha a opcao desejada:\n\n");
    printf("1) Inicializar Matriz\n");
    printf("2) Exibir Matriz\n");
    printf("3) Calcular Determinante\n");
    printf("4) Sair do Programa\n\n");
    scanf("%d", &escolha);

    if(escolha < 1 || escolha > 4){
        system ("cls");
        printf("\n---------- Entrada Invalida! ----------\n");
        printf("Certifique-se de digitar uma opcao valida!\n\n");

    } else {

    switch(escolha){

    case 1:
        do{
        system ("cls");
        printf("\nDigite o numero de linhas da Matriz: ");
        scanf("%d", &linhas);
        printf("Digite o numero de colunas da Matriz: ");
        scanf("%d", &colunas);

            if(linhas < 1 || colunas < 1){
                printf("\n---------- Entrada Invalida! ----------\n");
                printf("Uma matriz nao possui o numero de linhas e nem de colunas menores que 1!\n");
            }
                }while(linhas < 1 || colunas <1);

            printf("\nDigite os elementos da Matriz 1: \n");
            for(i=0;i<linhas;i++){
                for(j=0;j<colunas;j++){
                    printf("Digite o elemento A[%d][%d] da Matriz: ", i+1,j+1);
                    scanf("%d", &matriz[i][j]);
                    }
            }
            printf("\n");
    break;
    case 2:
        system ("cls");
        printf("Matriz\n\n");
        for(i=0;i<linhas;i++){
            for(j=0;j<colunas;j++){
                det = matriz[0][0];
                printf("(%d)",matriz[i][j]);
                }
            printf("\n");
        }
        printf("\n");
    break;
    case 3:
        system ("cls");
        if(linhas!=colunas){
            printf("\nImpossivel realizar operacao!\n");
            printf("O calculo de determinante e uma propriedade das Matrizes Quadradas!\n\n");
        }

        else if(linhas > 3 || colunas > 3){
            printf("\nCalculamos apenas determinante de Matrizes de ordem 3, 2 e 1.\n\n");
        }

        else if(linhas==1 && colunas==1){
            det = matriz[0][0];
            printf("\nDeterminante: (%d)\n\n", det);
        }

        else if(linhas==2 && colunas==2){
            det = (matriz[0][0]*matriz[1][1])-(matriz[0][1]*matriz[1][0]);
            printf("\nDeterminante: (%d)\n\n", det);
        }

        else if(linhas==3 && colunas==3){
            det = (matriz[0][0]*matriz[1][1]*matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0]) + (matriz[0][2]*matriz[1][0]*matriz[2][1]) - ((matriz[0][2]*matriz[1][1]*matriz[2][0]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]));
            printf("\nDeterminante: (%d)\n\n", det);
        }
        break;
        }
    }
    }while(escolha!=4);

    printf("-----------------------------\n");
    printf("Programa fechado com Sucesso!\n");
    printf("-----------------------------\n");


    return 0;
  }
