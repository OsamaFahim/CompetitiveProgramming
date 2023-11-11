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
  
void solve()
{
    ll n,m;
    cin >> n >> m;
    
    vector<ll> adj[n];
    
    for(ll i=0;i<m;++i){
      ll p;
      ll q;
      cin >> p >> q;
      --p;
      --q;
      
      adj[p].pb(q);      
      adj[q].pb(p);
    }
    
    
      ll initial = 0 , init_cnt = 0;
      ll second_initial = 0 , scnd_init_cnt = 0 ;
      ll x = 0, y = 0;
      for(auto it : adj){
        ll sz = it.size();
        if(sz > 1){
          if(initial == 0){
            initial = sz;
            init_cnt++;
          }
          else{
            if(sz != initial){
            second_initial = sz;
            scnd_init_cnt ++;
            }
            else
              init_cnt ++ ;
          }
        }
      }
      
      if(init_cnt == 1){
        x = initial;
        y = second_initial - 1;
      }
      else if(scnd_init_cnt == 1){
        x = second_initial;
        y = initial - 1;
      }
      else if(scnd_init_cnt == 0){
        x = initial;
        y = initial - 1;
      }
      
      cout << x << ' ' << y << nl;
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