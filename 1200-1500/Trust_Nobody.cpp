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

//Optimized approach in which we sort the array first and then check the partitions to identify the liars if ith person is telling
//the truth and if i + 1 th is telling a lie then correct partition is formed and then we print those number of liars which we
//have taken for the current partition. It could have been done in O(log(n)) but constraints were very light so it was fine to
//do O(n + log(n))  and also O(n^2) but i was unable to fiure out anything  
void solve()
{
    ll n;
    cin >> n;
    
    ll a[n];
    
    for(ll i=0;i<n;++i) cin >> a[i];
      
    sort(a,a+n);  
  
    bool found = false;
    for(ll i=0;i<n;++i){
      if(a[i] <= n - i - 1){
        if(i < n && a[i + 1] > n-i-1){
          cout << n - i - 1 << nl;
          found = true;
        }
        else if(i == n - 1){
          cout << 0 << nl;
          found = true;
        }
      }
    }
    
    if(!found) cout << -1 << nl;
}

//This was O(n^2) approach a little bit more intuitive for me , for every 0<=i<n we check how many liars are there if we initially
//consider i liars and if we actually found count of liars to be i we have found the correct partition and we print the i
//and if our clain is always contradictory for every partition we print -1 at the end
void solve2()
{
    ll n;
    cin >> n;
    
    ll a[n];
    
    for(ll i=0;i<n;++i) cin >> a[i];
      
     ll ans = -1; 
    for(ll i=0;i<n;++i){
      ll cnt = 0;
      for(ll j=0;j<n;++j){
        if(a[j] > i){
          cnt ++;
        }
      }
      
       if(cnt == i){
          ans = i;
          break;
        }
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