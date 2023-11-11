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

//This was a pretty easy problem , for me this contest's c was harder than D of the problem I think that D was very very
//easy and didn't require any such heavy logic, I made the correct logic but still watched the video before implementing
//which gave me some hints about one or two things which I were missing maybe but overall this question was super
//super easy.

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{};
    inp(a, n);
    ll coins = 0;
    
    for(ll i = 0; i < n; ++i){
        if(a[i] != 0){
            ll ind_before = i - 1;
            bool two = false;
            while(i < n && a[i] != 0){
                if(a[i] == 2)
                    two = true;
                a[i] = -1;
                i++;
            }
            if(two){
                if(ind_before >= 0 && a[ind_before] != -1)
                    a[ind_before] = -1;
                a[i] = -1;
            }
            else{
                if(ind_before >= 0 && a[ind_before] != -1)
                    a[ind_before] = -1;
                else if(a[i] != -1)
                    a[i] = -1;
            }
            coins++;
        }
    }
    
    for(ll i = 0; i < n; ++i)
        if(a[i] == 0)
            coins ++;
    
    cout << coins << nl;
}

int main()  
{
  fastIO();
  cout << fixed << setprecision(10);
  int tc = 0; 
  //cin >> tc;
  //while(tc --)
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