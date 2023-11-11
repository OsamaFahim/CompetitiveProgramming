#include <bits/stdc++.h>
#include <iomanip>

//Understanding this problem was very hard as it took you 2 days to understand this problem, it was a bit maths heavy and there are still 2 to 3 minor
//points which are not clear to you still

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
		ll n , k , g;
		cin >> n >> k >> g;
		
		ll tot = k * g;		
		ll r = ((g + 1) / 2) - 1;
			
		if(tot <= r * n - 1)
			cout << tot << nl;
		else{
			ll dist = r * (n - 1) ;
			ll rem = tot - dist;
			
			ll nth_dist = rem % g;
			if(nth_dist >= (g - 1) / 2)
				rem += g - nth_dist;
			else 
				rem -= nth_dist;
			
		  cout << tot - rem << nl;
		}
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