#include<cstdio>
#define MAX 2001

int max(int a, int b) 
{ 
	return a>b? a:b; 
}
int min(int a, int b) 
{ 
	return a<b? a:b; 
}
	
	

int arr[MAX];
int sum[MAX];
int dp[MAX][MAX];
	

int main(){

	int n,i,j,temp;
	
	scanf("%d",&n);
	arr[0] = sum[0] = 0;
	for(i=0;i<n;i++)
		scanf("%d",arr+n-i);
	for(i=1;i<=n;i++){
		sum[i] = sum[i-1] + arr[i];
	}
	dp[1][1] = arr[1];
	for(i=2;i<=n;i++){
		dp[i][1] = arr[i] + sum[i-1] - dp[i-1][min(i-1,2)];
		dp[i][i] = sum[i];
		for(j=2;j<i;j++){
			temp = sum[i-j] - dp[i-j][min(i-j,2*j)] + sum[i] - sum[i-j];
			dp[i][j] = max(dp[i][j-1],temp);
		}
	}
	printf("%d",dp[n][2]);
	return 0;
}
