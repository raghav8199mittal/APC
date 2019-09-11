#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'maxDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int maxDifference(int arr_count, int* arr) {
    int min=arr[0],max=-1,i;
    for(i=1;i<arr_count;i++)
    {
        if(arr[i]!=min&&arr[i]-min>max)
            max=arr[i]-min;
        if(arr[i]<min)
            min=arr[i];
        
        
    }
    return max;
}

int main()