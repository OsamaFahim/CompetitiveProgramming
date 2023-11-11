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

//A question teaching you the true essence of two pointer , the two pointer is very intuitive for the question and 
//i guess that if you know the two pointer approach you will be able to solve this question. Also there are a bit
//of permutation intuition that the at frst you are gonna initialize mini to 1 and maxi to n that if permutation
//is in order(sorted) then probably 1 is on the left most ind and right on the right most ind and if this is the 
//case then we are going to move our two pointers inwards(left) and outwards(right) and update min and max
//along the way if min and max are in correct sorted places then we would hope that we find something later
//in the array and update our pointers accordingly (left and right) and if that lets say min is on the correct
//position but max is not then we would update left pointer and also min variable and vice versa for opposite case
//the if else conditions tells the entire story read them to clear any confusions, also that min and max are also
//updated accordingly because lets say both left and right needs to be updated then now our min would become 2
//and max would become n - 2 , as these are the expected values in their desired locations so we do min++ and max--
//and if partial conditions are satisfied and if max is in correct place then only max-- and not min along with
//the pointer (left or right) which is resposible also changes and this is it for this problem.

//Overall a very decent and beautiful problem teaching the concept of two pointers properly alos see conditions
//below to clear confusions regarding the problem

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{};
    inp(a, n);
    
    ll left = 0, right = n - 1;
    ll maxi = n, mini = 1;
    bool ans = false;
    while(left <= right){
        if((a[left] == mini && a[right] == maxi) ||(a[left] == maxi && a[right] == mini)){
            left ++, right --;
            mini++,maxi--;
        }
        else if(a[left] == mini){
            left++,mini++;
        }
        else if(a[left] == maxi){
            left++,maxi--; 
        }
        else if(a[right] == mini){
            right--,mini++;
        }
        else if(a[right] == maxi){
            right--,maxi--;
        }
        else{
            ans = true;
            cout << left + 1 << ' ' << right + 1 << nl;
            break;
        }
    }
    
    if(!ans) cout << -1 << nl;
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