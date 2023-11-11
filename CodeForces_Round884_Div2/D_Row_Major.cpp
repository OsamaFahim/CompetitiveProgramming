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
   ll n;
   cin >> n;
    
   ll table[n]{};  
    
   vector<ll> factors;
   
   for(ll i=1;i<n;++i){
    if((n % i) == 0){
        factors.pb(i);
    }
   } 
    
   for(ll i=0;i<n;++i){
      for(ll j=0;j<factors.size();++j){
            if(i + factors[j] < n && table[i] == table[i + factors[j]])
                table[i + factors[j]]++;
      }
   }
   
   string ans = "";
   for(ll i=0;i<n;++i){
    ans.pb((table[i] + 'a'));
   }
   
   cout << ans << nl;
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