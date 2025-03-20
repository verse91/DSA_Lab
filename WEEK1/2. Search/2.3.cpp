#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_VAL = 100005; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    bitset<MAX_VAL> seen;
    int mex = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        seen[arr[i]] = true;


        while (seen[mex])
        {
            ++mex;
        }

        cout << mex << ' ';
    }

    return 0;
}
