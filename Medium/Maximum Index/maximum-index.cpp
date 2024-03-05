//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input aay
    // N: size of aay
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        int ans=-1;
  
        int suffixMax[n] = {0}, prefixMin[n] = {0};
        
        suffixMax[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], a[i]);
        }
        
        prefixMin[0] = a[0];
        for(int i=1; i<n; i++){
            prefixMin[i] = min(prefixMin[i-1], a[i]);
        }

        int i=0, j =0;
        while(i < n && j < n){
            if(prefixMin[i] > suffixMax[j]) i++;
            
            else if(suffixMax[j] >= prefixMin[i]){
                ans = max(ans , j-i);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends