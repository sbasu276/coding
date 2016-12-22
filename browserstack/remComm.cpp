#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

//#define BUFF 1024

int status=0; 
// 0 for not in comment, 1 for single line, 2 for multi line comment
int in_str=0;

string remcom(string in)
{
	int i,j;
	char prev,curr;
	int len = in.size();
	char op[len];//[BUFF];

	for(i=j=0; i<len; i++)
	{
		curr = in[i];
		// if i was in a string literal
		if(in_str)
		{
			// if the literal ends now
			if(curr == '"')
				in_str=0;
			op[j++] = curr;
		}
		else
		{
			if(status == 0) // not in comment
			{
				// if string literal begins
				if(curr == '"')
				{
					in_str=1;
					op[j++] = curr;
					continue;
				}

				if(curr == '/' && prev =='/')
					status = 1;
				else if(curr == '*' && prev == '/')
					status = 2;
				else if(curr != '/' || (curr == '/' && i<len-1 && !(in[i+1]=='/' || in[i+1]=='*')) )
					op[j++] = curr;
			}
			else if(status == 1)
			{
				status = 0;
				break;
			}
			else if (status == 2)
			{
				if(curr=='/' && prev=='*')
					status = 0;
			}
		}
		prev = curr;
	}
	op[j] = '\0';
	string retval(op);
	
	return retval;
}


int main()
{
	//read each line and parse comments
	string inp;

	while(getline(cin, inp))
	{
		string op = remcom(inp);
		if(op[0]!='\0')
			cout << op <<"\n" ;
	}
return 0;
}
	
