#include <stdio.h>
#include <string.h>
#include <stdlib.h>    
#include <time.h> 

int mediana(int low, int high, int mid,char **v){
    if(((strcasecmp(v[low],v[high])>0) && (strcasecmp(v[low],v[mid])<0)) || ((strcasecmp(v[low],v[high])<0) && (strcasecmp(v[low],v[mid])>0))){
        return low;
    }
    else if(((strcasecmp(v[high],v[low])>0) && (strcasecmp(v[high],v[mid])<0)) || ((strcasecmp(v[high],v[low])<0) && (strcasecmp(v[high],v[mid])>0))){
        return high;
    }
    else{
        return mid;
    }
}
void troca(char *a, char *b) 
{ 
    char temp[50];
    strcpy(temp,a); 
    strcpy(a ,b); 
    strcpy(b , temp);
} 
void quicksort(char **v, int low, int high){
    int piv,maior=0;
    if(low < high){
        piv = mediana(low,high,(low+high)/2,v);

        troca(v[piv],v[high]);
        maior = low;
        for(int i=maior; i<high;i++){
            if(strcasecmp(v[i],v[high])<0){
                troca(v[i],v[maior]);
                maior++;
            }
        }
        troca(v[maior],v[high]);
        quicksort(v, low, maior-1);
        quicksort(v, maior+1, high);
    }

}
int main() 
{ 
    int i=0,count=0;
    FILE *pr;
    char **v,c;
    pr = fopen("arq20000u.txt","r");
    for (c = getc(pr); c != EOF; c = getc(pr))
        if (c == '\n') 
            count = count + 1;

    v = malloc(sizeof(char*)*count);
    for(int j=0;j<count;j++){
        v[j] = malloc(sizeof(char)*50);
    }
    fseek(pr,0,SEEK_SET);
    fscanf(pr,"%s",v[i]);
    while(!feof(pr)){
        i++;
        fscanf(pr,"%s",v[i]);
    }
     struct timespec begin, end;
    long seconds, nanoseconds;
    double elapsed;

    for (int i=0; i<10; i++) {
        fseek(pr,0,SEEK_SET);
        fscanf(pr,"%s",v[i]);
        while(!feof(pr)){
            i++;
            fscanf(pr,"%s",v[i]);
        }
        clock_gettime(CLOCK_REALTIME, &begin);
        quicksort(v, 0, count-1);
        clock_gettime(CLOCK_REALTIME, &end);
        seconds = end.tv_sec - begin.tv_sec;
        nanoseconds = end.tv_nsec - begin.tv_nsec;
        elapsed += seconds + nanoseconds*1e-9;
    }


   // for (int i = 0; i < count; i++) 
      //  printf("%s ", v[i]); 
    //printf("\n"); 

   printf("Average time measured for 10 executions: %.3lf seconds.\n", elapsed/10);

    fclose(pr);
    return 0; 

}