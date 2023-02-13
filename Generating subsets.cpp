#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int> &set, int index, vector<int> &subset) {
  if (index == set.size()) {
    for (int i = 0; i < subset.size(); i++) {
      cout << subset[i] << " ";
    }
    cout << '\n';
    return;
  }

  // exclude the element at the current index
  generateSubsets(set, index + 1, subset);

  // include the element at the current index
  subset.push_back(set[index]);
  generateSubsets(set, index + 1, subset);

  // remove the element included in the previous step to restore the original
  subset.pop_back();
}

int main() {
  vector<int> set = {1, 2, 3};
  vector<int> subset;
  generateSubsets(set, 0, subset);

  return 0;
}
