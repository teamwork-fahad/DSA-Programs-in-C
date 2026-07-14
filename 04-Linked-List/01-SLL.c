#include <stdlib.h>
#include <stdio.h>
struct SLL
{
    int data;
    struct SLL *next;
} *new, *head, *temp;
void insert_beg();
void insert_end();
void display();
void create_node()
{
    int val;
    new = (struct SLL *)malloc(sizeof(struct SLL));
    if (new == NULL)
    {
        printf("Memory issue");
        return;
    }
    printf("\n Enter value->");
    scanf("%d", &val);
    new->data = val;
    new->next = NULL;
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


                case 0:
                    printf("\n Back to main menu");
                    break;

                default:
                    printf("\n Inalid");
                }


            } while (ch1 != 0);
            break;
        }
    } while (ch != 4);
}


void insert_beg()
{
    create_node();
    new->next=head;
    head=new;
    printf("\n Insert new node at beg");
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
    }
    printf("\n SLL insert end done..");
    display();
}

void display()
{
    if(head==NULL)
    {
        printf("\n SLL is empty");
    }
    else
    {
        temp=head;
        while(temp != NULL)
        {
            printf("\n %d",temp->data);
            temp=temp->next;
        }
    }
}
