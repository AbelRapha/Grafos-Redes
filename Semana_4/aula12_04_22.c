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
    for (int i=0;i<n;i++){
        printf("%d ", A[i][i]);
    }
    printf("\n");
}   

void addAresta(int u, int v){
  A[u][v]=1;
  A[v][u]=1;
}

int main(){
    int nVertices = 5;
    novoGrafo(nVertices);
    primeiraLinha();
    ultimaLinha();
    addAresta(3,2);
    meioLinha();
    primeiraColuna();
    meioColuna();
    ultimaColuna();
    diagonalPrincipal();
}