#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
#define ll long long

bool isSafeMultiply(ll x, ll y)
{
    if (x == 0 || y == 0)
        return true;
    if (x > LLONG_MAX / y)
        return false;
    return true;
}

ll tree(ll a, ll k, ll b, ll m, ll days)
{
    ll doi1 = days / k;
    ll doi2 = days / m;

    ll effectiveDays1 = days - doi1;
    ll effectiveDays2 = days - doi2;

    if (!isSafeMultiply(effectiveDays1, a) || !isSafeMultiply(effectiveDays2, b))
    {
        return LLONG_MAX;
    }

    ll cut1 = effectiveDays1 * a;
    ll cut2 = effectiveDays2 * b;

    if (cut1 > LLONG_MAX - cut2)
    {
        return LLONG_MAX;
    }

    return cut1 + cut2;
}

ll Day(ll a, ll k, ll b, ll m, ll n)
{
    ll left = 1, right = n / min(a, b) + 1, mid, res = right;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (tree(a, k, b, m, mid) >= n)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    ll a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    cout << Day(a, k, b, m, n) << endl;
    return 0;
}
