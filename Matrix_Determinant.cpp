#include <vector>
using namespace std;

long long determinant(vector<vector<long long>> m) {
    int n = m.size();
    if (n == 1) return m[0][0];
    if (n == 2) return m[0][0]*m[1][1] - m[0][1]*m[1][0];
    long long det = 0;
    int sign = 1;
    for (int col = 0; col < n; col++) {
        vector<vector<long long>> minor;
        for (int i = 1; i < n; i++) {
            vector<long long> row;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                row.push_back(m[i][j]);
            }
            minor.push_back(row);
        }
        det += sign * m[0][col] * determinant(minor);
        sign = -sign;
    }
    return det;
}
