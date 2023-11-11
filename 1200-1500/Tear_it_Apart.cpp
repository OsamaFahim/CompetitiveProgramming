#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//It was a wondeful question , you were thinking in completely different manner and that was wrong , you also need to 
//consider that in such question you can loop through all 26 characters and do your work now you should think like this too
//also the window size thing was not even a little close to your thinking that while performing the operations on 
//that bigger window to try to keep the character i you will also remove the useless characters of smaller window gaps
//and please reconsider this problem when you see it because you understood it in intihai neend. but concept was crystal clear
//you can simply traverse through all the characters when there is no clear pattern and then do your work and as for the
//window thingy it was a new approach which also tells us about how we are also accomodating and counting smaller options
//as well

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

void solve()
{
    string s;
    cin >> s;
    
    int len = s.length();
    ll mini_opr_ch = inf;
    for(char i = 'a'; i <= 'z'; ++i){
        ll window = 0 , max_window = ninf;
        for(ll j = 0; j < len; ++j){
            if(s[j] != i){
                window++;
                max_window = max(window,max_window);
            }
            else 
               window = 0;
        }
        mini_opr_ch = min(mini_opr_ch,max_window);
    }
    
    if(mini_opr_ch == 0){
        cout << 0 << nl;
    }
    else{
        ll ans = 0;
        while(mini_opr_ch > 0){
            mini_opr_ch /= 2;
            ans ++;
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
