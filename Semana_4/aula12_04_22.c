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
    for (int j=0; j<n; j++){
        printf("%d ",A[0][j]);
    }
    printf("\n");
}

void ultimaLinha(){
    for (int j=0; j<n; j++){
        printf("%d ", A[n-1][j]);
    }
    printf("\n");
}

void meioLinha(){
   int middle_element = n/2 + 1/2;
    for (int j=0; j<n;j++){
        printf("%d ",A[middle_element][j]);
    }
    printf("\n");
}

// Exercício 2

void primeiraColuna(){
    for (int i=0; i<n; i++){
        printf("%d ",A[i][0]);
    }
    printf("\n");
}

void ultimaColuna(){
    for (int i=0; i<n; i++){
        printf("%d ", A[i][n-1]);
    }
    printf("\n");
}

void meioColuna(){
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
    int row, column;
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
    for (int i=0; i<n; i++){
        for (int j = 0; j<n;j++){
            if (i == j) {
                A[i][i] = 0;
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

// Exercício 8

void grafoK(){
    printf("Digite um valor para ");
}



void addAresta(int u, int v){
  A[u][v]=1;
  A[v][u]=1;
}

void imprime(){
  for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ",A[i][j]);
    }
    printf("\n");
  }
}  

int main(){
    int nVertices = 5;
    novoGrafo(nVertices);
    grafoCn();
}