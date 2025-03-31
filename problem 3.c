/*
. Write a program in C to count the frequency of each element of an array. 
Test Data: 
Input the number of elements to be stored in the 
array :3 
Input 3 elements in the array: 
element 0:25 
element 1:12 
element - 2:43 
Expected Output : 
The frequency of all elements of an array : 
25 occurs 1 times 
12 occurs 1 times 
43 occurs 1 times
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,*checkked;
    int n,i,j,count;
    printf("INPUT THE NO OF ELEMENTS TO BE STORED IN THE ARRAY\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    checkked=(int*)malloc(n*sizeof(int));
    printf("INPUT THE ELEMENTS IN THE ARRAY\n");
    for(i=0;i<n;i++)
    {
        printf("element %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("The frequency of all elements of an array\n");
    for(i=0;i<n;i++)
    {
            count=0;
            if(checkked[i]==1)
            {
                continue;
            }
        for(j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
            count++;
            checkked[j]=1;
            }
        }
        printf("%d Occurs %d times\n",arr[i],count);
    }
    free(arr);
    free(checkked);
    return 0;
}