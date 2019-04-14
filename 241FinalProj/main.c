//
//  main.c
//  241FinalProj
//
//  Created by Brian on 4/13/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct InputChar{
  char value;
  struct InputChar *next;
  struct InputChar *previous;
} Input_c;

int grabLine(void);
int clearLine(void);
void addInputC(Input_c *toAdd);
void makeSentinel(void);
void printInput(void);

Input_c *inputSentinel;
int inputSize;

int main(int argc, const char * argv[]) {

  makeSentinel();
  printf("input something\n");
  grabLine();
  printInput();
  if(argc > 1){
    //todo implement cli
    printf("greater than 1 argc");
    return -1;
  }
  
  
  free(inputSentinel);
  return 0;
}

void printInput(void){
  Input_c *toPrint = inputSentinel->next;
  while(toPrint != inputSentinel){
    printf("%c", toPrint->value);
    toPrint = toPrint->next;
  }
  printf("\n");
}

int grabLine(void){
  char c = '\0';
  while((c = getchar())!='\n'){
    Input_c *toAdd = malloc(sizeof(Input_c));
    toAdd->value = c;
    addInputC(toAdd);
  }
  return 1;
}

void addInputC(Input_c *toAdd){
  if(inputSentinel->next == NULL && inputSentinel->previous == NULL){
    inputSentinel->next = toAdd;
    inputSentinel->previous = toAdd;
    toAdd->next = inputSentinel;
    toAdd->previous = inputSentinel;
    inputSize = 1;
  }else{
    inputSentinel->previous->next = toAdd;
    toAdd->next = inputSentinel;
    toAdd->previous = inputSentinel->previous;
    inputSentinel->previous = toAdd;
    inputSize++;
  }
}

void makeSentinel(void){
  inputSentinel = malloc(sizeof(Input_c));
  inputSentinel->next = NULL;
  inputSentinel->previous = NULL;
  inputSentinel->value = '\0';
}

