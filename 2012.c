#include <stdio.h>
int main(){
  int f;
  scanf("%d",&f);
  int can = ((float)((12-f)*3)/4.0 <= 4.0) ? 1:0;
  switch(can){
   case 1: printf("YES"); break;
   case 0: printf("NO"); break;
  }  
return 0;
}
