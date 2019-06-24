#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> mat;

class Matrix
{
    private:
        mat matrix;
    
        bool isMatrixSquare()
        {
            int rowSize = this->matrix.size();
            int colSize = this->matrix[0].size();

            return (rowSize == colSize);
        }
        
        int skewedMatrix()
        {
            // 1 -> Row > Column
            // 0 -> Column > Row
            
            int rowSize = this->matrix.size();
            int colSize = this->matrix[0].size();
            
            int retVal;
            rowSize > colSize ? retVal = 0 : retVal = 1;
            return (retVal);
        }
        
        bool isValidMultiplicationOperation(Matrix matrix1, Matrix matrix2)
        {
            int rowM1 = matrix1.rowSize();
            int colM1 = matrix1.colSize();
            int rowM2 = matrix2.rowSize();
            int colM2 = matrix2.colSize();
            
            return (rowM2 == colM1);
        }
        
        int rowSize()
        {
            return (this->matrix.size());
        }
        
        int colSize()
        {
            return (this->matrix[0].size());
        }
        
        int matrixElement(int row, int col)
        {
            if (row >= 0 && row < this->matrix.size() && col >= 0 && col < this->matrix[0].size())
            {
                return (this->matrix[row][col]);   
            }
            else
            {
                //Raise Exception
            }
        }
    
    public:
        Matrix()
        {
            this->matrix = {};
        }
        
        Matrix(mat doubleVector)
        {
            this->matrix = doubleVector;
        }
        
        void transpose()
        {
            // Skew = -1; Square matrix
            // Skew = 0; Skewed Row matrix
            // Skew = 1; Skewed Column matrix
            int skew = -1;
            if (!isMatrixSquare())
            {
                skew = skewedMatrix();
            }
            int rowSize = this->matrix.size();
            int colSize = this->matrix[0].size();
            int minSize = min(rowSize, colSize);
            int maxSize = max(rowSize, colSize);
            int temp;
            
            for (int row = 0; row < minSize; row++)
            {
                for(int col = row + 1; col < minSize; col++)
                {
                    temp = this->matrix[row][col];
                    this->matrix[row][col] = this->matrix[col][row];
                    this->matrix[col][row] = temp;
                }
            }
            
            if (skew == 0)
            {
                for (int row = minSize; row < maxSize; row++)
                {
                    for (int col = 0; col < minSize; col++)
                    {
                        this->matrix[col].emplace_back(this->matrix[row][col]);
                    }
                    this->matrix.erase(this->matrix.begin() + row);
                }
            }
            else if (skew == 1)
            {
                for (int row = minSize; row < maxSize; row++)
                {
                    this->matrix.emplace_back(vector<int>());
                    for (int col = 0; col < minSize; col++)
                    {
                        this->matrix[row].emplace_back(this->matrix[col][row]);
                    }
                }
                
                for (int row = 0; row < minSize; row++)
                {
                    this->matrix[row].erase(this->matrix[row].begin() + minSize);
                }
            }
        }
        
        void multiply(Matrix matrix1, Matrix matrix2)
        {
            int rowM1 = matrix1.rowSize();
            int colM1 = matrix1.colSize();
            int rowM2 = matrix2.rowSize();
            int colM2 = matrix2.colSize();
            if (!isValidMultiplicationOperation(matrix1, matrix2))
            {
                //Raise Exception
                return;
            }
            
            int row = this->matrix.size();
            if (row > 0)
            {
                for (int i = 0; i < row; i++)
                {
                    this->matrix.erase(this->matrix.begin() + i);
                }
            }
            
            for (int i = 0; i < rowM1; i++)
            {
                this->matrix.emplace_back(vector<int>());
                for (int j = 0; j < colM2; j++)
                {
                    this->matrix[i].emplace_back(0);
                }
            }
            
            for (int i = 0; i < rowM1; i++)
            {
                for (int j = 0; j < colM2; j++)
                {
                    for (int k = 0; k < colM1; k++)
                    {
                        this->matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
                    }
                }
            }
        }
        
        void printMatrix()
        {
            int row = this->matrix.size();
            if (row == 0)
            {
                return;
            }
            int col = this->matrix[0].size();
            
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << this->matrix[i][j] << "\t";
                }
                cout << "\n";
            }
        }
};

int main()
{
    // Matrix Initialization
    mat m1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    mat m2 = {{1,2,3},{4,5,6},{7,8,9}};
    
    Matrix a(m1);
    Matrix b(m2);
    Matrix c;
    Matrix d;
    
    // Transpose
    b.transpose();
    
    // Multiplication
    c.multiply(b,a);
    
    // Print Matrix
    c.printMatrix();
    cout << endl;
    b.printMatrix();
    
    return 0;
}
