#include<cstdlib>
#include<cstdio>

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int main()
{
	int n,k,m;
	int *a,*b;
	int **V;

	scanf("%d",&n);
	while(n-->0)
	{
		//k:Capacity
		int i,j;
		scanf("%d%d",&k,&m);
		a = (int*)malloc((m+1)*sizeof(int));
		b = (int*)malloc((m+1)*sizeof(int));
		V = (int**)malloc((m+1)*sizeof(int*));
		for(i=0;i<m+1;i++)
			V[i] = (int*)malloc((k+1)*sizeof(int));
		// a:weight, b:value
		a[0] = b[0] =0;
		for(i=1;i<=m;i++)
			scanf("%d%d",&a[i],&b[i]);

		for(i=0;i<=k;i++)
			V[0][i] = 0;
		for(i=1;i<=m;i++)
			V[i][0] = 0;

		for(i=1;i<=m;i++)
		for(j=1;j<=k;j++)
		{
			if(a[i]<=j)
			{
				V[i][j] = max((V[i-1][j-a[i]]+b[i]) , V[i-1][j]);
			}
			else
				V[i][j] = V[i-1][j];
		}

		printf("Hey stupid robber, you can get %d.\n",V[m][k]);

		free(V);
		free(a);
		free(b);
				
	}
return 0;
}

