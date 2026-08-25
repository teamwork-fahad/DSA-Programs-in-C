#include <stdlib.h>
#include <stdio.h>
struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
} *new, *head, *temp;

void insert_beg();
void insert_end();
void display();
void create_node()
{
    int val;
    new = (struct DLL *)malloc(sizeof(struct DLL));
    if (new == NULL)
    {
        printf("Memory issue");
        return;
    }
    printf("\n Enter value->");
    scanf("%d", &val);
    new->data = val;
    new->next = NULL;
    new->prev=NULL;
}


void main_menu()
{
    printf("\n =====> SLL <=====");
    printf("\n 1.Insert");
    printf("\n 2.Delete");
    printf("\n 3.Display");
    printf("\n 4.Exit");
}


void insert_menu()
{
    printf("\n 1.Insert Beg");
    printf("\n 2.Insert End");
    printf("\n 0.Back to main menu");
}


int main()
{
    int ch, ch1;
    do
    {
        main_menu();
        printf("\n Enter your choice=>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            do
            {
                insert_menu();
                printf("\n Enter your choice=>");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    insert_beg();
                    break;


                case 2:
                    insert_end();
                    break;

                case 3:
                    //insert_pos();
                    break;
                
                case 0:
                    printf("\n Back to main menu");
                    break;

                default:
                    printf("\n Inalid");
                }


            } while (ch1 != 0);
            break;

            case 4:
            display();
            break;
        }

        
    } while (ch != 4);
}


void insert_beg()
{
    create_node();
    new->prev=NULL;
    new->next=head;
    if(head != NULL)
    {
        head->prev=new;
    }
    head=new;
    printf("\n Done Insert new node at beg");
    display();
}


void insert_end()
{
    create_node();
    if(head==NULL)
    {
        head=new;
    }
    else 
    {
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
    printf("\n DLL insert end done..");
    display();
}

void display()
{
    int op;
    if(head==NULL)
    {
        printf("\n DLL is empty");
    }
    else
    {
        do
        {
            /* code */
        
        
        printf("\n press 1 for forward display(Left to Right) \n press 2 for backware display(Right to Left) press 0 for main menu");
        scanf("%d",&op);
        if(op==1)
        {
            temp=head;
            while(temp != NULL)
            {
                printf("%d",temp->data);
                temp=temp->next;
            }
        }
        else if(op==2)
        {
            temp=head;
            //this loop set our temp at last
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            while(temp != NULL)
            {
                printf("%d",temp->data);
                temp=temp->prev;
            }
        }
        else 
        {
            main_menu();
        }
        } while (op!=3);
    }
}
