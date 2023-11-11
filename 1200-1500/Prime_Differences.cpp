  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
    //The matrix transformation concept was used which is still useful for most of the other problems 
    //and concepts
    
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
    
  bool prime(ll n)
  {
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    
    for(ll i=2;i<n;++i){
      if((n % i) == 0)
        return false;
    }
    return true;
  }  
    
  void solve()
  {
    ll n,m;
    cin >> n >> m;
    
   ll a[n][m];
   memset(a,0,sizeof(a));
    
    if(!prime(n)){
      ll num = 1;
      for(ll i=0;i<m;++i)
        for(ll j=0;j<n;++j)
          a[j][i] = num++; 
    }
    else if(!prime(m)){
      ll num = 1;
      for(ll i=0;i<n;++i)
        for(ll j=0;j<m;++j)
          a[i][j] = num++;
    }
    else{
      ll num = 1;
      ll flip = 0;
      for(ll i=0;i<m;++i){
          if(flip == n) flip = 0;
           vector<ll> temp;
           for(ll k=0;k<flip;++k) temp.pb(num++);
            ll cnt = 0;
        for(ll j=0;j<n;++j){ 
          if(j < n - flip)
            a[j][i] = num ++;
          else
            a[j][i] = temp[cnt++];
        }
        flip++;
      }
    }
    
    for(ll i=0;i<n;++i){
      for(ll j=0;j<m;++j)
        cout << a[i][j] << ' ';
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
