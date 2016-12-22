#include<cstdio>

int dig[10][4]={
		{0,0,0,0},
		{1,1,1,1},
		{2,4,8,6},
		{3,9,7,1},
		{4,6,4,6},
		{5,5,5,5},
		{6,6,6,6},
		{7,9,3,1},
		{8,4,2,6},
		{9,1,9,1} };

int main()
{
	int a,b;
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d %d",&a,&b);
		a=a%10; // unit digit of base
		if(b==0)
		{
			printf("1\n");
			continue;
		}
		b=b&3; // b = b%4
		printf("%d\n",dig[a][(b-1)&3]);
	}
return 0;
}
