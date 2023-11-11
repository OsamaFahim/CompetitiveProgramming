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
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p);
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"  
#define mod 998244353     

//This was a beautiful problem and it feels like that it taught me a lot that how you can optimize your code 
//when the most naive way is O(n^2) then you can definitely use this kinda technique , the main crusk of this
//problem were these two equations : 
//  ans -= (a[i].first - a[i - 1].first) * (n - i - 1);  exclusion
//  ans += (a[i].first - a[i - 1].first) * (i - 1);      inclusion
//The first equation states that for eg that you s = 2 then the distance of a[2] with the elements to right of it has 
//been reduced by a factor of (a[i].first - a[i - 1].first) because consider these points on a number line
//          1  3  4  7
//first we would always pre compute for s = 1 , because that is just straight up loop and then we would use this
//precomputation to find anser of all s such that s in {x1,....,xn}, so now consider that ypur s changed from 1 to 3
//now as for 4 the precomputation has been done for segment [1,4] and we have to acknownledge the fact that we have
//moved from 1 to 3 and the distance has now been changed from [1,4] to [3,4] so the distance would be reduced
//by 3 - 1 , and this would be done for all the points that are after 3 thats why we are subtrcting this factor 
//and multiplying by n - i - 1 i.e number of elements after the current s.

//for the second equation
//and now after decrementing the value we must see that is there any value that would now be incrementing
//now consider that you are on s = 4 previously when on 3 , it was like [1,3] , [3,3] , [3,4] , [3,7] but as s has
//shifted to 4 now the segment will be [1,4] , [3,4], [4,4], [7,4] as we can see the [3,4] is still there but now
//an edge from 1 to 4 has also been created and we have to accomodate as well you got confused a lot as you thought
//that nitially when we were computing 1,4 in the beginning we would have computed it but note that as we moved to
//s = 3 we removed the edge from 1,4 as we said that now distance is 3,4 not 1,4 and we said that it is extra so 
//we decremented it in our formula as we need to print power of all n points so we needed to decrement that at that 
//point because in our vector we push back that valur for s = 3 but now as s = 4 we neeed that back so we incement
//this value and we can see that not only this point all the points would have been removed before 1 if they were
//so we need to accomodate all these points back for current value of s so that is we are doing i - 1 * .... as 
//adjacent point combination wont change for curr s but all the points before adjacent points needs to be
//included again so that is whange the inclusion formula gives us and that is it

//was a beautiful question i had diddicult understanding it but overall it was decent , very decent

void solve()
{
    ll n;
    cin >> n;
    pair<ll,ll> a[n]{};
    
    for(ll i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a,a + n);
    
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        ans += (a[i].first - a[0].first) + 1;
    }    
    
    vector<pair<ll,ll>> output;
    output.pb({a[0].second,ans});
    
    for(ll i = 1; i < n; ++i){
        ans -= (a[i].first - a[i - 1].first) * (n - i - 1); //exclusion
        ans += (a[i].first - a[i - 1].first) * (i - 1);     //inclusion
        
        output.pb({a[i].second,ans});
    }
    
    sort(output.begin(),output.end());
    for(auto e : output)
        cout << e.second << ' ';
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

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << ' ' << p.second;
    return os;
}