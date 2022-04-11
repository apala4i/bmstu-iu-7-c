#include "libfuncs_for_py.h"
#include <stdlib.h>
#include <math.h>

static void shiftLeftOnce(int *array, int size)
{
    int firstEl = array[0];
    for (int i = 1; i < size; ++i)
    {
        array[i - 1] = array[i];
    }
    array[size - 1] = firstEl;
}
void shiftArray(int *array, int size, int shiftStep)
{
    for (int i = 0; i < shiftStep; ++i)
    {
        shiftLeftOnce(array, size);
    }
}

int squareArray(int *array, int size, int *newArray)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (fabs(sqrt(array[i]) - (int)sqrt(array[i])) <= 0.00001)
        {
            if (newArray)
            {
                newArray[count] = array[i];
            }
            count ++;
        }
    }
    return count;
}