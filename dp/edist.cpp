/* Edit Distance between two strings */
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
using namespace std;

#define SIZE 2001

int table[SIZE][SIZE];
int cost[4];//={1,1,0,1};

int min(int a, int b, int c)
{
	int m=a;
	if(m>b) m=b;
	if(m>c) m=c;
return m;
}

int edist(string x, string y)
{
	int m = x.size();
	int n = y.size();
	int i,j;
	
	memset(table, 0 , sizeof(table));
	
	table[0][0] = cost[2];

	for(i=1;i<=n;i++)
		table[0][i]=i*cost[1];
	for(i=1;i<=m;i++)
		table[i][0]=i*cost[0];

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			int del_cost = table[i][j-1]+cost[0]; // delete
			int ins_cost = table[i-1][j]+cost[1]; // insert
			
			int s_cost = table[i-1][j-1];
			if(x[i-1] == y[j-1]) 
				s_cost += cost[2] ; // copy
			
			else	
				s_cost += cost[3] ; // replace
			
			printf("(%d,%d) d=%d i=%d s=%d\n",i,j,del_cost, ins_cost, s_cost); 
			
			table[i][j] = min(del_cost, ins_cost, s_cost);
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
			printf("%2d ",table[i][j]);
		cout << endl;
	}
	return table[m][n];
}

int main()
{
	string x,y;

	int t;
	cin >> t;

	while(t--)
	{
		for(int i=0;i<4;i++)
			cin >> cost[i];
		cin >> x >> y;
		cout << edist(x,y) <<endl;
		
	}
return 0;
}
