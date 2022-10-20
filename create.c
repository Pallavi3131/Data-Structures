#include<stdio.h>
#include<stdlib.h>
int main(){

    FILE *fp;
    fp = fopen("numbers.txt","w");
    int num,reps;
    printf("Enter the number of random entries to create ");
    scanf("%d",&reps);
    for(int i =0; i<reps; i++){
        num = rand();
    fprintf(fp," %d\n",num);
    }
    return 0;
}