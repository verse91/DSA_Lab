#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int>& a){
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 1; j < a.size() - i; ++j) {
            if (a[j] < a[j-1]) {
                std::swap(a[j], a[j-1]);
                for (int x : a) std::cout << x << " ";
                std::cout << "\n";
            }
        }
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto & x : a) std::cin >> x;
    bubbleSort(a);
    return 0;
}
