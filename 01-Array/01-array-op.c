#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortAscending(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n, choice, nextChoice, i, position, value, found;
    int max, min, sum, evenCount, oddCount;

    printf("How many elements you want? (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE)
    {
        printf("Invalid size. Size must be from 1 to %d.\n", MAX_SIZE);
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n==>Array Operation<==\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Sort Ascending\n");
        printf("7. Sort Descending\n");
        printf("8. Reverse Array\n");
        printf("9. Find Maximum\n");
        printf("10. Find Minimum\n");
        printf("11. Sum\n");
        printf("12. Average\n");
        printf("13. Count Even\n");
        printf("14. Count Odd\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            displayArray(arr, n);
            break;

        case 2:
            if (n == MAX_SIZE)
            {
                printf("Array is full. You cannot insert a new element.\n");
                break;
            }

            printf("Enter position (1-%d): ", n + 1);
            scanf("%d", &position);

            if (position < 1 || position > n + 1)
            {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter value: ");
            scanf("%d", &value);

            for (i = n; i >= position; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[position - 1] = value;
            n++;

            printf("Element inserted successfully.\n");
            break;

        case 3:
            if (n == 0)
            {
                printf("Array is empty. You cannot delete an element.\n");
                break;
            }

            printf("Enter position (1-%d): ", n);
            scanf("%d", &position);

            if (position < 1 || position > n)
            {
                printf("Invalid position.\n");
                break;
            }

            for (i = position - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;

            printf("Element deleted successfully.\n");
            break;

        case 4:
            if (n == 0)
            {
                printf("Array is empty. You cannot update an element.\n");
                break;
            }

            printf("Enter position (1-%d): ", n);
            scanf("%d", &position);

            if (position < 1 || position > n)
            {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter new value: ");
            scanf("%d", &value);
            arr[position - 1] = value;

            printf("Element updated successfully.\n");
            break;

        case 5:
            if (n == 0)
            {
                printf("Array is empty. You cannot search.\n");
                break;
            }

            printf("Enter search value: ");
            scanf("%d", &value);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (arr[i] == value)
                {
                    printf("%d found at position %d.\n", value, i + 1);
                    found = 1;
                }
            }

            if (!found)
            {
                printf("%d not found in the array.\n", value);
            }
            break;

        case 6:
            sortAscending(arr, n);
            printf("Array sorted in ascending order.\n");
            displayArray(arr, n);
            break;

        case 7:
            sortDescending(arr, n);
            printf("Array sorted in descending order.\n");
            displayArray(arr, n);
            break;

        case 8:
            for (i = 0; i < n / 2; i++)
            {
                value = arr[i];
                arr[i] = arr[n - 1 - i];
                arr[n - 1 - i] = value;
            }

            printf("Array reversed successfully.\n");
            displayArray(arr, n);
            break;

        case 9:
            if (n == 0)
            {
                printf("Array is empty. Maximum value is not available.\n");
                break;
            }

            max = arr[0];
            for (i = 1; i < n; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
            printf("Maximum element: %d\n", max);
            break;

        case 10:
            if (n == 0)
            {
                printf("Array is empty. Minimum value is not available.\n");
                break;
            }

            min = arr[0];
            for (i = 1; i < n; i++)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                }
            }
            printf("Minimum element: %d\n", min);
            break;

        case 11:
            sum = 0;
            for (i = 0; i < n; i++)
            {
                sum += arr[i];
            }
            printf("Sum: %d\n", sum);
            break;

        case 12:
            if (n == 0)
            {
                printf("Array is empty. Average is not available.\n");
                break;
            }

            sum = 0;
            for (i = 0; i < n; i++)
            {
                sum += arr[i];
            }
            printf("Average: %.2f\n", (float)sum / n);
            break;

        case 13:
            evenCount = 0;
            for (i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 0)
                {
                    evenCount++;
                }
            }
            printf("Even elements count: %d\n", evenCount);
            break;

        case 14:
            oddCount = 0;
            for (i = 0; i < n; i++)
            {
                if (arr[i] % 2 != 0)
                {
                    oddCount++;
                }
            }
            printf("Odd elements count: %d\n", oddCount);
            break;

        case 15:
            printf("Program is closing.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

        if (choice != 15)
        {
            do
            {
                printf("\nPress 0 to view menu or 15 to exit: ");
                scanf("%d", &nextChoice);
            } while (nextChoice != 0 && nextChoice != 15);

            if (nextChoice == 15)
            {
                choice = 15;
                printf("Program is closing.\n");
            }
        }
    } while (choice != 15);

    return 0;
}
