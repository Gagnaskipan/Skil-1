#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;
/*
  Þessi klasi býður upp á þrjár aðgerðir á heiltölufylkjum, transpose(), + og *,
  og jafnframt er hægt að lesa inn og skrifa út fylki með virkjunum >> og <<.
  Útfærslan á Matrix skal nota tvívítt fylki og þið getið gert ráð fyrir því að hámarksstærð
  þess sé 5x5. Forritið ykkar skal samanstanda af þremur skrám: Matrix.h,
  Matrix.cpp og main.cpp (sem er gefin).
*/
const int Max = 5;

class Matrix{
    private:
        int m_row;
        int m_column;
        int m_arr[Max][Max];
    public:
        // Matrix();              // Færibreytulaus smiður, til að upphafsstilla prívat meðlimabreytur (private member variables)
        Matrix(int row, int column);    // Smiður með færibreytum, notaður til að skilgreina breyturnar, d: m_row = row
        Matrix transpose();
        friend Matrix operator*(Matrix& matleft, Matrix& matright);
        friend Matrix operator+(Matrix& matleft, Matrix& matright);
        friend ostream& operator <<(ostream& out, const Matrix& mat);
        friend istream& operator >>(istream& in, Matrix& mat);

        // void showMatrix();
        // void sumMatrix();
        // void multiplyMatrix();
        // void transposeMatrix();
};

#endif // MATRIX_H

