/* The 3n+1 problem */
#include<cstdio>
using namespace std;

int cycleLen(int n)
{
	int count=1;
	while(n!=1)
	{
		if(n%2==0)
			n/=2;
		else
			n=3*n+1;
		count++;
	}
return count;
}


int main()
{
	int l,u;

	while(scanf("%d%d",&l,&u)!=EOF)
	{
		int ub = (l>u ? l : u);
		int lb = (l<=u ? l : u);

		int c, max = cycleLen(lb);
		for(int i=lb+1;i<=ub;i++)
		{
			c = cycleLen(i);
			if(max < c)
				max = c;
		}
		printf("%d %d %d\n",l,u,max);
	}
return 0;
}
