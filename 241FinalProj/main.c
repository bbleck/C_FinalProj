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

/**
 class id ->> needs to be autoincremented by 1 starting at
 **/

const char STUDENTS_DB[] = "students.txt";
const char CLASSES_DB[] = "classes.db";
const char ASSIGNMENTS_DB[] = "assignments.db";
const char ENROLLMENT_DB[] = "enrollment.db";
const char GRADES_DB[] = "grades.db";
const char USERS_DB[] = "users.db";

const char MAIN_MENU_TEXT[] = "Main Menu\n1. Add Data\n2. Edit Data\n3. Delete Data\n4. View Data\n5. Use Command Line Environment\n6. Exit\nEnter 1-6\n";
const char ADD_DATA_MENU_TEXT[] = "Add Data Menu\n1. Add Student\n2. Add Class\n3. Add Assignment\n4. Add Grade\n5. Enroll Student\n6. Return to Main Menu\nEnter 1-6\n";
const char EDIT_DATA_MENU_TEXT[] = "Edit Data Menu\n1. Edit Student\n2. Edit Class\n3. Edit Assignment\n4. Edit Grade\n5. Return to Main Menu\nEnter 1-5\n";
const char DELETE_DATA_MENU_TEXT[] = "Delete Data Menu\n1. Delete Student\n2. Delete Class\n3. Delete Assignment\n4. Delete Grade\n5. Drop Student\n6. Return to Main Menu\nEnter 1-6\n";
const char VIEW_DATA_MENU_TEXT[] = "View Data Menu\n1. View Students\n2. View Classes\n3. View Assignments\n4. View Grades\n5. View Enrollment\n6. Return to Main Menu\nEnter 1-6\n";
const char VIEW_GRADES_MENU_TEXT[] = "View Grades Menu\n1. View Class Average Grade\n2. View Student Average Grades\n3. View Class Assignment Average Grades\n4. View Class Assignment Grades\n5. Return to Main Menu\nEnter 1-5\n";

const char ADD_STUDENT_PROMPTS[3][60] = {
  {"Enter First Name\n"},
  {"Enter Last Name\n"},
  {"Enter Student SSN\n"}
};
const char ADD_CLASS_PROMPTS[1][60] = {
  {"Enter Class Title\n"}
};
const char ADD_ASSIGNMENT_PROMPTS[3][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment Title\n"},
  {"Enter Point Value\n"}
};
const char ADD_GRADE_PROMPTS[4][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"},
  {"Enter Student SSN\n"},
  {"Enter Earned Points\n"}
};
const char ENROLL_STUDENT_PROMPTS[2][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Student SSN\n"}
};
const char EDIT_STUDENT_PROMPTS[3][60] = {
  {"Enter Student SSN\n"},
  {"Enter New First Name ( or leave blank for no change )\n"},
  {"Enter New Last Name ( or leave blank for no change )\n"}
};
const char EDIT_CLASS_PROMPTS[2][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter New Class Title ( or leave blank for no change )\n"}
};
const char EDIT_ASSIGNMENT_PROMPTS[4][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"},
  {"Enter New Title (or leave blank for no change)\n"},
  {"Enter New Point Value (or leave blank for no change)\n"}
};
const char EDIT_GRADE_PROMPTS[4][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"},
  {"Enter Student SSN\n"},
  {"Enter New Earned Points (or leave blank for no change)\n"}
};
const char DELETE_STUDENT_PROMPTS[2][60] = {
  {"Enter SSN\n"},
  {"Are you sure you wish to delete \n"}
};
const char DELETE_CLASS_PROMPTS[2][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Are you sure you wish to delete \n"}
};
const char DELETE_ASSIGNMENT_PROMPTS[3][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"},
  {"Are you sure you wish to delete \n"}
};
const char DELETE_GRADE_PROMPTS[4][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"},
  {"Enter Student SSN\n"},
  {"Are you sure you wish to delete \n"}
};
const char DROP_STUDENT_PROMPTS[3][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Student SSN\n"},
  {"Are you sure you wish to delete \n"}
};
const char VIEW_ASSIGNMENTS_PROMPTS[1][60] = {
  {"Enter Class ID or (-1 for Class List)\n"}
};
const char VIEW_ENROLLMENT_PROMPTS[1][60] = {
  {"Enter Class ID or (-1 for Class List)\n"}
};
const char VIEW_CLASS_AVERAGE_PROMPTS[1][60] = {
  {"Enter Class ID or (-1 for Class List)\n"}
};
const char VIEW_STUDENT_AVERAGE_PROMPTS[1][60] = {
  {"Enter Student SSN\n"}
};
const char VIEW_CLASS_ASSIGNMENT_AVERAGE_PROMPTS[1][60] = {
  {"Enter Class ID or (-1 for Class List)\n"}
};
const char VIEW_CLASS_ASSIGNMENT_GRADES_PROMPTS[2][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"}
};
const char VIEW_GRADES_PROMPTS[2][60] = {
  {"Enter Class ID or (-1 for Class List)\n"},
  {"Enter Assignment ID or (-1 for Assignment List)\n"}
};
const char YES_NO[] = "(Y/N)?\n";
const char INVALID_INPUT[] = "Invalid Input\n";

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
//  int course_id;  // ******* TODO ****** REMOVE COURSE_ID FROM GRADE//
  int assignment_id;
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
void makeGradeSentinel(void);
int clearGradeList(void);
void fillGradeList(void);
void writeGradesList(void);
void addGradeList(Grade_Node *toAdd);
void toAddEnrollment(void);
void makeEnrollmentSentinel(void);
int clearEnrollList(void);
void fillEnrollList(void);
void writeEnrollList(void);
void addEnrollList(Enrollment_Node *toAdd);
void toEditStudent(void);
int ssnsAreEqual(char* ssn1, char* ssn2);
Student* studentExists(char* ssn);
void toEditCourse(void);
Course* courseExists(int course_id);
void toEditAssignment(void);
Assignment* assignExists(int course_id, int assignment_id);
void toEditGrade(void);
Grade* gradeExists(int assignment_id, char* ssn);
void toDeleteStudent(void);
void deleteAStudent(Student_Node *toRemove);
void deleteACourse(Course_Node *toRemove);
void deleteAnAssignment(Assignment_Node *toRemove);
void deleteAGrade(Grade_Node *toRemove);
void deleteEnrollment(Enrollment_Node *toRemove);
Student_Node* studentNodeExists(char* ssn);
Course_Node* courseNodeExists(int course_id);
void toDeleteCourse(void);
Assignment_Node* assignNodeExists(int course_id, int assignment_id);
void toDeleteAssignment(void);
Grade_Node* gradeNodeExists(int assignment_id, char* ssn);
void toDeleteGrade(void);
Enrollment_Node* enrollNodeExists(int course_id, char* ssn);
void toDeleteEnrollment(void);
void printGradeNode(Grade_Node* toPrint);
void printStudentNode(Student_Node* toPrint);
void printCourseNode(Course_Node* toPrint);
void printEnrollNode(Enrollment_Node* toPrint);
void printAssignmentNode(Assignment_Node* toPrint);
void printAssignments(void);
void printEnrollment(void);
void printCourses(void);
void printStudents(void);
void printGrades(void);
void toViewGradesMenu(void);
void retrieveSSN(char* name);
void toViewAssignments(void);
void toViewClassAverage(void);
void toViewStudentAverage(void);
void toViewClassAssignmentGrades(void);
void toViewClassAssignmentAvgGrades(void);
void giveCoursePrintAssigns(int courseID);

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

