#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
  string id;
  char dead;
  int profit;
};

class Solution {
public:
  static bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
  }

  vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);
    vector<int> result;
    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
      for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
        if (!slot[j]) {
          result.push_back(j + 1);
          slot[j] = true;
          break;
        }
      }
    }

    int totalProfit = 0;
    int numJobs = result.size();
    for (int i = 0; i < numJobs; i++) {
      totalProfit += arr[result[i] - 1].profit;
    }

    result.clear();
    result.push_back(numJobs);
    result.push_back(totalProfit);
    return result;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++) {
      string x;
      char y;
      int z;
      cin >> x >> y >> z;
      arr[i].id = x;
      arr[i].dead = y;
      arr[i].profit = z;
    }
    Solution ob;
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
  }

  return 0;
}
