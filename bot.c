#include<stdio.h>

void swap(int *a,int *b)
{
	*a^=*b^=*a^=*b;
}

void transpose(int arr[13][13])
{
	int i,j;
	for(i=0;i<13;i++)
		for(j=i;j<13;j++)
			swap(&arr[i][j],&arr[j][i]);
}


int main()
{
	int orient,arr[13][13]={0},bomb,i,j;	//orient=Orientation,bomb=bomb move left
	scanf("%d",&orient);
	for(i=0;i<13;i++)
		for(j=0;j<13;j++)
			scanf("%d",&arr[i][j]);
	scanf("%d",&bomb);

	for(i=0;i<13;i++)
	{
		for(j=0;j<13;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}

	transpose(arr);
	printf("\n");

	for(i=0;i<13;i++)
	{
		for(j=0;j<13;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}