int highestCourseID;
int highestAssignmentID;

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
  highestAssignmentID = 0;
  highestCourseID = 0;
  makeSentinel();
  makeStudentSentinel();
  makeCourseSentinel();
  makeAssignSentinel();
  makeGradeSentinel();
  makeEnrollmentSentinel();
  fillStudentList();
  fillCourseList();
  fillAssignmentList();
  fillGradeList();
  fillEnrollList();
  //todo: make sure all sentinels are called and lists filled
}

/**
 A function to sub delegate freeing the linked lists for input
 and databases.
 **/
void tearDownLists(void){
  free(inputSentinel);
  free(courseSentinel);
  free(studentSentinel);
  free(assignmentSentinel);
  free(gradeSentinel);
  free(enrollSentinel);
}

/**
 A function that puts a name stored in linked list memory into value at pointer parameter.
 **/
void retrieveName(char* name){
  int counter = 0;
//  int i = 0;
  Input_c *tempNode = inputSentinel->next;
  while(tempNode != inputSentinel && counter < CHAR_INPUT_SIZE){
    name[counter] = tempNode->value;
//    printf("%d: %c -> %c\n", counter, tempNode->value, name[counter]);
    counter++;
    tempNode = tempNode->next;
  }
  while(counter < CHAR_INPUT_SIZE){
    name[counter] = '\0';
//    printf("%d: %c\n", counter, name[counter]);
    counter++;
  }
//  for(i=0; i<30; i++){
//    printf("%c", name[i]);
//  }
//  printf("\n");
}

/**
 A function that puts a ssn stored in linked list memory into value at pointer parameter.
 **/
void retrieveSSN(char* name){
  int counter = 0;
//  int i = 0;
  Input_c *tempNode = inputSentinel->next;
  while(tempNode != inputSentinel && counter < SSN_INPUT_SIZE){
    name[counter] = tempNode->value;
//    printf("%d: %c -> %c\n", counter, tempNode->value, name[counter]);
    counter++;
    tempNode = tempNode->next;
  }
  while(counter < SSN_INPUT_SIZE){
    name[counter] = '\0';
//    printf("%d: %c\n", counter, name[counter]);
    counter++;
  }
//  for(i=0; i<9; i++){
//    printf("%c", name[i]);
//  }
//  printf("\n");
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
      toAddEnrollment();
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
    retrieveSSN(ssnStorage);
    return 1;
  }else{
    return 0;
  }
}

/**
 A function that takes a string pointer and adds a valid name into it.
 **/
