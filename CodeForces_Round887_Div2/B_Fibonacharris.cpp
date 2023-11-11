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

//It was very very very easey peoblem you made the correct logic but they was one very cheeky observation of analyzing the 
//constraints !!! The value of k was given to be very large but it was useless as we sae that after 30th fibonacci number
//n was 5 * 10^5 which is still larger than constraints of given n meaning that in at most 30 steps we would reach the value 
//greater than 2 * 10^5 so in that case foe k > 30 we wont be able to make fibonacci number within under 2*10^5 as fibonacci
//grows pretty fast this was the main crusk of this problem !!!!!!!!!!! you should have atleast tried brute maybe while trying
//this might have came into your head but still better luck next time InshAllah .....!!!.....

void fibonaccharis(ll x,ll y,ll pos,ll& ans)
{
    if(pos == 0){
        ans ++;
        return;
    }
    
    ll prev = x - y;
    if(prev > y)
        return;
    
    fibonaccharis(y,prev,pos - 1,ans);
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    
    if(k >= 30){
        cout << "0\n";
    }
    else{
        ll ans = 0;
        ll decrement = 0;
        for(ll x = n / 2; x <= n ; ++x){
            ll y = (n / 2) - decrement ++;
            if(y > x) break;
            else if(x + y == n - 1) x++;
            fibonaccharis(x,y,k - 3,ans);
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
