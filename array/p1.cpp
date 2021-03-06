/* Given an array A[] and a number x, check for pair in A[] with sum as x */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int check(vector<int>a,int N) {

	sort(a.begin() ,a.end());

	int l=0,r=a.size()-1;
	while(l<r) {
		if(a[l]+a[r]==N)
			return 1;
		else if(a[l]+a[r]<N)
			l++;
		else
			r--;
	}
return 0;
}

int main()
{
	int co;
	vector <int> a;
	cin>> co;
	for(int i=0;i<co;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	int b;
	cin >> b;
	cout<< check(a,b)<<endl;
return 0;
}
		
	





/*
----------
Algorithm:
----------
hasArrayTwoCandidates (A[], ar_size, sum)
1) Sort the array in non-decreasing order.
2) Initialize two index variables to find the candidate 
   elements in the sorted array.
       (a) Initialize first to the leftmost index: l = 0
       (b) Initialize second  the rightmost index:  r = ar_size-1
3) Loop while l < r.
       (a) If (A[l] + A[r] == sum)  then return 1
       (b) Else if( A[l] + A[r] <  sum )  then l++
       (c) Else r--    
4) No candidates in whole array - return 0

Time Complexity: Depends on what sorting algorithm we use. If we use Merge Sort or Heap Sort then (-)(nlogn) in worst case. If we use Quick Sort then O(n^2) in worst case.
Auxiliary Space : Again, depends on sorting algorithm. For example auxiliary space is O(n) for merge sort and O(1) for Heap Sort.

*/
