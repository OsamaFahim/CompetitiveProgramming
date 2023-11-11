#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T[], ll);
template<class T> void print(T[], ll);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mxn (ll)10010001
#define u_map unordered_map
 
//I solved this problem maan the logic was right everything but i dont know where my code went wrong maaaaan !!!! this time
//milimeters close 
 
void solve() 
{
    ll n,k;
    cin >> n >> k;
    
    ll a[n]{};
    inp(a,n);
    sort(a , a + n);
    
    ll ans = 0 , lst = -1;
    for(ll i = 0; i < n; ++i){
        if(i == n - 1 || a[i + 1] - a[i] > k){
            ans = max(ans , i - lst);
            lst = i;
        }
    }
    
    cout << n - ans << nl;
}

int main() {
    fastIO();
    cout << fixed << setprecision(10);
    int tc = 0; 
    cin >> tc;
    while(tc --)
       solve();
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

template<class T>
void inp(T arr[], ll n) {
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

template<class T>
void print(T arr[], ll n) {
    for (ll i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << nl;
}
