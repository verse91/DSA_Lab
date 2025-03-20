#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product
{
    string code;
    int count;
    int length;
};

bool compareNaturalOrder(const Product &a, const Product &b)
{
    if (a.length != b.length)
    {
        return a.length < b.length;
    }
    return a.code < b.code;
}

bool compareProducts(const Product &a, const Product &b)
{
    if (a.count != b.count)
    {
        return a.count > b.count;
    }
    return compareNaturalOrder(a, b);
}

bool compareCodes(const Product &a, const Product &b)
{
    return compareNaturalOrder(a, b);
}

void merge(vector<Product> &arr, int left, int mid, int right, bool useCounts)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Product> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        bool useLeft;
        if (useCounts)
        {
            useLeft = compareProducts(L[i], R[j]);
        }
        else
        {
            useLeft = compareCodes(L[i], R[j]);
        }
        if (useLeft)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeS(vector<Product> &arr, int left, int right, bool useCounts)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeS(arr, left, mid, useCounts);
        mergeS(arr, mid + 1, right, useCounts);
        merge(arr, left, mid, right, useCounts);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Product> products(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> products[i].code;
        products[i].count = 1;
        products[i].length = products[i].code.length();
    }

    mergeS(products, 0, N - 1, false);

    vector<Product> aggregated;
    if (N > 0)
    {
        Product current = products[0];
        for (int i = 1; i < N; ++i)
        {
            if (products[i].code == current.code)
            {
                current.count++;
            }
            else
            {
                aggregated.push_back(current);
                current = products[i];
            }
        }
        aggregated.push_back(current);
    }

    mergeS(aggregated, 0, aggregated.size() - 1, true);

    for (const auto &product : aggregated)
    {
        cout << product.code << " " << product.count << '\n';
    }

    return 0;
}
