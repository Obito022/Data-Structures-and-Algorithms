/**
  Consider the problem of calculating the number of ways n queens can be placed on an 
  n×n chessboard so that no two queens attack each other.
**/

#include <iostream>
using namespace std;

const int MAX_N = 10;  // Adjust the maximum value of N as per your requirement
int n;  // Size of the chessboard
int count;  // Counter to keep track of the number of solutions
bool column[MAX_N];  // Array to track occupied columns
bool diag1[2 * MAX_N - 1];  // Array to track occupied diagonals (\)
bool diag2[2 * MAX_N - 1];  // Array to track occupied diagonals (/)

void search(int y) {
  if (y == n) {  // All rows have been explored, a solution is found
    count++;
    return;
  }

  for (int x = 0; x < n; x++) { // Iterate over columns in the current row
    if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1; // Place a queen
    search(y + 1); // Move to the next row
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;//Backtrack and remove the queen
  }
}

int main() {
  // Get the size of the chessboard from the user or set it to a specific value

  cout << "Enter the size of the chessboard: ";
  cin >> n;

  // Initialize variables
  count = 0;
  for (int i = 0; i < n; i++) {
    column[i] = 0;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    diag1[i] = diag2[i] = 0;
  }

  // Call the search function
  search(0);

  // Print the number of solutions
  cout << "Number of solutions: " << count << endl;

  return 0;
}
