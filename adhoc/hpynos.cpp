#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	long n;	
	int a[811];
	scanf("%ld",&n);
	memset(a,0,sizeof(a));
	int times=1;
	while(1)
	{
		int sum=0;		
		while(n)
		{
			int tmp = n%10;
			sum += (tmp*tmp);
			n = n/10;
		}
	
		if(a[sum]==1)
		{
			printf("-1\n");
			break;
		}

		if(sum==1)
		{
			printf("%d\n",times);
			break;
		}

		a[sum]=1;
		n = sum;
		times++;
	}
return 0;
}
