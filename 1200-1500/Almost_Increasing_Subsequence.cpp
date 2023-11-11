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

//This was one of my favourite problems which helped me teach a lot from it very very beautiful problem bht bht bht mazadar I spent
//time on it and was able to understand it completely , if you are here to revise focus on dp[l] and dp[l + 1] part only and
//that redundany if condition which was not necessary and even made you think in wrong way apart from that everyything was fine 

void solve() 
{
    ll n, q;
    cin >> n >> q;

    ll a[n]{};
    inp(a, n);

    ll dp[n]{}; 

    for (ll i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + (a[i] <= a[i - 1] && a[i - 1] <= a[i - 2]);
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;

        --l, --r;

        if (r == l) 
            cout << "1\n";
        else 
            cout << (r - l + 1 - (dp[r] - dp[l + 1])) << nl; //It is possible that just after the l + 1 move bad value is found
            // such that x >= y >= z so you also have to eleminate that in the l,r subbarray thats why dp[l + 1]
    }
}

int main() {
    fastIO();
    cout << fixed << setprecision(10);
    int tc = 0; 
    // cin >> tc;
    // while(tc --)
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
