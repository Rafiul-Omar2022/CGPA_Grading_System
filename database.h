typedef struct student{
    char name[50];
    char id[50];
    int totalCourse;
    int totalCredit;
    float cgpa;
    float totalGPA;
}st;


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
    }
    else{
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
        printf("%10s | %20s | %15d | %15d | %10.2f | %10.2f\n", stu.id, stu.name, stu.totalCourse, stu.totalCredit, stu.totalGPA, stu.cgpa  );
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
