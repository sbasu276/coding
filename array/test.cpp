#include<iostream>
#include<vector>
using namespace std;

int pp(int a)
{
	vector<int> d;
	
	while(a)
	{
		d.push_back(a%10);
		a=a/10;
	}
	int i=d.size();
	for(int j=0;j<i/2;j++)
	{
		if(d[j]!=d[i-1-j])
			return 0;
	}
return 1;
}

int main()
{
	int r;
	int a;
	cin>>a;
	r= pp(a);
	cout<<r<<endl;

return 0;
}	
