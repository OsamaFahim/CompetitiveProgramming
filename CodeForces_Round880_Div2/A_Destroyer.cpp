#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define mod 998244353

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll cnt[105];

void solve(int tc = 0)
{
	while(tc -- ){
		ll n ;
		cin >> n;
		ll a[n];
		
		for(ll i=0;i<n;++i) cin >> a[i] ; 
		
			memset(cnt,0,sizeof(cnt));
			
			bool ans = 1;
			ll maxi = INT_MIN;
			if(n == 1){
				ans = (a[0] == 0) ? 1 : 0 ;
			}else{
				for(int i=0;i<n;++i){
					cnt[a[i]]++;
					maxi = max(maxi,a[i]);
				}
				
				for(int i=1;i<=maxi;++i){
					if(cnt[i] > cnt[i-1]){
						ans = 0;
						break;
					}
				}
			}

			cout << ((ans) ? "YES\n" : "NO\n");
	}
}

int main()
{
    fastIO();	
	int tc = 0;
	cin >> tc;
	solve(tc);
}