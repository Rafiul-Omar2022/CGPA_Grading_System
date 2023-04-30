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
    printf("\n\t5. Reset all\n");
    printf("\n\t0. exit\n\n");
    printf("Press ( 1 - 5 ) to operate.\n");
    printf("\nInput: ");
    scanf("%d", &n);

    switch(n){
    case 0:
        exit(0);
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
        break;
    default:
        goto point;
        break;
    }
}

