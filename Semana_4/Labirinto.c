#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
//matriz quadrada nxn
int n;
char labirinto[MAX_SIZE][MAX_SIZE];
char c;

void geraLabirinto(void);

void informacoes(void);

void imprimeLabirinto(void);

void resolveLabirinto(){
    /**
     seu código vem aqui.
     */
    for(int i=0;i<n;i++){
        labirinto[0][i]= '*';
        labirinto[i][n-1]= '*';
    }
}

int main(){

    geraLabirinto();
    imprimeLabirinto();
    resolveLabirinto();
    imprimeLabirinto();
    informacoes();
    
    
}


void geraLabirinto(){
    srand((int)time(NULL));
    printf("Digite n:");
    scanf("%d",&n);
    //probabilidade alfa de labirinto[i][j] valer 0.
    //prob. 1-alfa de valer 1.
    float alfa;
    printf("Digite um valor entre 0.7 e 1.0: ");
    scanf("%f",&alfa);
    printf("n=%d alfa=%f\n",n,alfa);
    for(int linha=0;linha<n;linha++){
        for(int col=0;col<n;col++){
            if(rand()*1.0/RAND_MAX<alfa)
                labirinto[linha][col]='0';
            else
                labirinto[linha][col]='1';
        }
    }
}

void informacoes(){
    
    scanf("%c",&c);
    printf("Neste projeto você deve sair do canto \n");
    printf("superior esquerdo e caminhar até o canto \n");
    printf("inferior direito [Digite Enter] \n");
    scanf("%c",&c);
    printf("Existem 4 movimentos possíveis \n");
    printf("para cima/para baixo/direita/esquerda \n");
    printf(" [Digite Enter] \n");
    scanf("%c",&c);
    printf("Só é permitido andar sobre zeros. \n");
    printf("O valor 1 é considerado um bloqueio. \n");
    printf(" [Digite Enter] \n");
    scanf("%c",&c);
    
    printf("Você deve desenhar um caminho (caso exista)\n sobre ");
    printf("o labirinto, usando * do canto superior \n");
    printf("esquerto até o canto inferior direito [Digite Enter] \n");
    scanf("%c",&c);
    
    
    
    
    resolveLabirinto();
    
    
    printf("Abaixo um exemplo  \n");
    
    
    imprimeLabirinto();
    
    printf("Só que este exemplo passa sobre bloqueios\n valores 1 [Digite Enter] \n");
    scanf("%c",&c);
    printf("Desenhe um caminho que não passa sobre 1 [Digite Enter] \n");
    scanf("%c",&c);
    printf("Trabalho em dupla. [Digite Enter] \n");
    scanf("%c",&c);
}


void imprimeLabirinto(){
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",labirinto[i][j]);
        }
        printf("\n");
    }
    printf("[Digite Enter]");
        scanf("%c",&c);
}

