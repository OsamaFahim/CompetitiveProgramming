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
#define yes "YES"
#define no "NO"

//You were not thinking that just like in the prefix array the first element should be equal to the first element
//similarly here the first elemnet wil be just arbitary and not the difference with any other i.e arr[0] = pref[0]
//You just thought that the first element is always going to be 1 which is not the case it is possible that original
//array may not start with 1, it is possible that it may start with any number greater than 1 or stuff You were
//just blindly thinking that start element must be 1 even though it is a permutation it is still posiible that 1 is 
//found at later ponints and the cnt logic just made life a hell lot easier , removing a lot of redundant calulations 
//ifs and made the problem easier if missing is greater than 2 then not possible, if == 2 then the missing elements
//sum must be equal to the element found >= n and if 1 then ans is always possible.

void solve()
{
    ll n;
    cin >> n;
    
    ll pref[n - 1]{};
    inp(pref, n - 1);
    
    ll greater_element = 0;
    ll mark[n + 1]{};
    ll cnt = 0;
    for(ll i = 0; i < n - 1; ++i){
        if(i == 0){
            if(pref[i] <= n && !mark[pref[i]]){
                mark[pref[i]] = 1;
                cnt ++;
            }
            else
                greater_element = pref[i];
        }
        else{
            if(pref[i] - pref[i - 1] <= n && !mark[pref[i] - pref[i - 1]]){
                mark[pref[i] - pref[i - 1]] = 1;
                cnt++;
            }
            else
                greater_element = pref[i] - pref[i - 1];
        }
    }
    
    //This was the main part of the logic without which you were making your life very very difficult.
    ll missing = n - cnt;   
    
    if(missing > 2)
       cout << no << nl;
    else if(missing == 2){
        ll num_1 = -1, num_2 = -2;
        for(ll i = 1; i <= n; ++i){
            if(!mark[i]){
                if(num_1 == -1){
                    num_1 = i;
                }
                else{
                    num_2 = i;
                    break;
                }
            }
        }
        
        if(num_1 + num_2 == greater_element) 
            cout << yes << nl;
        else 
            cout << no << nl;
    }
    else 
        cout << yes << nl;
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
