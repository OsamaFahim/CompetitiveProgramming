#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//You made most of the logic by yourself but syill made a lot of redundant and useless obserrvations it is an improvement
//but still keep working harder and do more

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

ll calc_MEX(ll a[],ll n,unordered_map<ll,ll>& freq)
{
    ll maxi = ninf;
    for(ll i = 0; i < n; ++i){
        ++freq[a[i]];
        maxi = max(maxi,a[i]);
    }
    
    maxi = (maxi == 0) ? maxi + 2 : maxi + 1;
    
    for(ll i=0;i<=maxi + 1;++i){
        if(!freq.count(i))
           return i;
    }
    return -1;
}

void solve()
{
  ll n;
  cin >> n;
  
  ll a[n]{};
  inp(a,n);
  
  unordered_map<ll,ll> freq;
  ll mex = calc_MEX(a,n,freq);
  
  if(mex == n){
    cout << "NO\n";
  }
  else if(!freq.count(mex + 1)){
      cout << "YES\n";
  }
  else{
    ll start = 0 , end = 0;
    bool found = false;
    
    for(ll i = 0; i < n; ++i){
        if(a[i] == mex + 1){
            if(!found){
                start = i;
                found = true;
            }
            end = i;
        }
    }
    
    for(ll i = start; i<= end; ++i){
        a[i] = mex;
    }
    
    freq.clear();
    ll make = mex + 1;
    mex = calc_MEX(a,n,freq);
    
    cout << ((mex == make) ? "YES\n" : "NO\n" );
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
