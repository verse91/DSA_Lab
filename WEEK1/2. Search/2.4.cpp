#include <iostream>
#include <string>
#include <vector>

int main()
{
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int k;
        std::cin >> k;
        int cnt = 0;
        int numb = 0;
        int numa;
        std::vector<int> check(1000005 + 2, 0);
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            if (check[tmp] == 0)
            {
                cnt++;
                check[tmp] = 1;
            }
            else if (check[tmp] == 1)
            {
                check[tmp] = 2;
                numb++;
            }
        }
        numa = cnt - numb;
        if (2 * cnt - 2 * k >= numa && 2 * cnt - 2 * k <= cnt)
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << "\n";
    }
}
