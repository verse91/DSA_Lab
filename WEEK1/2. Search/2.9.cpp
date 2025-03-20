#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long best_res = LLONG_MAX;

bool check(long long min_l, const vector<long long> &wall, const vector<long long> &wood)
{
    int wood_idx = 0;
    for (long long w : wall)
    {
        if (min_l <= w)
            continue;
        while (wood_idx < wood.size() && wood[wood_idx] < min_l - w)
            wood_idx++;
        if (wood_idx == wood.size())
            return false;
        wood_idx++;
    }
    return true;
}

long long binarySearch(const vector<long long> &wall, const vector<long long> &wood)
{
    long long low = 1;
    long long high = LLONG_MAX;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (check(mid, wall, wood))
        {
            best_res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return best_res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<long long> wall(n);
    for (int i = 0; i < n; i++)
        cin >> wall[i];

    cin >> m;
    vector<long long> wood(m);
    for (int i = 0; i < m; i++)
        cin >> wood[i];

    binarySearch(wall, wood);

    int cnt = 0;
    for (long long w : wall)
        cnt += (w < best_res);

    cout << best_res << " " << cnt << "\n";

    int wood_idx = 0;
    for (int i = 0; i < wall.size(); i++)
    {
        if (best_res <= wall[i])
            continue;
        while (wood_idx < wood.size() && wood[wood_idx] < best_res - wall[i])
            wood_idx++;
        cout << i + 1 << " " << wood_idx + 1 << "\n";
        wood_idx++;
    }

    return 0;
}
