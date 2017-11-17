/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cplummer
 *
 * Created on November 13, 2017, 12:37 PM
 */

#include <iostream>

using namespace std;


class Matrix
{
private:
    int array[2][2];
public:
    void assignVariable(int row, int column, int value)
    {
        array[row][column] = value;
    }//End of assign variable method.
    
    void assignAllVariables(int value)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            { 
                array[i][j] = value;
            }
        }
    }//End of assign all method.
    
    void printMatrix()
    {
      for(int i = 0; i < 2; i++)
      {
            for(int j = 0; j < 2; j++)
            { 
                if(i == 1 && j == 0)
                {
                   cout << endl;   
                }
                
                cout << array[i][j] << " ";
            }
        }  
      cout << endl;
    }//End of print matrix method.
    
    void add(const int& rhs)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            { 
                array[i][j] += rhs;
            }
        } 
    }
    
    void addMatrix(const Matrix& m)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            { 
                array[i][j] += m.array[i][j];
            }
        } 
    }
    
    void subtract(const int& rhs)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            { 
                array[i][j] -= rhs;
            }
        } 
    }
    
    void subtractMatrix(const Matrix& m)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            { 
                array[i][j] -= m.array[i][j];
            }
        } 
    }
    
    void operator+(const int& rhs)
    {
        add(rhs);
    }
    
    void operator+(const Matrix& m)
    {
        addMatrix(m);
    }
    
    void operator-(const int& rhs)
    {
        subtract(rhs);
    }
    
    void operator-(const Matrix& m)
    {
        subtractMatrix(m);
    }
};
/*
 * 
 */
int main(int argc, char** argv) {
    Matrix m1;
    Matrix m2;
    
    //Sets the values for the first matrix.
    m1.assignVariable(1,1,1);
    m1.assignVariable(0,0,1);
    m1.assignVariable(0,1,1);
    m1.assignVariable(1,0,1);
    
    m2.assignAllVariables(3);

    cout << "Matrix A: " << endl;
    m1.printMatrix();
    
    cout << "Matrix B: " << endl;
    m2.printMatrix();
    
    cout << "Matrix A + 1: " << endl;
    m1+1;
    m1.printMatrix();
    
    //Resets the first matrix.
    m1.assignVariable(1,1,1);
    m1.assignVariable(0,0,1);
    m1.assignVariable(0,1,1);
    m1.assignVariable(1,0,1);
    
    cout << "Matrix A - 1: " << endl;
    m1-1;
    m1.printMatrix();
    
    //Resets the first matrix.
    m1.assignVariable(1,1,1);
    m1.assignVariable(0,0,1);
    m1.assignVariable(0,1,1);
    m1.assignVariable(1,0,1);
    
    cout << "Matrix A + Matrix B" << endl;
    m1+m2;
    m1.printMatrix();
    
    //Resets the first matrix.
    m1.assignVariable(1,1,1);
    m1.assignVariable(0,0,1);
    m1.assignVariable(0,1,1);
    m1.assignVariable(1,0,1);
    
    cout << "Matrix A - Matrix B" << endl;
    m2-m1;
    m2.printMatrix();
    
    return 0;
}