int storeNameInput (char* nameStorage){
//  int i = 0;
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(nameStorage);
//    for(i=0; i<30; i++){
//      printf("%c", nameStorage[i]);
//    }
//    printf("\n");
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
    //todo: handle the -1 case for displaying values
    if(temp->value < '0' || temp->value > '9'){
//      printf("input is: %c\n", temp->value);
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
//  int i =0;
  while(1){
    printf("%s", prompt);
    if(storeNameInput(name)){
//      for(i=0; i<30; i++){
//        printf("%c", name[i]);
//      }
//      printf("\n");
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
  char first[CHAR_INPUT_SIZE] = {0};
  char last[CHAR_INPUT_SIZE] = {0};
  char ssnStr[SSN_INPUT_SIZE] = {0};
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
  char title[CHAR_INPUT_SIZE]={0};
  int course_id = ++highestCourseID;
  Course *courseAdd = malloc(sizeof(Course));
  Course_Node *courseNodeAdd = malloc(sizeof(Course_Node));
  printf("Add Class\n");
  getName(ADD_CLASS_PROMPTS[0], title);
  courseAdd->course_id = course_id;
  copyCharArray(courseAdd->course_title, title, CHAR_INPUT_SIZE);
  courseNodeAdd->course = courseAdd;
  addCourseList(courseNodeAdd);
  writeCourseList();
}

/**
 A function that will add a grade to the database.
 **/
void toAddGrade(void){
  int course_id = 0;
  int assignment_id = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  int pts_received = 0;
  int *courseID = &course_id;
  int *ptsReceived = &pts_received;
  int *assignID = &assignment_id;
  Grade *gradeAdd = malloc(sizeof(Grade));
  Grade_Node *gradeNodeAdd = malloc(sizeof(Grade_Node));
  printf("Add Grade\n");
  getInt(ADD_GRADE_PROMPTS[0], courseID);
  giveCoursePrintAssigns(course_id);
  //todo: print assignment id numbers of courseID
  getInt(ADD_GRADE_PROMPTS[1], assignID);
  getSSN(ADD_GRADE_PROMPTS[2], ssn);
  getInt(ADD_GRADE_PROMPTS[3], ptsReceived);
  gradeAdd->assignment_id = assignment_id;
  gradeAdd->pts_received = pts_received;
  copyCharArray(gradeAdd->ssn, ssn, SSN_INPUT_SIZE);
  gradeNodeAdd->grade = gradeAdd;
  addGradeList(gradeNodeAdd);
  writeGradesList();
}


/**
 A function that takes an int (the course ID) and prints all the
 assignments associated with that courseID
 **/
void giveCoursePrintAssigns(int courseID){
  Assignment_Node *temp = assignmentSentinel->next;
  if(temp == NULL){
    return;
  }
  while(temp!=assignmentSentinel){
    if(temp->assignment->course_id == courseID){
      printAssignmentNode(temp);
    }
    temp = temp->next;
  }
}

/**
 A function to enroll a student in a course.
 **/
void toAddEnrollment(void){
  int course_id = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  Enrollment *enrollmentAdd = malloc(sizeof(Enrollment));
  Enrollment_Node *enrollmentNodeAdd = malloc(sizeof(Enrollment_Node));
  printf("Add Enrollment\n");
  getInt(ENROLL_STUDENT_PROMPTS[0], &course_id);
  getSSN(ENROLL_STUDENT_PROMPTS[1], &ssn[0]);
  enrollmentAdd->course_id = course_id;
  copyCharArray(enrollmentAdd->ssn, ssn, SSN_INPUT_SIZE);
  enrollmentNodeAdd->enrollment = enrollmentAdd;
  addEnrollList(enrollmentNodeAdd);
  writeEnrollList();
}

/**
 A function that will add an assignment to database.
 **/
void toAddAssignment(void){
  int assignment_id = ++highestAssignmentID;
  int totPts = 0;
  int courseID = 0;
  char assignment_title[CHAR_INPUT_SIZE] = {0};
  int *pts_total = &totPts;
  int *course_id = &courseID;
  Assignment *assignAdd = malloc(sizeof(Assignment));
  Assignment_Node *assignNodeAdd = malloc(sizeof(Assignment_Node));
  printf("Add Assignment\n");
  getInt(ADD_ASSIGNMENT_PROMPTS[0], course_id);
  getName(ADD_ASSIGNMENT_PROMPTS[1], assignment_title);
  getInt(ADD_ASSIGNMENT_PROMPTS[2], pts_total);
  assignAdd->assignment_id = assignment_id;
  assignAdd->course_id = courseID;
  assignAdd->pts_total = totPts;
  copyCharArray(assignAdd->assignment_title, assignment_title, CHAR_INPUT_SIZE);
  assignNodeAdd->assignment = assignAdd;
  addAssignmentList(assignNodeAdd);
  writeAssignmentList();
}

/**
 A function that will retrieve a student entry, edit it,
 and update the student list and db to reflect changes.
 **/
void toEditStudent(void){
  int flag = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  char first[CHAR_INPUT_SIZE] = {0};
  char last[CHAR_INPUT_SIZE] = {0};
  Student *toEdit = NULL;
  while(1){
    getSSN(EDIT_STUDENT_PROMPTS[0], &ssn[0]);
    if((toEdit = studentExists(&ssn[0])) != NULL){
      break;
    }
  }
  printf("%s",EDIT_STUDENT_PROMPTS[1]);
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(&first[0]);
    copyCharArray(toEdit->first, first, CHAR_INPUT_SIZE);
    flag = 1;
  }
  printf("%s",EDIT_STUDENT_PROMPTS[2]);
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(&last[0]);
    copyCharArray(toEdit->last, last, CHAR_INPUT_SIZE);
    flag = 1;
  }
  if(flag){
    writeStudentList();
  }
//  printf("%c %c %c\n", studentSentinel->next->student->first[0], studentSentinel->next->student->last[0], studentSentinel->next->student->ssn[0]);
}

/**
 A function that will retrieve a course entry, edit it,
 and update the course list and db to reflect changes.
 **/
void toEditCourse(void){
  int flag = 0;
  int course_id = 0;
  char course_title[CHAR_INPUT_SIZE] = {0};
  Course *toEdit = NULL;
  while(1){
    getInt(EDIT_CLASS_PROMPTS[0], &course_id);
    if((toEdit = courseExists(course_id)) != NULL){
      break;
    }
  }
  printf("%s", EDIT_CLASS_PROMPTS[1]);
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(&course_title[0]);
    copyCharArray(toEdit->course_title, course_title, CHAR_INPUT_SIZE);
    flag = 1;
  }
  if(flag){
    writeCourseList();
  }
}

/**
 A function that will retrieve a course entry, edit it,
 and update the course list and db to reflect changes.
 **/
