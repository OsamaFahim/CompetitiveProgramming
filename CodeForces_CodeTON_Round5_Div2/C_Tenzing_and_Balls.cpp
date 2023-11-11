	#include <bits/stdc++.h>
	#include <iomanip>
 
	using namespace std;
 
	typedef long long ll;
	typedef long double ld;
	typedef unsigned long long ull;
	#define mod 998244353
	#define nl '\n'
	
	void fastIO();	
	
	void solve(int tc = 0)
	{
		while(tc--){
			ll n;
			cin >> n;
			
			ll a[n]{};
			
			for(ll i=0;i<n;++i) cin >> a[i];
				
			ll dp[n]{};
			map<ll,ll> mp;
			mp[a[0]] = 0;
			
			for(ll i = 1; i < n ; ++i){
				dp[i] = dp[i - 1];
				if(mp.find(a[i]) != mp.end()){
					dp[i] = max(dp[i], i + 1 - mp[a[i]] + ((mp[a[i]] != 0) ? dp[mp[a[i]] - 1] : 0));
					dp[i] = max(dp[i], i - mp[a[i]] + dp[mp[a[i]]]);
				}
				mp[a[i]] = i;
			}	
			
			cout << dp[n - 1] << nl;
		}
	}
 
 	int main()
	{
		fastIO();
		int tc = 0;
		cin >> tc;
		cout << fixed << setprecision(10);
		solve(tc);
	}
 
 	void fastIO()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	}