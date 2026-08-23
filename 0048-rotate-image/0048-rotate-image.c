void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i=0;i<matrixSize;i++){
        for(int j=i;j<matrixSize;j++){
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize/2;j++){
           int temp = matrix[i][j];
           matrix[i][j] =  matrix[i][matrixSize - 1 - j];
           matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}