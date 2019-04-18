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
int isMenuSelectionValid(char upperBound, char selection);
void toAddDataMenu(void);
void toEditDataMenu(void);
void toDeleteDataMenu(void);
void toViewDataMenu(void);
void toAddStudent(void);
int isValidNameInput(void);
void retrieveName(char* name);
int isValidSSNInput(void);
int isValidClassTitle(void);
void toAddClass(void);
void toAddAssignment(void);
int storeNameInput (char* nameStorage);
void getName(const char* prompt, char* name);
void getSSN(const char* prompt, char* ssn);


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
 A function that puts a name stored in linked list memory into value at pointer parameter.
 **/
void retrieveName(char* name){
  int counter = 0;
  Input_c *tempNode = inputSentinel->next;
  while(tempNode != inputSentinel && counter < 30){
    name[counter] = tempNode->value;
    counter++;
    tempNode = tempNode->next;
  }
  name[counter] = '\0';
}

/**
 A function to display the main menu and handle user selection.
 **/
void toMainMenu(void){
  printf("%s", MAIN_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid('6',inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toMainMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      toAddDataMenu();
      break;
    case '2':
      toEditDataMenu();
      break;
    case '3':
      toDeleteDataMenu();
      break;
    case '4':
      toViewDataMenu();
      break;
    case '5':
      //todo: use command line environ
      break;
    case '6':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toMainMenu();
}

/**
 A function to display the add data menu and handle user selection.
 **/
void toAddDataMenu(void){
  printf("%s", ADD_DATA_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid('6',inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toAddDataMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      toAddStudent();
      break;
    case '2':
      toAddClass();
      break;
    case '3':
      //todo: add assignment
      break;
    case '4':
      //todo: add grade
      break;
    case '5':
      //todo: enroll student
      break;
    case '6':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toAddDataMenu();
}

/**
 A function that takes a string pointer and adds a valid ssn into it.
 **/
int storeSSNInput(char* ssnStorage){
  clearLine();
  grabLine();
  if(isValidSSNInput()){
    retrieveName(ssnStorage);
    return 1;
  }else{
    return 0;
  }
}

/**
 A function that takes a string pointer and adds a valid name into it.
 **/
int storeNameInput (char* nameStorage){
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(nameStorage);
    return 1;
  }else{
    return 0;
  }
}

/**
 A function that prints a prompt to get a name and delegates name
 retrieval until successful.
 **/
void getName(const char* prompt, char* name){
  while(1){
    printf("%s", prompt);
    if(storeNameInput(name)){
      break;
    }
  }
}

/**
 A function that prints a prompt to get a ssn and delegates ssn
 retrieval until successful.
 **/
void getSSN(const char* prompt, char* ssn){
  while(1){
    printf("%s", prompt);
    if(storeSSNInput(ssn)){
      break;
    }
  }
}

/**
 A function that will add a student
 **/
void toAddStudent(void){
  char first[31];
  char last[31];
  char ssnStr[10];
  first[30] = '\0';
  last[30] = '\0';
  printf("Add Student\n");
  getName(ADD_STUDENT_PROMPTS[0], first);
  getName(ADD_STUDENT_PROMPTS[1], last);
  getSSN(ADD_STUDENT_PROMPTS[2], ssnStr);
  printf("First name: %s\n", first);
  printf("Last name: %s\n", last);
  printf("SSN: %s\n", ssnStr);
  //get rid of print statements and store data
}

/**
 A function that will add a class to database.
 **/
void toAddClass(void){
  char title[31];
  title[30] = '\0';
  printf("Add Class\n");
  getName(ADD_CLASS_PROMPTS[0], title);
//  while(1){
//    printf("%s", ADD_CLASS_PROMPTS[0]);
//    clearLine();
//    grabLine();
//    if(isValidClassTitle()){
//      retrieveName(title);
//      break;
//    }
//  }
  printf("Class title: %s\n", title);
}

/**
 A function that will add an assignment to database.
 **/
void toAddAssignment(void){
  
}

/**
 A function to test whether class title is valid.
 **/
int isValidClassTitle(void){
  //todo: implement validation
  return 1;
}

/**
 tests input to see if it is a valid name
 **/
int isValidNameInput(void){
  //todo: implement validation
  return 1;
}

/**
 A function to test whether ssn input is valid.
 **/
int isValidSSNInput(void){
  int i = 0;
  Input_c *temp = inputSentinel->next;
  if(inputSize != 9){
    return 0;
  }
  for(i = 0; i < 9; i++){
    if(temp->value < '0' || temp->value > '9'){
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}

/**
 A function to display the delete data menu and handle user selection.
 **/
void toDeleteDataMenu(void){
  printf("%s", DELETE_DATA_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid('6',inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toDeleteDataMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      //todo: delete student
      break;
    case '2':
      //todo: delete class
      break;
    case '3':
      //todo: delete assignment
      break;
    case '4':
      //todo: delete grade
      break;
    case '5':
      //todo: drop student
      break;
    case '6':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toDeleteDataMenu();
}

/**
 A function to display the view data menu and handle user selection.
 **/
void toViewDataMenu(void){
  printf("%s", VIEW_DATA_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid('6',inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toViewDataMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      //todo: view students
      break;
    case '2':
      //todo: view classes
      break;
    case '3':
      //todo: view assignments
      break;
    case '4':
      //todo: view grades
      break;
    case '5':
      //todo: view enrollment
      break;
    case '6':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toViewDataMenu();
}


/**
 A function to display the edit data menu and handle user selection.
 **/
void toEditDataMenu(void){
  printf("%s", EDIT_DATA_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid('5',inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toEditDataMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      //todo: edit student
      break;
    case '2':
      //todo: edit class
      break;
    case '3':
      //todo: edit assignment
      break;
    case '4':
      //todo: edit grade
      break;
    case '5':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toEditDataMenu();
}


/**
 A function to check whether input is valid for menu selections.
 Takes in an int, which represents the upper bound for valid selection.
 **/
int isMenuSelectionValid(char upperBound, char selection){
  if(selection < '1' || upperBound < selection){
    return 0;
  }
  return 1;
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
  if(inputSize == 0){
    return 1;
  }
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
