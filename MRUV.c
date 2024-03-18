#include <stdio.h>
#include <math.h>

double fdist_MRU(double V, double T){
  double dist;
  dist = V*T;
  return dist;
}
double fvel_MRU(double S, double T){
  double vel;
  vel = S/T;
  return vel;
}
double ftemp_MRU(double S, double V){
  double temp;
  temp = S/V;
  return temp;
}
double fdist_MRUV(double V, double A, double T){
  double dist;
  dist = V*T+(0.5*A*pow(T,2));
  return dist;
}
double fvel_MRUV(double V, double A, double T){
  double vel;
  vel = V+(A*T);
  return vel;
}
double fvelI_MRUV(double S, double A, double T){
  double velI;
  velI = (S - (0.5) * A * pow(T,2)) / T;
  return velI;
}
double ftemp_MRUV(double S, double V, double A){
  double temp;
  temp = (-V + sqrt(V * V + 2 * A * S)) / A;
  return temp;
}

int main(void) {
  int N=0,O=0;
  double dist_MRU,vel_MRU,temp_MRU, dist_MRUV,vel_MRUV,velI_MRUV,temp_MRUV,
  S=0,V=0,A=0,T=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&O);
    switch(O){
      case 1:
        scanf("%lf",&V);
        scanf("%lf",&T);
        dist_MRU = fdist_MRU(V,T);
        printf("%.2lf\n",dist_MRU);
      break;
      case 2:
        scanf("%lf",&S);
        scanf("%lf",&T);
        vel_MRU = fvel_MRU(S,T);
        printf("%.2lf\n",vel_MRU);
      break;
      case 3:
        scanf("%lf",&S);
        scanf("%lf",&V);
        temp_MRU = ftemp_MRU(S,V);
        printf("%.2lf\n",temp_MRU);
      break;
      case 4:
        scanf("%lf",&V);
        scanf("%lf",&A);
        scanf("%lf",&T);
        dist_MRUV = fdist_MRUV(V,A,T);
        printf("%.2lf\n",dist_MRUV);
      break;
      case 5:
        scanf("%lf",&V);
        scanf("%lf",&A);
        scanf("%lf",&T);
        vel_MRUV = fvel_MRUV(V,A,T);
        printf("%.2lf\n",vel_MRUV);
      break;
      case 6:
        scanf("%lf",&S);
        scanf("%lf",&A);
        scanf("%lf",&T);
        velI_MRUV = fvelI_MRUV(S,A,T);
        printf("%.2lf\n",velI_MRUV);
      break;
      case 7:
        scanf("%lf",&S);
        scanf("%lf",&V);
        scanf("%lf",&A);
        temp_MRUV = ftemp_MRUV(S,V,A);
        printf("%.2lf\n",temp_MRUV);
      break;    
    }
  }

return 0;
}