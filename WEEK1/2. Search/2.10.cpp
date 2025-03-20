#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

std::vector<long long> findGrid(long long l)
{
    long long minDiff = LLONG_MAX;
    std::vector<long long> result = {-1, -1};

    long long target = l - 1;

    long long m_max = (long long)(sqrt((long double)target / 2.0)) + 1;

    for (long long m = 1; m <= m_max; ++m)
    {
        long long numerator = target - m;
        long long denominator = 2 * m + 1;

        if (numerator % denominator == 0)
        {
            long long n = numerator / denominator;
            if (m <= n)
            {
                long long diff = n - m;
                if (diff < minDiff)
                {
                    minDiff = diff;
                    result = {m, n};
                }
            }
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        long long l;
        std::cin >> l;

        auto result = findGrid(2 * l);

        if (result[0] == -1)
        {
            std::cout << "-1 -1\n";
        }
        else
        {
            std::cout << result[0] << " " << result[1] << "\n";
        }
    }

    return 0;
}
