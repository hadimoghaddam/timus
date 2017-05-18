#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a>b?b:a)
int findKing(int, int, int);
int findBishop(int size, int xPos, int yPos);
int findKnight(int size, int xPos, int yPos);

int main(){
  int size, xPos, yPos;
  int king, knight, bishop, rook, queen;
  
  scanf("%d",&size);
  scanf("%d %d",&xPos,&yPos);
  
  rook = 2*(size-1);
  king = findKing(size, xPos, yPos);
  knight = findKnight(size, xPos, yPos);
  bishop = findBishop(size, xPos, yPos);
  king = findKing(size, xPos, yPos);
  printf("King: %d\n",king);
  printf("Knight: %d\n",knight);
  printf("Bishop: %d\n",bishop);
  printf("Rook: %d\n",rook);
  printf("Queen: %d\n",rook+bishop);

return 0;
}

int findKing(int size, int xPos, int yPos){
  int count = 0;
  for(int i=xPos-1;i<xPos+2; i++){
   for(int j=yPos-1;j<yPos+2; j++){
     if(i>0 && i<=size && j>0 && j<=size)
       count++;
   }
  }
  return count-1;
}

int findBishop(int size, int xPos, int yPos){
  int count =0;
/*
  for(int i=1; i< size; i++){
    if((xPos+i <= size) && (xPos+i > 0) && (yPos+i <= size) && (yPos+i > 0))
      count++;
    if((xPos-i <= size) && (xPos-i > 0) && (yPos+i <= size) && (yPos+i > 0))
      count++;
    if((xPos+i <= size) && (xPos+i > 0) && (yPos-i <= size) && (yPos-i > 0))
      count++;
    if((xPos-i <= size) && (xPos-i > 0) && (yPos-i <= size) && (yPos-i > 0))
      count++;
  }
*/
  count += min(xPos-1,yPos-1);
  count += min(size-xPos,yPos-1);
  count += min(xPos-1,size-yPos);
  count += min(size-xPos,size-yPos);
  return count;
}

int findKnight(int size, int xPos, int yPos){
  int count=0;
  for(int i=-2;i<=2; i++){
   for(int j=-2;j<=2; j++){
     if((!(i==j || i==-j || i==0 || j==0)) && (xPos+i <= size) && (xPos+i > 0) && (yPos+j <= size) && (yPos+j > 0)){
       //printf("%d %d\n",i,j);
       count++;
     }
   }
  }

return count;
}
