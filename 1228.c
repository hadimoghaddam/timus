#include <stdio.h>
int main(){
  long long unsigned num, dim_arr[20];
  int dim, i, curr_dim;
  scanf("%d %llu", &dim, &num);
  num--;
  for(i=0;i<dim;i++){
    scanf("%llu", &dim_arr[i]);
  }
  for(i=0; i<dim; i++){
    curr_dim = num/dim_arr[i];
    num = num%dim_arr[i];
    printf("%d ", curr_dim);
  }
  return 0;
}
