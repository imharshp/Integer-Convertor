/* Author: Harsh Patel
   CodeName: hw3.c
   Description: To convert a given int to hexadecimal,binary and octal. Also to
                save the results in the requested text file.
  GNumber: G01018715
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char *getDateAndTime();
int getInteger(char *str_array);
void getBinary(int);

void main(){
  FILE *myfile;
  char user_input[32],user_decision[32],filename[32];
  int number,q,a = 1,b;
  int binn[100];

  printf("Enter an Integer(1-1000000) or type in x to exit: ");
  scanf("%s",&user_input);

  number = getInteger(user_input);


  //Checking if the entered number is within range...
  while(number <= 0 || number > 1000000 ){
    if(number == -1)   // exit if number equals -1
      return;
    printf("\nEnter an Integer(1-1000000) or type x to exit: ");
    scanf("%s",user_input);
    number = getInteger(user_input);
  }

  printf("\n\nDecimal: %d",number);
  printf("\nHexadecimal: %x",number);
  printf("\nOctal: %o\n",number);
  getBinary(number);

  printf("\n\nSave to a file?(y/n):  ");
  scanf("%s",user_decision);

  //Checking if the user wants a saved file...
  if(strcmp(user_decision,"y") == 0){
    printf("\nEnter the file name: ");
    scanf("%s",filename);
    myfile = fopen(filename,"w");
    //Checking if the file selected is valid...
    while(myfile == NULL){
      printf("\nEnter the file name: ");
      scanf("%s",filename);
      myfile = fopen(filename,"w");
    }
    // Now writing in file...
    fprintf(myfile,"Harsh Patel\n");
    fprintf(myfile,"%s",getDateAndTime());
    fprintf(myfile,"\n\nDecimal: %d",number);
    fprintf(myfile,"\nHexadecimal: %x",number);
    fprintf(myfile,"\nOctal: %o\n",number);
    q = number;
    while(q != 0){
      binn[a++] = q%2;
      q /= 2;
    }
    fprintf(myfile,"Binary: ");
    for(b = a-1; b > 0; b--){
      fprintf(myfile,"%d",binn[b]);
    }
    fclose(myfile);
    printf("\n\nFile Saved!");

    }
    printf("\n\nOkay, GoodBye:)");
  }


// This function gets date and time...
char *getDateAndTime(){
  time_t t;
  time(&t);
  return ctime(&t);
}

// This function converts user_input to integer...
int getInteger(char *str_array){
  if (strcmp(str_array,"x") == 0)
    return -1;
  else
    return atoi(str_array);
}

// This function print binary number on the output screen...
void getBinary(int x){
  int quotient;
  int binNumber[100], i =1, j;
  quotient = x;

  while(quotient != 0){
    binNumber[i++] = quotient % 2;
    quotient /= 2;
  }
  printf("Binary: ");
  for(j = i-1; j > 0; j--)
    printf("%d",binNumber[j]);
}
