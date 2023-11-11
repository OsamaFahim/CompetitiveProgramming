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

//This was a fun problem although the specific technique was not that intuituive for me and it took me a while to
//understand and clearly grasp the concept. And you even read most part of the question incorrectly or 
//misunderstood the problem statement.

//Although as we can see that the arr given to us is sorted in ascending order and the constaints were that
// 1 <= n <= 1e5 so using binary search was a screaming hint that you ignored (chawala). THe main concept
//is that as we need to find the maximum length of subsequence having maximum score (ai * ai + 1 * ..... * ak)/k!
//and we have to do it for all the prefixes i.e from a1 to ak and then a1 to ak+1 and so on until the last
//so we have to print n integers satisfing the conditions mentioned above. 

//The idea is that as array is sorted and at i the element below it is either lesser or equal to a[i] >= a[i - 1]
//so there must be some k meaning elements behind i for which numerator starts to decrease and denominator will 
//increase lets undersatnd with example that if a[i] = 5 and behind lets say 2,2,3,4,5,5,a[i] as we can 
//see that considering a[i] as the largest element for the current prefix we are at so behind the elements would
//keep decreasing meaning that according to the score formula provided in the problem statement the numerator
//would keep decreasing conider i to be 4 then a[i-2]/2,a[i-1]/3,a[i] / 4 and so on which means that as the
//numerator would keep decreasing and denominator would keep increasing a point behind will come when we get 0
//(integer division) for eg if i might get 1/2 so such point should not be included in the length as it 
//is not helping in maximizing the score so we should stop just before such point and we can't do it by reverse 
//loop naively because TLE so we can use binary search to find such point as the array is already sorted (non-
//decreasing) as we know that hi would be set to i (currrent prefix end) so lo would be 0 and if 
//a[mid] >= i - mid + 1 , it measn that we are currently in valid length (range) so we try to find that are there
//any more elements that we can include so we set hi = mid - 1 to find more length and keep saving the mid 
//in index variable and if a[mid] < i - mid + 1 that means that denominator is larger and we will are not
//in correct range so we set lo = mid + 1 to get into the valid range. and after we have found the valid index
//till where num >  dem (looking from i and seeing backwards) so for that prefix or i we will push back 
//i - mid + 1 (which gives us length) in our result vector and this is it, it was a very good and amzing question.

//https://www.youtube.com/watch?v=2iVHnQmMwnI&t=917s ---> fot the grip on the concept from here

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{};
    inp(a,n);
    
    vector<ll> res;
    for(ll i = 0; i < n; ++i){
        ll lo = 0, hi = i;
        ll ind = 0;
        while(lo <= hi){
            ll mid = hi - (hi - lo) / 2;
            if(a[mid] >= i - mid + 1){
                ind = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        res.pb(i - ind + 1);
    }
    
    for(auto e : res) cout << e << ' '; 
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