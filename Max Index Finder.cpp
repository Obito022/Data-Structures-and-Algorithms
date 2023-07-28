/**
    * author : obito022 
    * date : 7/29/2023
**/
#include <iostream>
#include <vector>
// This is a homemade algorithm for dealing with max ints and and their indicies in a array.

/***
The "Max Index Finder" algorithm is a simple approach that iterates through a collection of 
elements, keeping track of the maximum element found so far and its corresponding indices. It can 
efficiently find all occurrences of the maximum element in the collection, making it useful for 
cases when the specific indices of the maximum value are required.

The steps of the "Max Index Finder" algorithm involve:
1. Initializing variables to store the maximum element and the vector of indices for the 
   maximum element.
2. Iterating through the collection to find the maximum element and its initial occurrence.
3. While iterating, updating the maximum element if a larger value is found and resetting the
   vector of indices to store the new maximum element's occurrence(s).
4. Continuing the iteration and adding any subsequent occurrences of the maximum element to the vector of 
   indices.
***/

using namespace std;

int main() {
  vector<int> a = {1, 2, 3, 3};

  int maxElement = a[0];
  vector<int> maxIndices = {0};

  for (int i = 1; i < a.size(); ++i) {
    if (a[i] > maxElement) {
      maxElement = a[i];
      maxIndices.clear();
      maxIndices.push_back(i);
    } else if (a[i] == maxElement) {
      maxIndices.push_back(i);
    }
  }

  cout << "Maximum element: " << maxElement << endl;
  cout << "Indices of the maximum element: ";
  for (int index : maxIndices) {
    cout << index << " ";
  }
  cout << endl;

  return 0;
}
