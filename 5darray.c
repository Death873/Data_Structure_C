#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *****arr;
    int a,b,c,d,e;
    int i,j,k,n,l;
    printf("ENTER THE DIMENSION\n");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    arr=(int *****)malloc(a*sizeof(int ****));
    for( i=0;i<a;i++)
    {
    	arr[i]=(int ****)malloc(b*sizeof(int ***));
		for( j=0;j<a;j++)
		{
			arr[i][j]=(int ***)malloc(c*sizeof(int **));
			for(k=0;k<a;k++)
			{
				arr[i][j][k]=(int **)malloc(d*sizeof(int *));
				for(n=0;n<a;n++)
				{
					arr[i][j][k][n]=(int *)malloc(e*sizeof(int));
				}
			}
		}
	}
	printf("ENTER THE VALUES\n");
	for(i=0;i<a;i++)
{
	for(j=0;j<b;j++)
	{
		for(k=0;k<c;k++)
		{
			for(l=0;l<d;l++)
			{
				for(n=0;n<e;n++)
			scanf("%d",&arr[i][j][k][l][n]);
			}
		}
	}
}
printf("YOUR DATA\n");
for(i=0;i<a;i++)
{
	for(j=0;j<b;j++)
	{
		for(k=0;k<c;k++)
		{
			for(l=0;l<d;l++)
			{
				for(n=0;n<e;n++)
			printf("%d\t",arr[i][j][k][l][n]);
			}
		}
	}
}
}
