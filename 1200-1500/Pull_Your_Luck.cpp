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
        
//EVERY QUESTION IS NOT A BINARY SEARCH PROBLEM !!!! LOL , the reason that binary search did not work for this question
//was that there was not specific condition on which we can make decision to make left or right move as there for any
//value obtained we cannot determine that if the value obtained is larger or smaller than 0 as we will get a modulo value
//and the values are in circle that if n = 11 then value before 0 is 10 so determination of true ,false or values being
//smaller and larger cannot be determined and thus if conditions are not possible we cannot apply binary search.

//KEY OBSERVATION : THE KEY OBSERVATION WAS THAT : we are anyways taking % n for our answer so the value of our answer
//that (i * (i + 1) / 2) % n will anyways gives us values lower than n so we dont need to check for the values 
//greater than n BUT THERE IS A CATCH : the division operator disturbs the modulo property and shows unexpected behaviour
//as for even values of i , the expression  (i * (i + 1) / 2) % n won't give us the expected result for even values
//as they are divided by 2 and then moded so for that we can loop from 1 to 2*n so that the expression 
//(i * (i + 1) / 2) % n becomes 2[n * (n + 1)] / 2 so that 2 is divided by 2 and the division 2 no longer becomes an 
//issue. 

//Also if the value of p is lesser than n then we need to loop to min(p,2*n) and not necessarily to 2*n.
        
void solve()
{
    ll n,x,p;
    cin >> n >> x >> p;
    
    bool ans = false;
    for(ll i = 1; i <= min(p,2 * n); ++i){
        ll val =  (i * (i + 1)) / 2;
        val %= n;
        
        
        if((val + x) % n == 0){
            cout << yes << nl;
            ans = true;
            break;
        }
    }
    
    if(!ans) 
        cout << no << nl;   
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