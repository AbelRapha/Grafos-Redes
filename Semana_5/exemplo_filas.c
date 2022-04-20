#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100
int F[MAX_SIZE];
int inicio, fim;
inicio=0;
fim=0;

//Adicionando elemento na F

F[fim]=1;
fim++;
F[fim++]=2;

//Retirando elementos da F;

int v = F[inicio++];

//Fila Vazia
fim, inicio = 0,0;

//Conjunto Vizinhos de um vértice

int Vizinos[MAX_SIZE];
int numero_de_vizinhos;

void vizinhos(int v){
    numero_de_vizinhos=0;
    for (int col=0; col<n;col++){
        if(A[v][col] != 0){
            Viz[numero_de_vizinhos++]=col;
        }
    }
}

// imprimindo a Fila de vizinhos

for (int i=0; i<numero_de_vizinhos;i++){
    printf("%d ", Vizinos[i]);
}


