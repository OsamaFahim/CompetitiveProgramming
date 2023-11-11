#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T [],ll);
template<class T> void print(T [],ll);
template<class T> void inp(vector<T>);
template<class T> void print(vector<T>);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"       

//This was a very beautiful problem and the technique used is a varied version of two pointer the approach you 
//implemented was accounting for all the operations that were required and not the minimum ones

//To get to the minimum number of operations which have to be performed can be be done in a similar cocnpet but
//using a beautiful observation firstly in the worst case you can clearly see that the answer will be n / 2
//so we first initialize the answer to n / 2 as this is the maximum number of operations that have to be done
//and then we will decrease them along the way based on the following condition observe that
            //  8 1 7 4  6 2 3   as we can see that their are some valid subsequences meaning that 
//even if the sorted order is not contiguos but still 1 2 3 these elements come after one another so we dont
//need to waste our operations on such elements as they will automatically become sorted when we will be 
//doing operations on other elements so consider an example where n = 8 as now ans = 8 / 2 = 4 because in one 
//operation two elements are being accounted for that is why we are dividing by 2 as max operations.
//so 1 2 3 4 5 6 7 8  l and r will be adjusted according to even and odd lengths (see conditions in code)
//         l r        
//for n = 8 we know that there can be 4 pairs (n / 2) on which can apply operations privided in problem
//statement to make them sorted according to min max operations so the pairs can be 
//  (4 5) , (3 6), (2 7), (1 8) and we will check for all the pairs whether for these pairs the condition
// ind(l) < ind(l + 1) < ind(l + 2) < ......... < ind(r - 2) < ind(r - 1) < ind(r) so take a pair (3 6) for
//instance then ind(3) < ind(4) < ind(5) < ind(6) but as we will naively try to do this then TLE can occur
//so what we can do is start from the middle pairs the last ones at which our left and right are initially
//and then check this condition at each iteration if(index[left] < index[left + 1] && index[right - 1] < index[right])
//in a while loop i.e while(left >= 1 && right <= n) (as in a permuation elements are from 1 to n)
//so we can see that until the if condition is satisfied we will keep decreasind the ans (ans--) because 
//the truness of this condition tells that the current operation is not necessary and also updating our
//left and right pointers accordinglt i.e left-- and right++ and as soon as the condition
//if(index[left] < index[left + 1] && index[right - 1] < index[right]) is false we must break out of the loop
//indicating that the steps cannot be further minimized , you got confused at this point so see
//when you decide that you have to apply operation on a certain pair for eg 3 6
//then 3 1 2 3 4 5 7 8 6 meaning that 3 wil come at first and 6 will come at last which signifies that 
//operations with pair (1 8) and (2 7) must be done to bring them back at the correct sorted poistions
//because otherwise 3 will remain at first and 6 at last so at any point when operation is necessary then 
//((l - 0) + (n - r) + 1) / 2 operations have to be done indicating no matter what is the position of other
//elements in the permutation we must handle them to get them to desired position so we cannot decrement tha
//and variable anymore and we will then break out of the loop and print ans, ((l - 0) + (n - r) + 1) / 2) these
//are the steps which must e performed and we simply cant ignore them the eq says that the numbers behind l
// and the numbers after r are to be dealt with so we add them and 1 is added as in permutation n is incluive
///(1 based index) so this was it and this was a beautiful prolem
//  3 1 2 3 4 5 7 8 6 after that
//  2 3 1 4 5 8 6 7 then
//  1 2 3 4 5 6 7 8   which says clearly says that 3 more steps are needed the moment i decided that 
//                    I need to apply operations on the pair  (3 6) meaning that 4 numbers are to be dealt
//                    i.e l - 0 + n - r + 1 and as one operation handles two number divide it by 2.

//note the exaple might not be correct as this is not a perfect dry run but the purpose was to just give and
//idea of whats going on you can dry run the example with correct values and stuff

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{};
    inp(a, n);
    
    map<ll,ll> index; //its better to use an array of n + 1 size in this scenario as we know that size of the 
                      //element cannot become greater than n
                                            
    for(ll i = 0; i < n; ++i){
        index[a[i]] = i;
    }
    
    ll ans = n / 2;
    ll left = n / 2, right;
    if(n & 1)
        right = left + 2; 
    else
        right = left + 1;
    
    while(left >= 1 && right <= n){
        if(index[left] < index[left + 1] && index[right - 1] < index[right])
            ans--;
        else 
            break;
            
        left--;
        right++;
    }
    
   cout << ans << nl;

   // cout << (n - r + l + 1) / 2 << '\n'; the formula in ediotiral without ans variable was also very nice
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
void inp(vector<T> arr)
{
    for(auto &e : arr)
         cin >> e;
}

template<class T>
void print(T arr[])
{
    for(auto &e : arr)
        cin >> e;
}