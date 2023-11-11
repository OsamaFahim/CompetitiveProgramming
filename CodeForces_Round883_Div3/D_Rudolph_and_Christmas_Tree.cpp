  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;

  //for this problem just remeber how intersection works and how the smaller and larger triangles (intersecting)
  //are proportional dimesionally ? Else it gave wonderful gerometry concept

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
      ll n,b,h;
      cin >> n >> b >> h;
      
      ld heights[n];
      
      for(ll i=0;i<n;++i) cin >> heights[i];
      
      const ld area = (b*h)/2.0;
      ld ans = 0.0;
      
      for(ll i=0;i<n;++i){
        ans += area;
        
        if(i < n - 1 && (heights[i] + h) > heights[i + 1]){
          ld h_dash = (heights[i] + h ) -  heights[i + 1];
          ld b_dash = (b * h_dash) / double(h);
          
          ans -= (h_dash * b_dash) / 2.0;
        }  
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