#include <string>
#include <vector>
#include <cstdint>

int64_t solve(const std::string &s, const std::string &ops){
    int n = s.size();
    std::vector<std::vector<int64_t>> dpTrue(n, std::vector<int64_t>(n, 0));
    std::vector<std::vector<int64_t>> dpFalse(n, std::vector<int64_t>(n, 0));
    for(int i=0;i<n;i++){
        if(s[i] == 't') dpTrue[i][i] = 1;
        else dpFalse[i][i] = 1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0; i<=n-len; i++){
            int j = i + len - 1;
            for(int k=i; k<j; k++){
                char op = ops[k];
                int64_t lt = dpTrue[i][k], lf = dpFalse[i][k];
                int64_t rt = dpTrue[k+1][j], rf = dpFalse[k+1][j];
                if(op == '&'){
                    dpTrue[i][j] += lt * rt;
                    dpFalse[i][j] += lt*rf + lf*rt + lf*rf;
                } else if(op == '|'){
                    dpTrue[i][j] += lt*rt + lt*rf + lf*rt;
                    dpFalse[i][j] += lf*rf;
                } else if(op == '^'){
                    dpTrue[i][j] += lt*rf + lf*rt;
                    dpFalse[i][j] += lt*rt + lf*rf;
                }
            }
        }
    }
    return dpTrue[0][n-1];
}
