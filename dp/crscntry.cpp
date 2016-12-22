#include<cstdio>

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int lcs_count(int a[],int b[],int m,int n)
{
	int L[m+1][n+1];
	int i,j;
	for(i=m;i>=0;i--)
	{
		for(j=n;j>=0;j--)
		{
			if(a[i] == 0 || b[j] == 0)
				L[i][j] = 0;
			else if(a[i]==b[j])
				L[i][j] = 1+L[i+1][j+1];
			else
				L[i][j] = max(L[i][j+1] , L[i+1][j]);
		}
	}
return L[0][0];
}

int main()
{
	int d,c;
	int a[2048],b[2048];
	int m,n,i,max,res;

	scanf("%d",&d);
	while(d-->0)
	{
		scanf("%d",&c);
		i=0;
		//if(c==0)
		//	continue;
		while(c)
		{
			a[i++] = c;
			scanf("%d",&c);
		}
		m=i;
		a[m]=0;
		
		max = 0;
		while(1)
		{
			scanf("%d",&c);
			if(c==0)
				break;
			
			i=0;
			while(c)
			{
				b[i++] = c;
				scanf("%d",&c);
			}
			n=i;
			b[n]=0;

			res = lcs_count(a,b,m,n);
			if(max < res)
				max = res;
		}
		printf("%d\n",max);

	}
return 0;
}
