/*
Write a program in C to count the total number of duplicate elements in an array. 
Test Data: 
Input the number of elements to be stored in the 
array :3 
Input 3 elements in the array : 
element 0:5 
element 1:1 
element 2:1 
Expected Output : 
Total number of duplicate elements found in the 
array is : 1
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int n,i,j,count=0;
    printf("INPUT THE NO OF ELEMENTS TO BE STORED IN THE ARRAY\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("INPUT THE ELEMENTS IN THE ARRAY\n");
    for(i=0;i<n;i++)
    {
        printf("element %d: ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count ++;
                break;
            }
        }
    }
    printf("Total number of duplicate items elements found in the array is:%d  ",count);
    free(arr);
    return 0;
}