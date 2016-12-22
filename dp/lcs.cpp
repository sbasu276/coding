#include<iostream>
using namespace std;

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

void lcs_count(char a[],char b[],int m, int n)
{
	int L[m+1][n+1];
	int i,j;

	for(i=m;i>=0;i--)
	{
		for(j=n;j>=0;j--)
		{
			if(a[i] == '\0' || b[j] == '\0')
				L[i][j] = 0;
			else if(a[i] == b[j])
				L[i][j] = 1+L[i+1][j+1];
			else
				L[i][j] = max(L[i][j+1] , L[i+1][j]);
		}
	}

	cout<<"\n LCS Length : "<<L[0][0]<<"\n";

}

int main()
{
	char a[]={'a','b','c','d','e','f'};
	char b[]={'a','c','d'};

	int m = sizeof(a)/sizeof(char);
	int n = sizeof(b)/sizeof(char);

	lcs_count(a,b,m,n);
return 0;
}
