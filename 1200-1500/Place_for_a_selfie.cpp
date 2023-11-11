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

//YOU KNOW THE FUN PART YOU READ THE QUESTION ALL WRONG AND THOUGH YOU NEE TO PRINT THE LINE WHICH INTERSECTS RATHER
//THAN A LINE WHICH DOESNOT INTERSECT THE PARABOLAS (AND THE QUESTION ASKED ABOUT ANY LINE NOT TOUCHING PARABOLA m[i])

//Overall Beautiful and very very interseting problem

//as we have y = ax^2 + bx + x and also y = mx , and if we consider that both of the interssects then the equation
//will become something like y_line = y_parablola i.e mx = ax^2 + bx + c ----> ax^2 + (b - k)x + c = 0
//seeing this equation we know that x can have real roots as well as imaginary roots for that purpose we always check
//the discriminat (D) of a quadratic equation where D = b^2 - 4ac but now after modifying the equation 
//b becomes b = (b - k[i]) (k[i] is coefficient of line i) so now D = (b - k[i])^2 - 4ac and we know that whenever
//D == 0 it has one real root , D > 0 it has 2 real roots and when D < 0 it has no real root and that is what we
//want, because if the quadratic equation has no valid root then we are not able to find the correct value of 
//x and if we are unable to find x we cannot substitute back and find y which means that we have not find a valid 
//pair (x,y) where the line intersects with the parabola. If the equation has no real roots then that means that the
// line doesnot intersect the parabola at any point.
//so as we want (b - k[i])^2 - 4ac < 0 , also as (b - k[i])^2  < 4ac so we can sort the vector in which coefficients
//of lines i.e k are stored and wheverever the condition is satisfied i.e (b - k[i])^2 < 4ac we will simply break
//out of the binary search while loop and print yes and the coefficient of the line k indicating that this line
//DOESNOT INTERSECT THE PARABOLA (LOL READ QUESTION CAREFULLY) but until the condition (b - k[i])^2 < 4ac is false 
//we are finding (b - k[i])^2 > 4ac we have to minimize the absolute difference of b and k[i] only then we will find
//(b - k[i])^2  will become lesser than zero as currently (b - k[i])^2 - 4ac >= 0 so we as we need to minimze the 
//difference and k vector is sorted in ascending order so if b >= k that means that we need larger value of k 
//to minimuze their difference so we can make lo = mid + 1 indicatng that now we are checking for larger values
//than k[mid] as all smaller values would still be lesser than b i.e b >= k and if k > b then we need to make value
//of k smaller to minimize the difference between b and k[i] so we will make k value smaller by making hi = mid - 1
//until ur condition is satisfied and if it we break out and if it never satisfies we bool remiains false and we print
//no.
    
void solve()
{
    ll n,m;
    cin >> n >> m;
    
    ll k[n]{};
    inp(k, n);
    sort(k, k + n);
    
    for(ll i = 0; i < m; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        
        ll lo = 0, hi = n - 1;
        bool ans = false;
        while(lo <= hi){
            ll mid = (lo + hi) / 2;
            
            if((b - k[mid]) * (b - k[mid]) < 4 * a * c){
                ans = true;
                cout << yes << nl;
                cout << k[mid] << nl;
                break;
            }
            else if(b >= k[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        if(!ans)
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