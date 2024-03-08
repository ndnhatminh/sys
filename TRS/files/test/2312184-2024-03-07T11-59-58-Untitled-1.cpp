#include<bits/stdc++.h>
using namespace std;
	int n, a[10000];
	map<int,int> mp;
	void check(int n){
		for(int i=1; i<=sqrt(n); i++){
			if(n%i==0){
				mp[i]++;
				if(i!=n/i) mp[n/i]++;
			}
		}
	}
	int main(){
		int q; cin >> q;
		while(q--){
			cin >> n;
			for(int i=0; i<n; i++){
				cin >> a[i];
				check(a[i]);
			}
			int res=1;
			for(auto it:mp){
				if(it.second>=2) res=it.first;
			}
			cout << res << endl;
			mp.clear();
		}
		return 0;
	}
