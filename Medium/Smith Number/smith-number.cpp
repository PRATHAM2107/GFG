//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void PrimeFactor(int n , vector<int> &factors)
    {
        if(n <= 1)
            return;
    
        while(n % 2 == 0)
        {
            factors.push_back(2);
    
            n = n / 2;
        }
        while(n % 3 == 0)
        {
            factors.push_back(3);
    
            n = n / 3;
        }
        
        for(int i=5; i*i<=n; i=i+6)
        {
            while(n % i == 0)
            {
                factors.push_back(i);
                n = n / i;
            }
    
            while(n % (i + 2) == 0)
            {
                factors.push_back(i+2);
                n = n / (i + 2);
            }
        }
    
        if(n > 3)
            factors.push_back(n);
    }
    
    int digitsum(int n)
    {
        int tmp = n;
        int res = 0;
        while(tmp){
            res += tmp%10;
            tmp = tmp/10;
        }
        return res;
    }
    
    
    int smithNum(int n) {
        // code here
        
        vector<int> factors;
        PrimeFactor(n , factors);
        int sum1=0, sum2=0;
        for(auto i: factors)
        {
            sum1+=digitsum(i);
        }
        
        sum2= digitsum(n);
        if(factors.size()==1)
            return 0;
            
        return sum1==sum2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends