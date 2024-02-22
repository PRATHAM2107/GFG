//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

#define mod 1000000007
class Solution
{
    public:
    vector<vector<int>>memo;
    int dp(int i, int j, string s, string t, int n, int m) {
    if (j == m) 
    {
        return 1;
    }
    if (i == n) 
    {
        return 0;
    }
    
    if (memo[i][j] != -1) 
    {
        return memo[i][j];
    }
    
    int inc = 0, ex = 0;
    if (s[i] == t[j]) 
    {
        inc = dp(i+1, j+1, s, t, n, m); 
    }
    ex = dp(i+1, j, s, t, n, m); 
    
    memo[i][j] = (inc + ex) % mod;
    return memo[i][j];
}
    int subsequenceCount(string s, string t)
    {
        int n = s.size(), m = t.size();
      memo.resize(n,vector<int>(m,-1));
      return dp(0,0,s,t,n,m)%mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends