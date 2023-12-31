//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int TotalWays(int N)
    {
        long mod = 1e9+7;
        long dp[N+1][2] = {1};    // One combination when N=0
        
        for(int i=1; i<=N; i++){
            for(int j=0; j<2; j++){
                if(j) dp[i][j] = dp[i-1][0];
                else dp[i][j] = (dp[i-1][0] + dp[i-1][1]) % mod;
            }
        }
        
        long ans = (dp[N][0] + dp[N][1]); 
        ans = (ans*ans)%mod; // squaring
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends