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

//In constructive Algorithms always start up with basic observations and then work your way upwards
//do not start directly with complex cases
//This is a constructive problem but this one was really really interesting as you would have to solve 
//two different problems regarding to the constraints , this required some deep deep deep very deep 
//observations and had cases like as follows : 

//if all the elements are positive and what if all the elements are
//negative in that case we can cosidering doing prefix (all positive) and suffix sums (all negative)
//it had other cases as well another good observations were : (prefixing or suffixing in worst case
//takses 19 steps as if all are positive or negative and maximum size can be n )

//if(max_positive >= max_negative && negative_cnt <= 12) we can make all negatives positive and then do
//prefix sums (as converting to positive would take 12 steps at max as we have <= 12 negatives and 19
//for prefixing so 12 + 19 = 31 which are just under the limits of the constraints)

//if(max_negative >= max_positive && positive_cnt <= 12) we can make all positives negatives and then do
//suffix sum (as converting to negative  would take 12 steps at max as we have <= 12 positives and 19
//for prefixing so 12 + 19 = 31 which are just under the limits of the constraints)

//there can be issues when negative cnt >= 13 and also max_positive is greater than max_negative then we
//cannot make negatives  positives as now it would at minimum require 13 steps to convert negatives
//to positives and then wo would have to make prefixes which can take 19 steps which can easily exceed
//the limit of 31 as 19 + 13 = 32 steps and that is if negatives_cnt = 13 it can even be 18 or something
//so the steps can even exceed so for this scenario we have two cases (as same thing can happen
//when positive_cnt >= 13) : 

//but first let us observe that even if a[i] = 1 to conert it to positive we need at max five steps
//as we can take i and j equal to a[i] += a[i] meaning 1 + 1 = 2 , 2 + 2 = 4, 4 + 4 = 8, 8 + 8 = 16,
//16 + 16 = 32 so at max five steps would be reuqired to make the lowest positive to maximum positive
//i.e 20. the steps can be lower if the number is greater than 1 to make it greater than 20. and same 
//is the case with negatives as to make -1 < -20 we would have to a[i] += a[i] at max at 5 steps
//-1 + -1 = -2 , -2 + -2 = -4, -4 + -4 = -8, -8 + -8 = -16, -16 + -16 = -32 , so we can see 5 steps at max
//with this observation in mind we deduct two cases:

//if(cnt_positives >= 13 && max_negative > max_positive) then we can make the maximum positive greater
//than or equal to 20 in at mox 5 steps and then we would make all negatives to positives in at most 7
//steps (because positives are lesser so it is better to utilize 12 steps rather than utilizing 13 or more
//steps to convert to opposite sign as it would exceed 31)
//and then we can make the prefix in at most 19 steps so in this case if we apply this logic
//it would take at max(5 + 7 + 19) = 31 steps which are just under the constraints provided. 

//if(cnt_negatives >= 13 && max_positive > max_negative) then we can make the maximum negative lesser
//than or equal to 20 in at mox 5 steps and then we would make all positves to negatives in at most 7
//steps (because positives are lesser so it is better to utilize 12 steps rather than utilizing 13 or more
//steps to convert to opposite sign as it would exceed 31) and then we can make the suffix in at 
//most 19 steps so in this case if we apply this logic it would take at max(5 + 7 + 19) = 31 steps which
//fits under the constraints provided. 

//I understood the logic from DOC NITA and while implementing 0 was causing a lot of trouble so i 
//considered it neither negative or positive and in some case it took more than 31 (38 steps)
//as it was treating negative as positive 

//The only contructive problem I like so far and actually learned something from it, it was nice !!!

//This workd for both version of the problem and for the A problem the 5 steps observations i guess 
//could be avoided and it would still work (maybe)

void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{};
    inp(a, n);
    
    vector<pair<ll,ll>> ans;
    ll cnt_negative = 0, cnt_positive = 0;
    ll max_positive = ninf; ll max_negative = ninf;
    ll max_positive_ind = -1, max_negative_ind = -1;
    for(ll i = 0; i < n; ++i){
        if(a[i] > 0) {
            cnt_positive ++;
            if(max_positive < a[i]){
                max_positive = a[i];
                max_positive_ind = i;
            }
        }
        else if (a[i] < 0){
            cnt_negative ++;
            if(max_negative < abs(a[i])){
                max_negative = abs(a[i]);
                max_negative_ind = i;
            }
        }
    }
    
    if(cnt_negative == 0){
        for(ll i = 1; i < n; ++i){
            ans.pb({i + 1 , i});
        }
    }
    else if(cnt_positive == 0){
        for(ll i = n - 2; i >= 0; --i){
            ans.pb({i + 1, i + 2});
        }
    }
    else{
        if(max_positive >= max_negative && cnt_negative <= 12){
            for(ll i = 0; i < n; ++i){
                if(a[i] < 0){
                    ans.pb({i + 1,max_positive_ind + 1});
                }
            }
            
            for(ll i = 1; i < n; ++i){
                ans.pb({i + 1,i});
            }
        }
        else if(max_negative > max_positive && cnt_positive <= 12){
            for(ll i = 0; i < n; ++i){
                if(a[i] > 0){
                    ans.pb({i + 1,max_negative_ind + 1});
                }
            }
                
            for(ll i = n - 2; i >= 0; --i){
                ans.pb({i + 1,i + 2});
            }   
        }
        else if(cnt_positive >= 13 && max_negative > max_positive){
            while(a[max_positive_ind] < 20){
                ans.pb({max_positive_ind + 1, max_positive_ind + 1});
                a[max_positive_ind] += a[max_positive_ind];
            }
            max_positive = a[max_positive_ind];
            
            for(ll i = 0; i < n; ++i){
                if(a[i] < 0){
                    ans.pb({i + 1,max_positive_ind + 1});
                }
            }
            
            for(ll i = 1; i < n; ++i){
                ans.pb({i + 1,i});
            }
        }
        else if(cnt_negative >= 13 && max_positive >= max_negative){
            while(a[max_negative_ind] > -20){
                ans.pb({max_negative_ind + 1,max_negative_ind + 1});
                a[max_negative_ind] += a[max_negative_ind];
            }
            max_negative = a[max_negative_ind];

            for(ll i = 0; i < n; ++i){
                if(a[i] >= 0){
                    ans.pb({i + 1,max_negative_ind + 1});
                }
            }
            
            for(ll i = n - 2 ; i >= 0; --i){
                ans.pb({i + 1,i + 2});
            }
        }
    }
    
     cout << ans.size() << nl;
     for(auto e : ans) 
        cout << e.first << ' ' << e.second << nl;
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
