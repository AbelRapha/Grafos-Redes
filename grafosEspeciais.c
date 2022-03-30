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
// FUnção que imprime o grafo criado pela função novoGrafo
void imprime(){
  for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d",A[i][j]);
    }
    printf("\n");
  }
}
// Função que atribui valor 1 na matriz de acordo com a sua posição a(ij)
void addAresta(int u, int v){
  A[u][v]=1;
  A[v][u]=1;
}
// Função que obtém o grau do grafo ao somar a linha respectiva ao vértice
int grau(int v){
  int s=0;
   for (int i=0; i<n;i++)
    s += A[v][i];
  
  return s;
}
int main(){
  printf("Olá Mundo \n");
  int nVertices=5;
  novoGrafo(nVertices);
  // Adicionando valores na matriz nas seguintes posições (0,1),(1,2),(2,3),(3,4)
  addAresta(0,1);
  addAresta(1,2);
  addAresta(2,3);
  addAresta(3,4);
  imprime();
  int vertice = 2; 
  printf("grau(%d)=%d\n",vertice,grau(vertice));
}