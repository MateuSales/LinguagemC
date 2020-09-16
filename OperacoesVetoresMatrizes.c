#include <stdio.h>
#include <stdlib.h>
/*--------------------------------------------
UECE - Universidade Estadual do Ceará
Centro de Ciências e Tecnologia
Disciplina: Introdução a Ciência da Comptação
Semestre: 2015.1  Data: 31/08/2015

Autores do Projeto:
José Mateus Sales Lima
Levy Gurgel Chaves
Artur Melo Catunda
Professor Orientador: Leonardo Rocha
----------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------
Protótipos de Todas as funções usadas no Programa. Representa o mapa das funções, pois as mesmas estão dispostas no programa na
mesma ordem que se encontram abaixo, alem de facilitar a operação realizada pelo compilador, e este cabeçalho ajuda bastante na
processo de criação do makefile.
------------------------------------------------------------------------------------------------------------------------------*/
void mostrar_vetor(int espaco, int *vetor);
void ler_vetor(int espaco, int *vetor);
void soma_vetores(int espaco1, int espaco2, int *vetor1, int *vetor2);
void multiplicar_por_escalar(int escalar, int espaco, int *vetor);
void produto_vetorial(int espaco1, int espaco2, int *vetor1, int *vetor2);
void produto_escalar(int espaco1, int espaco2, int *vetor1, int *vetor2);
void ler_matriz(int linhas, int colunas, int **matriz);
void mostrar_matriz(int linhas, int colunas, int **matriz);
void soma_matrizes(int linhas1,int colunas1,int linhas2,int colunas2, int **matriz1, int **matriz2);
void matriz_transposta(int linhas,int colunas, int **matriz1, int **mat_trans);
void multi_matriz(int linhas1,int colunas1, int linhas2, int colunas2,int **result, int **matriz1, int **matriz2);
void determinante_matriz(int linhas, int colunas, int **matriz1);
void verificacao_simetrico(int linhas,int colunas, int **matriz1);
void menu_operacoes_com_vetores();
void menu_operacoes_com_matrizes();

/*----------------------------------------------------------------------------------------------------------------------------------------------
Obs.: Todas as funções do programa estão modularizadas, ou seja, se prescisarmos de alguma destas funções em algum programa futuro, poderemos
apenas copiá-las e fornecê-las os parametros corretos para que ela funcione com corretude.
-----------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------
Esta é a nossa função "Main", a primeira função a ser executada pelo compilador, deixamos ela bem enxuta, com um menu simples,
criado com o switch, este menu irá direcionar o usuário para outras funções. Estas estão dispostas no final do código, como você
pode observar no cabeçalho.
E no final do programa deixamos uma mensagem para o usuário saber que o programa foi encerrado. Vale ressaltar que se o
usuário digitar uma opção que não tenha nehuma ligação com o menu, ele receberá uma mensagem de erro. Utilizamos um do-while
para que o usuário tenha uma nova chance de digitar outra opção em caso de erro. Prezamos pela simplicidade, e com a combinação de
 alguns elementos e os famosos "printf's" tentamos deixar o nosso programa bem interativo.
------------------------------------------------------------------------------------------------------------------------------*/
int main(){
    int escolha;

    printf("\nSeja bem vindo(a) ao nosso Menu Inicial\n\n");
    do{
    printf("________________________________\n");
    printf("\n");
    printf("         MENU PRINCIPAL         \n");
    printf("________________________________\n\n");
    printf("Escolha a opcao desejada:\n\n");
    printf("1) Operacoes com Vetores\n");
    printf("2) Operacoes com Matrizes\n");
    printf("3) Sair do Programa\n\n");
    scanf("%d", &escolha);

    if(escolha < 1 || escolha > 3){
        printf("\n---------- Entrada Invalida! ----------\n");
        printf("Certifique-se de digitar uma opcao valida!\n\n");

    } else {

    switch(escolha){

    case 1:
        menu_operacoes_com_vetores();
    break;
    case 2:
        menu_operacoes_com_matrizes();
    break;
      }

    }

    }while(escolha!=3);

    printf("-----------------------------\n");
    printf("Programa fechado com Sucesso!\n");
    printf("-----------------------------\n");

    return 0;
  }
