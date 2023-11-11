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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"  
#define mod 998244353     

//heck of a problem took lot of time and you should now be focused on thinking bit masks too

//Remember one very interesting and useful property of XOR i.e a + b = (a ^ b) + 2(a & b) for its proof
//and intuition watch starting part of https://www.youtube.com/watch?v=n_2H8X9L068

// as we can see that 
//  -> a + b = (a ^ b) + 2(a & b)
//  -> (a + b) / 2 = (a ^ b) / 2 + (a & b)  
//  -> a ^ b = (a ^ b) / 2 + (a & b)
//  -> a ^ b - (a ^ b) / 2 = a & b
//  -> a & b = after lcm .... a ^ b / 2
//  -> as we have a ^ b = x so,
//  -> a & b = x / 2

// now we have 2 equations 
// 1. a & b = x / 2
// 2. a ^ b = x ( given )

// after this deduction there are two appraoches to this problem one is the you can form the two numbers using 
// properties of bitwise and and bitwise xor 
//for eg take example where x = 10
// now a ^ b = 10 and a & b = 5
//binary of 10 = 1 0 1 0
//binary of 5  = 0 1 0 1

// table
// a  b  &  ^
// 0  0  0  0   --> 1st step other steps are similar see values of ^ & and then form the values of a and b 
// 0  1  0  1       which are along with them
// 1  0  0  1
// 1  1  1  0

//always keep values for 0 1 as 0 1 and not 1 1 as it just not seem to work 

//and me and ke column se value uthao aur xor ki jagah ka lia xor ka column se value uthao

//1st step
// conisde last bits of 10 and 5 i.e 0 1 now for which values of result of  1 xor and 1 and(exlsuive)
// it  0 1
// then for 1 0 values are 1 1
// then for 0 1 values are 0 1
// then for 1 0 values are 1 1

// final numbers are  1111 = 15 and 1 0 1 0 = 10 and 10 ^ 15 = 5 which is correct
// currectly I am not going to be coding this solution up 
//after forming the number check that if(a ^ b == x) if not print -1 else print a and b

//the second appraoch is more vaiable and I liked it more as it is constant in time O(1) although
//it is not as intuitive but still i understood

//considering the equations 
// 1. a & b = x / 2
// 2. a ^ b = x ( given )

// a ^ b cotains all the bits set which are set in either one of the numbers either a or b
//so lets consider that these bits i.e a ^ b bits are set in a , and a & b contains the bits which are
//set in both so we can see that one contains bits set in one of them and other contains bits which are set
//in both and as we have already considered that number a is going to have the set bits due to a ^ b 
// so we can write a as a = (a ^ b) + (a & b) , as a ^ b contains set bits in only a and a & b contains set
//bits in both a and b so if we add both of them we can form number a 
// so  a = (a ^ b) + (a & b) -> a = x  + (x / 2)
//and now as a & b contains bits set in both of them so we can consider b as a & b 
//as a & b will contain the bits set in both of them 
//dont get confused as a ^ b contained bits set in either one of them and a & b contains bits set in both
//after forming numbers we will check if(a ^ b == x) if not print -1 else print a and b

void solve()
{   
    ll x;
    cin >> x;
    
    if(x & 1)   //  a ^ b = x , as x is an integer so a + b / 2 should also be an integer and for that 
        cout << -1 << nl;       // a + b should be even which in turns x should be even
    else{
        ll a = x + (x / 2); //a ^ b + a & b
        ll b = x / 2; // a & b
        
        if((a ^ b) == x) // as a + b = x + x/2 + x/2 = x + (2x / 2) = x +x = 2x  so a + b =2x , (a + b) / 2 = x
            cout << a << ' ' << b << nl;    //already proved so no need to check (a + b )/ 2
        else
            cout << -1 << nl;       
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
    os << p.first << ' ' << p.second << nl;
    return os;
}