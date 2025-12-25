#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum=0;
    cin>>n;
    int dp[n+1][10]={0,};
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0){
                dp[i][j]=dp[i-1][1];
            }
            else if(j==9){
                dp[i][j]=dp[i-1][8];
            }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            }
            dp[i][j]%=1000000000;
        }
    }
    for(int i=0;i<=9;i++){
        sum+=dp[n][i];
        sum%=1000000000;
    }
    cout<<sum;
    return 0;
}
