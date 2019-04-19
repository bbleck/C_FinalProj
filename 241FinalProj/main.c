//
//  main.c
//  241FinalProj
//
//  Created by Brian on 4/13/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bb_strings.h"

/**  Define Macros ***************** **/
#define CHAR_INPUT_SIZE 30
#define SSN_INPUT_SIZE 9
#define MAIN_MENU_OPTS '6'
#define ADD_MENU_OPTS '6'
#define EDIT_MENU_OPTS '5'
#define DELETE_MENU_OPTS '6'
#define VIEW_D_MENU_OPTS '6'
#define VIEW_G_MENU_OPTS '5'
#define PASSWORD_SIZE 64
#define ROLE_SIZE 8
#define USERNAME_SIZE 20

/**  Struct typedefs *************** **/
typedef struct InputChar{
  char value;
  struct InputChar *next;
  struct InputChar *previous;
} Input_c;

typedef struct student{
  char first[CHAR_INPUT_SIZE];
  char last[CHAR_INPUT_SIZE];
  char ssn[SSN_INPUT_SIZE];
} Student;

typedef struct student_node{
  Student *student;
  struct student_node *next;
  struct student_node *previous;
} Student_Node;

typedef struct class{
  int course_id;
  char course_title[CHAR_INPUT_SIZE];
} Course;

typedef struct course_node{
  Course *course;
  struct course_node *next;
  struct course_node *previous;
} Course_Node;

typedef struct enrollment{
  int course_id;
  char ssn[SSN_INPUT_SIZE];
} Enrollment;

typedef struct enrollment_node{
  Enrollment *enrollment;
  struct enrollment_node *next;
  struct enrollment_node *previous;
} Enrollment_Node;

typedef struct assignment{
  int assignment_id;
  char assignment_title[CHAR_INPUT_SIZE];
  int pts_total;
  int course_id;
} Assignment;

typedef struct assignment_node{
  Assignment *assignment;
  struct assignment_node *next;
  struct assignment_node *previous;
} Assignment_Node;

typedef struct grade{
  int course_id;
  char ssn[SSN_INPUT_SIZE];
  int pts_received;
} Grade;

typedef struct grade_node{
  Grade *grade;
  struct grade_node *next;
  struct grade_node *previous;
} Grade_Node;

typedef struct user_record{
  char userName[USERNAME_SIZE];
  char role[ROLE_SIZE];
  char password[PASSWORD_SIZE];
} User_Record;

typedef struct user_node{
  User_Record *user;
  struct user_node *next;
  struct user_node *previous;
} User_Node;

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
void setUpLists(void);
void tearDownLists(void);
void makeStudentSentinel(void);
int clearStudentList(void);
void fillStudentList(void);
void writeStudentList(void);
void addStudentList(Student_Node *toAdd);
void copyCharArray(char *copyTo, char *copyFrom, int arrSize);
int clearCourseList(void);
void makeCourseSentinel(void);
void fillCourseList(void);
void addCourseList(Course_Node *toAdd);
void writeCourseList(void);
void toAddGrade(void);
int isValidIntInput(void);
int storeIntInput(int* intStorage);
void getInt(const char* prompt, int* id);
void makeAssignSentinel(void);
int clearAssignList(void);
void fillAssignmentList(void);
void writeAssignmentList(void);
void addAssignmentList(Assignment_Node *toAdd);

/**  Variable Declarations ********* **/
Input_c *inputSentinel;
int inputSize;
Student_Node *studentSentinel;
int studentSize;
Course_Node *courseSentinel;
int courseSize;
Enrollment_Node *enrollSentinel;
int enrollSize;
Assignment_Node *assignmentSentinel;
int assignmentSize;
Grade_Node *gradeSentinel;
int gradeSize;
User_Node *userSentinel;
int userSize;

/** ******************************** **/

/**
 Insertion point into program.
 **/
int main(int argc, const char * argv[]) {
  srand((unsigned int)time(0));
//  FILE *fp;
//  fopen(STUDENTS_DB, "w");
  
  setUpLists();
  if(argc > 1){
    //todo implement cli
    printf("greater than 1 argc");
    return -1;
  }
  toMainMenu();
  tearDownLists();
  return 0;
}

/**
 A function to sub delegate setting up the linked lists for input
 and databases.
 **/
void setUpLists(void){
  makeSentinel();
  makeStudentSentinel();
  makeCourseSentinel();
  makeAssignSentinel();
  fillStudentList();
  fillCourseList();
  fillAssignmentList();
  //todo: make sure all sentinels are called and lists filled
}

/**
 A function to sub delegate freeing the linked lists for input
 and databases.
 **/
void tearDownLists(void){
  free(inputSentinel);
  free(studentSentinel);
  free(assignmentSentinel);
}

