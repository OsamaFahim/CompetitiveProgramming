  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
  
  // It was on the very verge of being correct man very very close almost one liner silly mistake
  // and observation
    
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
       ll n,m,h;
      
      cin >> n >> m >> h;
      
      ll pos = 1;
      ll my_points = 0;
      ll my_penalty = 0;
      
      for(ll i=0;i<n;++i){
        ll a[m];
        for(ll j=0;j<m;++j)
          cin >> a[j];
        sort(a,a+m);
        ll penalty = 0;
        ll cur_h = h;
        ll points = 0;
        vector<ll> lvec;
        for(ll k=0;k<m;++k) {
         if((cur_h - a[k]) >= 0){
          cur_h -= a[k];
          penalty += a[k];
          lvec.pb(penalty);
          points++;
         }
          else break;
        }
        
        penalty = 0;
        for(ll i=0;i<lvec.size();++i) penalty += lvec[i]; 
        
        if( i == 0 ) my_points = points , my_penalty = penalty;
        else if(points > my_points ) pos ++; 
        else if(points == my_points && penalty < my_penalty) pos ++;
      }
      
      cout << pos << nl;
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