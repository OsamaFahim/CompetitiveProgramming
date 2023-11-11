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
#define mxn (ll)10010001

//BEautiful problem maximum jump can be reduced but at that time second maximum can become our maximum as max has reduced to max/2
//so that there can be problems like these too 

void solve()
{
    ll n,k;
    cin >> n >> k;
    
    ll a[n];
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    ll last[k+1]{};
    memset(last,-1,sizeof(last));
    ll maxi[k+1]{};
    ll scnd_max[k+1]{};
    
    for(ll i = 0; i < n; ++i){
        ll step = i - last[a[i]];
        if(step > maxi[a[i]]){
            scnd_max[a[i]] = maxi[a[i]];
            maxi[a[i]] = step;
        }
        else if(step > scnd_max[a[i]]){
            scnd_max[a[i]] = step;
        }
        last[a[i]] = i;
    }
    
    for(ll i = 1;i <= k; ++i){
        ll step = n - last[i];
        if(step > maxi[i]){
            scnd_max[i] = maxi[i];
            maxi[i] = step;
        }
        else if(step > scnd_max[i]){
            scnd_max[i] = step;
        }
    }
    
    ll ans = inf;
    for(ll i = 1; i <= k; ++i){
        ans = min(ans,max((maxi[i] + 1) / 2,scnd_max[i]));
    }
    
    cout << ans - 1 << nl;
    
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