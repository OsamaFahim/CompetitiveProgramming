#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
  
 //Logic is very intuitve here yara , the problem statement here is eveb self explanatory....still you
 //though dp lga leta haein bhaiya constraints to optimize krle ga remove kis order mei hora and eventually
 //was not able to solve the problem abba jani hosla rkh
  
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
  
  ll a[n];
  
  for(ll i=0;i<n;++i) cin >> a[i];
    
  ll maxi = *max_element(a,a+n);

  if(maxi <= 0){
    cout << maxi << nl;
  }
  else{
    ll sum = 0 , ans = 0; 
    for(ll i=0;i<2;i++){
      for(ll j=i;j<n;j+=2){
        if(a[j] >= 0){
          sum += a[j];
        }
      }
      ans = max(sum,ans);
      sum = 0;
    }
    cout << ans << nl;
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