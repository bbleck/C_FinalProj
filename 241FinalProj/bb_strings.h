//
//  bb_strings.h
//  241FinalProj
//
//  Created by Brian on 4/14/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#ifndef bb_strings_h
#define bb_strings_h

const char MAIN_MENU_TEXT[] = "1. Add Data\n2. Edit Data\n3. Delete Data\n4. View Data\n5. Use Command Line Environment\n6. Exit\n";
const char ADD_DATA_MENU_TEXT[] = "1. Add Student\n2. Add Class\n3. Add Assignment\n4. Add Grade\n5. Enroll Student\n6. Return to Main Menu\n";
const char EDIT_DATA_MENU_TEXT[] = "1. Edit Student\n2. Edit Class\n3. Edit Assignment\n4. Edit Grade\n5. Return to Main Menu\n";
const char DELETE_DATA_MENU_TEXT[] = "1. Delete Student\n2. Delete Class\n3. Delete Assignment\n4. Delete Grade\n5. Drop Student\n6. Return to Main Menu\n";
const char VIEW_DATA_MENU_TEXT[] = "1. View Students\n2. View Classes\n3. View Assignments\n4. View Grades\n5. View Enrollment\n6. Return to Main Menu\n";
const char VIEW_GRADES_MENU_TEXT[] = " 1. View Class Average Grade\n2. View Student Average Grades\n3. View Class Assignment Average Grades\n4. View Class Assignment Grades\n5. Return to Main Menu\n";

const char ADD_STUDENT_PROMPTS[3][] = {
  {"Enter First Name"},
  {"Enter Last Name"},
  {"Enter Student SSN"}
};
const char ADD_CLASS_PROMPTS[1][] = {
  {"Enter Class Title"}
};
const char ADD_ASSIGNMENT_PROMPTS[3][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment Title"},
  {"Enter Point Value"}
};
const char ADD_GRADE_PROMPTS[4][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"},
  {"Enter Student SSN"},
  {"Enter Earned Points"}
};
const char ENROLL_STUDENT_PROMPTS[2][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Student SSN"}
};
const char EDIT_STUDENT_PROMPTS[3][] = {
  {"Enter Student SSN"},
  {"Enter New First Name ( or leave blank for no change )"},
  {"Enter New Last Name ( or leave blank for no change )"}
};
const char EDIT_CLASS_PROMPTS[2][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter New Class Title ( or leave blank for no change )"}
};
const char EDIT_ASSIGNMENT_PROMPTS[4][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"},
  {"Enter New Title (or leave blank for no change)"},
  {"Enter New Point Value (or leave blank for no change)"}
};
const char EDIT_GRADE_PROMPTS[4][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"},
  {"Enter Student SSN"},
  {"Enter New Earned Points (or leave blank for no change)"}
};
const char DELETE_STUDENT_PROMPTS[2][] = {
  {"Enter SSN"},
  {"Are you sure you wish to delete "}
};
const char DELETE_CLASS_PROMPTS[2][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Are you sure you wish to delete "}
};
const char DELETE_ASSIGNMENT_PROMPTS[3][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"},
  {"Are you sure you wish to delete "}
};
const char DELETE_GRADE_PROMPTS[4][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"},
  {"Enter Student SSN"},
  {"Are you sure you wish to delete "}
};
const char DROP_STUDENT_PROMPTS[3][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Student SSN"},
  {"Are you sure you wish to delete "}
};
const char VIEW_ASSIGNMENTS_PROMPTS[1][] = {
  {"Enter Class ID or (-1 for Class List)"}
};
const char VIEW_ENROLLMENT_PROMPTS[1][] = {
  {"Enter Class ID or (-1 for Class List)"}
};
const char VIEW_CLASS_AVERAGE_PROMPTS[1][] = {
  {"Enter Class ID or (-1 for Class List)"}
};
const char VIEW_STUDENT_AVERAGE_PROMPTS[1][] = {
  {"Enter Student SSN"}
};
const char VIEW_CLASS_ASSIGNMENT_AVERAGE_PROMPTS[1][] = {
  {"Enter Class ID or (-1 for Class List)"}
};
const char VIEW_CLASS_ASSIGNMENT_GRADES_PROMPTS[2][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"}
};
const char VIEW_GRADES_PROMPTS[2][] = {
  {"Enter Class ID or (-1 for Class List)"},
  {"Enter Assignment ID or (-1 for Assignment List)"}
};
const char YES_NO[] = "(Y/N)?";


#endif /* bb_strings_h */
