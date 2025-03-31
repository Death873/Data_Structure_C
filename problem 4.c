/*
9. Write a program in C to find the maximum and minimum elements in an array. 
Test Data: 
Input the number of elements to be stored in the 
array :3 
Input 3 elements in the array : 
element 0:45 
element 1:25 
element 2:21 
Expected Output : 
Maximum element is: 45 
Minimum element is: 21
*/
#include<stdio.h>
 int main()
 {
    int n;
    printf("ENTER THE NO OF ELEMENTS TO STORE\n");
    scanf("%d",&n);
    int arr[n];
    int min,max,i;
    printf("INPUT %d ELEMENTS IN THE ARRAY :\n",n);
    for(i=0;i<n;i++)
    {
        printf("element %d: ",i);
        scanf("%d",&arr[i]);
    }
    min=arr[0];
    for(i=0;i<n;i++)
    {
        if(min<arr[i])
        {
            min=arr[i];
        }
        
    }
    max=min;
    for(i=0;i<n;i++)
    {
        if(max>arr[i])
        {
            max=arr[i];
        }
    }
    printf("Maximum element is: %d\n",min);
    printf("Minimum element is: %d",max);
    return 0;
 }