//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int a=-1, b=-1, c=-1,  len=INT_MAX;
        // if(n<3)
        //     return -1;
            
        for(int i=0; i<S.size(); i++)
        {
            if(S[i]=='0')
                a=i;
            else if(S[i]=='1')
                b=i;
            else
                c=i;
            if(a!=-1 && b!=-1 && c!=-1)
            {
               int start=min(min(a, b), c);
               int end= max(max(a, b), c);
               len=min(len,end-start+1);
            }
        }
        
           
        return len==INT_MAX?-1: len;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends