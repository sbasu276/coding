#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
//	ios::sync_with_stdio(false);
	
	int n,k,i,a;
	vector<int> arr;

	cin >> n >> k;

	for(i=0;i<n;i++)
	{
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());

	int count = 0;
	for(i=0;i<n;i++)
	{
		if(binary_search(arr.begin()+i, arr.end(), arr[i]+k))
		      count++;
	}
	
	cout << count <<"\n";

return 0;
}
				

