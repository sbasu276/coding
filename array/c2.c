#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
union A{
long long int y[5];
	union B{
		double g;
		union C{
			int k;
			union D{
				char ch;
				int x[5];
			} s;
		} a;
	} b;
}p;

//p=(union*)malloc(sizeof(union A));
memset(&p,0,sizeof(p));
p.b.a.k = 15;
printf("%d %lld \n",p.b.a.s.x[0],p.y[0]);
printf("%d\n",sizeof(p));


return 0;
}


