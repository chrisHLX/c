#include <stdio.h>
#include <cs50.h>

int smallest(int array[]);
int largest(int array[]);
int test_array[] = {10, 42, 74, 1, 36, 52, 11, 25};
int MAX = sizeof(test_array)/sizeof(int);

int main(void)
{
    int x;
    int y;


    // Bubble sort
    int i = -1;
    while (i != 0)
    {
        i = 0;
        for (int j = 0; j < MAX; j++)
        {
            printf("test_array[%i] = %i\n", j, test_array[j]);
            if (test_array[j] > test_array[j+1] && j != MAX - 1)
            {
                // Swap the array elements
                x = test_array[j];
                y = test_array[j+1];

                test_array[j] = y;
                test_array[j+1] = x;

                i++;
                printf("test_array[%i] = %i\n", j, test_array[j]);
            }
            else
            {
                printf("do nothing");
            }
        }
        printf("%i", i);
    }

    for (int l = 0; l < MAX; l++)
    {
        printf("\n sorted test_array[%i] = %i\n", l, test_array[l]);
    }


}

int smallest(int array[])
{
    int smallest = array[0];
    for (int i = 0; i < MAX; i++)
    {
        if (smallest > array[i])
        {
            smallest = array[i];
        }
    }
    return smallest;
}

int largest(int array[])
{
    int largest = array[0];
    for (int i = 0; i < MAX; i++)
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
    }
    return largest;
}
