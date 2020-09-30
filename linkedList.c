/*Programmer: Nikhil Kotharkar
  C program to store character data in linked list and count the number of constants stored.
  Roll no: 19816
*/

//start
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
void create();            // create node
void display();           // display data
void consonants();        // Count Constants
void end();               // exit program
void return_to_menu();    // return to menu
void green();             // change text color to green
void white();             // change text color to default(white)
void red();               // change text color to red
void yellow();            // change text color to yellow
struct node
{
        char data;
        struct node *link;
};
struct node *head=NULL;
int i=0;
int main()
{
        int choice;
        while(1){
                system("cls"); // command to clear the screen
                yellow();
                //Main Menu
                printf("==========================================================================================\n");
                printf("    C program to store characters in linked list and count number of constants stored.    \n");
                printf("==========================================================================================\n\n");
                white();
                if(i==0){
                    for (i = 0; i < 100; i++)
                    {
                        //loading progress (does no deal with actual code)
                        printf("\rLoading %d%%", i);
                        Sleep(10); //command to hold the control for the specific time
                    }
                        printf("\r            ");
                    }
                printf("\n-----------------------------------------\n");
                printf("\n                MENU                             \n");
                printf("-----------------------------------------\n");
                printf("\n 1.Insert data     \n");
                printf("\n 2.Display data   \n");
                printf("\n 3.Number of Consonants       \n");
                printf("\n 4.Exit       \n");
                printf("\n-----------------------------------------\n");
                printf("Enter your choice: ");
                fflush(stdin); // empty the buffer for fresh input
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        return_to_menu();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        consonants();
                                        break;
                        case 4:
                                        end();
                                        exit(0);
                                        break;

                        default:
                                        red();
                                        printf("\nInvalid Choice....Try Again\n\n");
                                        white();
                                        return_to_menu();
                }
                i=1;
        }
        return 0;
}
void create()
{
        // function to create a node and insert data
        int x;
        char temp1;
        struct node*temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter a character data for the node: ");
        scanf(" %c",&temp1);
        temp1=tolower(temp1); // convert alphabets to lower case
        if(temp1>='a' && temp1<='z') // condition to check if data enter is alphabet or not
        {
            temp->data=temp1; //store alphabet new node
            green();
            printf("\nData inserted successfully.\n\n");
            white();
            i=0;
        }
        else
        {
            red();
            printf("\nInvalid Input....Try Again\n\n");
            white();
            i=1;
		}
        if(i==1) //returns to main menu if else block runs
        {
            return_to_menu();
        }
        temp->link=NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->link!=NULL)
                {
                        ptr=ptr->link;
                }
                ptr->link=temp;
        }
}
void display()
{
        //function to traverse the node and display data
        int x;
        struct node*ptr;
        if(head==NULL) //checks if head node equals to null
        {
                red();
                printf("\nList is empty\n");
                white();
                return_to_menu();
        }
        else
        {
                ptr=head;
                printf("\nOUTPUT:\n");
                green();
                printf("The List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("\t|%c|",ptr->data );
                        ptr=ptr->link ;               //traverse the node
                }
                white();
                printf("\n\nPress any key to continue..");
                getch();

        }
}
void consonants()
{
        // function to find consonants in the data stored
        int count=0;
        struct node*ptr;
        if(head==NULL) // check if head node equals to null
        {
                red();
                printf("\nList is empty\n");
                white();
                return_to_menu();
        }
        else
        {
                ptr=head;
                while(ptr!=NULL)
                {
                        //check for constant alphabets
                        if(ptr->data!='a' && ptr->data!='e' && ptr->data!='i' && ptr->data!='o' &&ptr->data!='u')
                        {
                            count++;
                        }
                        ptr=ptr->link ; // traverse the node
                }
                printf("\nOUTPUT:\n");
                green();
                printf("\nThe number of consonants are %d\n",count);
                white();
                printf("\n\nPress any key to continue..");
                getch();
                system("cls");
        }
}

void end()
{
    //function to exit program
    system("cls");
    yellow();
    printf("\n\n==============================================");
    printf("\nThe program has Exited!!!");
    printf("\nThanks for your time...have a great day");
    printf("\n==============================================\n\n");
    white();
    Sleep(4000);
}
void return_to_menu()
{
    //function to return to menu when data is inserted or empty
    printf("\n Returning to main menu");
    for (i = 1; i < 3; i++) {
        printf(".", i);
        Sleep(1000);
        }
        system("cls");
        i=1; // for not running the loading progress in the menu again
        main();
}
void green()
{
  printf("\033[1;32m");
}
void white()
{
  printf("\033[0m");
}
void red()
{
  printf("\033[1;31m");
}
void yellow()
{
  printf("\033[1;33m");
}
//end
