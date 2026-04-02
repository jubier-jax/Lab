#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<int>> B(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                B[i][j] += A[i][k] * A[k][j];

    int total = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            total += B[i][j];

    cout << total;
}
