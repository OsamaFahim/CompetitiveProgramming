  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
    //You made the most of the logic which was to think in reverese but you made the part complecated but 
    //not thinking of breaking ins sums of zeroes and ones
    
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
    
   ll compute(ll* a,ll& ind,ll num){
      ll cnt =0;
     while(ind>=0 && a[ind] == num){
       cnt++;
       ind--;
     }
     return cnt;
   } 
    
  void solve()
  {
    ll n;
    cin >> n;
    
    ll a[n];
    
    for(ll i=0;i<n;++i) cin >> a[i];
    
  
    if(a[n-1] == 1){
      cout << "NO\n";
      return;
    }
    else{
      cout << "YES\n";
      ll ind = n - 1;
      vector<ll> ans;
      while(ind >= 0){
        ll zrs = compute(a,ind,0);
        ll ons = compute(a,ind,1);
        if(zrs && ons){
        ll sum = (zrs + ons) - 1;
        for(ll i=0;i<sum;++i) ans.pb(0);
        ans.pb(ons);
       } else if(zrs){ 
          for(ll i=0;i<zrs;++i) ans.pb(0);
        }
      }
      for(auto v : ans) cout << v << ' ';
      cout << nl;  
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
