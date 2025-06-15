/*
ID = 24003510
NAME = Emir Azimil Akbar Bin Mohd Fauzi
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to find the maximum size square from (i, j)
int maxSquareRecur(int i, int j, vector<vector<int>> &mat, int &ans) {
    // Base condition: out of bounds
    if (i < 0 || i == mat.size() || j < 0 || j == mat[0].size())
        return 0;

    // Recursive calls for right, down, and diagonal directions
    int right = maxSquareRecur(i, j + 1, mat, ans);
    int down = maxSquareRecur(i + 1, j, mat, ans);
    int diag = maxSquareRecur(i + 1, j + 1, mat, ans);

    // If current cell is 0, it can't be part of any square
    if (mat[i][j] == 0)
        return 0;

    // Minimum of the three directions + 1 (for the current cell)
    int side = 1 + min({right, down, diag});
    ans = max(ans, side);  // Update the global maximum

    return side;
}

// Function that initializes the recursion
int maxSquare(vector<vector<int>> &mat) {
    int ans = 0;
    maxSquareRecur(0, 0, mat, ans);
    return ans;
}

// Main function
int main() {
    // Sample matrix of 0s and 1s
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    cout << "Maximum square sub-matrix size: " << maxSquare(mat) << endl;

    return 0;
}