/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int ar1[], int n, int ar2[], int m, int ar3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (ar1[i] < ar2[j]) ar3[k++] = ar1[i++];
        else ar3[k++] = ar2[j++];
    }

    while (i < n) ar3[k++] = ar1[i++];

    while (j < m) ar3[k++] = ar2[j++];
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t;
    cin >> t;
    while (cin >> n >> m || t > 0)
    {
        t--;
        int *a = new int[n], *b = new int[m], *c = new int[n + m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        merge(a, n, b, m, c);
        int nc = n + m;
        ;
        for (int i = 0; i < nc; i++)
        {
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
