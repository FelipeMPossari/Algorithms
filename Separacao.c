//Inclusão da biblioteca
#include <stdio.h>
//Declaração da função main
int main() {
  //Declarações de variáveis 
  FILE *pent, *psint, *psfloat;
  int inte, complI;
  double num, complF;
  //Abertura dos arquivos que serão usados
  pent = fopen("entrada.dat", "r");
  psint = fopen("inteiros.dat", "w");
  psfloat = fopen("reais.dat", "w");
  //Início do laço de repetição para ler todo o arquivo
  while (!feof(pent)) {
    //Leitura dos números do arquivo
    fscanf(pent, "%lf", &num);
    //Atribuição do valor recebido a um inteiro
    inte = num;
    //If para checar se o número é inteiro 
    if (inte == num) {
      //If para checar se o número é positivo
      if (num >= 0) {
        //Conta do complemento de milhão e impressão para o arquivo
        complI = 1000000 - inte;
        fprintf(psint, "%d %d\n", inte, complI);
      } else {
        complI = (-1000000) - inte;
        fprintf(psint, "%d %d\n", inte, complI);
      }
    } else {
      //O mesmo tratamento, porém para números decimais
      if (num > 0) {
        complF = 1000000 - num;
        fprintf(psfloat, "%.6lf %.6lf\n", num, complF);
      } else {
        complF = (-1000000) - num;
        fprintf(psfloat, "%.6lf  %.6lf\n", num, complF);
      }
    }
  }
  //Fechamento dos arquivos utilizados
  fclose(pent);
  fclose(psint);
  fclose(psfloat);
}





  