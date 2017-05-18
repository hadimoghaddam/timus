#include <stdio.h>
#include <math.h>
float find_dist(float x1, float y1, float x2, float y2);
int main(){
  int n, i; float r, dist_curr, dist = 0;
  float num1_curr, num1_prev, num1_init;
  float num2_curr, num2_prev, num2_init;
  scanf("%d %f", &n, &r);
  scanf("%f %f", &num1_prev, &num2_prev);
  if (n==1){
    printf("%0.2f",2*3.14159*r);
    return 0;
  }
  num1_init = num1_prev; num2_init = num2_prev;
  for(i=0;i<n-1;i++){
    scanf("%f %f", &num1_curr, &num2_curr);
    dist += find_dist(num1_curr, num2_curr, num1_prev, num2_prev);
    num1_prev = num1_curr; num2_prev = num2_curr; 
  }
  dist += find_dist(num1_curr, num2_curr, num1_init, num2_init); 
  dist += 2*3.14159*r;
  printf("%0.2f",dist);
  return 0;
}

float find_dist(float x1, float y1, float x2, float y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
