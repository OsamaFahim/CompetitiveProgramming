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

    ll n, m, vis[mxn], mn = inf, bad[mxn], nbad[mxn];
    vector<pair<pair<ll, ll>, ll>> g[mxn];

    void dfs(ll node)
    {
        if (vis[node]) return;
        vis[node] = 1;
        for (pair<pair<ll, ll>, ll> a : g[node]) {
            if (bad[a.first.first])  mn = min(mn, a.first.second);
            else  if (!vis[a.first.first])  dfs(a.first.first);
        }
    }
    
    void solve()
    {
        cin >> n >> m;

        for (ll i = 0; i < m; ++i) {
            ll a, b, c;
            cin >> a >> b >> c;
            g[a].pb({{b, c}, g[b].size()});
            g[b].pb({{a, c}, g[a].size() - 1});
        }

        bad[n] = 1;
        dfs(1);
        if (mn == inf) {
            cout << "inf\n";
        } else {
        ll ans = mn;
        vector<string> out1;
        vector<ll> out2;
        string now = "";
        for (ll i = 1; i <= n; ++i) now.pb('0' + vis[i]);
        out1.pb(now);
        out2.pb(mn);
        while (1) {
            for (ll i = 1; i <= n; ++i) nbad[i] = 0;
            for (ll i = 1; i <= n; ++i) {
                if (bad[i]){
                    for (pair<pair<ll, ll>, ll>& a : g[i]) {
                        if (bad[a.first.first]) continue;
                        a.first.second -= mn;
                        g[a.first.first][a.second].first.second -= mn;
                        if (a.first.second <= 0) nbad[a.first.first] = 1;
                    }
                }
            }
            for (ll i = 1; i <= n; ++i) bad[i] |= nbad[i];
            if (bad[1]) break;
               
    		for(int i=1;i<=n;++i) vis[i] = 0;
                
    		mn = inf;
    		dfs(1);
    		ans += mn;
    		string now = "";
    		for(int i = 1;i<=n;++i) now.pb('0' + vis[i]);
    			out1.pb(now);
    			out2.pb(mn);	
    	}
    		cout << ans << ' ' << out1.size() << nl;
    		for(ll i=0;i<out1.size();++i){
    			cout << out1[i] << ' ' << out2[i] << nl;
    		}
    	}
    }
		
	int main()
	{
		fastIO();
		cout << fixed << setprecision(10);
		/*int tc = 0;
		cin >> tc;
		while(tc --)*/
			solve();
	}
    
		
	void fastIO()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}
	
    
    
    