void toEditAssignment(void){
  int flag = 0;
  int assignment_id = 0;
  char assignment_title[CHAR_INPUT_SIZE] = {0};
  int pts_total = 0;
  int course_id = 0;
  Assignment *toEdit = NULL;
  while(1){
    getInt(EDIT_ASSIGNMENT_PROMPTS[0], &course_id);
    getInt(EDIT_ASSIGNMENT_PROMPTS[1], &assignment_id);
    if((toEdit = assignExists(course_id, assignment_id)) != NULL){
      break;
    }
    printf("Invalid Class ID / Assignment ID combination.\n");
  }
  printf("%s", EDIT_ASSIGNMENT_PROMPTS[2]);
  clearLine();
  grabLine();
  if(inputSize != 0){
    retrieveName(&assignment_title[0]);
    copyCharArray(toEdit->assignment_title, assignment_title, CHAR_INPUT_SIZE);
    flag = 1;
  }
  printf("%s", EDIT_ASSIGNMENT_PROMPTS[3]);
  clearLine();
  grabLine();
  //todo: change this to validate in a loop
  if(inputSize != 0){
    retrieveInt(&pts_total);
    toEdit->pts_total = pts_total;
    flag = 1;
  }
  if(flag){
    writeAssignmentList();
  }
}

/**
 A function that will retrieve a grade entry, edit it,
 and update the grade list and db to reflect changes.
 **/
void toEditGrade(void){
  int flag = 0;
  int course_id = 0;
  int assignment_id = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  int pts_received = 0;
  Grade *toEdit = NULL;
  while(1){
    getInt(EDIT_GRADE_PROMPTS[0], &course_id);
    //todo: print list of assignments attached to courseid
    getInt(EDIT_GRADE_PROMPTS[1], &assignment_id);
    getSSN(EDIT_GRADE_PROMPTS[2], &ssn[0]);
    if((toEdit = gradeExists(assignment_id, ssn)) != NULL){
      break;
    }
    printf("Invalid Class ID/Assignment ID/SSN combination.\n");
  }
  printf("%s", EDIT_GRADE_PROMPTS[3]);
  clearLine();
  grabLine();
  //todo: change this to validate in a loop
  if(inputSize != 0){
    retrieveInt(&pts_received);
    toEdit->pts_received = pts_received;
    flag = 1;
  }
  if(flag){
    writeGradesList();
  }
}

/**
 A function that will delete a student from the students
 linked list and database.
 **/
void toDeleteStudent(void){
  char ssn[SSN_INPUT_SIZE] = {0};
  Student_Node *toDelete = NULL;
  while(1){
    getSSN(DELETE_STUDENT_PROMPTS[0], &ssn[0]);
    if((toDelete = studentNodeExists(&ssn[0])) != NULL){
      break;
    }
  }
  while(1){
    printf("%s",DELETE_STUDENT_PROMPTS[1]);
    clearLine();
    grabLine();
    if(inputSize==1){
      if(inputSentinel->next->value == 'y'
         || inputSentinel->next->value == 'Y'){
        break;
      }
      if(inputSentinel->next->value == 'n'
         || inputSentinel->next->value == 'N'){
        return;
      }
    }
  }
  deleteAStudent(toDelete);
  writeStudentList();
}

/**
 A function that will delete a class from the classes
 linked list and database.
 **/
void toDeleteCourse(void){
  int course_id = 0;
  Course_Node *toDelete = NULL;
  while(1){
    getInt(DELETE_CLASS_PROMPTS[0], &course_id);
    if((toDelete = courseNodeExists(course_id)) != NULL){
      break;
    }
  }
  while(1){
    printf("%s",DELETE_CLASS_PROMPTS[1]);
    clearLine();
    grabLine();
    if(inputSize==1){
      if(inputSentinel->next->value == 'y'
         || inputSentinel->next->value == 'Y'){
        break;
      }
      if(inputSentinel->next->value == 'n'
         || inputSentinel->next->value == 'N'){
        return;
      }
    }
  }
  deleteACourse(toDelete);
  writeCourseList();
}

/**
 A functino that queries user for course id and then
 displays the associated assignment records.
 **/
void toViewAssignments(void){
  int course_id = 0;
  Assignment_Node *toCheck = assignmentSentinel->next;
  getInt(VIEW_ASSIGNMENTS_PROMPTS[0], &course_id);
  while(toCheck != assignmentSentinel){
    if(toCheck->assignment->course_id == course_id){
      printAssignmentNode(toCheck);
    }
    toCheck = toCheck->next;
  }
}

/**
 A function that queries user for course id and then
 displays the associated enrollment records.
 **/
void toViewEnrollment(void){
  int course_id = 0;
  Enrollment_Node *toCheck = enrollSentinel->next;
  if(toCheck == NULL){
    return;
  }
  getInt(VIEW_ENROLLMENT_PROMPTS[0], &course_id);
  while(toCheck != enrollSentinel){
    if(toCheck->enrollment->course_id == course_id){
      printEnrollNode(toCheck);
    }
    toCheck = toCheck->next;
  }
}

/**
 A function that queries user for course id and then
 displays the average grades for that course.
 **/
void toViewClassAverage(void){
  //todo: implement this functionality
}

/**
 A function that queries user for ssn and then
 displays the average grades for that student.
 **/
void toViewStudentAverage(void){
  //todo: implement this functionality
}

/**
 A function that queries user for course id and then
 displays the averages grades for each assignment.
 **/
void toViewClassAssignmentAvgGrades(void){
  //todo: implement this functionality
}

/**
 A function that queries user for course id and assignment id
 and displays each corresponding grade record.
 **/
