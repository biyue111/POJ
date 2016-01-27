#include <cstdio>
#include <stdlib.h>
#include <algorithm>

#define MAX_N 351

using namespace std;

int main()
{
    int N,res;
    int dp[MAX_N][MAX_N],a[MAX_N][MAX_N];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++){
        scanf("%d",&a[i][j]);
        dp[i][j] = 0;
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++){
        if(i==0) dp[i][j] = a[i][j];
        else if(j==0) dp[i][j] = dp[i-1][j] + a[i][j];
        else if(j==i) dp[i][j] = dp[i-1][j-1] + a[i][j];
        else dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
        //printf("%d",i);
    }

    res = 0;
    for(int i=0;i<N;i++)
        if(dp[N-1][i] > res) res = dp[N-1][i];
    printf("%d\n",res);
    return 0;
}
