#include <stdio.h>

int main() {
  double N,K;
  printf("Ingrese n: ");
  scanf("%lf",&N);
  printf("Ingrese k: ");
  scanf("%lf",&K);

  double r = 1; 
  double k = 0;

  while(K-k>0){
    r = r*(N-k)/(k+1);
    k = k+1;
  }
  
  printf("Elemento: %lf\n", r);
  return 0;
}
