#include<cstdio>
#define MAX 10000

long long max(long long a, long long b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	int t;
	int n;
	int i,j=1;
	long long v[MAX], p[MAX];
	scanf("%d",&t);
	while(j<=t)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
			scanf("%lld",&v[i]);

		p[0] = v[0];
		p[1] = max(v[0] , v[1]);

		for(i=2;i<n;i++)
			p[i] = max(p[i-1] , (p[i-2]+v[i]));

		printf("Case %d: %lld\n",j,p[n-1]);
		j++;
	}

return 0;
}