/**
 A function that puts a name stored in linked list memory into value at pointer parameter.
 **/
void retrieveName(char* name){
  int counter = 0;
  Input_c *tempNode = inputSentinel->next;
  while(tempNode != inputSentinel && counter < CHAR_INPUT_SIZE){
    name[counter] = tempNode->value;
    counter++;
    tempNode = tempNode->next;
  }
//  name[counter] = '\0';
}

/**
 A function that puts an in store in linked list memory into value at a pointer reference.
 Assumes validation has already been made.
 **/
void retrieveInt(int* iPtr){
  *iPtr = 0;
  Input_c *tempNode = inputSentinel->next;
  *iPtr += atoi(&tempNode->value);
  tempNode = tempNode->next;
  while(tempNode != inputSentinel){
    *iPtr *= 10;
    *iPtr += atoi(&tempNode->value);
    tempNode = tempNode->next;
  }
}

/**
 A function to display the main menu and handle user selection.
 **/
void toMainMenu(void){
  printf("%s", MAIN_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid(MAIN_MENU_OPTS, inputSentinel->next->value)){
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
     !isMenuSelectionValid(ADD_MENU_OPTS, inputSentinel->next->value)){
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
      toAddAssignment();
      break;
    case '4':
      toAddGrade();
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
 A function that takes an int pointer and adds a valid int into its value.
 **/
int storeIntInput(int* intStorage){
  clearLine();
  grabLine();
  if(!isValidIntInput()){
    printf("invalid input\n");
    return 0;
  }
  if(inputSize != 0){
    retrieveInt(intStorage);
    return 1;
  }else{
    return 0;
  }
}

/**
 A function to validate that input is only digits.
 **/
int isValidIntInput(void){
  Input_c *temp = inputSentinel->next;
  while(temp != inputSentinel){
    if(temp->value < '0' || temp->value > '9'){
      printf("input is: %c\n", temp->value);
      return 0;
    }
    temp = temp->next;
  }
  return 1;
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
 A function that prints a prompt to get an ID and delegates ID
 retrieval until successful.
 **/
void getInt(const char* prompt, int* id){
  while(1){
    printf("%s", prompt);
    if(storeIntInput(id)){
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
  char first[CHAR_INPUT_SIZE];
  char last[CHAR_INPUT_SIZE];
  char ssnStr[SSN_INPUT_SIZE];
  Student *toAdd = malloc(sizeof(Student));
  Student_Node *toAddNode = malloc(sizeof(Student_Node));
  printf("Add Student\n");
  getName(ADD_STUDENT_PROMPTS[0], first);
  getName(ADD_STUDENT_PROMPTS[1], last);
  getSSN(ADD_STUDENT_PROMPTS[2], ssnStr);
  copyCharArray(toAdd->first, first, CHAR_INPUT_SIZE);
  copyCharArray(toAdd->last, last, CHAR_INPUT_SIZE);
  copyCharArray(toAdd->ssn, ssnStr, SSN_INPUT_SIZE);
  toAddNode->student = toAdd;
  addStudentList(toAddNode);
  writeStudentList();
}

/**
 A function to copy the contents of an array into another array.
 **/
void copyCharArray(char *copyTo, char *copyFrom, int arrSize){
  int i = 0;
  for(i=0; i<arrSize; i++){
    copyTo[i] = copyFrom[i];
  }
}

/**
 A function that will add a class to database.
 **/
void toAddClass(void){
  char title[CHAR_INPUT_SIZE];
  int course_id = rand();
  Course *courseAdd = malloc(sizeof(Course));
  Course_Node *courseNodeAdd = malloc(sizeof(Course_Node));
  //todo: check if any other course already has the id; re-randomize if needed
  printf("Add Class\n");
  //move values into new course
  getName(ADD_CLASS_PROMPTS[0], title);
  courseAdd->course_id = course_id;
  copyCharArray(courseAdd->course_title, title, CHAR_INPUT_SIZE);
  //move new node into course node
  courseNodeAdd->course = courseAdd;
  //add course node into list
  addCourseList(courseNodeAdd);
  //write course list db to reflect change
  writeCourseList();
}

/**
 A function that will add a grade to the database.
 **/
void toAddGrade(void){
  
}

/**
 A function that will add an assignment to database.
 **/
void toAddAssignment(void){
  int assignment_id = rand();
  int totPts = 0;
  int courseID = 0;
  //todo: check for duplicate id, re-randomize if needed
  char assignment_title[CHAR_INPUT_SIZE];
  int *pts_total = &totPts;
  int *course_id = &courseID;
  Assignment *assignAdd = malloc(sizeof(Assignment));
  Assignment_Node *assignNodeAdd = malloc(sizeof(Assignment_Node));
  printf("Add Assignment\n");
  getInt(ADD_ASSIGNMENT_PROMPTS[0], course_id);
  getName(ADD_ASSIGNMENT_PROMPTS[1], assignment_title);
  getInt(ADD_ASSIGNMENT_PROMPTS[2], pts_total);
//  printf("%d, %c, %d, %d", assignment_id, assignment_title[0], courseID, totPts);
  //move values into new assignment
  assignAdd->assignment_id = assignment_id;
  assignAdd->course_id = courseID;
  assignAdd->pts_total = totPts;
  copyCharArray(assignAdd->assignment_title, assignment_title, CHAR_INPUT_SIZE);
  //add new assignment into new assignment node
  assignNodeAdd->assignment = assignAdd;
  //add new assignment node into list
  addAssignmentList(assignNodeAdd);
  //rewrite assignment list to reflect change
  writeAssignmentList();
  printf("assignments in db: %d\n", assignmentSize);
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
  if(inputSize != 9){
    return 0;
  }
  if(!isValidIntInput()){
    return 0;
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
     !isMenuSelectionValid(DELETE_MENU_OPTS, inputSentinel->next->value)){
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
     !isMenuSelectionValid(VIEW_D_MENU_OPTS, inputSentinel->next->value)){
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
     !isMenuSelectionValid(VIEW_G_MENU_OPTS, inputSentinel->next->value)){
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
 A function to add a student node onto the end of the linked list.
 **/
void addStudentList(Student_Node *toAdd){
  if(studentSentinel->next == NULL && studentSentinel->previous == NULL){
    studentSentinel->next = toAdd;
    studentSentinel->previous = toAdd;
    toAdd->next = studentSentinel;
    toAdd->previous = studentSentinel;
    studentSize = 1;
  }else{
    studentSentinel->previous->next = toAdd;
    toAdd->next = studentSentinel;
    toAdd->previous = studentSentinel->previous;
    studentSentinel->previous = toAdd;
    studentSize++;
  }
}

/**
 A function to add a course node onto the end of the linkd list.
 **/
void addCourseList(Course_Node *toAdd){
  if(courseSentinel->next == NULL && courseSentinel->previous == NULL){
    courseSentinel->next = toAdd;
    courseSentinel->previous = toAdd;
    toAdd->next = courseSentinel;
    toAdd->previous = courseSentinel;
    studentSize = 1;
  }else{
    courseSentinel->previous->next = toAdd;
    toAdd->next = courseSentinel;
    toAdd->previous = courseSentinel->previous;
    courseSentinel->previous = toAdd;
    courseSize++;
  }
}

/**
 A function to add an assignment node onto the end of the assignment linked list.
 **/
void addAssignmentList(Assignment_Node *toAdd){
  if(assignmentSentinel->next == NULL && assignmentSentinel->previous == NULL){
    assignmentSentinel->next = toAdd;
    assignmentSentinel->previous = toAdd;
    toAdd->next = assignmentSentinel;
    toAdd->previous = assignmentSentinel;
    assignmentSize = 1;
  }else{
    assignmentSentinel->previous->next = toAdd;
    toAdd->next = assignmentSentinel;
    toAdd->previous = assignmentSentinel->previous;
    assignmentSentinel->previous = toAdd;
    assignmentSize++;
  }
}

/**
 A function to write the contents of the student linked list into
 the Student database. Overwrites the Student database.
 **/
void writeStudentList(void){
  FILE *fp;
  Student_Node *toAdd = studentSentinel->next;
  fp = fopen(STUDENTS_DB, "w");
  while(toAdd != studentSentinel && toAdd != NULL){
    fwrite(toAdd->student, sizeof(Student), 1, fp);
    toAdd = toAdd->next;
  }
  fclose(fp);
}

/**
 A functin to write the contents of the course linked list into
 the courses database.  Overwrites the courses database.
 **/
void writeCourseList(void){
  FILE *fp;
  Course_Node *toAdd = courseSentinel->next;
  fp = fopen(CLASSES_DB, "w");
  while(toAdd != courseSentinel && toAdd != NULL){
    fwrite(toAdd->course, sizeof(Course), 1, fp);
    toAdd = toAdd->next;
  }
  fclose(fp);
}

/**
 A functin to write the contents of the assignments linked list into
 the assignments database.  Overwrites the assignments database.
 **/
void writeAssignmentList(void){
  FILE *fp;
  Assignment_Node *toAdd = assignmentSentinel->next;
  fp = fopen(ASSIGNMENTS_DB, "w");
  while(toAdd != assignmentSentinel && toAdd != NULL){
    fwrite(toAdd->assignment, sizeof(Assignment), 1, fp);
    toAdd = toAdd->next;
  }
  fclose(fp);
}


/**
 A function to read one student at a time from the Student database,
 then adding the student to a student node, which is then added to the
 student linked list.
 **/
void fillStudentList(void){
  FILE *fp;
  if((fp = fopen(STUDENTS_DB, "r")) != NULL){
    //file exists, fill student list
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
      Student *studentAdd = malloc(sizeof(Student));
      Student_Node *studentNodeAdd = malloc(sizeof(Student_Node));
      fread(studentAdd, sizeof(Student), 1, fp);
      studentNodeAdd->student = studentAdd;
      addStudentList(studentNodeAdd);
    }
    fclose(fp);
  }else{
    fp = fopen(STUDENTS_DB, "w");
    fclose(fp);
  }
}

/**
 A function to read one course at a time from the course database,
 then adding the course to the course node, which is then added to the
 course linked list.
 **/
void fillCourseList(void){
  FILE *fp;
  if((fp = fopen(CLASSES_DB, "r")) != NULL){
    //file exists, fill course list
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
      Course *courseAdd = malloc(sizeof(Course));
      Course_Node *courseNodeAdd = malloc(sizeof(Course_Node));
      fread(courseAdd, sizeof(Course), 1, fp);
      courseNodeAdd->course = courseAdd;
      addCourseList(courseNodeAdd);
    }
    fclose(fp);
  }else{
    fp = fopen(CLASSES_DB, "w");
    fclose(fp);
  }
}

/**
 A function to read one assignment at a time from the assignment database,
 then adds the course to a course node, which is added to the assignment
 linked list.
 **/
void fillAssignmentList(void){
  FILE *fp;
  if((fp = fopen(ASSIGNMENTS_DB, "r")) != NULL){
    //file exists, fill course list
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
      Assignment *assignAdd = malloc(sizeof(Assignment));
      Assignment_Node *assignNodeAdd = malloc(sizeof(Assignment_Node));
      fread(assignAdd, sizeof(Assignment), 1, fp);
      assignNodeAdd->assignment = assignAdd;
      addAssignmentList(assignNodeAdd);
    }
    fclose(fp);
  }else{
    fp = fopen(ASSIGNMENTS_DB, "w");
    fclose(fp);
  }
}

/**
 A function to clear the student list.
 **/
int clearStudentList(void){
  if(studentSize==0){
    return 1;
  }
  Student_Node *toClear = studentSentinel->previous;
  while(toClear != studentSentinel){
    Student_Node *nextClear = toClear->previous;
    if(toClear->student != NULL){
      free(toClear->student);
    }
    free(toClear);
    toClear = nextClear;
  }
  studentSentinel->next = NULL;
  studentSentinel->previous = NULL;
  studentSize = 0;
  return 1;
}

/**
 A function to clear the course list.
 **/
int clearCourseList(void){
  if(courseSize == 0){
    return 1;
  }
  Course_Node *toClear = courseSentinel->previous;
  while(toClear != courseSentinel){
    Course_Node *nextClear = toClear->previous;
    if(toClear->course != NULL){
      free(toClear->course);
    }
    free(toClear);
    toClear = nextClear;
  }
  courseSentinel->next = NULL;
  courseSentinel->previous = NULL;
  courseSize = 0;
  return 1;
}

/**
 A function to clear the assignment linked list.
 **/
int clearAssignList(void){
  if(assignmentSize == 0){
    return 1;
  }
  Assignment_Node *toClear = assignmentSentinel->previous;
  while(toClear != assignmentSentinel){
    Assignment_Node *nextClear = toClear->previous;
    if(toClear->assignment != NULL){
      free(toClear->assignment);
    }
    free(toClear);
    toClear = nextClear;
  }
  assignmentSentinel->next = NULL;
  assignmentSentinel->previous = NULL;
  assignmentSize = 0;
  return 1;
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
 A helper function to build the student sentinel node
 and store a reference to it in the global variable.
 **/
void makeStudentSentinel(void){
  studentSize = 0;
  studentSentinel = malloc(sizeof(Student_Node));
  studentSentinel->next = NULL;
  studentSentinel->previous = NULL;
}

/**
 A helper function to build the class sentinel node and
 store a reference to it in the global variable.
 **/
void makeCourseSentinel(void){
  courseSize = 0;
  courseSentinel = malloc(sizeof(Course_Node));
  courseSentinel->next = NULL;
  courseSentinel->previous = NULL;
}

/**
 A helper function to build the assignment sentinel node and
 store a reference to it in the global variable.
 **/
void makeAssignSentinel(void){
  assignmentSize = 0;
  assignmentSentinel = malloc(sizeof(Assignment_Node));
  assignmentSentinel->next = NULL;
  assignmentSentinel->previous = NULL;
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
