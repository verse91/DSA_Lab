#include <iostream>
#include <vector>
#include <algorithm>

void linearSearch(std::vector<int> &a, int target) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == target){
            std::cout << i << "\n";
            std::cout << i + 1 << "\n";
            std::cout << a.size() - i - 1 << "\n";
            std::cout << a.size() - i << "\n";
        }
    }
        if (std::find(a.begin(), a.end(), target) == a.end()) std::cout << -1;
}

int main() {
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto & x : a) std::cin >> x;
    int key; std::cin >> key;
    linearSearch(a, key);


    return 0;
}
