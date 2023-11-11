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

//One of my facourite Problems !!!
//This problem thought that how you can analyze patterns and make solution easier than expected for eg in this case the numbers 
//were going in order like 1 , 2 , 3 , 5 , 6, 7 ,8 , 9, 10 , 11, 12 , 13 , 15, 16
//but there is one number missing i.e 4 which is enoguh indication that it is base 9 number representation but aprart from 9
//4 is missing im the sequence and this was it and also that if you provide number k then the mod / div tecnique can also
//provide you the kth number of that base system for 22 will give you 22nd number in base 9 that is 25 so this was good prob
//There is also a technique of binary search and stuff which is not required but i suggest you should learn and implement that
//as well to learn stuff so that it can be applied to other problems but as far as this prob is concerend base 9 conept was enough

string kthNum_inBase9(ll k)
{
    string res = "";
    while (k != 0){
        ll rem = k % 9;
        res = to_string(rem) + res;
        k /= 9;
    }
    
    return res;
}

void solve()
{
    ll k;
    cin >> k;
    
    string num = kthNum_inBase9(k); 
    
    for(auto it : num){
        if(it <= '3')
            cout << it;
        else
            cout << char(it + 1) ;
    }
    
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
