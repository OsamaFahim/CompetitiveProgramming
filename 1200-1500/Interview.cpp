#include <bits/stdc++.h>    
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
#define yes "YES"
#define no "NO"

//------ THis was my first ever interactive problem which i had solved
//It was fun as I found something new to learn and it was very very amazing experience
//The problem itself was a very basic and simple binary search problem which was nothing hard , but I got the hint
//beforehand that it was a binary search problem apart from that thinking of this binary search approach was very
//very easy

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n];
    inp(a, n);
    
    ll pref[n]{};
    pref[0] = a[0];
    for(ll i = 1; i < n; ++i){
        pref[i] += pref[i - 1] + a[i];
    }
    
    ll lo = 0, hi = n - 1, ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;    
        cout << '?' << ' ';
        cout << mid - lo + 1 << ' ';
        for(ll i = lo; i <= mid; ++i){
            cout << i + 1 << ' ';    
        }
        cout << nl;
        ll weight;
        cin >> weight;
        ll left_stones = pref[mid] - ((lo == 0) ? 0 : pref[lo - 1]);
                
        if(weight > left_stones){
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
            
    }
    
    cout << "! " << ans + 1 << nl;
    cout << flush ;
}

int main()  
{
  //fastIO();
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