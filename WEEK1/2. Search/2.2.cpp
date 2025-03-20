#include <iostream>
#include <vector>
#include <algorithm>

void linearSearch(std::vector<int> &a, int target)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == target)
        {
            cnt++;
        }
    }
    std::cout << cnt << "\n";
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == target)
        {
            std::cout << i << " ";
            std::cout << i + 1 << "\n";
        }
    }
    if (cnt == 0)
        return;
    if (std::find(a.begin(), a.end(), target) == a.end())
        std::cout << cnt;
}

int main()
{
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a)
        std::cin >> x;
    int key;
    std::cin >> key;
    linearSearch(a, key);

    return 0;
}
