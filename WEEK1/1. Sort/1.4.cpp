#include <iostream>
using namespace std;
int A[101];
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using ll = long long;

void Merge(int a[], int l, int m, int h)
{
    int b[h + 1];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        Merge(a, l, m, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
    {
        cin >> x;
    }
    mergeSort(a, 0, n - 1);
    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}
