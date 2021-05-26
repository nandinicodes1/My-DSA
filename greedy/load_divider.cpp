#include <iostream>
using namespace std;
int main() {
    int n,max1=0,d=0,ans=0;;
    cin>>n;
    int a[n];
    int load=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        load+=a[i];
    }
    if(load%n!=0){
        cout<<"-1";
    }
    else{
        load=load/n;
        for(int i=0;i<n;i++){
            d+=a[i]-load;
            ans=(d>0)?d:-d;
            max1=max(max1,ans);
        }
        cout<<max1;
    }
    return 0;
}

