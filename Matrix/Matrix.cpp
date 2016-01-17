#include "Matrix.h"
using namespace std;
/*
  Færibreytulaus smiður, til að upphafsstilla prívat meðlimabreytur (private member variables),
  afhverju þarf ég ekki að hafa hann?
*/
// Matrix::Matrix(){}

Matrix::Matrix(int row, int column){
    m_row = row;        // Þar sem m_row=i í forlykkjunni
    m_column = column;  // Þar sem m_column=j í forlykkjunni
    for(int m_row=0 ; m_row<row ; m_row++){
        for(int m_column= 0 ; m_column<column ; m_column++){
        m_arr[m_row][m_column] = 0;
        }
    }
}

ostream& operator <<(ostream& out, const Matrix& mat){
    for (int x = 0; x < mat.m_row; x++){
        for (int y = 0; y < mat.m_column; y++){
            out << mat.m_arr[x][y] << "\t";
        }
        out << endl;
    }
    return out;
}
istream& operator >>(istream& in, Matrix& mat){
    int temp;
    for (int x = 0; x < mat.m_row; x++){
        for (int y = 0; y < mat.m_column; y++){
            in >> temp;
            mat.m_arr[x][y] = temp;
        }
    }
    return in;
}

Matrix Matrix::transpose(){
    Matrix mattrans(m_column, m_row);
    for (int x = 0; x < m_row; x++){
        for (int y = 0; y < m_column; y++){
            mattrans.m_arr[y][x] = m_arr[x][y];
        }
    }
    return mattrans;
}

Matrix operator+(Matrix& matleft, Matrix& matright){
    int sum = 0;
    Matrix matsum(matleft.m_row, matleft.m_column);
    for (int x = 0; x < matleft.m_row; x++){
        for (int y = 0; y < matleft.m_column; y++){
             sum = matleft.m_arr[x][y] + matright.m_arr[x][y];
             matsum.m_arr[x][y] = sum;
        }
    }
    return matsum;
}

Matrix operator*(Matrix& matleft, Matrix& matright){

    Matrix matmult(matleft.m_row, matright.m_column);

    for (int x = 0; x < matleft.m_row; x++){
        for (int y = 0; y < matright.m_column; y++){
             for (int z = 0; z < matleft.m_column; z++){
                    matmult.m_arr[x][y] += matleft.m_arr[x][z] * matright.m_arr[z][y];
             }
        }
    }
    return matmult;
}
