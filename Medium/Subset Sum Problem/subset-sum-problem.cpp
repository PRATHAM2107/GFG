//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        bool dp[101][10001];
        memset(dp, 0, sizeof(dp));
    
        // If sum is zero, we can always have an empty subset to get sum 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
    
        // If the first element is less than or equal to sum, we can form the subset
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }
    
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notTaken = dp[i - 1][target];
    
                bool taken = false;
                if (arr[i] <= target) {
                    taken = dp[i - 1][target - arr[i]];
                }
    
                dp[i][target] = notTaken || taken;
            }
        }
    
        return dp[n - 1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends