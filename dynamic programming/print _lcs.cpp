#include <iostream>
using namespace std;

string printlcs(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    string ans="";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    while(i!=0 || j!=0){
        if(s1[i]==s2[j]){
            ans.push_back(s1[i]);
            i--;j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main() {
	int n,m;
	cin>>n>>m;
	
	string s1,s2;
	cin>>s1>>s2;
	cout<<printlcs(s1,s2,n,m)<<endl;
	return 0;
}
