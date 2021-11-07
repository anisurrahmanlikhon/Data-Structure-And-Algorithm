#include <stdio.h>

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

int main(void) {
   int i = 0,
       j = 0,
       k = 0,
       range = 0,
       keyElement = 0,
       totalElements = 0,
       array[MAX_ELEMENTS];
    
printf("How many elements: ");
scanf("%d", &totalElements);
for(i = 0; i < totalElements; i++)
{
    printf("Elements#%d : ", i+1);
    scanf("%d",&array[i]);
}
   range = totalElements - 1;
    for (i = 0; i < totalElements -1; i++)
    {
        for(j = 0; j < range -i; j++)
        {
            if (array[j] > array[j+1])
            {
                k = array[j];
                array[j] = array[j+1];
                array[j+1] = k;
            }
        }
    }
    printf("After Sorting:\n");
    for(i =0; i < totalElements; i++)
    {
        printf("%d  ", array[i]);
    }
   return 0;
}
