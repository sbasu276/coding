#include<cstdio>
#include<stack>
#include<cstring>

void lis(int a[],int size)
{
	int L[size],s[size];
	int max_i,max,i,j;
	std::stack<int> res;

	for(i=0;i<size;i++)
	{
		L[i]=1;
		s[i]=0;
	}

	for(i=1;i<size;i++)
		for(j=0;j<i;j++)
			if(a[j]<a[i] && L[i]<L[j]+1)
			{
				L[i] = L[j]+1;
				s[i] = j;
			}
	max=L[0];
	max_i=0;
	for(i=1;i<size;i++)
		if(max <= L[i])
		{
			max=L[i];
			max_i=i;
		}
	
	j=max_i;
	res.push(a[j]);
	while(j)
	{
		i=s[j];
		res.push(a[i]);
		j=i;
	}

	while(!res.empty())
	{
		printf("%d ",res.top());
		res.pop();
	}
	printf("\nLength of LIS: %d\n",max);
}

/* Searches the position of the element which is smallest of all elements which are bigger than key and present in the array
*/
int bin_search(int a[], int l, int r, int val)
{
	int m;
	while(r-l>1)
	{
		m = l+(r-l)/2;
		if(a[m] > val)
			r = m;
		else if (a[m] < val)
			l = m;
		else 
			return m;
	}
return r;
}

void lis_eff(int a[],int s)
{
	int L[s];
	int len=1;
	int i;
	L[0]=a[0];
	for(i=1;i<s;i++)
	{
		if(a[i] < L[0])
			L[0]=a[i];
		else if(a[i] >= L[len-1])
			L[len++]=a[i];
		else
		{
			int k = bin_search(L, 0, len-1, a[i]);
			L[k] = a[i];
		}
	}

	printf("\nLength of Efficient LIS: %d\n",len);

}




int main()
{
//	int a[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

	int a[] = {4,0,2,3};
	int s=sizeof(a)/sizeof(int);
	lis(a,s);
	lis_eff(a,s);
return 0;
}
