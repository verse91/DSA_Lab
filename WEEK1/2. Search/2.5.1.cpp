#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<long long> arr(n);
        for (long long &x : arr)
        {
            std::cin >> x;
        }

        std::sort(arr.begin(), arr.end());

        long long sum = 0;
        if (n == 2)
        {
            sum = arr[1] - arr[0];
        }
        else if (n >= 5)
        {
            sum = arr[n - 1] - arr[0] + arr[n - 2] - arr[1];
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                sum += arr[n - 1 - i] - arr[i];
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
