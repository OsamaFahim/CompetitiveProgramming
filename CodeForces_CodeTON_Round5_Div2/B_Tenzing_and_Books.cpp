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
			ll n , x;
			cin >> n >> x;
			
			ll a[n]{};
			ll b[n]{};
			ll c[n]{};
			
			for(ll i = 0 ; i < n; ++i) cin >> a[i];
			for(ll i = 0 ; i < n; ++i) cin >> b[i];
			for(ll i = 0 ; i < n; ++i) cin >> c[i];	
			
			ll ans = 0 , now = 0;
			for(ll i = 0 ; i < n; ++i){
				now |= a[i];
				if((now | x )!= x) break;
				else ans |= a[i];
			}
			
			now = 0;
			for(ll i = 0 ; i < n; ++i){
				now |= b[i];
				if((now | x) != x) break;
				else ans |= b[i];
			}
				
			now = 0;
			for(ll i = 0 ; i < n; ++i){
				now |= c[i];
				if((now | x) != x) break;
				else ans |= c[i];
			}
				
			if(ans == x)
				cout << "YES\n";
			else
				cout << "NO\n";
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