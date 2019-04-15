//
//  main.c
//  241FinalProj
//
//  Created by Brian on 4/13/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bb_strings.h"


/**  Struct typedefs *************** **/
typedef struct InputChar{
  char value;
  struct InputChar *next;
  struct InputChar *previous;
} Input_c;


/**  Function Declarations ********* **/
int grabLine(void);
int clearLine(void);
void addInputC(Input_c *toAdd);
void makeSentinel(void);
void printInput(void);
void testLinkedList(void);
void toMainMenu(void);


/**  Variable Declarations ********* **/
Input_c *inputSentinel;
int inputSize;

/** ******************************** **/

/**
 Insertion point into program.
 **/
int main(int argc, const char * argv[]) {
  makeSentinel();
  if(argc > 1){
    //todo implement cli
    printf("greater than 1 argc");
    return -1;
  }
  toMainMenu();
  
  
  free(inputSentinel);
  return 0;
}

/**
 A function to display the main menu and handle user selection.
 **/
void toMainMenu(void){
  printf("%s", MAIN_MENU_TEXT);
  
}

/**
 A function to print the contents of the linked list for input.
 **/
void printInput(void){
  if(inputSize == 0){
    printf("Input size is 0.\n");
    if(inputSentinel->next != NULL || inputSentinel->previous != NULL){
      printf("Error: input size is 0, but input pointers not NULL\n");
    }else{
      printf("No input in memory.\n");
    }
    return;
  }
  Input_c *toPrint = inputSentinel->next;
  while(toPrint != inputSentinel){
    printf("%c", toPrint->value);
    toPrint = toPrint->next;
  }
  printf("\n");
  printf("%d\n", inputSize);
}

/**
 A function to take a whole line from stdin and put it into memory.
 **/
int grabLine(void){
  char c = '\0';
  while((c = getchar())!='\n'){
    Input_c *toAdd = malloc(sizeof(Input_c));
    toAdd->value = c;
    addInputC(toAdd);
  }
  return 1;
}

/**
 A function to clear the contents of the linked list for input,
 and to free the memory of the linked list nodes.
 **/
int clearLine(void){
  Input_c *toClear = inputSentinel->previous;
  while(toClear != inputSentinel){
    Input_c *nextClear = toClear->previous;
    free(toClear);
    toClear = nextClear;
  }
  inputSentinel->next = NULL;
  inputSentinel->previous = NULL;
  inputSize = 0;
  return 1;
}


/**
 A function to add an input node onto the end of the linked list.
 **/
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


/**
 A helper function to build the input sentinel node
 and store a reference to it in the global variable.
 **/
void makeSentinel(void){
  inputSize = 0;
  inputSentinel = malloc(sizeof(Input_c));
  inputSentinel->next = NULL;
  inputSentinel->previous = NULL;
  inputSentinel->value = '\0';
}

/**
 A function to test the input linked list functions
 using printf statements.
 **/
void testLinkedList(void){
  printf("input something\n");
  grabLine();
  printf("line grabbed\n");
  printInput();
  clearLine();
  printf("memory cleared\n");
  printInput();
  printf("input something\n");
  grabLine();
  printf("line grabbed\n");
  printInput();
  clearLine();
  printf("line cleared\n");
  printInput();

}
