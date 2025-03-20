#include <iostream>
#include <vector>
#include <algorithm>

void InsertionSort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;

        for (int k = 0; k < arr.size(); k++)
        {
            if (k == 0)
                std::cout << "[ ";
            std::cout << arr[k];
            if (k == i)
                std::cout << " ] ";
            else
                std::cout << " ";
        }
        std::cout << "\n";

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    std::cout << "[ ";
    for (const auto &x : arr) std::cout << x << " ";
    std::cout << "]";
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a)
    {
        std::cin >> x;
    }
    InsertionSort(a);
    return 0;
}
