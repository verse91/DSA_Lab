#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWeight(const vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return 0;

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int max1 = sortedArr[n - 1];
    int max2 = sortedArr[n - 2];
    int min1 = sortedArr[0];
    int min2 = sortedArr[1];

    int case1 = max1 - min1;
    int case2 = max1 + max2 - min1 - min2;

    return max(case1, case2);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i];
        }

        cout << maxWeight(arr) << endl;
    }

    return 0;
}
