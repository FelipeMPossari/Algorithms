#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct lis{
  char palavra[1000];
  struct lis *prox;
}lista;

void inserir(lista **comeco, char pala[]){ 
    lista *atual = (*comeco),*ante =(*comeco), *novo=malloc(sizeof(lista));
    strcpy(novo->palavra, pala);
  if((*comeco)==NULL){
    novo->prox = NULL;
    (*comeco) = novo;
    return;
  }
  while(atual->prox && strcmp(atual->palavra,novo->palavra)<0){
    ante = atual;
    atual = atual->prox;
  }
  if(strcmp(atual->palavra,novo->palavra)>0){
    if(atual==(*comeco)){
      novo->prox = atual;
      (*comeco) = novo;
      return;
    }
    novo->prox = atual;
    ante->prox = novo;
    return;
  }
  if(strcmp(atual->palavra,novo->palavra)==0){
  return;
  }
  if(atual->prox==NULL){
    novo->prox = NULL;
    atual->prox = novo;
    return;
  }
}


void imprimir(lista **comeco){
  lista *atual;
  atual = (*comeco);
  if((*comeco)==NULL){
    printf("NULL\n");
    return;
  }

  
  while(atual!=NULL){
    printf("%s ",atual->palavra);
    atual = atual->prox;
  }
  printf("\n");
  return;
}

int remover(lista **comeco, char pala[]){
  lista *atual=(*comeco), *anterior=(*comeco);
  if((*comeco)==NULL){
    printf("NULL\n");
    return 0;
  }
  while(atual->prox && strcmp(atual->palavra,pala)!=0){
    anterior = atual;  
    atual = atual->prox;
  }
  if((*comeco)==atual&&strcmp((*comeco)->palavra,pala)==0){
    *comeco = atual->prox;
    free(atual);
    return 1;
  }
  if(strcmp(atual->palavra,pala)==0){
    anterior->prox = atual->prox;
    free(atual);
    return 1;
  }
  return 1;
}

int main(void) {
  lista (*comeco)=NULL;
  char npalavra[31];
  int opcao=0;


  int N, M;
  scanf("%d %d",&N,&M);
  
  for(int i=0;i<N;i++){
    scanf("%s",npalavra);
    inserir(&comeco,npalavra);
  }
  for(int i=0;i<M;i++){
    scanf("%d",&opcao);
    if(opcao==1){
      scanf("%s",npalavra);
      inserir(&comeco,npalavra);
    }
    if(opcao==0){
      scanf("%s",npalavra);
      if(remover(&comeco,npalavra)==1){
        imprimir(&comeco);
      }
    }
  }

  return 0;
}


