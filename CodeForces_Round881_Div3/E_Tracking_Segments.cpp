#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//This code has a time complexity of O(logq * ( q + n + m)) which is enough hint that what was used in the code and the intuition was beautifully described in its
//tutorial , it was a beautiful problem giving me 2 beautiful conepts for later figure on your own what these conepts were

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
		ll n , m;
		cin >> n >> m;
		
		ll l[m],r[m];
		fill(l,l + m,0);
		fill(r,r + m,0);
		
		for(ll i=0;i<m;++i) {
			cin >> l[i] >> r[i];
			l[i]--;
			r[i]--;
		}
		
		ll q;
		cin >> q;
		ll charge[q];
		fill(charge,charge + q,0);
		
		for(ll i = 0 ; i < q; ++i){
			cin >> charge[i]; 
			charge[i]--;
		}
		
		ll left = 0 , right = q - 1 , ans = -1;
		while(left <= right){
			ll mid = (left + right) / 2;
			
			ll a[n];
			fill(a,a + n,0);
			
			for(ll i = 0;i <= mid; ++i)
				a[charge[i]] = 1;
			
			for(ll i = 1;i < n;++i)
				a[i] += a[i - 1];
			
			bool y = false;
			for(ll i = 0 ; i < m;++i){
				ll ones = a[r[i]] - (l[i] > 0 ? a[l[i]-1] : 0LL);
				ll zeros = (r[i] - l[i] + 1) - ones;
				if(ones > zeros){
					y = true;
					break;
				}
			}
			
			if(y){
				right = mid - 1;
				ans = mid;
			}
			else
				left = mid + 1;
		}
					
		cout << ((ans != -1) ? ans + 1 : -1 ) << nl ;
		
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