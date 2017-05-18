#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int costCalc(char* Sandro, char* code, int count);
void removeSpace(char *code);
int getline1(char **lineptr, int *n, FILE *stream);
int main(){
  char Sandro[]= "Sandro";
  int sandroLen = strlen(Sandro);
  char *code;
  int codeSize=200;
  int codeLen,cost;
  int minCost = 60;
  code = (char *)malloc(codeSize * sizeof(char));
  getline1(&code,&codeSize,stdin);

  codeLen = strlen(code);
  for(int i=0;i<codeLen-sandroLen;i++){
    cost = costCalc(Sandro, &code[i], sandroLen);
    if (cost < minCost){
      minCost = cost;
    }
  }
  printf("%d\n",minCost);

return 0;
}

int costCalc(char* Sandro, char* code, int count){
  int cost = 0;
  for(int i=0;i<count;i++){
    if((Sandro[i]- code[i]) != 0 ){
      cost+=5;
      if(!((Sandro[i] < 91 && code[i]<91 && Sandro[i] >64 && code[i]>64) || (Sandro[i] > 96 && code[i]>96 && Sandro[i] <122 && code[i]<122))) 
       if(!((Sandro[i]-code[i] == 32 ) || (Sandro[i]-code[i] == -32))){
        cost+=5;
       }
    }
  }
  return cost;
}

int getline1(char **lineptr, int *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    int size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}