/*------------------------------------------------------------------------------------------------------------------------------------
Esta função irá mostrar os valores armazenados no vetor, em outras palavras as coordenasdas dos vetores, faz o uso da estrutura "for",
e recebe como parametro o espaco e um vetor.
-------------------------------------------------------------------------------------------------------------------------------------*/
void mostrar_vetor(int espaco, int *vetor){
  int i;

  for(i=0;i<espaco;i++){
    printf("Coordenada %d: (%d)\n", i+1, vetor[i]);
  }
  printf("\n");
}

/*-----------------------------------------------------------------------------------------------------------------------------------------
Esta função vai ler valores digitados pelo usuário e guardar em posições diferentes do vetor criado pela função malloc,
esta função recebe como parametro um vetor, para que o compilador saiba onde os valores serão alocados, e recebe também,
o espaço(quem determina o tamanho), pois de acordo com o espaço digitado o compilador saberá quantas coordenadas solicitar de cada vetor.
É esta a função que vai permitir que o usuário atribua valores aos vetores. Já que por padrão eles serão inicializados com espaço = 3, e 
todas as suas coordenadas 0, isso de ambos os vetores.
--------------------------------------------------------------------------------------------------------------------------------------------*/
void ler_vetor(int espaco, int *vetor){
int i;

   for(i=0;i<espaco;i++){
    printf("Digite a coordenada %d: ", i+1);
    scanf("%d", &vetor[i]);
   }
   printf("\n");
}
/*------------------------------------------------------------------------------------------------------------------------------------------------
Obs.: Todas as funções que precisam dos dois vetores para realizar a operção têm uma condição inicial que verifica os espaços dos dois vetores 
(por isso "espaco1" e "espaco2"), se forem iguais a operação será realizada, se forem diferentes, retornará um erro, pois os dois vetores
devem estar no mesmo espaço para execução do cálculo. Inicialmente tinhamos fixado o espaço digitado na leitura do primeiro vetor, passando o mesmo 
como parametro para o segundo vetor, no entanto, observamos que seria interessante deixar que o usuário entrasse com espaços diferentes, pois ele
poderia calcular o produto escalar de dois vetores que situam-se em espaços totalmente distintos.
---------------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------------
Esta função vai somar os vetores termo a termo, por exemplo o elemento vetor1[0][0] + vetor2[0][0] (este é o exemplo para espaco = 1), e retornar
pro usuário as coordenadas do vetor resultante de acordo com o espaço fornecido. Receberá como parametro dois vetores. A quntidade de vezes que será
realizada tal operação, será determinada por "espaco1".
-------------------------------------------------------------------------------------------------------------------------------------------------*/
void soma_vetores(int espaco1, int espaco2, int *vetor1, int *vetor2){
    int i;

    if(espaco1!=espaco2){
      printf("\nEsta operacao so pode ser realizada com vetores que estao no mesmo espaco!\n\n");
      return;
    }

    printf("\n");
    printf("\nCoordenadas do Vetor Resultante: \n");
    for(i=0;i<espaco1;i++){
        printf("Coordenada %d: (%d)\n", i+1, (vetor1[i] + vetor2[i]));
    }
    printf("\n");
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------
Esta função vai pegar o "escalar" digitado e multiplicar ele por cada coordenada do vetor, e retornanar pro usuário as coordenasdas resultantes do vetor.
Foi pensando nesta função que implemantamos e criamos um espaço para o vetor1 e um espaço para o vetor2.
--------------------------------------------------------------------------------------------------------------------------------------------------------*/
void multiplicar_por_escalar(int escalar, int espaco, int *vetor){
  int i;

  printf("\nCoordenadas do Vetor Resultante:\n");
        for(i=0;i<espaco;i++){
          printf("Coordena %d: (%d)\n", i +1, escalar * vetor[i]);
    }
    printf("\n");
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------
Esta função vai multiplicar os vetores termo a termo, por exemplo o elemento vetor1[0][0] * vetor2[0][0], e retornar pro usuário as coordenadas do vetor
resultante de acordo com o espaço fornecido.
-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void produto_vetorial(int espaco1, int espaco2, int *vetor1, int *vetor2){
    int i;

    if(espaco1!=espaco2){
      printf("\nEsta operacao so pode ser realizada com vetores que estao no mesmo espaco!\n\n");
      return;
    }

    printf("\nCoordenadas do Vetor Resultante: \n");
    for(i=0;i<espaco1;i++){
        printf("Cordenada %d: (%d)\n", i+1, vetor1[i] * vetor2[i]);
    }
    printf("\n");
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------
Esta função vai multiplicar os vetores termo a termo, por exemplo o elemento vetor1[0][0] * vetor2[0][0], e retornar pro usuário a soma dos termos, de acordo com
o espaço fornecido. Uma das diferença desta função pra anterior é que esta retorna um escalar e a outra, retornava um vetor, com suas coordenadas.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void produto_escalar(int espaco1, int espaco2, int *vetor1, int *vetor2){
   int i, escalar=0;

   if(espaco1!=espaco2){
      printf("\nEsta operacao so pode ser realizada com vetores que estao no mesmo espaco!\n\n");
      return;
    }

     for(i=0;i<espaco1;i++){
            escalar = escalar + (vetor1[i]*vetor2[i]);
      }
   printf("\nEscalar: (%d)\n\n", escalar);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------
Esta função vai ler valores digitados pelo usuário e guardar em posições diferentes da matriz criada pela função malloc. Recebe como parametro numero de linhas,
colunas e a matriz que irá armazenar os valores.
----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ler_matriz(int linhas, int colunas, int **matriz){
    int i, j;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("Digite o elemento A[%d][%d] da Matriz: ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
Em nosso programa decidimos mostrar a Matriz digitada pelo usuário, e para isso criamos uma função para realizar tal tarefa, com isso o usuário visualizará a
matriz digitada e verificará a corretude da mesma.
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void mostrar_matriz(int linhas, int colunas, int **matriz){
    int i, j;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("%d ",matriz[i][j]);
                }
            printf("\n");
    }
    printf("\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
Função criada para somar termo a termo os elementos de duas Matrizes, com restrições em caso de erro por parte do usuário. E mostra a matriz resultante.
-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void soma_matrizes(int linhas1,int colunas1,int linhas2,int colunas2, int **matriz1, int **matriz2){
     int i,j;

       if(linhas1 != linhas2 || colunas1 != colunas2){
            printf("\nDigite matrizes de dimensoes iguais!\n");
            printf("Linhas da Matriz 1 = Linhas da Matriz 2.\n");
            printf("Colunas da Matriz 1 = Colunas da Matriz 2.\n");
            return;
       }
       else {
          printf("\n------------- Matriz Resultante -------------\n\n");
          for(i=0; i < linhas1 ;i++){
              for(j=0 ; j < colunas1 ;j++){
                   printf("%d  ",matriz1[i][j] + matriz2[i][j]);
                 }
             printf("\n");
         }
     }
     printf("\n");
}

/*----------------------------------------------------------------------------------------
Função que vai tranformar a matriz digitada pelo usuário em matriz simetrica e mostrá-la.
-----------------------------------------------------------------------------------------*/
void matriz_transposta(int linhas,int colunas, int **matriz1, int **mat_trans){
    int i,j;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            mat_trans[j][i] = matriz1[i][j];
            }
        }

    printf("\n--------- Matriz Transposta ---------\n\n");
    for(i=0;i<colunas;i++){
        for(j=0;j<linhas;j++){
            printf("%d  ", mat_trans[i][j]);
            }
            printf("\n");
         }
}

/*--------------------------------------------------------------------------------------------------------------------
Função que vai multiplicar duas matrizes e vai armazenar o resultado na matriz resultante, claro que tal operação será
realizada conforme as regras estabelicidas pelo calculo de multiplicação de matrizes.
---------------------------------------------------------------------------------------------------------------------*/
void multi_matriz(int linhas1,int colunas1, int linhas2, int colunas2,int **result, int **matriz1, int **matriz2){
  int i,j,k;

  if(colunas1!=linhas2){
    printf("\nImpossivel realizar operacao!\n");
    printf("Numero de linhas da Matriz 1 devem ser iguais ao numero de colunas da Matriz2!\n\n");
    return;
  }

  printf("\n------Matriz Resultante------\n\n");
  for(i=0;i<linhas1;i++){
    for(j=0;j<colunas2;j++){
      result[i][j]=0;
      for (k=0;k<colunas1;k++){
        result[i][j] += matriz1[i][k] * matriz2[k][j];
      }
      printf("%d ",result[i][j]);
    }
          printf("\n");
  }
}

/*---------------------------------------------------------------------------------------------------------------------------
Função que vai calcular o determinante de matrizes de ordem 1, 2 ou 3, uma função que possui restrições caso o usuário digite
valores que não condizam com o que se pede.
-----------------------------------------------------------------------------------------------------------------------------*/

void determinante_matriz(int linhas, int colunas, int **matriz1){
  int det;

  if(linhas!=colunas){
    printf("\nImpossivel realizar operacao!\n");
    printf("O calculo de determinante e uma propriedade das Matrizes Quadradas!\n\n");
    return;
  }

  else if(linhas > 3 || colunas > 3){
    printf("\nCalculamos apenas determinante de Matrizes de ordem 3, 2 e 1.\n\n");
    return;
  }

  else if(linhas==1 && colunas==1){
    det = matriz1[0][0];
    printf("\nDeterminante: (%d)\n\n", det);
  }

  else if(linhas==2 && colunas==2){
    det = (matriz1[0][0]*matriz1[1][1])-(matriz1[0][1]*matriz1[1][0]);
    printf("\nDeterminante: (%d)\n\n", det);
  }

  else if(linhas==3 && colunas==3){
    det = (matriz1[0][0]*matriz1[1][1]*matriz1[2][2]) + (matriz1[0][1]*matriz1[1][2]*matriz1[2][0]) + (matriz1[0][2]*matriz1[1][0]*matriz1[2][1]) - ((matriz1[0][2]*matriz1[1][1]*matriz1[2][0]) + (matriz1[0][0]*matriz1[1][2]*matriz1[2][1]) + (matriz1[0][1]*matriz1[1][0]*matriz1[2][2]));
    printf("\nDeterminante: (%d)\n\n", det);
  }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
Função que vai verificar se a Matriz digitada pelo usuário é Simétrica, em caso de positivaidade ela irá retornar "uma mensagem informando", e concluiremos que
ela é simétrica. No entanto, se a Matriz digitada não for simétrica a função irá retornar "outra mensagem informando", e concluiremos que é a matriz não será
simétrica. Possui uma condição inicial que verifica se a Matriz é quadrada, visto que a simetria é uma propriedade das matrizes simétricas.
--------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void verificacao_simetrico(int linhas,int colunas, int **matriz1){
  int i,j,aux;
  aux = 0;

  if(linhas!=colunas){
    printf("\nA simetria e uma propriedade das matrizes simetricas!\n");
    printf("Numero de linhas devem serem iguais aos de colunas.\n\n");
    return;
  }

  for(i=0;i<linhas;i++){
    for(j=0;j<colunas;j++){
      if(matriz1[i][j] == matriz1[j][i])
        aux++;
      }
    }

  if(aux == linhas*colunas){
    printf("\nsimetrica!\n\n");
  }

  else {
    printf("\nNao simetrica!\n\n");
  }
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
Criamos esta função para organizar o programa, e deixar a função "main" mais enxuta, se na "main" o usuário selecionar a opção: Operações com Vetores,
ele será redirecionado para esta função, que irá direcionar ele para casos especificos de acordo com a opção escolhida. Cada caso irá, proporcionar opçãos
distintas que o usuário irá escolher de acordo com sua necessidade.
Para criar nossos "Menu's" utilizamos o comando "switch", com seus respectivos casos, e utilizamos o comando "if" para restringir o usuário a opções válidas.
Usamos também o comando do-while, que nos possibilitou a repetição de uma sequência de comandos até que a condição estabelecida dentro do while fosse falsa.
É este comando o responsável pelo retorno a menus anteriores e pelo fechamento do programa. No inicio do programa depois da declaração das variáveis, inicializamos
os vetores com a função malloc, onde ambos os espaços correspondem a 3 e as coordenadas dos dois são preenchidas com valor 0. Nos dois primeiros casos, damos
ao usuário a opção de inicializar vetor1 e vetor2, respectivamente, para que possa atribuir o espaço desejado assim como as coordenadas dos vetores. 
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void menu_operacoes_com_vetores(){
    int escolha, espaco1=3, espaco2=3, escalar, sub_escolha, i;
    int *vetor1;
    int *vetor2;

    vetor1 = (int *)malloc(espaco1*sizeof(int));
    vetor2 = (int *)malloc(espaco2*sizeof(int));

    for(i=0;i<espaco1;i++){
      vetor1[i] = 0;
      vetor2[i] = 0;
    }

    do{
        printf("________________________________\n");
        printf("\n");
        printf("      OPERACOES COM VETORES     \n");
        printf("________________________________\n\n");
        printf("1) Inicializar Vetor 1\n");
        printf("2) Inicializar Vetor 2\n");
        printf("3) Somar dois Vetores\n");
        printf("4) Multiplicar um vetor por um escalar\n");
        printf("5) Realizar o produto vetorial entre dois vetores\n");
        printf("6) Realizar o produto escalar entre dois vetores\n");
        printf("7) Exibir Vetores\n");
        printf("8) Voltar ao menu anterior\n\n");
        scanf("%d", &escolha);

        if(escolha < 1 || escolha > 8){
            printf("\n---------- Entrada Invalida! ----------\n");
            printf("Certifique-se de digitar uma opcao valida!\n\n");

         } else {
          switch(escolha){
            case 1:
              do{
              printf("Digite o espaco (somente o numero): ");
              scanf("%d", &espaco1);
              if(espaco1 < 1){
                printf("\nDigite um espaco valido, ou seja, maior que zero!\n\n");
              }

              }while(espaco1 < 1);

              vetor1 = (int *)malloc(espaco1*sizeof(int));
              printf("Digite as coordenadas do primeiro vetor:\n");
              ler_vetor(espaco1, vetor1);
            break;

            case 2:
              do{
              printf("Digite o espaco (somente o numero): ");
              scanf("%d", &espaco2);
              if(espaco2 < 1){
                printf("\nDigite um espaco valido, ou seja, maior que zero!\n\n");
              }

              }while(espaco2 < 1);
              vetor2 = (int *)malloc(espaco2*sizeof(int));
              printf("\nDigite as coordenadas do segundo vetor:\n");
              ler_vetor(espaco2, vetor2);
            break;

            case 3:
              soma_vetores(espaco1, espaco2, vetor1, vetor2);
            break;

            case 4:
              printf("Digite o escalar: ");
              scanf("%d", &escalar);
              do{
                printf("\nSelecione o vetor que desejar:\n");
                printf("1) Vetor 1\n");
                printf("2) Vetor 2\n");
                printf("3) Selecionar os dois vetores\n\n");
                scanf("%d", &sub_escolha);

                if(sub_escolha < 1 || sub_escolha > 3){
                  printf("\n---------- Entrada Invalida! ----------\n");
                  printf("Certifique-se de digitar uma opcao valida!\n\n");
                }
              }while(sub_escolha < 1 || sub_escolha > 3);

              if(sub_escolha==1){
                printf("\nVetor 1 ___________________________________\n");
                multiplicar_por_escalar(escalar, espaco1, vetor1);
              }
              else if(sub_escolha==2){
                printf("Vetor 2 ___________________________________\n");
                multiplicar_por_escalar(escalar, espaco2, vetor2);
              }
              if(sub_escolha==3){
                printf("Vetor 1 ___________________________________");
                multiplicar_por_escalar(escalar, espaco1, vetor1);
                printf("Vetor 2 ___________________________________");
                multiplicar_por_escalar(escalar, espaco2, vetor2);
              }
            break;

            case 5:
              produto_vetorial(espaco1, espaco2, vetor1, vetor2);
            break;

            case 6:
              produto_escalar(espaco1, espaco2, vetor1, vetor2);
            break;

            case 7:
              do{
                printf("\nSelecione o vetor que desejar:\n");
                printf("1) Vetor 1\n");
                printf("2) Vetor 2\n");
                printf("3) Mostrar os dois vetores\n\n");
                scanf("%d", &sub_escolha);

                if(sub_escolha < 1 || sub_escolha > 3){
                  printf("\n---------- Entrada Invalida! ----------\n");
                  printf("Certifique-se de digitar uma opcao valida!\n\n");
                }
              }while(sub_escolha < 1 || sub_escolha > 3);

              if(sub_escolha==1){
                printf("-------------- Vetor 1 --------------\n\n");
                mostrar_vetor(espaco1, vetor1);
              } 
              if(sub_escolha==2){
                printf("\n-------------- Vetor 2 --------------\n\n");
                mostrar_vetor(espaco2, vetor2);
              }
              if(sub_escolha==3){
                printf("-------------- Vetor 1 --------------\n\n");
                mostrar_vetor(espaco1, vetor1);
                printf("\n-------------- Vetor 2 --------------\n\n");
                mostrar_vetor(espaco2, vetor2);
              }  

            break;
          }
       }
    }while(escolha!=8);
  }

/*----------------------------------------------------------------------------------------------------------------------------------------------------
Bem parecido com o menu anterior criamos este menu, para as matrizes.
Logo após a declaração das Matrizes, temos a inicialização de ambas com ordem = 3, e todos os elemtos das duas igual a zero. No entanto, nos casos: 1 e 2,
o usuário pode atribuir novas dimensões assim como, novos valores para os elementos das matrizes.
Uma coisa que achamos interessante e vale destacar e que as operações que são realizadas com apenas uma Matriz, possibilita ao usuário a escolha
se ele quer realizar tal operação com a Matriz1 ou com a Matriz2. E dentro desta sub escolha ciamos uma estrutura para que ele digite apenas valores
válidos.
------------------------------------------------------------------------------------------------------------------------------------------------------*/

void menu_operacoes_com_matrizes(){
  int escolha, sub_escolha, i, j;
  int lin1=3, col1=3, lin2=3, col2=3;
  int **matriza, **matrizb, **resultante, **matriz_trans;

  matriza = (int **)malloc(lin1*sizeof(int*));
    for(i=0;i<lin1;i++){
        matriza[i] = (int *)malloc(col1*sizeof(int));
    }

  for(i=0;i<lin1;i++){
    for(j=0;j<col1;j++){
        matriza[i][j] = 0;
    }
  }

  matrizb = (int **)malloc(lin2*sizeof(int*));
    for(i=0;i<lin2;i++){
        matrizb[i] = (int *)malloc(col2*sizeof(int));
    }

  for(i=0;i<lin2;i++){
    for(j=0;j<col2;j++){
        matrizb[i][j] = 0;
    }
  }

        do{
            printf("________________________________\n");
            printf("\n");
            printf("    OPERACOES COM MATRIZES      \n");
            printf("________________________________\n\n");
            printf("1) Inicializar Matriz 1\n");
            printf("2) inicializar Matriz 2\n");
            printf("3) Somar duas Matrizes\n");
            printf("4) Multiplicar duas Matrizes\n");
            printf("5) Calcular a transposta de uma Matriz\n");
            printf("6) Calcular determinante de uma Matriz([1x1], [2x2] ou [3x3])\n");
            printf("7) Verificar se uma Matriz e Simetrica\n");
            printf("8) Exibir Matrizes\n");
            printf("9) Voltar ao menu anterior\n\n");
            scanf("%d", &escolha);

            if(escolha < 1 || escolha > 9){
              printf("\n---------- Entrada Invalida! ----------\n");
              printf("Certifique-se de digitar uma opcao valida!\n\n");

              } else{
                switch(escolha){
                   case 1:
                   do{
                      printf("\nDigite o numero de linhas da Matriz 1: ");
                      scanf("%d", &lin1);
                      printf("Digite o numero de colunas da Matriz 1: ");
                      scanf("%d", &col1);

                      if(lin1 < 1 || col1 < 1){
                        printf("\n---------- Entrada Invalida! ----------\n");
                        printf("Uma matriz nao possui o numero de linhas e nem de colunas menores que 1!\n");
                      }
                    }while(lin1 < 1 || col1 <1);

                    matriza = (int **)malloc(lin1*sizeof(int*));
                    for(i=0;i<lin1;i++){
                      matriza[i] = (int *)malloc(col1*sizeof(int));
                    }
                    printf("\nDigite os elementos da Matriz 1: \n");
                    ler_matriz(lin1, col1, matriza);
                   break;

                   case 2:
                      do{
                        printf("\nDigite o numero de linhas da Matriz 2: ");
                        scanf("%d", &lin2);
                        printf("Digite o numero de colunas da Matriz 2: ");
                        scanf("%d", &col2);

                        if(lin2 < 1 || col2 < 1){
                          printf("\n---------- Entrada Invalida! ----------\n");
                          printf("Uma matriz nao possui o numero de linhas e nem de colunas menores que 1!\n");
                        }
                      }while(lin2 < 1 || col2 <1);

                      matrizb = (int **)malloc(lin2*sizeof(int*));
                      for(i=0;i<lin2;i++){
                         matrizb[i] = (int *)malloc(col2*sizeof(int));
                      }
                      printf("\nDigite os elementos da Matriz 2:\n");
                      ler_matriz(lin2, col2, matrizb);
                   break;

                   case 3:
                    soma_matrizes(lin1, col1, lin2, col2, matriza, matrizb);
                   break;

                   case 4:
                    resultante = (int **) malloc(lin1 * sizeof(int*));
                      for(i=0; i < lin1; i++)
                          resultante[i] = (int*)malloc(col2 * sizeof(int));
                    multi_matriz(lin1, col1, lin2, col2, resultante, matriza, matrizb);
                   break;

                   case 5:
                    do{
                      printf("\nSelecione a Matriz que desejar:\n");
                      printf("1) Matriz 1\n");
                      printf("2) Matriz 2\n");
                      printf("3) Selecionar as duas Matrizes\n\n");
                      scanf("%d", &sub_escolha);

                      if(sub_escolha < 1 || sub_escolha > 3){
                        printf("\n---------- Entrada Invalida! ----------\n");
                        printf("Certifique-se de digitar uma entrada valida!\n\n");
                      }
                    }while(sub_escolha < 1 || sub_escolha > 3);

                    if(sub_escolha==1){

                        matriz_trans = (int **)malloc(col1*sizeof(int*));
                        for(i=0;i<col1;i++){
                          matriz_trans[i] = (int *)malloc(lin1*sizeof(int));
                        }
                        for(i=0;i<lin1;i++){
                          for(j=0;j<col1;j++){
                             matriz_trans[i][j] = 0;
                          }
                        }
                      printf("\nMatriz 1 ___________________________________\n");
                      matriz_transposta(lin1, col1, matriza, matriz_trans);
                    }

                    else if(sub_escolha==2){

                      matriz_trans = (int **)malloc(col2*sizeof(int*));
                        for(i=0;i<col2;i++){
                          matriz_trans[i] = (int *)malloc(lin2*sizeof(int));
                        }
                        for(i=0;i<lin2;i++){
                          for(j=0;j<col2;j++){
                             matriz_trans[i][j] = 0;
                          }
                        }
                      printf("\nMatriz 2 ___________________________________\n");
                      matriz_transposta(lin2, col2, matrizb, matriz_trans);
                    }

                    else if(sub_escolha==3){

                        matriz_trans = (int **)malloc(col1*sizeof(int*));
                        for(i=0;i<col1;i++){
                          matriz_trans[i] = (int *)malloc(lin1*sizeof(int));
                        }
                        for(i=0;i<lin1;i++){
                          for(j=0;j<col1;j++){
                             matriz_trans[i][j] = 0;
                          }
                        }

                        matriz_trans = (int **)malloc(col2*sizeof(int*));
                        for(i=0;i<col2;i++){
                          matriz_trans[i] = (int *)malloc(lin2*sizeof(int));
                        }
                        for(i=0;i<lin2;i++){
                          for(j=0;j<col2;j++){
                             matriz_trans[i][j] = 0;
                          }
                        }
                        printf("\nMatriz 1 ___________________________________\n");
                        matriz_transposta(lin1, col1, matriza, matriz_trans);
                        printf("\nMatriz 2 ____________________________________\n");
                        matriz_transposta(lin2, col2, matrizb, matriz_trans);
                    }

                   break;

                   case 6:
                      do{
                        printf("\nSelecione a Matriz que desejar:\n");
                        printf("1) Matriz 1\n");
                        printf("2) Matriz 2\n");
                        printf("3) Selecionar as duas Matrizes\n\n");
                        scanf("%d", &sub_escolha);

                        if(sub_escolha < 1 || sub_escolha > 3){
                          printf("\n---------- Entrada Invalida! ----------\n");
                          printf("Certifique-se de digitar uma entrada valida!\n\n");
                        }
                     }while(sub_escolha < 1 || sub_escolha > 3);

                     if(sub_escolha==1){
                      printf("\nMatriz 1 ___________________________________\n");
                      determinante_matriz(lin1, col1, matriza);
                     }

                     else if(sub_escolha==2){
                      printf("\nMatriz 2 ____________________________________\n");
                      determinante_matriz(lin2, col2, matrizb);
                     }

                     else if(sub_escolha==3){
                      printf("\nMatriz 1 ___________________________________\n");
                      determinante_matriz(lin1, col1, matriza);
                      printf("\nMatriz 2 ____________________________________\n");
                      determinante_matriz(lin2, col2, matrizb);
                     }
                   break;

                   case 7:
                     do{
                        printf("\nSelecione a Matriz que desejar:\n");
                        printf("1) Matriz 1\n");
                        printf("2) Matriz 2\n");
                        printf("3) Selecinar as duas Matrizes\n\n");
                        scanf("%d", &sub_escolha);

                        if(sub_escolha < 1 || sub_escolha > 3){
                          printf("\n---------- Entrada Invalida! ----------\n");
                          printf("Certifique-se de digitar uma entrada valida!\n\n");
                        }
                     }while(sub_escolha < 1 || sub_escolha > 3);

                     if (sub_escolha==1){
                      printf("\nMatriz 1 ___________________________________\n");
                      verificacao_simetrico(lin1, col1, matriza);
                     }
                    else if(sub_escolha==2){
                      printf("\nMatriz 2 ____________________________________\n");
                      verificacao_simetrico(lin2, col2, matrizb);
                    }
                    else if(sub_escolha==3){
                      printf("\nMatriz 1 ___________________________________\n");
                      verificacao_simetrico(lin1, col1, matriza);
                      printf("\nMatriz 2 ____________________________________\n");
                      verificacao_simetrico(lin2, col2, matrizb);
                    }
                   break;

                   case 8:
                    do{
                        printf("\nSelecione a Matriz que desejar:\n");
                        printf("1) Matriz 1\n");
                        printf("2) Matriz 2\n");
                        printf("3) Mostrar as duas Matrizes\n\n");
                        scanf("%d", &sub_escolha);

                        if(sub_escolha < 1 || sub_escolha > 3){
                          printf("\n---------- Entrada Invalida! ----------\n");
                          printf("Certifique-se de digitar uma entrada valida!\n\n");
                        }
                     }while(sub_escolha < 1 || sub_escolha > 3);

                    if(sub_escolha==1){
                      printf("------------- Matriz 1 -------------\n\n");
                      mostrar_matriz(lin1, col1, matriza);
                    }

                    if(sub_escolha==2){
                      printf("------------- Matriz 2 -------------\n\n");
                      mostrar_matriz(lin2, col2, matrizb);
                    }

                    if(sub_escolha==3){
                      printf("------------- Matriz 1 -------------\n\n");
                      mostrar_matriz(lin1, col1, matriza);
                      printf("------------- Matriz 2 -------------\n\n");
                      mostrar_matriz(lin2, col2, matrizb);
                    }

                   break;
                }
              }
            }while(escolha!=9);
        }