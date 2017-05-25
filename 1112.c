#include <stdio.h>
void sort(int *, int*, int);
int find_conflicts(int*, int*, int, int);
int main(){
  int list_1[100], list_2[100], flist_1[100], flist_2[100]; 
  int num_segs=0, i, num1, num2;
  int fcounter=0, fpointer =0;
  int conflicts;
 
// inputting data
  scanf("%d",&num_segs);
  for(i=0; i<num_segs; i++){
    scanf("%d%d",&num1, &num2);
    if(num1>num2){
      list_1[i] = num2; list_2[i] = num1;
    }
    else{
      list_2[i] = num2; list_1[i] = num1;
    }
  }
// sorting segments
  sort(list_1, list_2, num_segs);

// remove abundant segments

  while(fpointer < num_segs){
    int conflicts = find_conflicts(list_1, list_2, fpointer, num_segs);
    if(conflicts != 0){
      fpointer++;
      continue;
    }
    flist_1[fcounter]=list_1[fpointer];
    flist_2[fcounter]=list_2[fpointer];
    while((flist_2[fcounter] > list_1[fpointer]) && (fpointer < num_segs))
      fpointer++;
    
    fcounter++;
  }

//  fcounter--;
  
 
// print out segment for correctness
/*  for(i=0; i<num_segs; i++)
    printf("[%d-%d]\n", list_1[i], list_2[i]);
*/
  printf("%d\n", fcounter);
  for(i=0; i<fcounter; i++)
    printf("%d %d\n", flist_1[i], flist_2[i]);

  return 0;
}  

void sort(int *list_1, int *list_2, int size){
  int i, j, temp;
  for(i=0; i<size; i++){
    for(j=i+1; j<size; j++){
      if(list_1[j] < list_1[i]){
//        printf("swapping [%d,%d] with [%d,%d]\n", list_1[i], list_2[i], list_1[j], list_2[j]);
        temp = list_1[j]; list_1[j] = list_1[i]; list_1[i] = temp;
        temp = list_2[j]; list_2[j] = list_2[i]; list_2[i] = temp;
      }
      else if((list_1[j] == list_1[i]) && (list_2[j] < list_2[i])){
//        printf("swapping [%d,%d] with [%d,%d]\n", list_1[i], list_2[i], list_1[j], list_2[j]);
        temp = list_1[j]; list_1[j] = list_1[i]; list_1[i] = temp;
        temp = list_2[j]; list_2[j] = list_2[i]; list_2[i] = temp;
      }
    }
  }
}



int find_conflicts(int* list_1, int* list_2, int ptr, int num_segs){
  int i, conflicts = 0;
  for(i=ptr+1;i<num_segs; i++){
    if((list_1[ptr]<=list_1[i]) && (list_2[ptr]> list_2[i])) conflicts++;
  }

  return conflicts;
}
