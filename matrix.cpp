#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
typedef vector<vector<int>> mat;

class Matrix
{
    private:
        mat matrix;
    
        // Check if the matrix is a square matrix or not
        bool isMatrixSquare()
        {
            int rowSize = this->matrix.size();
            int colSize = this->matrix[0].size();

            return (rowSize == colSize);
        }
        
        // Check if the matrix has either more rows or more columns
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
        
        // Check for the validity of the matrices before multiplying them
        bool isValidMultiplicationOperation(Matrix matrix1, Matrix matrix2)
        {
            int rowM1 = matrix1.rowSize();
            int colM1 = matrix1.colSize();
            int rowM2 = matrix2.rowSize();
            int colM2 = matrix2.colSize();
            
            return (rowM2 == colM1);
        }
        
        // Returns row size of the matrix
        int rowSize()
        {
            return (this->matrix.size());
        }
        
        // Returns column size of the matrix
        int colSize()
        {
            return (this->matrix[0].size());
        }
        
        // Returns the matrix value at the given row and column index
        int matrixElement(int row, int col)
        {
            if (row >= 0 && row < this->matrix.size() && col >= 0 && col < this->matrix[0].size())
            {
                return (this->matrix[row][col]);   
            }
            else
            {
                cout << "Matrix multiplication not feasible" << endl;
            }
        }
    
    public:
        // Default constructor
        Matrix()
        {
            this->matrix = {};
        }
        
        // Assigning matrix. Parameterized constructor
        Matrix(mat doubleVector)
        {
            this->matrix = doubleVector;
        }
        
        // In-place transpose of matrix
        void transpose()
        {
            // Skew = -1; Square matrix
            // Skew = 0; Skewed Row matrix
            // Skew = 1; Skewed Column matrix
            if (this->matrix.size() < 1)
            {
                return;
            }
            
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
            
            // Make the transpose on the square of the matrix
            for (int row = 0; row < minSize; row++)
            {
                for(int col = row + 1; col < minSize; col++)
                {
                    temp = this->matrix[row][col];
                    this->matrix[row][col] = this->matrix[col][row];
                    this->matrix[col][row] = temp;
                }
            }
            
            // Matrix with more rows than columns
            // Take each row post the square of the matrix and assign it to the columns after the square
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
            // Matrix with more columns than rows
            // Take each column post the square of the matrix and assign it to the rows after the square
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
        
        // Matrix Multiplication
        void multiply(Matrix matrix1, Matrix matrix2)
        {
            int rowM1 = matrix1.rowSize();
            int colM1 = matrix1.colSize();
            int rowM2 = matrix2.rowSize();
            int colM2 = matrix2.colSize();
            if (!isValidMultiplicationOperation(matrix1, matrix2))
            {
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
        
        // Display matrix to the console(Debugging purposes only)
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
        
        // Return the stored matrix
        mat getMatrix()
        {
            return (this->matrix);
        }
        
        void setMatrix(mat matrix)
        {
            //cout << this->matrix.size() << endl;
            this->matrix = matrix;
        }
};

int main()
{
    // Matrix Initialization
    mat m1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    mat m2 = {{1,2,3},{4,5,6},{7,8,9}};
    mat m3 = {{1}};
    mat transposeCheck = {{1,4,7},{2,5,8},{3,6,9}}; // Transpose of m2
    mat multCheck;
    
    Matrix a(m1);
    Matrix b(m2);
    Matrix c;
    Matrix d;
    
    // Transpose
    b.transpose();
    assert(b.getMatrix() == transposeCheck); // Square matrix transpose check
    
    transposeCheck = {};
    assert(c.getMatrix() == transposeCheck); // Transpose on a empty matrix
    
    transposeCheck = {{1,5,9},{2,6,10},{3,7,11},{4,8,12}};
    a.transpose();
    assert(a.getMatrix() == transposeCheck); // Column matrix transpose check
    
    a.transpose();
    transposeCheck = m1;
    assert(a.getMatrix() == transposeCheck); // Transpose of a transpose matrix check
    
    c.setMatrix(m3);
    c.transpose();
    transposeCheck = {{1}};
    assert(c.getMatrix() == transposeCheck); // Transpose of a single element matrix
    
    // Multiplication
    c.multiply(b,a);
    multCheck = {{84, 96, 108, 120}, {99, 114, 129, 144}, {114, 132, 150, 168}};
    assert(c.getMatrix() == multCheck); // Multiplication of 3x3 with 3x4
    
    c.multiply(b,b);
    multCheck = {{30, 66, 102}, {36, 81, 126}, {42, 96, 150}};
    assert(c.getMatrix() == multCheck); // Multiplication of 3x3 with 3x3
    
    mat temp = {{1}};
    a.setMatrix(temp);
    c.multiply(a,a);
    multCheck = {{1}};
    assert(c.getMatrix() == multCheck); // Multiplication of 1x1 with 1x1
    
    c.multiply(a,b);
    multCheck = {{1}};
    assert(c.getMatrix() == multCheck); // Multiplication of 1x1 with 3x3(Won't work and retains the old value)
    
    temp = {{-1,2,-3},{-4,5,-6},{7,-8,9}};
    a.setMatrix(temp);
    c.multiply(a,a);
    multCheck = {{-28,32,-36},{-58,65,-72},{88,-98,108}};
    assert(c.getMatrix() == multCheck); // Multiplication of 3x3 and 3x3 with negative values
    
    // Print Matrix
    //c.printMatrix();
    cout << endl;
    //b.printMatrix();
    
    return 0;
}
