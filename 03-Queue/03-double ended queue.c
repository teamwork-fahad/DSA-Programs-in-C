#include <stdio.h>

#define MAX 5

int QUEUE[MAX];
int FRONT = -1;
int REAR = -1;

// Check Overflow
int isFull()
{
    if ((FRONT == 0 && REAR == MAX - 1) ||
        (FRONT == REAR + 1))
    {
        return 1;
    }

    return 0;
}

// Check Empty
int isEmpty()
{
    if (FRONT == -1)
    {
        return 1;
    }

    return 0;
}

// Insert from Front
void insertFront()
{
    int ITEM;

    if (isFull())
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &ITEM);

    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else if (FRONT == 0)
    {
        FRONT = MAX - 1;
    }
    else
    {
        FRONT = FRONT - 1;
    }

    QUEUE[FRONT] = ITEM;

    printf("%d inserted from FRONT.\n", ITEM);
}

// Insert from Rear
void insertRear()
{
    int ITEM;

    if (isFull())
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &ITEM);

    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else if (REAR == MAX - 1)
    {
        REAR = 0;
    }
    else
    {
        REAR = REAR + 1;
    }

    QUEUE[REAR] = ITEM;

    printf("%d inserted from REAR.\n", ITEM);
}

// Delete from Front
void deleteFront()
{
    int ITEM;

    if (isEmpty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    ITEM = QUEUE[FRONT];

    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else if (FRONT == MAX - 1)
    {
        FRONT = 0;
    }
    else
    {
        FRONT = FRONT + 1;
    }

    printf("%d deleted from FRONT.\n", ITEM);
}

// Delete from Rear
void deleteRear()
{
    int ITEM;

    if (isEmpty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    ITEM = QUEUE[REAR];

    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else if (REAR == 0)
    {
        REAR = MAX - 1;
    }
    else
    {
        REAR = REAR - 1;
    }

    printf("%d deleted from REAR.\n", ITEM);
}

// Display
void display()
{
    int I;

    if (isEmpty())
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }

    printf("Queue elements: ");

    I = FRONT;

    while (I != REAR)
    {
        printf("%d ", QUEUE[I]);
        I = (I + 1) % MAX;
    }

    printf("%d\n", QUEUE[REAR]);
}

// Main
int main()
{
    int type, choice;

    printf("===== DEQUE PROGRAM =====\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");

    printf("Enter Deque Type: ");
    scanf("%d", &type);

    if (type != 1 && type != 2)
    {
        printf("Invalid Deque Type!\n");
        return 0;
    }

    do
    {
        printf("\n===== MENU =====\n");

        if (type == 1)
        {
            // Input Restricted Deque
            printf("1. Insert from Rear\n");
            printf("2. Delete from Front\n");
            printf("3. Delete from Rear\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        }
        else
        {
            // Output Restricted Deque
            printf("1. Insert from Front\n");
            printf("2. Insert from Rear\n");
            printf("3. Delete from Front\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (type == 1)
        {
            // Input Restricted Deque
            switch (choice)
            {
                case 1:
                    insertRear();
                    break;

                case 2:
                    deleteFront();
                    break;

                case 3:
                    deleteRear();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    printf("Program Ended.\n");
                    break;

                default:
                    printf("Invalid Choice!\n");
            }
        }
        else
        {
            // Output Restricted Deque
            switch (choice)
            {
                case 1:
                    insertFront();
                    break;

                case 2:
                    insertRear();
                    break;

                case 3:
                    deleteFront();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    printf("Program Ended.\n");
                    break;

                default:
                    printf("Invalid Choice!\n");
            }
        }

    } while (choice != 5);

    return 0;
}