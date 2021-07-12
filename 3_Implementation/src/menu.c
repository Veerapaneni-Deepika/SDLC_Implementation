#include "fun.h"
void menu()
{
    int choice = 0;
    do
    {
        printf("\nMAIN MENU\n");
        printf("\n1.Add Books");
        printf("\n2.Search Books");
        printf("\n3.View Books");
        printf("\n4.Delete Book");
        printf("\n5.Update Password");
        printf("\n0.Exit");
        printf("\nEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addBookInDataBase();
            break;
        case 2:
            searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\nINVALID INPUT!!! Type between 0-5...");
        }                                            //Switch Ended
    }
    while(choice != 0);                                        //Loop Ended
}