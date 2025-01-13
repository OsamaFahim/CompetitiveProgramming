#include<bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    if (std::abs(a - b) % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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