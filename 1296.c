#include <stdio.h>
#include <stdlib.h>
int main(){
  int n, i, j, new_num;
  scanf("%d",&n);
  int * array = (int *)malloc(n * sizeof(int));
  int neut = 0;
  int counter = 0;
  int curr_accum = 0;
  int max_val =0;
  //parse_data
  for(i=0;i<n;i++){
    scanf("%d",&new_num);
    if (new_num==0 || (neut==0 && counter==0 && new_num<0))
      continue;
    if(neut==0){
      curr_accum+=new_num;
      if(new_num>=0)
        neut = 1;
      else neut = -1;
    }  
    else if(neut==1){
      if(new_num >= 0)
        curr_accum+=new_num;
      else{
        array[counter++] = curr_accum;
        if(curr_accum > max_val)
          max_val = curr_accum;
        curr_accum = new_num;
        neut = -1;
      }
    }  
    else{
      if(new_num >= 0){
        array[counter++] = curr_accum;
        curr_accum = new_num;
        neut = 1;
      }
      else
        curr_accum+=new_num;
    }
  }
  if(curr_accum > 0){
    array[counter++] = curr_accum;
    if(curr_accum > max_val)
      max_val = curr_accum;

  }

  // calculate the smallest
  int curr_stream = 0;
  for(i=0; i<counter; i+=2)
  {
    for(j=i; j<counter; j+=2){
      if(curr_stream + array[j]> max_val)
          max_val = curr_stream + array[j];
      if(j==counter-1){
        curr_stream=0; break;
      }
      if(curr_stream + array[j] + array[j+1] > 0){
        curr_stream += (array[j] + array[j+1]);
        if(curr_stream> max_val)
          max_val = curr_stream;
      }
      else 
        break;

      
    }
    curr_stream = 0;
  }
/*


  for(i=0;i<counter;i+=2){
    if(i == counter){
      curr_stream+= array[i];
      if(curr_stream > max_val)
        max_val = curr_stream;
    }
    else if(array[i]+array[i+1] > 0){
      if(curr_stream + array[i] > max_val)
        max_val = curr_stream+array[i];
      curr_stream += array[i] + array[i+1];
    }
    else{
      if(i < counter){
        if(curr_stream+array[i] > max_val)
          max_val = curr_stream+array[i];
      }
      else if(curr_stream > max_val)
          max_val = curr_stream;
      curr_stream = 0;
     }
  }

  printf("res: ");
  for(i=0;i<counter;i++)
    printf("%d ",array[i]);
*/  

  printf("%d",max_val); 

}
