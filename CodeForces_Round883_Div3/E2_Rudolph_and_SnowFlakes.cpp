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

  // It Taught me binary search but primalarly it taught me how use larger datatypes , the idea of 
  // levels related to geometric progression was missing in your head initially 
   
void solve()
{
   ull n;
   cin >> n;
   
   bool possible = false;
   
   for(ll i=2;i<=60 && !possible;++i){
       ll low = 2;
       ll high = 1e10 + 10;
       
       while(low <= high){
        ll mid = (low + high) / 2;
        __int128 max_term = 1;
        
        for(ll j=1;j<=i + 1;++j){
            max_term *= mid;
            if(max_term > 1e27)
                break;
        }
            
        if(max_term <= 1e27){
            __int128 gp_sum = (max_term - 1) / (mid - 1);
            if(gp_sum == n){
                possible = true;
                break;
            }
            else if(gp_sum > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            high = mid - 1;
        }
       }
   }
   
   if(possible) cout << "YES\n";
   else cout << "NO\n";
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