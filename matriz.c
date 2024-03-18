//Declaração de biblioteca
#include <stdio.h>
//Declaração da função e passagem de parâmetros
int funca(int lin, int col, int matriz[1000][1000], int tam, int mzero, int *maximo) {
  //Declaração de variáveis
  int qzeros = 0, tamr;
  //If para verificar a menor distancia até a borda da submatriz
  if (lin > col)
    tamr = tam - lin;
  else
    tamr = tam - col;
  //if para verificar se o tamanho real é negativo
  if (tamr <= 0)
    return 0;
  //for para percorrer toda a submatriz 
  for (int l = lin; l < lin + tamr; l++) {
    for (int g = col; g < col + tamr; g++) {
      //If para contar a quantidade de zeros
      if (matriz[l][g] == 0)
        qzeros = qzeros + 1;
    }
  }
  //If para verificar se a matriz chegou ao tamanho 0
  if (tam == 0)
    return 0;
  //If para verificar se a quantidade de zeros é maior que o máximo
  if (qzeros > mzero)
    //Chamada da função recursiva com tamanho menor
    funca(lin, col, matriz, tam - 1, mzero, maximo);
  //If para verificar se a quantidade de zeros é menor ou igual ao máximo
  if (qzeros <= mzero && tamr > *maximo) {
    *maximo = tamr;
    return 0;
  }
}
int main(void) {
  //Declaração de variáveis
  int m[1000][1000], n, k, maximo = 0;
  //Leitura de do tamanho de matriz e quantidade de zeros
  scanf("%d %d", &n, &k);
  //Leitura da matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
    }
  }
  //for para percorrer toda a matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      funca(i, j, m, n, k, &maximo);
    }
  }
  //Impressão da maior matriz com k ou menos zeros
  printf("%d", maximo);
}