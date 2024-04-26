//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<pair<int, int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        
        int i=0, j=0, k=0;
        while(i<n && j<m && i>=0 && j>=0)
        {
            if(matrix[i][j]==0)
            {
                i+=dir[k].first;
                j+=dir[k].second;
            }
            else
            {
                matrix[i][j]=0;
                if(k==3) k=0;
                else k++;
                i+=dir[k].first;
                j+=dir[k].second;
            }
        }
        
        if(i==-1) i=0;
        if(j==-1) j=0;
        if(i==n)  i= n-1;
        if(j==m)  j= m-1;
        
        return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends