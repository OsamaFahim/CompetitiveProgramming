#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T [],ll);
template<class T> void print(T [],ll);
template<class T> void inp(vector<T>&);
template<class T> void print(vector<T>&);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"       

//The problem was very very easy man i don't know why you extremly 
//overcomplicated it during the contest man the observation you made initially
//was correct that the minimum element should occur n - 1 times then
//the second minimum should n - 2 times and so on but the idea of duplicated
//made you confuse and you made a wrong observation which was very very 
//costly for you aprrt from that the problem was super simple and even if theri are duplicates
//the thing n - i thing holds even for them because if lets say three duplicates then one duplicate
//ocuurs most times and the second -1 and the third - 2 times , this was the main point to
//notice and this was it Apart from that easy and interseting problem and please try to prove
//your observations with good examples so that you dont have any problems in the furure...
//While practicing it took a little bit more time because you were trying to do a neat implementation

void solve()
{
    ll n;
    cin >> n;
    ll tot = ((n * (n - 1) / 2) + 1);
    vector<ll> b(tot);
    for(ll i = 0; i < tot - 1; ++i){
        cin >> b[i];
    }
    b[tot - 1] = 1e9 ;    
    sort(b.begin(),b.end());

    ll i = 0;
    ll ind = 0;
    vector<ll> ans;
    while(i < n && ind < tot)
    {
        ans.pb(b[ind]);
        ind += n - i - 1;
        i++;
    }
    
   for(auto e : ans)
        cout << e << ' ';
    cout << nl;
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

template<class T>
void inp(vector<T>& arr)
{
    for(auto &e : arr)
         cin >> e;
}

template<class T>
void print(vector<T>& arr)
{
    for(auto &e : arr)
        cout << e << ' ';
    cout << nl;
}