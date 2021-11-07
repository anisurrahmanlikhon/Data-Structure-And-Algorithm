#include <stdio.h>
#define MAX_ELEMENTS 50
int main()
{   

 int i = 0,
     j = 0,
     k = 0,
     element = 0,
     array[MAX_ELEMENTS],
     totalElements = MAX_ELEMENTS;
printf("Enter an element [-1 for Exit]: ");
scanf("%d", &element);

while ( (element !=-1) ) 
{  
 k = i-1;
  while ((element <array[k]) && (k>=0))
  { 
    array[k+1] = array[k];
    --k;
   }
array[k+1] = element;

printf ("After inserting %d, array becomes:\n",element);
for (j = 0; j<=i; j++)
  {  
   printf ("%d   ", array[j]);
  }
  printf ("\n Enter another element[-1 for Exit]: ");
  scanf ("%d", &element);
  i++;
}

printf ("\n The final sorted array is:\n");
for (j = 0; j<i; j++)
 {   
  printf ("%d   ", array[j]);

 }
 return 0;
}
