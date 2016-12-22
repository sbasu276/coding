#include<cstdio>
#include<cstdlib>
#define MAX 1000

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	int n,i;
	int a[MAX],b[MAX];
	int M[MAX][2];
	int t1,t2;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);

	M[n-1][0] = a[n-1];
	M[n-1][1] = b[n-1];

	for(i=n-2;i>=0;i--)
	{
		M[i][0] = max((M[i+1][0]+a[i]+abs(b[i]-b[i+1])) , (M[i+1][1]+a[i]+abs(b[i]-a[i+1])));
		M[i][1] = max((M[i+1][0]+b[i]+abs(a[i]-b[i+1])) , (M[i+1][1]+b[i]+abs(a[i]-a[i+1])));
	}

	printf("%d\n",(M[0][0] > M[0][1] ? M[0][0] : M[0][1]));

/*	printf("\n");
	for(i=0;i<n;i++)
	printf("%d ",M[i]);
	printf("\n");
*/
return 0;
}
