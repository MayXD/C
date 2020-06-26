#include<stdio.h>

int main(){
  char temp[10];
  printf("input string\n");
  scanf("%s",temp);
  for(int i=0;i<10;i++)
    printf("%c",temp[i]);
  return 0;
}