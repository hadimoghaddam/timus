#include <stdio.h>
int main(){
  int a,na,b,nb;
  scanf("%d%d",&a,&b);
  na = (a+b > 10)? 10-a: (b-1)>0 ? b-1 : 0; 
  nb = (a+b > 10)? 10-b: (a-1)>0 ? a-1 : 0;
  printf("%d %d",na,nb);

return 0;
}
