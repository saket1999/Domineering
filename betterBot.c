#include<stdio.h>

int type,movei,movej;

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

int boxmove(int arr[13][13],int orient)	//search for 4x4 space and fill 2 spcae securing 2 space
{
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(i-1>=0&&j-1>=0&&arr[i][j]==0&&arr[i+1][j]==0&&arr[i][j+1]==0&&arr[i+1][j+1]==0&&arr[i][j-1]!=0&&arr[i+1][j-1]!=0&&arr[i-1][j]!=0&&arr[i-1][j+1]!=0)
			{
					if(orient==1)
					{
						type=1;
						movei=j+1;
						movej=i;
					}
					else
					{
						type=1;
						movei=i;
						movej=j+1;
					}
					return 0;
	
			}
		}
	}

	for(j=0;j<12;j++)
	{
		for(i=0;i<12;i++)
		{
			if(arr[i][j]==0&&arr[i+1][j]==0&&arr[i][j+1]==0&&arr[i+1][j+1]==0)
			{
				if(orient==1)
				{
					type=1;
					movei=j+1;
					movej=i;
				}
				else
				{
					type=1;
					movei=i;
					movej=j+1;
				}
				return 0;
			}
		}
	}

	return -1;
}

int fillsingle(int arr[13][13],int orient)		//search 1x2 space and fill it
{
	int i,j;
	for(i=0;i<11;i++)
	{
		for(j=0;j<13;j++)
		{
			if(arr[i][j]==0&&arr[i+1][j]==0&&arr[i+2][j]==0)
			{
				if((i+3)==13)
				{
					if(orient==1)
					{
						type=1;
						movei=j;
						movej=i+1;
					}
					else
					{
						type=1;
						movei=i+1;
						movej=j;
					}
					return 0;
				}
				if(arr[i+3][j]!=0)
				{
					if(orient==1)
					{
						type=1;
						movei=j;
						movej=i+1;
					}
					else
					{
						type=1;
						movei=i+1;
						movej=j;
					}
					return 0;
				}

			}
		}
	}

	for(i=0;i<12;i++)
	{
		for(j=0;j<13;j++)
		{
			if(arr[i][j]==0&&arr[i+1][j]==0)
			{
				if(orient==1)
				{
					type=1;
					movei=j;
					movej=i;
				}
				else
				{
					type=1;
					movei=i;
					movej=j;
				}
				return 0;
			}
		}
	}
	return -1;
}

int bombmove(int arr[13][13],int orient)
{
	if(orient==1)
		transpose(arr);
	int i,j,flag,x,y,cnt=0,max=0;
	for(x=0;x<9;x++)
	{
		for(y=0;y<9;y++)
		{
			flag=0;
			cnt=0;
			for(i=x;i<x+5;i++)
			{
				for(j=y;j<y+5;j++)
				{
					if(arr[i][j]==1&&arr[i][j+1]==1&&j+1<y+5)
						j=j+1;
					else if(arr[i][j]==1&&arr[i][j+1]!=1)
					{
						flag=-1;
					}
					else if(arr[i][j]==1&&arr[i][j+1]==1&&j+1>=y+5)
						flag=-1;
			
				}
			}

			for(j=y;j<y+5;j++)
			{
				for(i=x;i<x+5;i++)
				{
					if(arr[i][j]==2&&arr[i+1][j]==2&&i+1<x+5)
						i=i+1;
					else if(arr[i][j]==2&&arr[i+1][j]!=2)
					{
						flag=-1;
					}
					else if(arr[i][j]==2&&arr[i+1][j]==2&&i+1>=x+5)
						flag=-1;
			
				}
			}
			if(flag==0 && orient==2)
			{
				for(i=x;i<x+5;i++)
				{
					for(j=y;j<y+5;j++)
					{
						if(arr[i][j]==0&&arr[i][j+1]==0&&j+1<y+5)
							cnt++;

					}
				}
			}
			if(flag==0 && orient==1)
			{
				for(j=y;j<y+5;j++)
				{
					for(i=x;i<x+5;i++)
					{
						if(arr[i][j]==0&&arr[i+1][j]==0&&i+1<x+5)
							cnt++;

					}
				}
			}

			if(flag==0 && cnt>=max)
			{
				type=2;
				movei=x;
				movej=y;
				max=cnt;
			}
		}
	}

	return flag;
}

int main()
{
	int orient,arr[13][13]={0},bomb,i,j,move,prior;	//orient=Orientation,bomb=bomb move left
	scanf("%d",&orient);
	for(i=0;i<13;i++)
		for(j=0;j<13;j++)
			scanf("%d",&arr[i][j]);
	scanf("%d",&bomb);

	if(orient==1)							//for playing always vertical
		transpose(arr);

	prior=boxmove(arr,orient);
	if(prior==-1)
	prior=fillsingle(arr,orient);
	if(prior==-1)
	prior=bombmove(arr,orient);
	printf("%d %d %d",type,movei,movej);
	return 0;
}