//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long countWays(int n, int k){
        // code here
        long long mod=1e9+7;
        if(n==1)
            return k;
        long long pre=k;
        long long cur=(1LL*k*(k))%mod;
       
        for(int i=3;i<=n;i++){
            
            long long ans=((pre*(k-1))%mod+(cur*(k-1))%mod)%mod;
            pre=cur;
            cur=ans;
        }
       return cur;
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends