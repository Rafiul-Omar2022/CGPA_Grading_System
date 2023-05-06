                                     CGPA_Grading_System 💎
                          

> Hey, this is a CGPA calculator program which can calculate many
> students cgpa, and can store.

Program features ⭐:

 

 - Create and add multiple person's name, id, marks, courses, credits.
 - Can search a person by id
 - Can view all person's information.
 - Can reset all information.
 - Database system is using file system in a binary mood.

                               username: admin
        Default Login system:
                               password: admin123

         
         For changing login information, go to login.h , and change this:
            
			            #define USER "yourName"
						#define PASS "yourPassword"
						

 In this Program, used the grading system below : 
 
   *For changing grading, simply go to **`database.h`** file and change your grade.👇*

    float gradingPoint(float num){
    // NSU grading system
    if( num >= 93 ) return 4.0;// A Excellent
    else if( num >= 90 ) return 3.7; // A-
    else if( num >= 87 ) return 3.3; // B+
    else if( num >= 83 ) return 3.0; // B Good
    else if( num >= 80 ) return 2.7; // B-
    else if( num >= 77 ) return 2.3; // C+
    else if( num >= 73 ) return 2.0;// C Average
    else if( num >= 70 ) return 1.7; // C-
    else if( num >= 70 ) return 1.7; // D+
    else if( num >= 67 ) return 1.3; // D Poor
    else if( num >= 60 ) return 1.0;
    else return 0.0;
    }

My linkedin:  [Linkedin](https://www.linkedin.com/in/rafiulomar/)
