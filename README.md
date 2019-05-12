# 241FinalProj
A school data application in C: using a flat file database for students, classes, grades, assignments, and enrollment.

The project is fully functional at this time.

A list of things that I would change if I were to continue this project:

1. A serious reorganization. The project is currently in a single .c file so that it could be easily submitted for grading via email, but it should be broken into separate .h files each with its own separate estate of concern.

2. The internal data structure. I am not positive if I would keep the internal linked list to handle receiving and processing input.  I made the decision to use a linked list of Input_c (essentially a struct that contains a single char value) because I expected to have to do a lot more complex parsing of inputs than ended up being the case.  I also went with that data structure because everything I read about scanf was that it shouldn't be used, so I decided to write my own functions to do what scanf does but without the overflow security risk.

3. A complete re-evaluation of the project.  If you closely look at the code, you'll probably notice that I tried to break the functions associated with the menu system into small sub-functions (as close to each function doing one thing as I could get). Moving into the Custom Command Line system and the standard Command Line Argument system, the code increasingly becomes duplicative. A couple things happened for this to be the case. The first is that I simply ran out of time to refactor the functions into better sub-functions that could be reused--it needed to function by a deadline and I think my code reflects the decision to just get it working. The second, and related to the first, is that the deliverable specifics for the project kept changing and that made planning how to design the code very difficult (time-wise, the project needed to be started before the first version of the list of specific deliverables was available in written form and the deliverables were still being codified until one week before the project was due).

4. Technical improvements with my ability to code in C. I believe a lot of my code could be abstracted. For example, there are many functions that perform essentially the same operations on the data structures held in memory. I have a feeling that void pointers could be the key to abstracting these functions, but void pointers is an area I've only recently become aware of and therefore I need to spend more time learning C to learn how to use them correctly (or to discover another better alternative).

5. Standardizing print outputs.  There were no codified standards for how view options should present information to the user.  To make the program better, I should standardize the print outputs so the user can become accustomed to the information being displayed and easily read it. In its current state the program provides, in most cases, the bare minimum information required.  
