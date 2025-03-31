/*
10. Write a program in C to separate odd and even integers into separate arrays. 
Test Data: 
Input the number of elements to be stored in the 
array :5 
Input 5 elements in the array: 
element - 0:25 
element1:47 
element - 2:42 
element 3:56 
element - 4:32 
Expected Output : 
The Even elements are: 
42 56 32 
The Odd elements are: 
25 47
*/
#include<stdio.h>
int main()
{
    int n;
    printf("ENTER THE NO OF ELEMENTS TO STORE\n");
    scanf("%d",&n);
    int arr[n],even[n],odd[n];
    int i,e,o;
    printf("INPUT %d ELEMENTS IN THE ARRAY :\n",n);
    for(i=0;i<n;i++)
    {
        printf("element %d: ",i);
        scanf("%d",&arr[i]);
    }
e=0;
o=0;
for(i=0;i<n;i++)
{
    if(arr[i]%2==0)
    {
        even[e]=arr[i];
        e++;
    }
    else
    {
        odd[o]=arr[i];
        o++;
    }
}
printf("THE EVEN ELEMENTS ARE:\n");
for(i=0;i<e;i++)
{
    printf("%d\t",even[i]);
}
printf("\nTHE ODD ELEMENTS ARE:\n");
for(i=0;i<o;i++)
{
    printf("%d\t",odd[i]);
}
return 0;
}