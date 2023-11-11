#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//I can only say shame on you osama you were not able to solve this question yourself shame shame shame booooooo !
//However it uses a simple concept of delta that when the slope has increasing or decreasing points we simply count those points
//and that will be the only change we need to accomodate for to put in array b

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
    
  ll contrst = 0;
  for(ll i = 1; i <n; ++i){
    contrst += abs(a[i] - a[i-1]);
  }

  if(contrst == 0){
    cout << 1 << nl;
  }
  else{
    ll state = 0;
    ll sz = 1;  
    for(ll i=1;i<n;++i){
      if(a[i] > a[i - 1] && state != 1){
        sz++;
        state = 1;
      }
      else if(a[i] < a[i - 1] && state != -1){
        sz++;
        state = -1;
      }
    }
    cout << sz << nl;
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