#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;
/*
  �essi klasi b��ur upp � �rj�r a�ger�ir � heilt�lufylkjum, transpose(), + og *,
  og jafnframt er h�gt a� lesa inn og skrifa �t fylki me� virkjunum >> og <<.
  �tf�rslan � Matrix skal nota tv�v�tt fylki og �i� geti� gert r�� fyrir �v� a� h�marksst�r�
  �ess s� 5x5. Forriti� ykkar skal samanstanda af �remur skr�m: Matrix.h,
  Matrix.cpp og main.cpp (sem er gefin).
*/
const int Max = 5;

class Matrix{
    private:
        int m_row;
        int m_column;
        int m_arr[Max][Max];
    public:
        // Matrix();              // F�ribreytulaus smi�ur, til a� upphafsstilla pr�vat me�limabreytur (private member variables)
        Matrix(int row, int column);    // Smi�ur me� f�ribreytum, nota�ur til a� skilgreina breyturnar, d: m_row = row
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

