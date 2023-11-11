#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

// In such questions either there is a pattern or you can restrict numbers or something for example in this case
//restricting the prime numbers would work out the best because then the mex would be a prime number
//as we would be able to take other subarrays which do not include those prime numbers (2,3) as they would be min
//and we would always try to take 1 so that we dont get 1 as MEX in our selection for subarray
//so by fixing prime numbers and 1 in the middle and always trying to choose a subarray which wont include 1 `
//so that 3 or 2 can be obtained , and we would want that minimum numbers are fixed on left most and right most indexes of the array because 
//so that the maximum number of subarrays in between inclusive of 1 have their mex of 2 or 3 which is indeed a prime number.
//This required a little observation just and apart from that the problem was quite simple and intuitive
//just that observe more and intuition was mainaly about how you can maximimize the range of l and r for which
//MEX is a prime number that is why we keep 1 in middle the smallest ever mex and 2 and 3 as away as possible to
//make subarrays l and r ranges in such a way that MEX obtained becomes these numbers which are far waway when we include
//2.
  
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
  
  if(n == 1){
    cout << 1 << nl;
  }else if(n == 2){
    cout << 1 << ' '<< 2 << nl;
  }
  else{
    vector<ll> v(n,0);
    v[0] = 2, v[n-1] = 3, v[n/2] = 1;
    
    ll cnt = 4;
    for(ll i=0;i<n;++i){
      if(v[i] == 0){
        v[i]=cnt++;
      }
    }
    
    for(ll i=0;i<n;++i) cout << v[i] << ' ';
      cout << nl;
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