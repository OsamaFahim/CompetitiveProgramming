  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
  typedef long long ll;
  typedef long double ld;
  typedef unsigned long long ull;
  void fastIO();
  #define mod 998244353
  #define nl '\n'
  #define pb push_back
  #define inf LLONG_MAX
  #define ninf LLONG_MIN
  #define mxn 105
    
  void solve()
  {
      ll n;
      cin >> n;
      
      ll a[n];
      
      for(ll i=0;i<n;++i) cin >> a[i];
        
      sort(a,a+n);
        
      ll lo = 0;
      ll hi = 1e9;
      ll ans = 0;
      
      while(lo<=hi){
        ll mid = (lo + hi) / 2;
        
        ll val = a[0] + mid;
        ll cnt = 1;
        
        for(ll i=1;i<n;++i){
          if(abs(val - a[i]) > mid){
            val = a[i] + mid;
            cnt ++;
            if(cnt > 3)
               break;
          }
        }
        
        if(cnt <= 3){
          ans = mid;
          hi = mid - 1;
        }
        else
          lo = mid + 1;
      }
      
      cout << ans << nl;
  }
		
	int main()
	{
		fastIO();
		cout << fixed << setprecision(10);
		int tc = 0;
		cin >> tc;
		while(tc --)
		  solve();
	}
		
	void fastIO()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	}
