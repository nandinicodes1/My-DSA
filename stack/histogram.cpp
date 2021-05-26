#include<bits/stdc++.h>
using namespace std;
int maxarea(int arr[],int n)
{
	stack<int> s;
	
	int max_area=0;
	int tp;
	int tp_area;
	int i=0;
	while(i<n)
	{
		if(s.empty()||arr[s.top()]<=arr[i])
		{
			s.push(i++);
		}
		else
		{
			tp=s.top();
			s.pop();
			
			tp_area=arr[tp]*(s.empty() ? i :i-s.top()-1);
			if(max_area<tp_area)
			{
				max_area=tp_area;
			}
		}
	}
	while(s.empty()==false)
	{
		tp=s.top();
		s.pop();
			
		tp_area=arr[tp]*(s.empty() ? i :i-s.top()-1);
		if(max_area<tp_area)
		{
			max_area=tp_area;
		}
	}
	return max_area;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<maxarea(arr,n);
	return 0;
}



/*
stack<pair<long long,long long>>s;
    int pidx=-1;
    vector<long long> left;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[i]<=s.top().first){
            s.pop();
        }
        if(s.empty()){
            left.push_back(pidx);
        }else{
            left.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    
    
    while(!s.empty()){
        s.pop();
    }
    
    
    
    //stack<pair<long long,long long>>st;
    vector<long long> right;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[i]<=s.top().first){
            s.pop();
        }
        if(s.empty()){
            right.push_back(n);
        }else{
            right.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    vector<long long> width,area;
    for(int i=0;i<n;i++){
        width[i]=right[i]-left[i]-1;
    }
    long long ans=INT_MIN;
    for(int i=0;i<n;i++){
        area[i]=arr[i]*width[i];
        //ans=max(ans,area[i]);
    }
    for(int i=0;i<n;i++){
        ans=max(ans,area[i]);
    }
    
    return ans;
    */
