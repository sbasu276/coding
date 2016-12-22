/* Find the pair of numbers in an array(containing +ve & -ve elements) whose sum is closest to zero */

/*
Algorithm:
---------
1) Sort all the elements of the input array.
2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
3) sum = a[l] + a[r]
4) If sum is -ve, then l++
5) If sum is +ve, then r–
6) Keep track of abs min sum.
7) Repeat steps 3, 4, 5 and 6 while l < r
*/

#include<iostream>
#include<algorithm>
using namespace std;

void find_pair(int a[],int size)
{
	int i,l=0,r=size-1;
	int min_sum,sum,min_l=l,min_r=r;
	sort(a,a+size);
	min_sum = a[l]+a[r];
	while(l<r)
	{
		sum = a[l]+a[r];
		if(sum<0)
			l++;
		else
			r--;
		if(abs(sum)<abs(min_sum))
		{
			min_l=l;
			min_r=r;
			min_sum=sum;
		}
	}
	cout<<a[min_l]<<"\t"<<a[min_r]<<endl;
}

int main()
{
	int a[]={1,60,-10,70,-80,85};
	int s=sizeof(a)/sizeof(a[0]);
	find_pair(a,s);
return 0;
}
