/* Find leaders(greater than all elements to its right) in an array 
{12,17,3,4,5,2} => 17,5,2

Algo:
----
start scanning array from right to left.
keep track of the max encountered so far.
whenever a new max is found, print it


*/

#include<cstdio>

int main()
{
	int a[]={16,17,4,3,5,2};
	int size=sizeof(a)/sizeof(a[0]);
	int max=a[size-1];

	printf("%d ",a[size-1]);
	for(int i=size-2; i>=0; i--)
	{
		if(a[i]>max)
		{
			printf("%d ",a[i]);
			max=a[i];
		}
	}
return 0;
}
