#include <stdio.h>
#include <stdlib.h>
int main(){
  char phone[100];
  int i=0, num_words;
  //char **words;  

  while(scanf("%c",&phone[i]) && phone[i++]!='\n' && ){}
  if(phone[i-1] != '-'){
    scanf("%d",&num_words);
    //char **b = (char **) malloc(num_words * sizeof(char*) );
    char *b[num_words];
    for(int j=0; j<num_words; j++)
      b[j] = (char *)malloc(50 * sizeof(char));
    for (int j=0;j< num_words;j++){
      scanf("%s",b[j]);
    }
  }else{break;}
  find_solution(*phone, **b, num_words); //recursive
return 0;
}

find_solution(char *phone, char **b, int num_words){
  

}
