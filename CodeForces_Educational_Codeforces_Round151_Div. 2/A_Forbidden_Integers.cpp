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
        ll n,k,x;
        cin >> n >> k >> x;
        
        if(x != 1){
            cout << "YES\n";
            cout << n << nl;
            for(ll i=1;i<=n;++i){
                cout << 1 << ' ';
            }
            cout << nl;
        }else{
          if(k == 1) cout << "NO\n";
          else if(k == 2){
              if(!(n & 1)){
                cout << "YES\n";
                ll qu = n / 2;
                cout << qu << nl;
                for(ll i=0;i<qu;++i)
                   cout << 2 << ' ';
                cout << '\n';
              }else{
               cout << "NO\n";   
              }
          }else{
            cout << "YES\n";
            if(!(n & 1)){
                ll qu = n / 2;
                 cout << qu << nl;
                   for(ll i=0;i<qu;++i)
                      cout << 2 << ' ';
                cout << '\n';
            }else{
               ll qu = (n / 2) - 1;
               cout << qu + 1 << nl;
                for(ll i=0;i<qu;++i)
                      cout << 2 << ' ';
                
                cout << 3 << nl;
            }
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
