//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n= s.size();
        
        if(n<=2)
        {
            if((stoi(s))%8==0)
                return 1;
            else
                return -1;
        }
        
        string tmp= s.substr(n-3, 3);
        
        if(stoi(tmp)%8==0)
                return 1;
            else
                return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends