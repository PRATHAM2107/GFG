//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int fun(vector<int>& height , int ind ,vector<int>& v){
        if(ind==0) 
            return 0;
        if(ind==1)  
            return abs(height[1]-height[0]);
        
        if(v[ind]!=-1)  
            return v[ind];
        
        int left = fun(height,ind-1,v) + abs(height[ind]-height[ind-1]);
        int right = fun(height,ind-2,v) + abs(height[ind]-height[ind-2]);
        
        v[ind] = min(left,right);
        return v[ind];
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> v(n+1,-1);
        int ans = fun(height , n-1 , v);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends