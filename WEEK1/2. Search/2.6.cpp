#include <iostream>
#include <vector>

void binarySearch(std::vector<int> &a, int target)
{
    int left = 0;
    int right = a.size() - 1;
    int count = 0;
    int position = -1;

    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;

        if (a[mid] == target)
        {
            position = mid;
            break;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << position << "\n";

    if (position != -1)
    {
        std::cout << count << "\n";
    }
}

int main()
{
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int target;
    std::cin >> target;

    binarySearch(a, target);

    return 0;
}
