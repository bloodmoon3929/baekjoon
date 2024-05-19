#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string A,B;
    cin>>A>>B;

    

    int M=A.length();
    int N=B.length();
    

    int dp[M+1][N+1];
    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = 0;


    
    
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[M][N];
    return 0;
}