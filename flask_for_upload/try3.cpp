// Problem: B. Equalize by Divide
// Contest: Codeforces - Codeforces Round #854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1799/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
    	int n,c=0,d=0;
    	cin>>n;
    	long long a[n],j=0,ma=0,x;
    	vector <pair<long long,long long>> v,ans;
    	// unordered_map m;
    	// cin>>a[0];
    	// ma=a[0];
    	// set <long> 
        pair<long long,long long> p;
    	for (long i=0;i<n;i++){
			cin>>x;
			if (x==1){
				c=1;
			}
			if ((c==1) and (x!=1)){
				d=-1;
			}
			// m[x]=i;
			// p.first=x;
			v.push_back(make_pair(x,i));
			
        }
        if (d==-1){
        	cout<<"-1\n";
        	continue;
        }
        if (n==1){
        	cout<<"0\n";
        	continue;
        }
        make_heap(v.begin(),v.end());
        long long s=0;
        
        while ((*v.begin()).first!=(*v.end()).first){
        	s++;
            long long z;
        	long long x=(*v.begin()).first;
            long i=(*v.begin()).second;
            long j=(*v.end()).second;
        	long long y=(*v.end()).first;
        	while (x>y){
                s++;
                z=x/y;
                if (x%y){
                    z++;
                }
                x=z;
                ans.push_back(make_pair(i,j));

            }
            v.pop_back();
            v.push_back(make_pair(x,i));
            
        	
        }
        cout<<s<<"\n";
        for (long long i = 0; i < s; i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        
        }
    }
}