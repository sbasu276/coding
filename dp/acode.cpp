#include<cstdio>
#define MAX 5001

int acode_opt(char *str)
{
	int i,n; 
	int D,D1,D2;
	int s[MAX];
	
	for(n=0;str[n];n++)
		s[n]=str[n]-'0';
		
	
	--n; //point to the last index; the array is 0,1...n now!
	if(s[n]==0)
	{
		D2 = 0;
		if(s[n-1]>2 || s[n-1]<1)
			return 0;
		D1=1;
	}
	else
	{	
		D2 = 1;
		if(s[n-1]==0)
			D1=0;
			
		else
			D1 = 1 + (10*s[n-1]+s[n] <= 26);
	}
	D=D1+D2;
	i=n-2;
	while(i>=0)
	{
		if(s[i]==0)
			D = 0;
		
		else
		{
			if(10*s[i]+s[i+1] <=26)
				D = D1+D2;
			else
				D = D1;
		}
		i--;
		D2=D1;
		D1=D;
	}
	
return D;
}

/*
int acode(char *str)
{
	int i,n; 
	int D[MAX];
	int s[MAX];
	
	for(n=0;str[n];n++)
		s[n]=str[n]-'0';
		
	
	--n; //point to the last index; the array is 0,1...n now!
	if(s[n]==0)
	{
		D[n] = 0;
		if(s[n-1]>2 || s[n-1]<1)
			return 0;
		D[n-1]=1;
	}
	else
	{	
		D[n] = 1;
		if(s[n-1]==0)
			D[n-1]=0;
			
		else
			D[n-1] = 1 + (10*s[n-1]+s[n] <= 26);
	}

	i=n-2;
	while(i>=0)
	{
		if(s[i]==0)
			D[i] = 0;
		
		else
		{
			if(10*s[i]+s[i+1] <=26)
				D[i] = D[i+1]+D[i+2];
			else
				D[i] = D[i+1];
		}
		i--;
	}
	
return D[0];
}
*/
int main()
{
	char str[MAX];
	while(1)
	{
		scanf("%s",str);
		
		if(str[0]=='0' && str[1]=='\0')
			break;
		//printf("%d\n",acode(str));
		printf("%d\n",acode_opt(str));
	}
return 0;
}
