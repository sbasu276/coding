#include<stdio.h>
int main()
{
	int a[3][3][2]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
	//printf("%d %d %d \n",*(*(*(a+0)+2)+1), *(*(*(a+2)+1)+1), *(a[1][1]+1));
	
	printf("%d %d\n",sizeof(int),sizeof(long int));
	return 0;
}
