#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//mind == blown maaan phufff
//In this problem there were a lot of observations and hopefully this problem taught you that how you can approach and 
//think about problems in a little bit different manner. How you can make observation that if a[i] is zero then after 
//how many steps will //it will again become zero that is it will become after mutiple of three steps so we can take (% 3)
//ans similarly for all a[i] if they were being made equal 0 at the same % 3 value then it is possible that entire A becomes 
//zero else it is possible //that if one a[i] is zero at lets say 1 step and other a[i + x] is zero at lets say 2 steps then what
//will happen is that at 2nd step when a[i + x] is zero a[i] will not be zero so they will never be zero at the same time else if
//all of them become zero for same (%3) value then all of them after some 3 multiple of steps becomes zero answer will be yes
//a % 2b and b % 2a is a way to check that whether a or b respectively in the order they are written will reach zero at which steps
// and at the we will take % 3 of the steps as a-2b or b-2a must reach zero at some point as they will be (a - 4b,b - 4a),
//(a - 6b,b-6a)...... so they  must reach zero as that is beig decreased so we count steps that at which step it will become by
//doing a % 2b or b % 2a ... as a - 2*b = r and clearly it is equation of division and as we need r we can take mod
//and base cases were simple tat if a[i] == 0 it will take 0 steps and if b[i] was 0 it will take one step to make a[i] = 0
// major takeway was that you have to think all if a[i] must be zero thats why the steps % 3 must be same value for all a[i]

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

// This recursive function count steps that after how many steps 0 can be reached for each of scenarios described above
ll count_steps(ll a,ll b)
{
    if(a == 0)
        return 0;
    if(b == 0)
        return 1;
    
    if(a >= 2*b) return count_steps(a % (2 * b),b);
    if(b >= 2*a) return count_steps(a,b % (2 * a));
    
    return 1 + count_steps(b,abs(a-b));
}

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{},b[n]{};
    
    for(ll i=0;i<n;++i) cin >> a[i];
    for(ll i=0;i<n;++i) cin >> b[i];
        
    bool first = false;
    bool res = true;
    ll cmp;    
        
    for(ll i = 0; i < n; ++i)
        if(!(a[i] == 0 && b[i] == 0)){
            if(!first){
                cmp = (count_steps(a[i],b[i])) % 3 ;
                first = true;
            }
            else{
                ll ans = (count_steps(a[i],b[i])) % 3;
                if(ans != cmp){
                    res = false;
                    break;
                }
            }
        }
        
    cout << ((!res) ? "NO\n" : "YES\n" );
            
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