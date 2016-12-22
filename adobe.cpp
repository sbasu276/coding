#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=1, rem=1; 
	while(rem)
	{
		rem= (rem*10+1)%n; count++;
	} 
	while(count--)
	{ 
		cout<<"1";
	}
	cout<<endl;
return 0;
}
