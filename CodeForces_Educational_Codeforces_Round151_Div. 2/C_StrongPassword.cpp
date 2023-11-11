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
        string s;
        cin >> s;
        
        ll m;
        cin >> m;
        
        string l,r;
        cin >> l >> r;
        
       ll len = s.length();
 
       vector<ll> dict[10];
        
        for(ll i=0;i<len;++i)
            dict[s[i] - '0'].pb(i);
        
        for(ll i=0;i<10;++i)
           dict[i].pb(len);
        
        ll ind = -1;
        for(ll i=0;i<m;++i){
            ll lo = l[i] - '0';
            ll ho = r[i] - '0';
            ll newind = 0;
            for(ll j=lo;j<=ho;++j){
                ll id = upper_bound(dict[j].begin(),dict[j].end(),ind) - dict[j].begin();  //this retuns if max index is found after ind variabl
                if(dict[j][id] == len){
                    cout << "YES\n";
                    return;
                }else
                    newind = max(newind,dict[j][id]);
            }
            ind = newind;
        }
        
        cout << "NO\n";
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