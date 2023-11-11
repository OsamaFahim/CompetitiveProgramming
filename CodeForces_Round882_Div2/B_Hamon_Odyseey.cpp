  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
  // a & b >= (a & b & c) --- > Universal Truth 
    
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
      
    ll AND = a[0];
  
    for(ll i=0;i<n;++i) AND &= a[i];
      
    if(AND > 0)
      cout << 1 << nl;
    else{
      ll ind = 0;
      ll ans = 0;
      AND = a[0];
      
      while(AND != 0){
        AND &= a[ind];
        ind ++ ;
      }
      
      if(AND == 0 && ind != 0)  ans ++ ;
      if(ind == n)
        cout << ans << nl;
      else{
        AND = a[ind];
        for(;ind<n;++ind){
          AND &= a[ind];
          if(AND == 0){
            ans ++;
            if(ind != n - 1) AND = a[ind + 1];
          }
        }
        cout << ans << nl;
      }
    }
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