void toViewClassAssignmentGrades(void){
  int course_id = 0;
  int assignment_id = 0;
  Grade_Node *toCheck = gradeSentinel->next;
  if(toCheck == NULL){
    return;
  }
  getInt(VIEW_CLASS_ASSIGNMENT_GRADES_PROMPTS[0], &course_id);
  //todo: print the assignments for a course
  getInt(VIEW_CLASS_ASSIGNMENT_GRADES_PROMPTS[1], &assignment_id);
  while(toCheck != gradeSentinel){
    if(toCheck->grade->assignment_id == assignment_id){
      printGradeNode(toCheck);
    }
    toCheck = toCheck->next;
  }
}

/**
 A function that will delete an assignment from the assignments
 linked list and database.
 **/
void toDeleteAssignment(void){
  int course_id = 0;
  int assignment_id = 0;
  Assignment_Node *toDelete = NULL;
  while(1){
    getInt(DELETE_ASSIGNMENT_PROMPTS[0], &course_id);
    getInt(DELETE_ASSIGNMENT_PROMPTS[1], &assignment_id);
    if((toDelete = assignNodeExists(course_id, assignment_id)) != NULL){
      break;
    }
    printf("Invalid Class ID / Assignment ID combination.\n");
  }
  while(1){
    printf("%s",DELETE_ASSIGNMENT_PROMPTS[2]);
    clearLine();
    grabLine();
    if(inputSize==1){
      if(inputSentinel->next->value == 'y'
         || inputSentinel->next->value == 'Y'){
        break;
      }
      if(inputSentinel->next->value == 'n'
         || inputSentinel->next->value == 'N'){
        return;
      }
    }
  }
  deleteAnAssignment(toDelete);
  writeAssignmentList();
}

/**
 A function that will delete a grade from the grades
 linked list and database.
 **/
void toDeleteGrade(void){
  int course_id = 0;
  int assignment_id = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  Grade_Node *toDelete = NULL;
  while(1){
    getInt(DELETE_GRADE_PROMPTS[0], &course_id);
    //todo: print out grades associated with course id
    getInt(DELETE_GRADE_PROMPTS[1], &assignment_id);
    getSSN(DELETE_GRADE_PROMPTS[2], &ssn[0]);
    if((toDelete = gradeNodeExists(assignment_id, ssn)) != NULL){
      break;
    }
    printf("Invalid Class ID/Assignment ID/SSN combination.\n");
    return;
  }
  while(1){
    printf("%s",DELETE_GRADE_PROMPTS[3]);
    clearLine();
    grabLine();
    if(inputSize==1){
      if(inputSentinel->next->value == 'y'
         || inputSentinel->next->value == 'Y'){
        break;
      }
      if(inputSentinel->next->value == 'n'
         || inputSentinel->next->value == 'N'){
        return;
      }
    }
  }
  deleteAGrade(toDelete);
  writeGradesList();
}

/**
 A function that will delete an enrollment from the enrollment
 linked list and database.
 **/
void toDeleteEnrollment(void){
  int course_id = 0;
  char ssn[SSN_INPUT_SIZE] = {0};
  Enrollment_Node *toDelete = NULL;
  while(1){
    getInt(DROP_STUDENT_PROMPTS[0], &course_id);
    getSSN(DROP_STUDENT_PROMPTS[1], &ssn[0]);
    if((toDelete = enrollNodeExists(course_id, ssn)) != NULL){
      break;
    }
    printf("Invalid Class ID/Assignment ID/SSN combination.\n");
  }
  while(1){
    printf("%s",DROP_STUDENT_PROMPTS[2]);
    clearLine();
    grabLine();
    if(inputSize==1){
      if(inputSentinel->next->value == 'y'
         || inputSentinel->next->value == 'Y'){
        break;
      }
      if(inputSentinel->next->value == 'n'
         || inputSentinel->next->value == 'N'){
        return;
      }
    }
  }
  deleteEnrollment(toDelete);
  writeEnrollList();
}

/**
 A function that takes two ints and looks for a course/assignment match in
 the enroll linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Enrollment_Node* enrollNodeExists(int course_id, char* ssn){
  Enrollment_Node *temp = enrollSentinel->next;
  while(temp != enrollSentinel){
    if(course_id == temp->enrollment->course_id
       && ssnsAreEqual(ssn, temp->enrollment->ssn)){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes two ints and looks for a course/assignment match in
 the assignments linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Grade* gradeExists(int assignment_id, char* ssn){
  Grade_Node *temp = gradeSentinel->next;
  while(temp != gradeSentinel){
    if(assignment_id == temp->grade->assignment_id
       && ssnsAreEqual(ssn, temp->grade->ssn)){
      return temp->grade;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes two ints and looks for a course/assignment match in
 the assignments linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Grade_Node* gradeNodeExists(int assignment_id, char* ssn){
  Grade_Node *temp = gradeSentinel->next;
  while(temp != gradeSentinel){
    if(assignment_id == temp->grade->assignment_id
       && ssnsAreEqual(ssn, temp->grade->ssn)){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}


/**
 A function that takes two ints and looks for a course/assignment match in
 the assignments linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Assignment* assignExists(int course_id, int assignment_id){
  Assignment_Node *temp = assignmentSentinel->next;
  while(temp != assignmentSentinel){
    if(course_id == temp->assignment->course_id
       && assignment_id == temp->assignment->assignment_id){
      return temp->assignment;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes two ints and looks for a course/assignment match in
 the assignments linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Assignment_Node* assignNodeExists(int course_id, int assignment_id){
  Assignment_Node *temp = assignmentSentinel->next;
  while(temp != assignmentSentinel){
    if(course_id == temp->assignment->course_id
       && assignment_id == temp->assignment->assignment_id){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes an int and looks for a match in the
 courses linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Course* courseExists(int course_id){
  Course_Node *temp = courseSentinel->next;
  while(temp != courseSentinel){
    if(course_id == temp->course->course_id){
      return temp->course;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes an int and looks for a match in the
 courses linked list.  If found, returns
 pointer parameter to the correspoding node.
 **/
