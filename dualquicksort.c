#include <stdio.h>
#include <string.h>
#include <stdlib.h>    
#include <time.h>    

int part(char** v, int low, int high, int* lp); 

void troca(char *a, char *b) 
{ 
    char temp[50];
    strcpy(temp,a); 
    strcpy(a ,b); 
    strcpy(b , temp);
} 

void dualquick(char** v, int low, int high) 
{ 
    if (low < high) { 
        int lp, rp; 
        rp = part(v, low, high, &lp); 
        dualquick(v, low, lp - 1); 
        dualquick(v, lp + 1, rp - 1); 
        dualquick(v, rp + 1, high); 
    } 
} 

int part(char** v, int low, int high, int* lp) 
{ 
    if (strcasecmp(v[low] , v[high])>0) 
        troca(v[low], v[high]); 
    int j = low + 1, k = low + 1; 
    int g = high - 1; 
    while (k <= g) { 

        if (strcasecmp(v[k], v[low])<0){ 
            troca(v[k], v[j]); 
            j++; 
        } 

        else if (strcasecmp(v[k], v[high])>=0) { 
            while (strcasecmp(v[g], v[high])>0 && k < g) 
                g--; 
            troca(v[k], v[g]); 
            g--; 
            if (strcasecmp(v[k] , v[low])<0) { 
                troca(v[k], v[j]); 
                j++; 
            } 
        } 
        k++; 
    } 
    j--; 
    g++; 


    troca(v[low], v[j]); 
    troca(v[high], v[g]); 

    *lp = j; 


    return g; 
} 

int main() 
{ 
    int i=0,count=0;
    FILE *pr;
    char **v,c;
    pr = fopen("arq160000u.txt","r");
    for (c = getc(pr); c != EOF; c = getc(pr))
        if (c == '\n') 
            count = count + 1;

    v = malloc(sizeof(char*)*count);
    for(int i=0;i<count;i++){
        v[i] = malloc(sizeof(char)*50);
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
        dualquick(v, 0, count-1);
        clock_gettime(CLOCK_REALTIME, &end);
        seconds = end.tv_sec - begin.tv_sec;
        nanoseconds = end.tv_nsec - begin.tv_nsec;
        elapsed += seconds + nanoseconds*1e-9;
    }

    //for (int i = 0; i < count; i++) 
      // printf("%s ", v[i]); 
  //  printf("\n"); 

    printf("Average time measured for 10 executions: %.3lf seconds.\n", elapsed/10);

    fclose(pr);
    return 0; 

} 