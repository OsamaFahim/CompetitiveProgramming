#include<bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x % 2 != 0) {
            ++odd;
        } else {
            ++even;
        }
    }    
    
    if ((odd % 4) == 0 || (odd % 4) == 3 || (odd % 4) == 1 && even % 2 == 1) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
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