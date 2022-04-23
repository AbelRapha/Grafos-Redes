#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
//matriz de adjacência
int A[MAX_SIZE][MAX_SIZE];
//número de vértices
int n;
void novoGrafo(int N){
    n=N;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }
}
void imprime(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
void addAresta(int u, int v){
    A[u][v]=1;
    A[v][u]=1;
}

int VIZ[MAX_SIZE];
int n_viz;
void vizinhos(int v){
    n_viz=0;
    for(int col=0;col<n;col++){
        if(A[v][col]!=0){
            VIZ[n_viz++]=col;
        }
    }
   /** printf("[");
    for(int i=0;i<n_viz;i++){
        printf("%d,",VIZ[i]);
    }
    printf("]\n"); */
}
#define BRANCO 0
#define PRETO 1
int PAI[MAX_SIZE];

void buscaEmLargura(int v_ini){
    int COR[MAX_SIZE];
    int DIST[MAX_SIZE];
    for(int v=0;v<n;v++){
        COR[v]=BRANCO;
        DIST[v] = -1;
        PAI[v] = -1;
    }
    int FILA[MAX_SIZE];
    int ini = 0;
    int fim = 0;
    FILA[fim++]=v_ini;
    COR[v_ini]=PRETO;
    PAI[v_ini] = v_ini;
    DIST[v_ini]=0;
    while(ini!=fim){
        int v = FILA[ini++];
        printf("Visitou %d pai=%d dist=%d\n",v,PAI[v],DIST[v]);
        vizinhos(v);
        for(int i=0;i<n_viz;i++){
            int w = VIZ[i];
            if(COR[w]==BRANCO){
                COR[w]=PRETO;
                DIST[w]=DIST[v]+1;
                PAI[w] = v;
                FILA[fim++]=w;
            }
        }
    }
    /**printf("---------\n");
    for(int v=0;v<n;v++){
        printf("Vertice %d pai=%d dist=%d\n",v,PAI[v],DIST[v]);
    }*/
}

void caminhoOrigem(int w){
    if(PAI[w]!=-1){
        while(PAI[w]!=w){
            printf("%d->",w);
            w = PAI[w];
        }
        printf("%d\n",w);
    }else{
        printf("Não existe caminho\n");
    }
}
// Verificar a conexidade
// Obs. Se um vértice não for ligado a uma aresta comum ao vértice de origem, então o grafo é desconexo
int conexo(){
    int soma_vertice = 0;
    for (int linha = 0; linha<n;linha++){
        for (int coluna = 0; coluna<n;coluna++){
            soma_vertice+= A[linha][coluna];
        }
    }
    if (soma_vertice<= n+1){
        printf("Grafo Desconexo!! \n");
    }
    else{
        printf("Grafo Conexo \n");
    }
}

int main(){
    int nVertices=7;
    novoGrafo(nVertices);
    addAresta(0,1);addAresta(1,2);addAresta(2,3);
    addAresta(3,4);addAresta(4,5);addAresta(5,6);
    addAresta(6, 0);
    imprime();
    conexo();
    vizinhos(0);
    buscaEmLargura(0);
    caminhoOrigem(3);
}


