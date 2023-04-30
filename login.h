#define USER "admin"
#define PASS "admin123"

void login(){

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
}

int loginAccess( char name[], char password[] ){
     if( !strcmp(name, USER ) && !strcmp(password, PASS) ) return 1;
     else if( (!strcmp(name, USER ) == 1) && (!strcmp(password, PASS) == 0) ) return -1;
     else if( (!strcmp(name, USER ) == 0) && (!strcmp(password, PASS) == 1) ) return -2;
     else return 0;
}
