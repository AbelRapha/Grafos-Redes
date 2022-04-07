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

// Criando a função que mostra a diagonal principal da matriz. OBS (aij = aji) 
// Exemplos de elementos da diagonal principal (a11,a22,a33,a44,aii,ajj), ou seja, onde o índice da coluna é igual ao da linha

