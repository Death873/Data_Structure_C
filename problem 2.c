/*. Write a program in C to print all unique elements in an array. 
Test Data: 
Print all unique elements of an array: 
Input the number of elements to be stored in the 
array: 4 
Input 4 elements in the array: 
element 0:3 
element 1:2
element 2:2 
element 3:5 
Expected Output : 
The unique elements found in the array are: 
35*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int n,i,j,isunique;
    printf("INPUT THE NO OF ELEMENTS STORED IN THE ARRAY\n");
    scanf("%d",&n);
arr=(int*)malloc(n*sizeof(int));
printf("INPUT %d ELEMENTS IN THE ARRAY\n",n);
for(i=0;i<n;i++)
{
    printf("element %d: ",i);
    scanf("%d",&arr[i]);
}

printf("The Unique elements in the array are:\n");
for(i=0;i<n;i++)
{
    isunique=1;
   for(j=0;j<n;j++)
   {
    if(i!=j && arr[i]==arr[j])
    {
        isunique=0;
        break;
    }
   }
    if(isunique)
    printf("%d\t",arr[i]);
}
free(arr);
return 0;
}