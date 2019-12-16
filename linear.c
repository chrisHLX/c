// Performs a linear search
#include <stdio.h>
#include <cs50.h>

int find_smallest(int array[]);
int sort(int array[]);
const int CONST = 10;

int main(void)
{
    int new_array[10] = {33, 12, 32, 6, 3, 2, 43, 21, 25, 18};
    sort(new_array);
}

// Returns smallest element
int find_smallest(int array[])
{
    int smallest = array[0];
    for (int i = 0; i < CONST; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
    }
    return smallest;
}

int sort(int array[])
{
    int sorted[CONST];
    int unsorted[CONST];
    int rem;
    for (int i = 0; i < CONST; i++)
    {
        unsorted[i] = array[i];
        //printf("%i\n", unsorted[i]);
    }

    // Adds smallest element to sorted then removes it from unsorted
    for (int i = 0; i < CONST; i++)
    {
        rem = find_smallest(unsorted);
        sorted[i] = rem;
        printf("%i\n", sorted[i]);

        //Removing smallest by changing it to 100, loop ends before reaching 100
        for (int j = 0; j < CONST; j++)
        {
            if (unsorted[j] == rem)
            {
                unsorted[j] = 100;
            }
        }
    }
    return 0;
}
