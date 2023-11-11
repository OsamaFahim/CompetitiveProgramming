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

//This peoblem was not that intuitive for me as it was a constructive algorithm problem, but overall this problem was good
//the only problem is that there can be many observations that you can make to solve this problem, here the main 
//observation was to see that at every index n - i represents the count of subarrays which include that partculat index
//too and if k >= n - i we place positive value as positive will work out but as soon as n - i > k we need something
//else to figure out that can be anything according to your observation in this case we place k and for 
//k - 1 elements we place -1 so that it remains lesser than k and we cant have subarrays sum equal to 0 so after
//k elements from ith index that (i + k) we will have to place a larger value than -1 to avoid zero -2,-2 anything etc.

void solve()
{
    ll n,k;
    cin >> n >> k;
    
    ll ans[n]{};
    
    for(ll i = 0; i < n; ++i){
        if(k >= n - i){
            ans[i] = 1000;
            k -= n - i;
        }
        else{
            ans[i] = k;
            for(ll j = i + 1; j < i + k; j++){
                ans[j] = -1;
            }
            
            for(ll j = i + k; j < n; ++j){
                ans[j] = -2;
            }
            break;
        }
    }
    
    print(ans,n); 
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
