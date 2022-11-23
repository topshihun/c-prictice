#include <stdio.h>
#include <stdlib.h>

int main(){
  float faHeight,moHeight,Height;
  char sex;
  printf("Please enter father's height:");
  scanf("%f",&faHeight);
  printf("Please enter mother's height:");
  scanf("%f",&moHeight);
  printf("Please enter childer's sex(M is Male,F is Female):");
  getchar();
  scanf("%c",&sex);
  if(sex == 'M')
    Height = (faHeight + moHeight) * 0.54;
  else if(sex == 'F')
    Height = (faHeight * 0.923 + moHeight) / 2.0;
  printf("The childer'height is %.3f.\n",Height);
  system("pause");
  return 0;
}
