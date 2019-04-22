//
//  bb_strings.h
//  241FinalProj
//
//  Created by Brian on 4/14/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#ifndef bb_strings_h
#define bb_strings_h

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

#endif /* bb_strings_h */
