int A[MAX_SIZE][MAX_SIZE];
// número de vértices
int n;

#define MAX_SIZE 

//Criação da estrutura do grafo
void novoGrafo(int N){
  n=N;
  for (int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A[i][j]=0;
    }
  }
}

// Criando a função que mostra a diagonal principal da matriz. OBS (aij = aji) 
// Exemplos de elementos da diagonal principal (a11,a22,a33,a44,aii,ajj), ou seja, onde o índice da coluna é igual ao da linha
void mostraDiagonal(){
    printf("------------DIAGONAL PRINCIAL DA MATRIZ-----------");
    printf("\n");
    for (int i = 0; i<n; i++){
        printf("%d", A[i][i]); 
    }
    printf("\n");
}

// Criando a Função que mostra apenas os quatro cantos da matriz
// Basicamente, serão sempre os elementos (a00,a0 n-1, an-1 0, an-1 n-1) sendo a sempre linha coluna a ordem.
// Obs. estamos trabalhando com matrizes quadradas, então sempre haverá 4 cantos.

void mostraCantos(){
    printf("---------- Os 4 Cantos da Matriz------------------ \n");
    
    // Mostrando o primeiro canto. linha 0 coluna 0
    printf("%d",A[0][0]);
    
    // Monstrando o elemento da linha 0 e coluna n -1
    printf("%d",A[0][n-1]);
    
    // Monstrando o elemento de linha n-1 e coluna 0
    printf("%d",A[n-1][0]);
    
    // Mostrando o elemento de linha n-1 e coluna n-1
    printf("%d \n",A[n-1][n-1]);
}