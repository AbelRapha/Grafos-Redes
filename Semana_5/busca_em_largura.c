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
}
#define BRANCO 0
#define PRETO 1
int PAI[MAX_SIZE];
int DIST[MAX_SIZE];
void buscaEmLargura(int v_ini){
    int COR[MAX_SIZE];
    
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
// Usar busca em largura e utilizar o vetor pai e distância. Se D for menor do 0, então o grafo é desconexo, caso contrário é conexo
int conexo(){
    buscaEmLargura(2);
    int valor = 0;
    for (int i=0; i<n; i++){
        if (DIST[i]<0){
            printf("--------Grafo desconexo------\n");
            break;
        }
        else{
            valor = DIST[i];
        }
    }
    if (valor >0){
        printf("-------Grafo Conexo--------\n");
    }
}

int main(){
    int nVertices=7;
    novoGrafo(nVertices);
    addAresta(1,2);addAresta(2,3);
    addAresta(3,4);addAresta(4,5);addAresta(5,6);
    addAresta(1,3);addAresta(1,4);addAresta(1,5);addAresta(1,6);
    imprime();
    vizinhos(0);
    conexo(); // Dentro da função conexo, há a função busca em largura associada ao vértice correspondente
}


