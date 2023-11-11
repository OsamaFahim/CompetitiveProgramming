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
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"       

//The main idea of the problem is that as we have to change the array such that ai != bi and sum (a) == sum (b)
//and that all the elements must remain positive notice that 0 is not a positive integer so all the elements must 
//be greater than or equal to 1, so whenever we find 1 we must increment that a[i] as we cant decrement and 
//at the same time we must change it so we will have to increment it if we want the array to get changed and 
//at the same time we would have to decrement some other numbers greater than 1 to accomodate this increment
//so that sum(a) = sum(b) , so let cnt_1 be the count of 1's in arr so the remaining elements are (n - cnt1)
//notice that the sum of (n - cnt1) elements must be altleast equal to (n - cnt1) + cnt1 only then the increments
//due to 1 would be handled and the sum of both a and b would become equal (also (n - cnt1) + cnt1) = n
//example : 1 1 1 1 3 3 here the sum of (n - cnt1) elements that 3 3 is 6 which is equal to n and now the 
//increments which had to be done on 1 can now be handeled as 2 2 2 2 1 1 so, this was the part of (n - cnt1)
//elements now conisdering the total and to find the sum of (n - cnt1) elemets we can simply subtract the 
//count of 1 from the entire sum and that would give us sum of (n - cnt1) elements and it must be sum(n - cnt1) >= n
//i.e sum_a - cnt_1 >= n then the answer would always be possible . this is enough for the solution below
//but there can be other observations as well as (n - cnt1) elements sum must be >= n but what about the sum
//of the entire array sum of a must be >= *(n-cnt1) +cnt1* + cnt1 as the thing in * is the sum of n - cnt1
//elements and the remaining sum must be equals to  sum(n-cnt1) + cnt1 which seems obvious as the remaining
//elements are the number of 1's so they must be added to the sum of (n - cnt1) elements so that the sum
//stays the same and if the condition gets fails means < the above conditions then good array is not possible
//althoguh this thing is very nice that sum(n - cnt1) which is sum_a - cnt1 must be greater than equal to n
//cout << ((sum_a - cnt_1 >= n) ? yes : no) << nl; which accomdates the ones which must be incremented so thats
//it was a good decent problem i liked it after learning about it but not during the contest lol ....
// sum(a) must be sum(n - cnt1) + cnt1, cnt1 is added because all the elements must remain greater than 1 so if
//cnt1 is sol arge that sum(n - cnt1) is not accomodating so not possible 

//https://codeforces.com/blog/entry/119058 this ediotrial was very good in explaining this question 
//and the equations required to understand and solve the question

void solve()
{   
    ll n;
    cin >> n;
    ll a[n]{};
    inp(a,n);
    
    if(n == 1){
        cout << no << nl;
    }
    else{
        ll sum_a = 0, cnt_1 = 0;
        for(ll i = 0; i < n; ++i){
            sum_a += a[i];
            cnt_1 += a[i] == 1;
        }

      cout << ((sum_a - cnt_1 >= n) ? yes : no) << nl;  //This was a equation which was reduced down to this
      //to revise the concept with entirity visit the solution of editorial and there it was written in 
      //complete detail 
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