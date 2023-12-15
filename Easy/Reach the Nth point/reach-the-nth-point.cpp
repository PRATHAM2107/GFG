//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int mod = 1000000007;
		    int pre=0, cur=1, next;
		    
		    for(int i=0; i<n; i++)
		    {
		        next=pre+cur;
		        pre=cur;
		        cur=next%mod;
		    }
		    
		    return cur;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends