#include <stdio.h>
#include <stdlib.h>

int main(){
  float a,b;
  char c;
  scanf("%f %c %f",&a,&c,&b);
  switch(c){
    case '+':printf("%f %c %f = %f\n",a,c,b,a+b); break;
    case '-':printf("%f %c %f = %f\n",a,c,a-b); break;
    case '*':printf("%f %c %f = %f\n",a,c,a*b); break;
    case '/':
      if(b == 0) puts("Error:The dividend cannot be 0\n");
      printf("%f %c %f = %f\n",a,c,a/b); break;
    default:printf("Error:Please enter a valid symbol(+,-,*,/)\n"); break;
  }
  system("pause");
  return 0;
}
