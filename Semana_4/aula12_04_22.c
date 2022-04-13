// ALUNOS: ABEL RAPHA DE JESUS MACEDO RA: 230424
//         LUIZ HENRIQUE RUBIM FERRANDA RA: 183222

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int A[MAX_SIZE][MAX_SIZE];
// número de vértices
int n;

//Criação da estrutura do grafo
void novoGrafo(int N){
  n=N;
  for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A[i][j]=0;
    }
  }
}

// Exercício 1

void primeiraLinha(){
    printf("PRIMEIRA LINHA \n");
    for (int j=0; j<n; j++){
        printf("%d ",A[0][j]);
    }
    printf("\n");
}

void ultimaLinha(){
    printf("ÚLTIMA LINHA \n");
    for (int j=0; j<n; j++){
        printf("%d ", A[n-1][j]);
    }
    printf("\n");
}

void meioLinha(){
    printf("MEIA LINHA \n");
   int middle_element = n/2 + 1/2;
    for (int j=0; j<n;j++){
        printf("%d ",A[middle_element][j]);
    }
    printf("\n");
}

// Exercício 2

void primeiraColuna(){
    printf("PRIMEIRA COLUNA \n");
    for (int i=0; i<n; i++){
        printf("%d ",A[i][0]);
    }
    printf("\n");
}

void ultimaColuna(){
    printf("ÚLTIMA COLUNA \n");
    for (int i=0; i<n; i++){
        printf("%d ", A[i][n-1]);
    }
    printf("\n");
}

void meioColuna(){
    printf("MEIO COLUNA \n");
   int middle_element = n/2 + 1/2;
    for (int i=0; i<n;i++){
        printf("%d ",A[i][middle_element]);
    }
    printf("\n");
}

// Exercício 3

void diagonalPrincipal(){
    printf("DIAGONAL PRINCIPAL \n");
    for (int i=0;i<n;i++){
        printf("%d ", A[i][i]);
    }
    printf("\n");
}   

void diagonalSecundaria(){
    printf("DIAGONAL SECUNDÁRIA \n");
    for (int i=0; i<n;i++){
        printf("A[%d][%d] = %d ",i,n-i-1, A[i][n-i-1]);
    }
    printf("\n");
}

// Exercício 4
void triangularSuperior(){
    printf("Triangular Superior \n");
    for (int i=0; i<n;i++){
        for (int j=0; j<i; j++){
            printf("**");
        }
        for (int j=i; j<n;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Exercício 5
void triangularInferior(){
    printf("Triangular Inferior \n");
    for (int i=0; i<n;i++){
        for (int j=0; j<i;j++){
            printf("%d ", A[i][j]);
        }
            for (int j=i; j<n; j++){
                printf("**");
        }
        printf("\n");
    }
    printf("\n");
}

// Exercício 6

void vizinhosDoVertice(){
    printf("Vizinhos de um vértice \n");
    int row;
    row = 0;
    printf("Digite um valor da linha que deseja buscar: ");
    scanf("%d", &row);
    for (int j=0; j<n; j++){
        if (A[row][j]>0) {
            printf("%d ",j);
        }
        
    }
    printf("\n");
}

// Exercício 7

void grafoKn(){
    printf("Grafo Kn \n");
    for (int i=0; i<n; i++){
        for (int j = 0; j<n;j++){
            if (i == j) {
                A[i][i] = 0;
                printf("%d ",A[i][i]);
            }
            else{
                A[i][j]=1;
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
    }
}

void grafoCn(){
    printf("Grafo Cn \n");
    for (int i=0; i<n; i++){
        for (int j = 0; j<n;j++){
            A[i][j]=0;
            if (i == j) {
                A[i][j] = 0;
            }
            else if (i == 0){
                A[i][i+1] =1;
                A[i][n-1] = 1;
            }
            else if (i == n-1){
                A[i][0] =1;
                A[i][n-2] =1;
            }
            else{
                A[i][i-1] =1;
                A[i][i+1] =1;
            }
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
}    

void grafoPn(){
    printf("Grafo Pn \n");
    for (int i=0; i<n; i++){
        for (int j = 0; j<n;j++){
            A[i][j] = 0;
            if (i==j) {
                A[i][i] = 0;
            }
            else if(i==0){
                A[i][i+1] = 1;
            }
            else if(i== n-1){
                A[n-1][n-2]=1;
            }
            else{
                A[i][i-1] = 1;
                A[i][i+1] = 1;
            }
        printf("%d ", A[i][j]);
        }
        printf("\n");
    }     
}

// Exercício 8

void grafoK(){
    printf("GRAFO K n1, n2\n");
    int n1,n2;
    printf("Digite um valor para n1: ");
    scanf("%d",&n1 );
    printf("Digite um valor para n2: ");
    scanf("%d",&n2 );
    for (int i = 0; i<n1+n2; i++){
        for (int j = 0; j<n1+n2; j++){
            A[i][j]=0;
        }
    }
    for (int i = 0; i<n1;i++){
        for (int j = n1; j<n1+n2; j++){
            A[i][j] = 1;
            A[j][i] = 1;
        }
    }
    for (int i = 0; i<n1+n2; i++){
        for (int j = 0; j<n1+n2; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int nVertices = 5;
    novoGrafo(nVertices);
    primeiraLinha();
    meioLinha();
    ultimaLinha();
    primeiraColuna();
    meioColuna();
    ultimaColuna();
    diagonalPrincipal();
    diagonalSecundaria();
    triangularSuperior();
    triangularInferior();
    vizinhosDoVertice(); //Caso aparece uma linha vazia quer dizer que não tiveram vizinhos do vértice
    grafoKn();
    grafoCn();
    grafoPn();
    grafoK();
}
