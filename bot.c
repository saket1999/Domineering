#include<stdio.h>

void swap(int *a,int *b)
{
	*a^=*b^=*a^=*b;
}

void transpose(int arr[13][13])				//so that we will play always vertial
{
	int i,j;
	for(i=0;i<13;i++)
		for(j=i+1;j<13;j++)
			swap(&arr[i][j],&arr[j][i]);
}

void display(int arr[13][13])
{
	int i,j;
	for(i=0;i<13;i++)
	{
		for(j=0;j<13;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void boxmove(int arr[13][13],int orient)	//search for 4x4 space and fill 2 spcae securing 2 space
{
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(arr[i][j]==0&&arr[i+1][j]==0&&arr[i][j+1]==0&&arr[i+1][j+1]==0)
			{
				if(orient==1)
					printf("%d %d %d",1,j+1,i);
				else
					printf("%d %d %d",1,i,j+1);
				return;
			}
		}
	}
}

int main()
{
	int orient,arr[13][13]={0},bomb,i,j,move;	//orient=Orientation,bomb=bomb move left
	scanf("%d",&orient);
	for(i=0;i<13;i++)
		for(j=0;j<13;j++)
			scanf("%d",&arr[i][j]);
	scanf("%d",&bomb);

	if(orient==1)							//for playing always vertical
		transpose(arr);

	boxmove(arr,orient);
	return 0;
}