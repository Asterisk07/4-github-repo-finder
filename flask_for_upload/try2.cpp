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
    	int n;
    	cin>>n;
    	long long a[n],j=0,ma=0;
    	cin>>a[0];
    	// ma=a[0];
        ordered_set s;
        
    	for (long i=1;i<n;i++){
			cin>>a[i];
			if (a[i]>a[ma]){
				ma=i;
			}
        }
        if (n==1){
        	cout<<"0\n";
        	continue;
        }
        cout<<n<<"\n";
        for (long i=0;i<n;i++){
        	if (i!=ma){
        		cout<<i<<" "<<ma<<"\n";
        	}
        	
	
        }
        if (ma==0){
        	j=1;
        // cout<<
        }
    }
}