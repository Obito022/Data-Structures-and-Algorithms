#include <iostream>
#include <vector>
using namespace std;

void generate_permutation(vector<int>& arr, vector<int>& permutation, vector<bool>& chosen) {
  if (permutation.size() == arr.size()) {
    for (int x : permutation) {
      cout << x << " ";
    }
    cout << endl;
  } else {
        for (int i = 0; i < arr.size(); i++) {
          if (chosen[i]) continue;
          chosen[i] = true;
          permutation.push_back(arr[i]);
          generate_permutation(arr, permutation, chosen);
          permutation.pop_back();
          chosen[i] = false;
        }
    }
}

int main() {
  vector<int> arr = {1, 2, 3};
  vector<int> permutation;
  vector<bool> chosen(arr.size(), false);

  generate_permutation(arr, permutation, chosen);

  return 0;
}
