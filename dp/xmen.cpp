#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

long bin_search(long a[],long l,long r, long key)
{
	long m;
	while(r-l>1)
	{
		m = l+(r-l)/2;
		if(a[m] > key)
			r=m;
		else if(a[m] < key)
			l=m;
		else
			return m;
	}
return r;
}
		

int main()
{
	int t;
	long a,b,n;
	long i,len;
	map<long,long> table;
	long *c,*L;

	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%ld",&n);
		//a = (long*)malloc(sizeof(long)*n);
		//b = (long*)malloc(sizeof(long)*n);
		c = (long*)malloc(sizeof(long)*n);
		L = (long*)malloc(sizeof(long)*n);
		
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			table.insert(pair<long,long>(a,i));
		}
	//	len=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&b);
			if(table.count(b)) // if b[i] exists in a[]
				c[i] = table.find(b)->second;
		}

		printf("\nC: ");
		for(i=0;i<n;i++)
		{
			printf("%ld ",c[i]);
		}
		printf("\n");
		
		long k=1;
		L[0] = c[0];
		for(i=1;i<n;i++)
		{
			if(c[i] < L[0])
				L[0] = c[i];
			else if(c[i] > L[k-1])
				L[k++] = c[k];
			else
				L[bin_search(L, 0, k-1, c[i])] = c[i];
		}

		printf("%ld\n",k);
		free(c);
		free(L);
	}
return 0;
}
