//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        if(fruits.size()==1 || fruits.size()==2)
            return fruits.size();
            
        int pre=fruits[0], cur=0, i=0, j=1, maxlen=0, curlen=1;
        while(j<fruits.size() && fruits[j]==pre)
        {
            curlen++;
            i=j;
            j++;
        }
        if(j<fruits.size())
        {
            curlen++;
            j++;
        }
        
        while(j<fruits.size())
        {
            if(fruits[j] == fruits[j-1]|| fruits[j] == pre) 
            {
               curlen++;
            }
            else
            {
                maxlen=max(maxlen, curlen);
                curlen=j-i;
            }
           
            if(fruits[j]!=fruits[j-1])
            {
                i=j-1;
                pre=fruits[j-1];
            }
          
           j++;
        }
        maxlen=max(maxlen, curlen);
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends