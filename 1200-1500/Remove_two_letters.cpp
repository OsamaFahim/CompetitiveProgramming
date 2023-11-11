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

//Ah man the problem was very very easy yet you made a pretty bad blunder, you made most of the logic correct but the only
//thing is that so close yet so far mann you thought that standing at the second character you are going to see if the
//last two characters are equal to the ith one then it means that two same strings will be obtained so of this condition
//satisfies we would have to subtract one from the total number of strings we would be getting from the current total
//and the current total is n - 1 so we would keep decrementing whenever s[i] == s[i + 2] beccuase duplicated string will 
//be obtained consider an example:  x a x  b l 
//          first window : x a --> remaining : x b l
//          second window: a x --> remaining : x b l as we can see whenever s[i] = s[i + 2] we will get duplicate string
//you were thinking wrong but still the logic was simple and amazing that consider the total that is n - 1 and then
//keep decrementing the answer whenever you find s[i] == s[i + 2] ... for (i --> n - 2). (loop) and this was it.



void solve()
{
    ll n;
    cin >> n;
    
    string s;
    cin >> s;
    
    ll ans = n - 1;
    for(ll i = 0; i < n - 2; ++i){
        if(s[i] == s[i + 2])
            ans --;
    }
    
    cout << ans << nl;
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