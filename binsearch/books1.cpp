#include<cstdio>
#include<cstring>
#define MAX 501

int main()
{
	int t,k,m;
	int i,j,l,temp[MAX];
	long long int high,low,mid,load,a[MAX];

	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d%d",&k,&m);
		
		scanf("%lld",&a[0]);
		high = low = a[0];
		for(i=1;i<k;i++)
		{
			scanf("%lld",&a[i]);
			high += a[i];
			if(low < a[i])
				low = a[i];
		}

		while(high > low)
		{
			mid = low + (high-low)/2;
			int req = 1;
			int load = 0;
			for(i=0;i<k;i++)
			{
				if(load + a[i] <= mid)
					load += a[i];
				else
				{
					req++;
					load = a[i];
				}
			}
			
			if(req <= m)
				high = mid;
			else
				low = mid+1;
		}
		// low gives the max load a worker will take. this value is minimized.
		load = 0;
		l=0;
	
		i=k-1;
		l=m-2;
		int rem = m;
		int stop = 0;
		while(i>=0)
		{
			load = 0;
			while((load+a[i])<= low && i>=0)
			{
				load += a[i];
				// if # remaining workers = # of remaining books then assign single book to everyone
				if(rem == i+1)
				{
					while(l>=0)
					{
						temp[l] = i;
						i--; l--;
					}
					break;
					stop = 1;
				}
				i--;
			}
			if(stop == 1)
				break;
			temp[l] = i+1;
			l--;
			rem--;
		}
		
			
		for(i=0,j=0;i<k;i++)
		{
			
			if(i==temp[j] && temp[j])
			{
				printf("/ ");
				j++;
			}
			printf("%lld",a[i]);
			if(i==k-1)
				break;
			printf(" ");
			
		
			
			
		}
		
		printf("\n");
		memset(temp, 0 ,sizeof(temp)); // flash temp array.
	

	}


return 0;
}
