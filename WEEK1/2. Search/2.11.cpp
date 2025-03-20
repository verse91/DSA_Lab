#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

bool canDivide(int n, int k, vector<ll> &pages, ll max_sum)
{
    int count = 1;
    ll current_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_sum + pages[i] <= max_sum)
        {
            current_sum += pages[i];
        }
        else
        {
            count++;
            current_sum = pages[i];
            if (count > k)
                return false;
        }
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> pages(n);
    ll total = 0, max_page = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
        total += pages[i];
        max_page = max(max_page, pages[i]);
    }

    ll left = max_page, right = total, result = total;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (canDivide(n, k, pages, mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
