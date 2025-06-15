/*
ID = 24003510
NAME = Emir Azimil Akbar Bin Mohd Fauzi
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find median of a matrix using extra space
int findMedian(vector<vector<int>> &mat) {
    vector<int> temp;

    // Flatten the matrix into a 1D array
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            temp.push_back(mat[i][j]);
        }
    }

    // Sort the flattened array
    sort(temp.begin(), temp.end());

    // Return the middle element
    int mid = temp.size() / 2;
    return temp[mid];
}

int main() {
    // Example 3x3 matrix (must be odd number of elements)
    vector<vector<int>> matrix = {
        {1, 3, 6},
        {3, 6, 2},
        {7, 4, 1}
    };

    cout << "Median of the matrix is: " << findMedian(matrix) << endl;

    return 0;
}