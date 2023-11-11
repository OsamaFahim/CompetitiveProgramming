#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T [],ll);
template<class T> void print(T [],ll);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mxn (ll)10010001
#define u_map unordered_map

//This was a super easy problem you made the correct logic but was scared that the approach may be wrong as the approach was itself
//very easy very easy question and not a 1500 problem in my opinion ...

void solve()
{
    ll n,s1,s2;
    cin >> n >> s1 >> s2;
    
    vector<pair<ll,ll>> v(n,{0,0});
    for(ll i = 0; i < n; ++i){
        ll a;
        cin >> a;
        v[i] = {a,i + 1};
    }
    
   sort(v.begin(), v.end(), greater<pair<ll, ll>>());

   ll curr_s1 = s1,curr_s2 = s2;
   vector<ll> robo1, robo2;
   
   for(ll i = 0; i < n; ++i){
         if(curr_s1 >= curr_s2){
            robo2.pb(v[i].second);
            curr_s2 += s2;
         }
         else{
            robo1.pb(v[i].second);
            curr_s1 += s1;
         }
   }
   
   cout << robo1.size() << ' ';
   for(auto it : robo1){
    cout << it << ' ';
   }
   cout << nl;
   
   cout << robo2.size() << ' ';
   for(auto it : robo2){
    cout << it << ' ';
   }
   cout << nl;
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

template<class T>
void inp(T arr[],ll n)
{
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

template<class T>
void print(T arr[],ll n)
{
    for(ll i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << nl;
}
