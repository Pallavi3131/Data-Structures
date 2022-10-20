#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)   {   
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++){ 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
       }
   }
}
int main()
{
  
  int d, i=0, j, A[1000000];
  FILE *fp = fopen("numbers.txt","r");
  FILE *pf = fopen("bubble_sort.txt","w");
  while (fscanf(fp,"%d",&A[i])!=-1){
      i++;
  }
  bubbleSort(A,i);
  for(int y =0; y<i; y++){
    fprintf(pf,"%d \n",A[y]);
    }
  fclose(fp);
   return 0;
}