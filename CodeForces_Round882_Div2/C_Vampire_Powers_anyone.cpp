  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
  
  //A very beautiful curated question teaching you the conept of XOR,bitmasks constraint analysis amd much
  //more whenver you think about it consider doing it again

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
      int n;
      cin >> n;
      
      int a[n]{};
      
      for(ll i=0;i<n;++i) cin >> a[i];
      
      int ans = 0;
      
      for(int i=0;i<256;++i){
        bool vis[256] = {0};
        int cur_xor = 0;
        for(int j=0;j<n;++j){
          cur_xor ^= a[j];
          vis[cur_xor] = 1;  
          ans = max(ans,cur_xor);
          if(vis[cur_xor^i]){
            ans = max(ans,i);
            break;
          }
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