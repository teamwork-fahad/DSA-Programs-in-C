#include <stdio.h>

#define MAX 5

int QUEUE[MAX];
int FRONT = -1;
int REAR = -1;

// Circular Enqueue
void enqueue()
{
    int ITEM;

    printf("Enter value to insert: ");
    scanf("%d", &ITEM);

    // Step 1: Check for Overflow
    if ((REAR + 1) % MAX == FRONT)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }

    // Step 2: Update Pointers
    if (FRONT == -1)
    {
        // Queue was empty
        FRONT = 0;
        REAR = 0;
    }
    else
    {
        // Circular move
        REAR = (REAR + 1) % MAX;
    }

    // Step 3: Insert Item
    QUEUE[REAR] = ITEM;

    printf("%d inserted into queue.\n", ITEM);
}

// Circular Dequeue
void dequeue()
{
    int ITEM;

    // Step 1: Check if queue is empty
    if (FRONT == -1)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    // Step 2: Store front element
    ITEM = QUEUE[FRONT];

    // Step 3: Update pointers
    if (FRONT == REAR)
    {
        // Only one element
        FRONT = -1;
        REAR = -1;

        printf("Queue becomes empty.\n");
    }
    else
    {
        // Circular move
        FRONT = (FRONT + 1) % MAX;
    }

    // Step 4: Return ITEM
    printf("%d deleted from queue.\n", ITEM);
}

// Display
void display()
{
    int I;

    // Step 1: Check if queue is empty
    if (FRONT == -1)
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }

    printf("Queue elements: ");

    // Step 2: Set I = FRONT
    I = FRONT;

    // Step 3: Print until REAR
    while (I != REAR)
    {
        printf("%d ", QUEUE[I]);

        // Circular move
        I = (I + 1) % MAX;
    }

    // Step 4: Print last element
    printf("%d", QUEUE[REAR]);

    printf("\n");
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}