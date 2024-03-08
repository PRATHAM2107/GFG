//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
bool sameFreq(string s)
    {
        int n = s.length();
        vector<int> v(26,0);
        for(int i = 0; i<n; i++){
            char ch = s[i];
            v[ch-'a']++;
        }
        int mini = 1e6;
        for(int i = 0; i<26; i++){
            if(v[i]!=0){
                mini = min(mini,v[i]);
            }
        }
        int cnt = 0;
        int minicnt = 0;
        for(int i = 0; i<26; i++){
            if(v[i]!=0){
                if(v[i]>mini){
                    if((v[i]-mini)>1)return false;
                    cnt++;
                }
                if(v[i]==mini)minicnt++;
            }
        }
        if(cnt==0)return true;
        if(cnt==1)return true;
        if(cnt>1 && minicnt>1)return false;
        if(cnt>1 && minicnt==1 && mini==1)return true;
        if(cnt>1 && minicnt==1 && mini>1)return false;
        
        
        return true;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends