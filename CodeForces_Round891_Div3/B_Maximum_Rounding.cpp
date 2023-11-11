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

//Very Very easy maan you were not able to understand the question during whole contest , it was a
// very simple  implementation problem and was very very easy just try to understand question in more 
//time from now on as this was nothing you solved it in 15 mins (it is a lot as you were slow lol)

void solve()
{
    string s;
    cin >> s;
    ll len = s.length();    
    
    bool carry = false;
    ll k = -1;
    for(ll i = len - 1; i >= 0; --i){
        if(s[i] >= '5'){
            k = i;
            ll prev = i;
            while(i > 0 && s[i - 1] == '9'){
                s[i] = '0';
                --i;
            }
           s[i]= '0';
           if(i > 0)
               s[i - 1]++;
           else{
                carry = true;
                break;
           } 
        }
    }
    
    if(k != -1){
        for(ll i = k; i < len; ++i)
            s[i] = '0';
    }
    
    if(carry){
        s = "1" + s;
    }
    
    cout << s << nl;
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