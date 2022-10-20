#include<stdio.h>
#include<stdlib.h>
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
 
 int main (){
     int d, i=0, j, A[1000000];
  FILE *fp = fopen("numbers.txt","r");
  FILE *pf = fopen("insertion_sort.txt","w");
  while (fscanf(fp,"%d",&A[i])!=-1){
      i++;
  }
  insertionSort(A,i);
  for(int y =0; y<i; y++){
    fprintf(pf,"%d \n",A[y]);
    }
  fclose(fp);
   return 0;
 }