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
#define mxn (ll)105
   
ll find_index(ll a[],ll size,ll element)
{
     ll ind = -1;
    for(ll i=1;i<=size;++i){
       if(a[i] == element){
          ind = i;
          break;
       }
    }
    return ind;
}



void print(vector<ll>& ans)
{
    for(ll i=0;i<ans.size();++i){
        cout << ans[i] << ' ';
    }
    cout << nl;
}   
   
void solve()
{
    ll n;
    cin >> n;
    
    ll a[n + 1];
    
    for(ll i=1;i<=n;++i) cin >> a[i];
    
    ll nth_ind = find_index(a,n,n);
    
    if(nth_ind == n){
        vector<ll> ans;
        ll maxi = n;
        ll i;
        for(i=n;i>=1;i--){
            if(a[i] == maxi){
               ans.pb(maxi);
               maxi -= 1;
            }
            else break;
        }
            
        for(ll j=1;j<=i;++j) ans.pb(a[j]);    
        print(ans);
    }
    else{
        if(nth_ind == 1){
            ll nth_1_ind = find_index(a,n,n-1);
            
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