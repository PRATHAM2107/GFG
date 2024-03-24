//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	 void solve(vector<string> &ans, string op, int one , int zero, int N){
       if(N == one + zero){
           ans.push_back(op);
           return;
       }
       string op1 = op;
       string op2 = op;
       if(one<=zero){
          op1+="1";
           solve(ans,op1,one+1,zero,N);
           
       }
       else{
           op1+="1";
           op2+="0";
           
           solve(ans,op1,one+1,zero,N);
           solve(ans,op2,one,zero+1,N);
       }
   }
    vector<string> NBitBinary(int N)
    {
        vector<string> ans;
        
        string op = ""; 
        
        int one = 0;
        int zero = 0;
        
        solve(ans,op,one,zero,N);
        
        return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends