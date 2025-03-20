#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y, z;
};

bool compare(const Point &a, const Point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y > b.y;
    return a.z < b.z;
}

void merge(vector<Point> &points, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Point> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = points[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = points[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (compare(L[i], R[j]))
        {
            points[k++] = L[i++];
        }
        else
        {
            points[k++] = R[j++];
        }
    }

    while (i < n1)
        points[k++] = L[i++];
    while (j < n2)
        points[k++] = R[j++];
}

void mergeS(vector<Point> &points, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeS(points, left, mid);
        mergeS(points, mid + 1, right);
        merge(points, left, mid, right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    mergeS(points, 0, n - 1);

    for (const auto &p : points)
    {
        cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
    }

    return 0;
}
