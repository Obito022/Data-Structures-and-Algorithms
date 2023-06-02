#include <iostream>
#include <vector>
using namespace std;
// Total Time complexity O(n * (2^n))

vector<vector<int>> generateSubsets(vector<int> &set) {
  int n = set.size();
  vector<vector<int>> subsets;
  for (int b = 0; b < (1 << n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
      if (b & (1 << i)) subset.push_back(set[i]);
    }
    subsets.push_back(subset);
  }
  return subsets;
}


int main() {

  vector<int> set = {2, 4, 5};

  vector<vector<int>> subsets = generateSubsets(set);

  for (auto subset : subsets) {
    for (auto element : subset) {
      cout << element << " ";
    }
    cout << endl;
  }

  return 0;
}
