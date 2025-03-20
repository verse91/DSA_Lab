#include <iostream>
#include <vector>
#include <algorithm>

void SelectionSort(std::vector<int> &a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        std::vector <int> b = a;
        int minIndex = i;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(a[i], a[minIndex]);
        if (a != b) {
        for (int x : a)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
        b = a;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a)
    {
        std::cin >> x;
    }
    SelectionSort(a);
    return 0;
}
