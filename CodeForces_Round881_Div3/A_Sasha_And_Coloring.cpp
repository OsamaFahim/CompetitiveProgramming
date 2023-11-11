#include <bits/stdc++.h>
#include <iomanip>

//was a very easy problem you misinterperated some statements and was unable to make a very easy samll observation 
//Nice Sneaky Observation

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define mod 998244353
#define nl '\n'

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void solve(int tc=0)
{
	while(tc -- ){
		ll n ;
		cin >> n;
		
		ll a[n];
		memset(a,0,sizeof(a));
		
		for(ll i = 0 ; i < n; ++i) cin >> a[i];
		
		sort(a,a + n);
			
		ll ans = 0;	
		for(ll i = 0 ; i < (n - 1 -i);++i)
			ans += a[n - 1 - i] - a[i];
		
		cout << ans << nl;
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