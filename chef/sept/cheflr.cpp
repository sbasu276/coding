#include<cstdio>
#define MAX 100001
#define MOD 1000000007
int main()
{
	int t,i;
	char s[MAX];
	scanf("%d",&t);
	int root,l;
	while(t--)
	{
		scanf("%s",s);
		root=1;
		for(i=0;s[i];i++)
		{
			if(i%2==0)
				l=(root%MOD)<<1;
			else
				l=((root%MOD)<<1)-1;
		//	r=l+2;

			if(s[i]=='l')
				root=l;
			else
				root=l+2;
		}
		printf("%d\n",root%MOD);
	}
return 0;
}
