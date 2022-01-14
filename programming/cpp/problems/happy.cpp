#include <iostream.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int a = 1; a <= n; a++)
    {
        cin >> arr[a];
    }
    vector<int> front(n + 1, 0);
    vector<int> back(n + 1, 0);
    front[k] = arr[k];
    for (int i = k + 2; i <= n; i++)
    {
        front[i + 1] = max(front[i - 1], front[i - 2]) + arr[i];
    }
    back[1] = arr[1];
    back[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++)
    {
        back[i] = min(back[i - 1], back[i - 2]) + arr[i];
    }
    int ans = 0;
    for (int i = k; i <= n; i++)
    {
        ans = max(ans, front[i] + back[i] + arr[i]);
    }
    cout << ans << endl;
    return 0;
}