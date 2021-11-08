#include <stdio.h>
#define MAX_ELEMENTS 50

int main()
{   
  int i = 0,
     j = 0,
     k = 0,
     search = 0,
     index_min = 0,
     totalElements = 0,
     array[MAX_ELEMENTS];
     
printf("\nHow many elements: ");
scanf("%d",&totalElements);
printf("\nEnter %d elements:\n", totalElements);
    for(i = 0; i < totalElements;++i)
    {
        printf("    Element# %2d: ", i+1);
 scanf("%d", &array[i]);
    }
    
    for(search = 0; search < totalElements - 1; search++)
        {
        index_min = search;
        for (j=search+1; j < totalElements;j++) {
            if (array [index_min] > array[j])
        {
           index_min =j;
        }
        }
        if (index_min != search) 
    {
     k= array[search];
    array[search]= array[index_min];
    array[index_min] = k;
     
      }  
        } 
    printf ("\nAfter Sorting: \n");
    for (i = 0; i < totalElements; i++)
    {
        printf ("%6d", array[i]);
    }
    return 0;
  }
