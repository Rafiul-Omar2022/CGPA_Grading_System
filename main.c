#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER "admin"
#define PASS "admin123"

typedef struct student{
    char name[50];
    char id[50];
    int totalCourse;
    int totalCredit;
    float cgpa;
    float totalGPA;
}st;

float gradingPoint(float num);
void asciImg();
int loginAccess( char name[], char password[] );
void append();
void add();
void view();
void search();
void reset();
int interface();

int main(){

    system("cls");
    asciImg();
    char userName[50];
    char UserPassword[50];
    char any[10];


    label:
    system("cls");
    asciImg();
    printf("\t\t\t\t\t- LOGIN: \n\n\n\n");
    printf("Enter Name: ");
    scanf(" %[^\n]s", userName);
    printf("Enter Password: ");
    scanf(" %[^\n]", UserPassword);
    int status = loginAccess(userName, UserPassword);
    if( status == 1 ){
        interface();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
    }
    else if( status == -1){
        printf("\nInvalid Password\n");
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        goto label;
    }
    else if( status == -2 ){
        printf("\nInvalid Username\n");
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        goto label;
    }
    else {
        printf("\nBoth username and password invalid \n");
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        goto label;
    }

    return 0;
}

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
    else if( num >= 60 ) return 1.0; //
    else return 0.0;

}

void asciImg(){
    printf("\t\t\t\t\t ######   ######   ########     ###\n");
    printf("\t\t\t\t\t##    ## ##    ##  ##     ##   ## ##\n");
    printf("\t\t\t\t\t##       ##        ##     ##  ##   ##\n");
    printf("\t\t\t\t\t##       ##   #### ########  ##     ##\n");
    printf("\t\t\t\t\t##       ##    ##  ##        #########\n");
    printf("\t\t\t\t\t##    ## ##    ##  ##        ##     ##\n");
    printf("\t\t\t\t\t ######   ######   ##        ##     ##\n");
    printf("\n\n\t\t\t\t\t\t\t\t - CGPA Grading System\n\n");
    printf("\t\t\t\t======================================================\n\n\n");
}

int loginAccess( char name[], char password[] ){
     if( !strcmp(name, USER ) && !strcmp(password, PASS) ) return 1;
     else if( (!strcmp(name, USER ) == 1) && (!strcmp(password, PASS) == 0) ) return -1;
     else if( (!strcmp(name, USER ) == 0) && (!strcmp(password, PASS) == 1) ) return -2;
     else return 0;
}

void append(){
    FILE *fp;

    system("cls");
    asciImg();

    int size = 0;
    printf("\nHow many student do you want to create: ");
    scanf("%d", &size);
    st stu[size];

    fp = fopen("database.txt", "a");

    for(int i=0; i<size; i++){
        printf("Student Name: ");
        scanf(" %[^\n]s", stu[i].name);
        printf("Student ID: ");
        scanf(" %[^\n]s", stu[i].id);
        stu[i].totalCourse = 0;
        stu[i].totalCredit = 0;
        stu[i].cgpa = 0.0;
        stu[i].totalGPA = 0.0;
        printf("\n\n");
        fwrite(&stu[i], sizeof(st), 1, fp);
    }
    fclose(fp);

}

void add(){
    st stu;
    FILE *fp, *fp1;
    system("cls");
    asciImg();

    fp = fopen("database.txt", "r");
    fp1 = fopen("temp.txt", "w");

    char id[50];
    int found = 0;

    printf("Enter student Id to Add: ");
    scanf(" %[^\n]s", id);

     while(fread(&stu, sizeof(st), 1, fp)){
        if(!strcmp(stu.id, id)){
            found = 1;

            int courseNumber = 0;
            int credit = 0;
            float marks = 0;
            printf("\n\nId: %s, Name: %s, cgpa: %.2f\n\n", stu.id, stu.name, stu.cgpa);
            printf("\nHow many course do you want to add: ");
            scanf("%d", &courseNumber);
            stu.totalCourse += courseNumber;

            for(int i=1; i <= courseNumber; i++){

                    printf("Course number: %d, enter course credit: ", i);
                    scanf("%d", &credit);
                    printf("Course number: %d, enter course marks: ", i);
                    scanf("%f", &marks);
                    stu.totalCredit += credit;

                    float grade = gradingPoint( marks );
                    stu.totalGPA += ( credit *  grade );
            }

            stu.cgpa = ( float ) stu.totalGPA / stu.totalCredit;
        }

        fwrite(&stu, sizeof(st), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);

     if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("database.txt", "w");

        while(fread(&stu, sizeof(st), 1, fp1)){
            fwrite(&stu, sizeof(st), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
    }else{
        printf("\nRecord not found!\n");
    }


}

void view(){
    st stu;
    FILE *fp;

    system("cls");
    asciImg();

    fp = fopen("database.txt", "r");
    printf("\n%10s | %20s | %15s | %15s | %10s | %10s\n", "ID", "Name", "Complete course", "Total Credit", "Total GPA" , "CGPA");
    printf("\n\t-----------------------------------------------------------------------------------------\n\n","","","","","","");
    while( fread(&stu, sizeof(st), 1, fp ) ){
        printf("%10s | %20s | %15d | %15d | %10.2f | %10.2f\n",
                stu.id, stu.name, stu.totalCourse, stu.totalCredit, stu.totalGPA, stu.cgpa  );
    }
    fclose(fp);
}

void search(){
    st stu;
    FILE *fp;

    char studentID[50];
    system("cls");
    asciImg();

    fp = fopen("database.txt", "r");
    printf("Enter student id: ");
    scanf(" %[^\n]s", studentID);

    printf("\n");

    int found = 0;

    while( fread(&stu, sizeof(st), 1, fp ) ){
        if( !strcmp( studentID, stu.id ) ){
            found = 1;
            printf("\n%10s | %20s | %15s | %15s | %10s | %10s\n", "ID", "Name", "Complete course", "Total Credit", "Total Credit" , "CGPA");
            printf("\n\t-----------------------------------------------------------------------------------------\n\n","","","","","","");
            printf("%10s | %20s | %15d | %15d | %10.2f | %10.2f\n", stu.id, stu.name, stu.totalCourse, stu.totalCredit, stu.totalGPA, stu.cgpa  );
        }
    }
    fclose(fp);
    if( !found ) printf("\nStudent Id not found\n");
}

void reset(){
    FILE *fp, *fp1;
    system("cls");
    asciImg();
    fp = fopen("database.txt", "w");
    fp1 = fopen("temp.txt", "w");
    fclose(fp);
    fclose(fp1);
}

int interface(){

    int n;
    char any[50];
    point:
    system("cls");
    asciImg();
    printf("\n\t1. Entry new student\n");
    printf("\n\t2. Entry courses and marks\n");
    printf("\n\t3. View all \n");
    printf("\n\t4. Search student\n");
    printf("\n\t5. Reset all\n\n");
    printf("Press ( 1 - 4 ) to operate.\n");
    printf("\nInput: ");
    scanf("%d", &n);

    switch(n){
    case 1:
        append();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        interface();
        break;
    case 2:
        add();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        interface();
        break;
    case 3:
        view();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        interface();
        break;
    case 4:
        search();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        interface();
        break;
    case 5:
        reset();
        printf("\nPress any number/character to continue.....");
        scanf(" %s", any);
        interface();
    default:
        goto point;
        break;
    }
}


