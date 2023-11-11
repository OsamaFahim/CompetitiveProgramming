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

// This is my favourite problem till now . It sounded so complex but the idea is very simple that you binary search and if the number
// of days are less than equal to lamda(number of days required to remove the elements from 1 to mid ) then that means 
// after k days no element would be remaining from one to mid so we cant choose our answer so we make lo = mid + 1 else
// that means that after even if we choose k days some days will be left because to remove all elements from 1 to mid 
// it requires more days than k and if we choose k elements some days would be left and we could choose our answer
// so we set high = mid - 1 and the check function helps us get number of days from 1 to mid... that function was a little
// bit tricky but still very easy analyze it again that to remove a[i] elemets in 5 days .... mid - x*(i + 1) >= a[i]
// the right must be greater equal to a[i] only then it is possible to remove a[i]th element in x days and i + 1 denotes
// the number of elements that would also be removed along with a[i] so we remove the number of elements removed after x days
// from mid i.e mid -= x * (i + 1) and add number of days in tot var initially initialized to 0 i.e tot += x
// and x days we can find via (mid - a[i] / i + 1) + 1 , + 1 is because >= as long as the eq is greater a[i] we can remove 
// elements so that is +1 is added. you also verified using pen and paper so this was it and a beautiful interesting, great
// learning experience problem. Hopefully in future I would be able to solve problems like these on my own.

const ll N = 1e7;
ll a[N]{};
ll n , k;

bool check(ll mid)
{
    ll tot = 0;
    for(ll i = n - 1; i >= 0; i--){
        if(a[i] > mid) continue;
        ll x = ((mid - a[i]) / (i + 1)) + 1;    //This one is a logical formula !!!
        tot += x;
        mid -= x * (i + 1);
        if(mid < 0)
            return false;
    }
    
    return tot > k ;
}

void solve()
{
    cin >> n >> k;
    inp(a,n);
    
    if(a[0] != 1){
        cout << "1\n";
    }
    else{
        ll ans = 0;
        ll lo = 0, hi = 1e12;
        while(lo <= hi){ 
            ll mid = (hi - lo) / 2 + lo;
            if(check(mid) == true){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
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
