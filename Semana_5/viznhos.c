#include <stdio.h>
#include <stdlib.h>

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
  printf("--------------Grau do vértice------------------- \n");
  int s=0;
   for (int i=0; i<n;i++)
    s += A[v][i];
  
  return s;
}

int VIZ[MAX_SIZE];
int numero_vizinho;
void vizinhos(int v){
    numero_vizinho=0;
    for (int col=0;col<n;col++){
        if (A[v][col] != 0){
            VIZ[numero_vizinho++]=0;
            printf("%d, A[%d][%d] =%d\n",numero_vizinho++,v,col,A[v][col]);
        }
    }
    printf("[");
    for (int i=0; i<numero_vizinho;i++){
        printf("%d", VIZ[i]);
    }
    printf("]\n");
}

int main(){
  int nVertices=5;
  novoGrafo(nVertices);
  // Adicionando valores na matriz nas seguintes posições (0,1),(1,2),(2,3),(3,4)
  addAresta(1,0);
  addAresta(0,0);
  addAresta(4,3);
  addAresta(2,2);
  imprime();
  //int vertice = 2; 
  //printf("grau(%d)=%d\n",vertice,grau(vertice));
  vizinhos(0);
}