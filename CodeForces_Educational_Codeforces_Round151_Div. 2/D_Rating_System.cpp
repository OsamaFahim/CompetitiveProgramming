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
        ll n;
        cin >> n;
        
        ll a[n]{};
        
        for(ll i=0;i<n;++i) cin >> a[i];
            
        ll sum=0,mx=0,delta=0,k=0;
            
        for(ll i=0;i<n;++i){
            sum += a[i];
            mx = max(mx,sum);
            if((sum - mx) < delta){
                delta = sum - mx;
                k = mx;
            }
        }
        
        cout << k << nl;
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
