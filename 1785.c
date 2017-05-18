#include <stdio.h>
int main(){
  int m;
  scanf("%d",&m);
  if (m>0 && m<=4) printf("few\n");
  if (m>4 && m<=9) printf("several\n"); 
  if (m>9 && m<=19) printf("pack\n");
  if (m>19 && m<=49) printf("lots\n"); 
  if (m>49 && m<=99) printf("horde\n");
  if (m>99 && m<=249) printf("throng\n"); 
  if (m>249 && m<=499) printf("swarm\n"); 
  if (m>499 && m<=999) printf("zounds\n");
  if (m>=1000) printf("legion\n"); 

    
return 0;
}
