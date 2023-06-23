#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int optimalMergePattern(vector<int>& files) {
  priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

  // Push all the file sizes into the priority queue
  for (int size : files) {
    pq.push(size);
  }

  int total_time = 0;

  // Merge the files until only one file remains in the priority queue
  while (pq.size() > 1) {
    int file1 = pq.top();
    pq.pop();

    int file2 = pq.top();
    pq.pop();

    int merged_file = file1 + file2;
    total_time += merged_file;

    pq.push(merged_file);
  }

  return total_time;
}

int main() {
  vector<int> files = {6, 5, 2, 3};
  int min_time = optimalMergePattern(files);

  cout << "Minimum time required to merge all files: " << min_time << endl;

  return 0;
}
