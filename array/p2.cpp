/* Find out the Majority Element in an array */
/*
Algorithm:
----------
Moore's voting scheme. 
1. Cancel elements with non matching elements. The survivor is potential ME.
2. Check whether it occurs >n/2 times.
*/


#include<iostream>
using namespace std;
void find_maj(int a[],int size)
{
	int i,maj_i=0,count=1;
	for(i=1;i<size;i++)
	{
		if(a[i]==a[maj_i])
			count++;
		else
			count--;
		if(count==0)
		{
			maj_i=i;
			count=1;
		}
	}
	maj_i=a[maj_i];

	count=0;
	for(i=0;i<size;i++)
		if(a[i]==maj_i)
			count++;
	if(count>size/2)
		cout<<maj_i<<endl;
	else
		cout<<"NONE"<<endl;
}

int main()
{
	int a[]={1,3,1,3,2,7,6,4,3,3,3,3,1,3,3};
	int s=sizeof(a)/sizeof(a[0]);
	find_maj(a,s);
return 0;
}
