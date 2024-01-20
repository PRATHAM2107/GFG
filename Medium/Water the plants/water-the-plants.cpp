//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>> range;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            range.push_back({ max(0, i-gallery[i]), min(n-1, i+gallery[i])});
        }
        
        sort(range.begin(),range.end());
        
        
        int start=0;
        int i=0;
        int ans=0;
        
        while(start<n)
        {
            int maxr=-1e9;
            while(i<range.size())
            {
                if(range[i].first>start)
                break;
                
                maxr=max(maxr,range[i].second);
                i++;
            }
            
            if(maxr<start)
                return -1;
            
            ans++;
            start=maxr+1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends