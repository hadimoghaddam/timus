#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE (2*256*1024/4)
int main(){
  long long int a;
  double *b = (double *) malloc(sizeof(double) * SIZE);
  int i=0;
  while(scanf("%lld",&a)!= EOF){
    b[i++] = sqrt(a);
  }
  for(int j=i-1;j>=0;j--)
    printf("%0.4f\n",b[j]);
  return 0;
}
