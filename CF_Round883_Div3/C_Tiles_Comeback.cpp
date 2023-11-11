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

//Wow Dumbo, Now all of a sudden you have made the logic of the problem by yourself and What happened in the contest ? 
//You were not even able to understand that atleast k of each color is required and that last tile must be present >= k
//times and if last tile is same as a[0] tile then you simply need to count the last tiles and if the last tiles are >= k
//then answer exsist as you can simply count those tiles and this was it and if the a[0] tile is not same as nth tile
//then you need to include some other tiles as well , as we hace chosen tile 1 and keep track of its index till the
//count of a[0] tile is less than equal to k because these will be the number of tiles that we must jump to satisfy
//the conditions provided and from that index the count of nth tile must still be >= k because after that we will
//we still need to jump k last tiles and this was it, maybe you were able to solve the qeustion because you saw codes
//from the standing section but you just skimmed thorugh it maybe if you just would have read the question carefully
//you might have implemented it correctly and also I believe that I got hint from reading the code I must have helped
//you in some way overall it was a very question which you should have done during the contest. 

void solve()
{
    ll n,k;
    cin >> n >> k;
    
    ll a[n]{};
    inp(a,n);
    
    ll nth_cnt = 0 ,first_cnt = 0;
    ll last_ind = -1;
    for(ll i = 0; i < n; ++i){
        if(a[i] == a[n - 1])
            nth_cnt++;
        else if(a[i] == a[0]){
            first_cnt++;
            if(first_cnt <= k)
                last_ind = i;
        }
    }
    
    
    if(a[0] == a[n - 1]){
        if(nth_cnt >= k)
            cout << yes << nl;
        else
            cout << no << nl;
    }
    else{
        ll cnt_after = 0;
        for(ll i = last_ind; i < n; ++i){
            if(a[i] == a[n - 1]) 
                cnt_after ++;
        }
        
        if(cnt_after >= k && first_cnt >= k)
            cout << yes << nl;
        else
            cout << no << nl;
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
