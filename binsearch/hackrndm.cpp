#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n,k,i;
	map<unsigned int,unsigned int> table;
	// key,value pair
	scanf("%u%u",&n,&k);
	unsigned int arr[n],a;

	for(i=0;i<n;i++)
	{
		scanf("%u",&arr[i]);
		table.insert(make_pair(arr[i], arr[i]+k));
	}
	

	int count = 0;
	for(i=0;i<n;i++)
	{
		int key = arr[i]+k;
		map<unsigned int,unsigned int>::iterator it = table.find(key);
		if(it != table.end())
		{
		   //element found;
		      count++;
		}

	}
	
	printf("%d\n",count);


return 0;
}
				

