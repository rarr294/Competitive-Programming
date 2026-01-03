#include <stddef.h>

void transpose_matrix(size_t rows, size_t cols,const int matrix[rows][cols],int transpose[cols][rows]){
  for(int a = 0;a < rows;a++){
    for(int b = 0;b < cols;b++){
       transpose[b][a] = matrix[a][b];
    }
  }
}
