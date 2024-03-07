//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string str, int n) {
        // code here
       vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        string res = "";
        int len = 0;
        int index = 0;
    
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (str[i - 1] == str[j - 1] && dp[i - 1][j - 1] < (j - i)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
    
                    if (dp[i][j] > len) {
                        len = dp[i][j];
                        index = max(i, index);
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    
        if (len > 0) {
            for (int i = index - len + 1; i <= index; ++i) {
                res += str[i - 1];
            }
        }
        else 
            return "-1";

    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends