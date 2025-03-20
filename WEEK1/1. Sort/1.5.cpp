#include <iostream>
#include <vector>

void swap(std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<std::string> &arr, int low, int high)
{
    std::string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_s(std::vector<std::string> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_s(arr, low, pi - 1);
        quick_s(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string> codes;
    for (int i = 0; i < n; ++i)
    {
        std::string code;
        std::cin >> code;
        codes.push_back(code);
    }

    if (!codes.empty())
    {
        quick_s(codes, 0, codes.size() - 1);
    }

    int unique_count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || codes[i] != codes[i - 1])
        {
            unique_count++;
        }
    }

    std::cout << unique_count << std::endl;

    return 0;
}
