#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int main(){
  int start,end;
  int minTrivIdx = 0;
  int min triviality = INT_MAX;
  scanf("%d %d",&start,&end);
  if(start==1){
    printf("1\n");
    return 0;
  }

//odd numbers
  for(int i=end; i>=start; i--){
    if(i%2==0)
      continue;
    if()

  }
//even numbers
  for( int i=start; i<= end; i++){
    triviality = findTriviality(divisors, i); 
    if(triviality < minTrivi)
      minTriv = triviality;
      minTrivIdx = i;
  }

  printf("%d", )
return 0;
}
int findTriviality(int * divisors, int num){
  


}


