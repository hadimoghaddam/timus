#include <stdio.h>
int main(){
  long long a[9],i, num;
  long long final_val=1;
  scanf("%lld",&num);
  if(num==0){
    printf("10");
    return 0;
  }
  for(i=0;i<10;i++)
    a[i]=0;
  while(num!=1){
    for(i=9;i>1;i--){
      if((num%i)==0){
        a[i]++;
        num=num/i;
//        printf("got %d, now: %d\n",i,num);
        break;
      }
    } 
    if(i==1){
      printf("-1");
      return 0;
    }
  }

  i=2;
  while(i!=10){
    if(a[i]>0){
      if(final_val == 1)
        final_val=i;
      else final_val = final_val*10+i;
      a[i]--;
    }
    else i++;
  }
  printf("%lld\n",final_val);
  return 0;
}
