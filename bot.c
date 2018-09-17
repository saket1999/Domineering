#include<stdio.h>

int main()
{
	int orient,arr[13][13]={0},bomb,i.,j;	//orient=Orientation,bomb=bomb move left
	scanf("%d",&orient);
	for(i=0;i<13;i++)
		for(j=0;j<13;j++)
			scanf("%d",&arr[i][j]);
	scanf("%d",&bomb);
	return 0;
}