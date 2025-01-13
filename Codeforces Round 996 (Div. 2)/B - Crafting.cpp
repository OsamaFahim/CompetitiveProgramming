#include<bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    
    int cnt_less = 0, cnt_equal = 0, ind = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            ++cnt_less;
            ind = i;
        } else if (a[i] == b[i]) {
            ++cnt_equal;
        }
    }
    
    if (cnt_less > 1 || cnt_less == 1 && cnt_equal >= 1) {
        std::cout << "NO\n";        
    } else {
        int req = b[ind] - a[ind];
        for (int i = 0; i < n; ++i) {
            if (i != ind) {
                if (a[i] - req < b[i]) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
        
        std::cout << "YES\n"; 
    }
}

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);
   
   int t;
   std::cin >> t;
   
   while (t--) {
       solve();
   }
   
   return 0;
}