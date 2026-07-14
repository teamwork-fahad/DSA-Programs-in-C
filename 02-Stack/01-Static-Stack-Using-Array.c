#include<stdio.h>

#define SIZE 5

int top=-1;

int stack[SIZE];

void push();

void pop();

void peek();

int is_empty();//return 1 means empty

int is_full();//return 1 means full

void display();

void menu()

{

    printf("\n ===>Stack Operation<===");

    printf("\n 1.PUSH(Insert)");

    printf("\n 2.POP(Delete)");

    printf("\n 3.PEEK(Top)");

    printf("\n 4.Display");

    printf("\n 5.Exit");

}

int main()

{

    int ch;

    do{

        menu();

        printf("\n Enter your choice=>");

        scanf("%d",&ch);

        switch(ch)

        {

            case 1:

                push();

                break;


            case 2:

                pop();

                break;


            case 3:

                peek();

                break;


            case 4:

                display();

                break;


            case 5:

                printf("Bye Bye");

                break;


            default:

                printf("Invalid");

        }

    }while(ch!=5);

    return 0;

}

void push()

{

    int val;

    if(is_full()==1)

    {

        printf("Stack is overflow");

        return;

    }

    printf("\n Enter value=>");

    scanf("%d",&val);

    top++;

    stack[top]=val;

    printf("\n Insert done.....");

}

void pop()

{

    if(is_empty()==1)

    {

        printf("\n Stack is underflow");

    }

    else

    {

        printf("%d is deleted",stack[top]);

        top--;

    }

}

void peek()

{

    if(is_empty()==1)

    {

        printf("\n Stack is underflow");

    }

    else

    {

        printf("%d is on TOP",stack[top]);

    }

}

int is_empty()

{

    if(top==-1)

    {

        return 1;

    }

    else

    {

        return 0;

    }

}

int is_full()

{

    if(top==SIZE-1)

    {

       

        return 1;

    }

    else

    {

        return 0;

    }

}

void display()

{

    if(is_empty()==1)

    {

        printf("\n Stack is empty");

    }

    else

    {

        printf("\n Stack elements (Top to Bottom):");

        for(int i=top; i>=0; i--)

        {

            printf("\n | %d |", stack[i]);

        }

        printf("\n ---");

    }

}