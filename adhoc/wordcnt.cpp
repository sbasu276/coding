#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	cin.ignore(1,'\n');

	while(t--){
		string line;
		getline(cin,line);
		line+=" ";

		string word;
		stringstream brk;
		brk<<line;

		int last=-1,cnt=0;
		int ans=0;
		while(brk>>word)
		{
			if(int(word.size())==last)
				++cnt;
			else
			{
				last=int(word.size());
				cnt=1;
			}

			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
