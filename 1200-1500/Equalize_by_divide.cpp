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

//This was a fun problem I made the correct logic but was afford to check it out as I was confused at one minor point that
//after sorting what to do after some operations a certain value has become smaller than the minimum val i.e v[0].first,
//meaning after dividing the entire array by v[0].first i.e (v[i].first = ceil(v[i].first * 1.0 / v[0].first))
//it is possible that some v[i].first becomes smaller than the minimum value which is v[0].first so for that as the 
//constraints are were very very light so after doing these operations we can again sort the array and the entire thing
//is stuck inside a while loop that while(v[0].first != v[n - 1].first) , meaning just after sorting we will check that
//if the minimum value that the first value has become equal to the last value if this condition is true then it means all
//the elements have been equal, dont get confused as I know that you might be thinking that the last element (v[n -1].first)
//and the first element (v[0].first) may become equal and still the entire array might not be equal so we are checking the
//condition just after sorting has been done so if the v[0].first = v[n - 1].first then that definitely means that 
//array has been equal because sorting was done in the very last step 
            /*while (v[i].first != v[0].first){
                    operations are being calculated and placed inisde answer vector
                    
                after that
                sort(v.begin(),v.end())
                which shows that if the above condition is true than that definiely means that first and last elements
                have become equal because the array is first sorted then cond is checked
            }*/
//and we can afford to sort after doing operations on the array every time because the constraints are low
//and even the value is 10 ^ 9 it would taken atmost 29 steps to make it equal to 2 so even if n = 2 (as case of 1
//has been handeled seperately so minimum element would be atleast 2 not lower than that) and a[0] = 2,a[1]=1e9
//even they 30(n) i.e 30 * 2 = 60 would be completely ok and it would be done under 30*n steps and even if 
//n = 100 and all elements i.e i = 1 .... i = n - 1 are 10^9 and i = 0 is 1 , then that meaans that all the elements
//should become a[0] i.e 2, so it would take approx 1000 * 29  = 29000 steps in the worst case which is still lesser than
//30 * n i.e 30 * 1000 = 30,000 so the steps would always be under 30*n thats it is not dealt with in code

//overall wondeful problem still teaching if constraints lower have fun!!!

//just focus on the point you forgot it is possible that after dividing all v[i].first by v[0].first(minimum value)
//some other v[i].first becomes smaller than v[0].first so for that after performing operations and putting them(indexes)
//in out answer vector we can sort the array until v[0].first != v[n - 1].first (all elemnets are not equal .... explained
//in detail along with while loop snipper with explanation written above the while loop snippet). so then the even 
//if v[i].first has become smaller than v[0].first, we will now divide others with the new min as array is sorted.
//and also that any number after some ceil division can be made equal to 2 (it is very intuitive statement) as min
//will be 2 and not less as 1 is handled before as with 1 impossible to make array equal. becuase after a point min
//may or maynot become 2 so this was it aprat from that you had the correct idea in your head !!!!

void solve()
{
    ll n;
    cin >> n;
    
    vector<pair<ll,ll>> v(n);
    ll cnt1 = 0;
    for(ll i = 0 ; i < n; ++i){
        cin >> v[i].first;
        v[i].second = i;
        
        if(v[i].first == 1)
            cnt1++;
    }
    
    if(cnt1 == n){
        cout << 0 << nl;
    }
    else if(cnt1 != 0 && cnt1 != n){
        cout << -1 << nl;
    }
    else{
        sort(v.begin(),v.end());
        vector<pair<ll,ll>> ans;
        
        while(v[0].first != v[n - 1].first){
            for(ll i = 0; i < n; ++i){
                if(v[i].first != v[0].first){
                    v[i].first = ceil(v[i].first * 1.0 / v[0].first);
                    ans.pb({v[i].second + 1,v[0].second + 1});
                }
            }
            sort(v.begin(),v.end());
        }
        
        cout << ans.size() << nl;
        for(auto e : ans)
            cout << e.first << ' ' << e.second << nl;
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