Course_Node* courseNodeExists(int course_id){
  Course_Node *temp = courseSentinel->next;
  while(temp != courseSentinel){
    if(course_id == temp->course->course_id){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes a SSN and looks for a match in the
 Students linked list.  If found, returns 1 and sets the node
 pointer parameter to the correspoding node.
 **/
Student* studentExists(char* ssn){
  Student_Node *temp = studentSentinel->next;
  while(temp != studentSentinel){
    if(ssnsAreEqual(ssn, temp->student->ssn)){
      return temp->student;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 A function that takes a SSN and looks for a match in the
 Students linked list.  If found, returns 1 and sets the node
 pointer parameter to the correspoding node.
 **/
Student_Node* studentNodeExists(char* ssn){
  Student_Node *temp = studentSentinel->next;
  while(temp != studentSentinel){
    if(ssnsAreEqual(ssn, temp->student->ssn)){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

/**
 Function that returns 1 if passed in SSNs are equal.
 **/
int ssnsAreEqual(char* ssn1, char* ssn2){
  int i = 0;
  for(i=0; i<SSN_INPUT_SIZE; i++){
    if(ssn1[i]!=ssn2[i]){
      return 0;
    }
  }
  return 1;
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
      toDeleteStudent();
      break;
    case '2':
      toDeleteCourse();
      break;
    case '3':
      toDeleteAssignment();
      break;
    case '4':
      toDeleteGrade();
      break;
    case '5':
      toDeleteEnrollment();
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
      printStudents();
      break;
    case '2':
      printCourses();
      break;
    case '3':
      toViewAssignments();
      break;
    case '4':
      toViewGradesMenu();
      break;
    case '5':
      toViewEnrollment();
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
 A function to display the view grades menu and handle user selection.
 **/
void toViewGradesMenu(void){
  printf("%s", VIEW_GRADES_MENU_TEXT);
  clearLine();
  grabLine();
  if(inputSize != 1 ||
     !isMenuSelectionValid(VIEW_G_MENU_OPTS, inputSentinel->next->value)){
    printf("%s", INVALID_INPUT);
    toViewGradesMenu();
  }
  switch (inputSentinel->next->value) {
    case '1':
      toViewClassAverage();
      break;
    case '2':
      toViewStudentAverage();
      break;
    case '3':
      toViewClassAssignmentAvgGrades();
      break;
    case '4':
      toViewClassAssignmentGrades();
      break;
    case '5':
      return;
    default:
      printf("Unexpected Error, try again.\n");
      break;
  }
  toViewGradesMenu();
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
      toEditStudent();
      break;
    case '2':
      toEditCourse();
      break;
    case '3':
      toEditAssignment();
      break;
    case '4':
      toEditGrade();
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
 A function to add an grade node onto the end of the grade linked list.
 **/
void addGradeList(Grade_Node *toAdd){
  if(gradeSentinel->next == NULL && gradeSentinel->previous == NULL){
    gradeSentinel->next = toAdd;
    gradeSentinel->previous = toAdd;
    toAdd->next = gradeSentinel;
    toAdd->previous = gradeSentinel;
    gradeSize = 1;
  }else{
    gradeSentinel->previous->next = toAdd;
    toAdd->next = gradeSentinel;
    toAdd->previous = gradeSentinel->previous;
    gradeSentinel->previous = toAdd;
    gradeSize++;
  }
}

/**
 A function to add an enrollment node onto the end of the enrollment linked list.
 **/
void addEnrollList(Enrollment_Node *toAdd){
  if(enrollSentinel->next == NULL && enrollSentinel->previous == NULL){
    enrollSentinel->next = toAdd;
    enrollSentinel->previous = toAdd;
    toAdd->next = enrollSentinel;
    toAdd->previous = enrollSentinel;
    enrollSize = 1;
  }else{
    enrollSentinel->previous->next = toAdd;
    toAdd->next = enrollSentinel;
    toAdd->previous = enrollSentinel->previous;
    enrollSentinel->previous = toAdd;
    enrollSize++;
  }
}

/**
 A function to remove a student node from the students linked list.
 Assumes that the passed in student node has already been confirmed to exist
 in the students linked list.
 **/
void deleteAStudent(Student_Node *toRemove){
  Student_Node *previous = NULL;
  Student_Node *next = NULL;
  if(toRemove == NULL){
    return;
  }
  previous = toRemove->previous;
  next = toRemove->next;
  previous->next = next;
  next->previous = previous;
  if(toRemove->student != NULL){
    free(toRemove->student);
  }
  free(toRemove);
  studentSize--;
}

/**
 A function to remove a course node from the courses linked list.
 Assumes that the passed in course node has already been confirmed to exist
 in the courses linked list.
 **/
void deleteACourse(Course_Node *toRemove){
  Course_Node *previous = NULL;
  Course_Node *next = NULL;
  if(toRemove == NULL){
    return;
  }
  previous = toRemove->previous;
  next = toRemove->next;
  previous->next = next;
  next->previous = previous;
  if(toRemove->course != NULL){
    free(toRemove->course);
  }
  free(toRemove);
  courseSize--;
}

/**
 A function to remove an assignment node from the assignments linked list.
 Assumes that the passed in assignment node has already been confirmed to exist
 in the assignments linked list.
 **/
void deleteAnAssignment(Assignment_Node *toRemove){
  Assignment_Node *previous = NULL;
  Assignment_Node *next = NULL;
  if(toRemove == NULL){
    return;
  }
  previous = toRemove->previous;
  next = toRemove->next;
  previous->next = next;
  next->previous = previous;
  if(toRemove->assignment != NULL){
    free(toRemove->assignment);
  }
  free(toRemove);
  assignmentSize--;
}

/**
 A function to remove a grade node from the grades linked list.
 Assumes that the passed in grade node has already been confirmed to exist
 in the grades linked list.
 **/
void deleteAGrade(Grade_Node *toRemove){
  Grade_Node *previous = NULL;
  Grade_Node *next = NULL;
  if(toRemove == NULL){
    return;
  }
  previous = toRemove->previous;
  next = toRemove->next;
  previous->next = next;
  next->previous = previous;
  if(toRemove->grade != NULL){
    free(toRemove->grade);
  }
  free(toRemove);
  gradeSize--;
}

/**
 A function to remove a course node from the courses linked list.
 Assumes that the passed in course node has already been confirmed to exist
 in the courses linked list.
 **/
void deleteEnrollment(Enrollment_Node *toRemove){
  Enrollment_Node *previous = NULL;
  Enrollment_Node *next = NULL;
  if(toRemove == NULL){
    return;
  }
  previous = toRemove->previous;
  next = toRemove->next;
  previous->next = next;
  next->previous = previous;
  if(toRemove->enrollment != NULL){
    free(toRemove->enrollment);
  }
  free(toRemove);
  enrollSize--;
}


/**
 A function to write the contents of the student linked list into
 the Student database. Overwrites the Student database.
 **/
void writeStudentList(void){
  FILE *fp = fopen(STUDENTS_DB, "w");
  Student_Node *toAdd = studentSentinel->next;
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
  FILE *fp = fopen(CLASSES_DB, "w");
  Course_Node *toAdd = courseSentinel->next;
  
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
  FILE *fp = fopen(ASSIGNMENTS_DB, "w");
  Assignment_Node *toAdd = assignmentSentinel->next;
  
  while(toAdd != assignmentSentinel && toAdd != NULL){
    fwrite(toAdd->assignment, sizeof(Assignment), 1, fp);
    toAdd = toAdd->next;
  }
  fclose(fp);
}

/**
 A functin to write the contents of the grades linked list into
 the grades database.  Overwrites the grades database.
 **/
void writeGradesList(void){
  FILE *fp = fopen(GRADES_DB, "w");
  Grade_Node *toAdd = gradeSentinel->next;
  
  while(toAdd != gradeSentinel && toAdd != NULL){
    fwrite(toAdd->grade, sizeof(Grade), 1, fp);
    toAdd = toAdd->next;
  }
  fclose(fp);
}

/**
 A functin to write the contents of the enrollment linked list into
 the enrollment database.  Overwrites the enrollment database.
 **/
void writeEnrollList(void){
  FILE *fp = fopen(ENROLLMENT_DB, "w");
  Enrollment_Node *toAdd = enrollSentinel->next;
  
  while(toAdd != enrollSentinel && toAdd != NULL){
    fwrite(toAdd->enrollment, sizeof(Enrollment), 1, fp);
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
      if(fread(studentAdd, sizeof(Student), 1, fp)){
        studentNodeAdd->student = studentAdd;
        addStudentList(studentNodeAdd);
      };
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
      if(fread(courseAdd, sizeof(Course), 1, fp)){
        courseNodeAdd->course = courseAdd;
        addCourseList(courseNodeAdd);
      };
    }
    fclose(fp);
  }else{
    fp = fopen(CLASSES_DB, "w");
    fclose(fp);
  }
  if(courseSentinel->previous == NULL){
    return;
  }
  if(courseSentinel->previous->course->course_id > highestCourseID){
    highestCourseID = courseSentinel->previous->course->course_id;
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
      if(fread(assignAdd, sizeof(Assignment), 1, fp)){
        assignNodeAdd->assignment = assignAdd;
        addAssignmentList(assignNodeAdd);
      };
    }
    fclose(fp);
  }else{
    fp = fopen(ASSIGNMENTS_DB, "w");
    fclose(fp);
  }
  if(assignmentSentinel->previous == NULL){
    return;
  }
  if(assignmentSentinel->previous->assignment->assignment_id > highestAssignmentID){
    highestAssignmentID = assignmentSentinel->previous->assignment->assignment_id;
  }
}

/**
 A function to read one grade at a time from the grade database,
 then adds the course to a grade node, which is added to the grade
 linked list.
 **/
void fillGradeList(void){
  FILE *fp;
  if((fp = fopen(GRADES_DB, "r")) != NULL){
    //file exists, fill course list
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
      Grade *gradeAdd = malloc(sizeof(Grade));
      Grade_Node *gradeNodeAdd = malloc(sizeof(Grade_Node));
      if(fread(gradeAdd, sizeof(Grade), 1, fp)){
        gradeNodeAdd->grade = gradeAdd;
        addGradeList(gradeNodeAdd);
      };
    }
    fclose(fp);
  }else{
    fp = fopen(GRADES_DB, "w");
    fclose(fp);
  }
}

/**
 A function to read one enrollment at a time from the enrollment database,
 then adds the course to a enrollment node, which is added to the enrollment
 linked list.
 **/
void fillEnrollList(void){
  FILE *fp;
  if((fp = fopen(ENROLLMENT_DB, "r")) != NULL){
    //file exists, fill course list
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp)){
      Enrollment *enrollAdd = malloc(sizeof(Enrollment));
      Enrollment_Node *enrollNodeAdd = malloc(sizeof(Enrollment_Node));
      if(fread(enrollAdd, sizeof(Enrollment), 1, fp)){
        enrollNodeAdd->enrollment = enrollAdd;
        addEnrollList(enrollNodeAdd);
      };
    }
    fclose(fp);
  }else{
    fp = fopen(ENROLLMENT_DB, "w");
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
 A function to clear the grade linked list.
 **/
int clearGradeList(void){
  if(gradeSize == 0){
    return 1;
  }
  Grade_Node *toClear = gradeSentinel->previous;
  while(toClear != gradeSentinel){
    Grade_Node *nextClear = toClear->previous;
    if(toClear->grade != NULL){
      free(toClear->grade);
    }
    free(toClear);
    toClear = nextClear;
  }
  gradeSentinel->next = NULL;
  gradeSentinel->previous = NULL;
  gradeSize = 0;
  return 1;
}

/**
 A function to clear the enroll linked list.
 **/
int clearEnrollList(void){
  if(enrollSize == 0){
    return 1;
  }
  Enrollment_Node *toClear = enrollSentinel->previous;
  while(toClear != enrollSentinel){
    Enrollment_Node *nextClear = toClear->previous;
    if(toClear->enrollment != NULL){
      free(toClear->enrollment);
    }
    free(toClear);
    toClear = nextClear;
  }
  enrollSentinel->next = NULL;
  enrollSentinel->previous = NULL;
  enrollSize = 0;
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
 A helper function to build the grade sentinel node and
 store a reference to it in the global variable.
 **/
void makeGradeSentinel(void){
  gradeSize = 0;
  gradeSentinel = malloc(sizeof(Grade_Node));
  gradeSentinel->next = NULL;
  gradeSentinel->previous = NULL;
}

/**
 A helper function to build the enroll sentinel node and
 store a reference to it in the global variable.
 **/
void makeEnrollmentSentinel(void){
  enrollSize = 0;
  enrollSentinel = malloc(sizeof(Enrollment_Node));
  enrollSentinel->next = NULL;
  enrollSentinel->previous = NULL;
}

/**
 A function that takes a Student Node and prints the attached
 Student record.
 **/
void printStudentNode(Student_Node* toPrint){
  int i = 0;
  for(i=0; i<SSN_INPUT_SIZE; i++){
    printf("%c", toPrint->student->ssn[i]);
  }
  printf(" \n");
  for(i=0; i<CHAR_INPUT_SIZE; i++){
    printf("%c", toPrint->student->first[i]);
  }
  printf(" \n");
  for(i=0; i<CHAR_INPUT_SIZE; i++){
    printf("%c", toPrint->student->last[i]);
  }
  printf("\n\n");
}

/**
 A function that prints all student records.
 **/
void printStudents(void){
  Student_Node *temp = studentSentinel->next;
  while(temp != studentSentinel){
    if(temp == NULL){
      break;
    }
    printStudentNode(temp);
    temp = temp->next;
  }
}

/**
 A function that takes a Course Node and prints the attached
 Course record.
 **/
void printCourseNode(Course_Node* toPrint){
  int i = 0;
  printf("%d ", toPrint->course->course_id);
  for(i=0; i<CHAR_INPUT_SIZE; i++){
    printf("%c", toPrint->course->course_title[i]);
  }
  printf("\n");
}

/**
 A function that prints all course records.
 **/
void printCourses(void){
  Course_Node *temp = courseSentinel->next;
  while(temp != courseSentinel){
    if(temp == NULL){
      break;
    }
    printCourseNode(temp);
    temp = temp->next;
  }
}

/**
 A function that takes a Enrollment Node and prints the attached
 Enrollment record.
 **/
void printEnrollNode(Enrollment_Node* toPrint){
  int i = 0;
  printf("%d ", toPrint->enrollment->course_id);
  for(i=0; i<SSN_INPUT_SIZE; i++){
    printf("%c", toPrint->enrollment->ssn[i]);
  }
  printf("\n");
}

/**
 A function that prints all enroll records.
 **/
void printEnrollment(void){
  Enrollment_Node *temp = enrollSentinel->next;
  while(temp != enrollSentinel){
    if(temp == NULL){
      break;
    }
    printEnrollNode(temp);
    temp = temp->next;
  }
}

/**
 A function that takes a assignment Node and prints the attached
 assignment record.
 **/
void printAssignmentNode(Assignment_Node* toPrint){
  int i = 0;
  printf("Assignment ID: %d ,", toPrint->assignment->assignment_id);
  for(i=0; i<CHAR_INPUT_SIZE; i++){
    printf("%c", toPrint->assignment->assignment_title[i]);
  }
  printf(", Course ID: %d ,", toPrint->assignment->course_id);
  printf(" Points: %d", toPrint->assignment->pts_total);
  printf("\n");
}

/**
 A function that prints all assignment records.
 **/
void printAssignments(void){
  Assignment_Node *temp = assignmentSentinel->next;
  while(temp != assignmentSentinel){
    if(temp == NULL){
      break;
    }
    printAssignmentNode(temp);
    temp = temp->next;
  }
}


/**
 A function that takes a grade Node and prints the attached
 grade record.
 **/
void printGradeNode(Grade_Node* toPrint){
  int i = 0;
  printf("%d ", toPrint->grade->assignment_id);
  for(i=0; i<SSN_INPUT_SIZE; i++){
    printf("%c", toPrint->grade->ssn[i]);
  }
  printf(" %d", toPrint->grade->pts_received);
  printf("\n");
}

/**
 A function that prints all grade records.
 **/
void printGrades(void){
  Grade_Node *temp = gradeSentinel->next;
  while(temp != gradeSentinel){
    if(temp == NULL){
      break;
    }
    printGradeNode(temp);
    temp = temp->next;
  }
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
