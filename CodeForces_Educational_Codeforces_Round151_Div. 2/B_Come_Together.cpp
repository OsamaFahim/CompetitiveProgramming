    #include <bits/stdc++.h>
    #include <iomanip>

    using namespace std;
    
    //This problem utilizez the conept of Manhatan Distance 
    
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

    ll calc(ll x,ll y,ll z)
    {
        if(y>=x && z>=x)
            return min(y-x,z-x);
        else if(y<=x && z<=x)
            return min(x-y,x-z);
        return 0;
    }

    void solve()
    {
        ll xa,ya;
        cin >> xa >> ya;
        
        ll xb,yb;
        cin >> xb >> yb;
        
        ll xc,yc;
        cin >> xc >> yc;
        
        cout << calc(xa,xb,xc) + calc(ya,yb,yc) + 1 << nl;
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
