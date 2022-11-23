#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int num = 0;
  int GussNum = 0;
  srand(time(NULL));
  num = rand()%100 + 1;
  for(int i=0;i<10;i++){
    printf("Please enter your number:");
    scanf("%d",&GussNum);
    if(GussNum>num)
      puts("Wrong!\nToo high!\n");
    else if(GussNum<num)
      puts("Wrong\nToo low!\n");
    else{
      printf("Congratulation!\nYou Win.You guessed %d times.\n",i);
      system("pause");
      return 0;
    }
  }
  printf("Over 10 times.\nYou defeated.\n");
  system("pause");
  return 0;
}
