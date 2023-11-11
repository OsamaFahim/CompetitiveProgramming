  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
    //for this ques you should have patiently tried other things, you were very very close
    
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
    ll n,k;
    cin >> n >> k;
    
    ll a[n];
    
    for(ll i=0;i<n;++i) cin >> a[i];
      
    vector<ll> diff;
  
    for(ll i=1;i<n;++i)
      diff.pb(abs(a[i] - a[i-1]));
    
    sort(diff.begin(),diff.end());
    
    k = (n - k);
    ll ans = 0;
    
    for(ll i=0;i<diff.size() && i<k;++i)
      ans += diff[i];
    
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