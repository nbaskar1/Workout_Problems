#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

class Matrix
{
    private:
        matrix mat;
    
        int isSquare()
        {
            int row_size = this->mat.size();
            int col_size = this->mat[0].size();
            //cout << row_size << col_size << endl;
            // 1 -> Same size
            // 0 -> Unequal size
            int ret_val;
            row_size == col_size ? ret_val = 1 : ret_val = 0;
            return (ret_val);
        }
        
        int skewedMatrix()
        {
            int row_size = this->mat.size();
            int col_size = this->mat[0].size();
            
            // 1 -> Row > Column
            // 0 -> Column > Row
            int ret_val;
            row_size > col_size ? ret_val = 0 : ret_val = 1;
            return (ret_val);
        }
        bool isMultiplicationValid(Matrix a, Matrix b)
        {
            int row_1 = a.row_size();
            int col_1 = a.col_size();
            int row_2 = b.row_size();
            int col_2 = b.col_size();
            
            if (row_2 == col_1)
            {
                return (true);
            }
            return (false);
        }
        int row_size()
        {
            return (this->mat.size());
        }
        int col_size()
        {
            return (this->mat[0].size());
        }
        int matrix_element(int i, int j)
        {
            if (i >= 0 && i < this->mat.size() && j >= 0 && j < this->mat[0].size())
            {
                return (this->mat[i][j]);   
            }
            else
            {
                //Raise Exception
            }
        }
    
    public:
        Matrix()
        {
            this->mat = {};
        }
        Matrix(matrix val)
        {
            this->mat = val;
        }
        
        void transpose()
        {
            // Skew = -1; Square matrix
            // Skew = 0; Skewed Row matrix
            // Skew = 1; Skewed Column matrix
            int square = isSquare();
            int skew = -1;
            if (square == 0)
            {
                skew = skewedMatrix();
                //cout << skew << endl;
            }
            int row_size = this->mat.size();
            int col_size = this->mat[0].size();
            int min_size = min(row_size, col_size);
            int max_size = max(row_size, col_size);
            int temp;
            
            for (int i = 0; i < min_size; i++)
            {
                for(int j = i + 1; j < min_size; j++)
                {
                    temp = this->mat[i][j];
                    this->mat[i][j] = this->mat[j][i];
                    this->mat[j][i] = temp;
                }
            }
            
            if (skew == 0)
            {
                for (int i = min_size; i < max_size; i++)
                {
                    for (int j = 0; j < min_size; j++)
                    {
                        this->mat[j].push_back(this->mat[i][j]);
                    }
                    this->mat.erase(this->mat.begin() + i);
                }
            }
            else if (skew == 1)
            {
                for (int i = min_size; i < max_size; i++)
                {
                    this->mat.push_back(vector<int>());
                    for (int j = 0; j < min_size; j++)
                    {
                        this->mat[i].push_back(this->mat[j][i]);
                    }
                }
                
                for (int i = 0; i < min_size; i++)
                {
                    this->mat[i].erase(this->mat[i].begin() + min_size);
                }
            }
            
            //cout << matrix.size() << " - " << matrix[0].size() << endl;
        }
        
        void transpose_2(Matrix mat)
        {
            int row_size = mat.row_size();
            int col_size = mat.col_size();
            
            int row = this->mat.size();
            
            if (row > 0)
            {
                for (int i = 0; i < row; i++)
                {
                    this->mat.erase(this->mat.begin() + i);
                }
            }
            
            for (int i = 0; i < col_size; i++)
            {
                this->mat.push_back(vector<int>());
                for (int j = 0; j < row_size; j++)
                {
                    this->mat[i].push_back(mat.matrix_element(j, i));
                }
            }
        }
        
        void multiplication(Matrix a, Matrix b)
        {
            int row_1 = a.row_size();
            int col_1 = a.col_size();
            int row_2 = b.row_size();
            int col_2 = b.col_size();
            //cout << row_1 << col_1 << row_2 << col_2 << endl;
            if (!isMultiplicationValid(a, b))
            {
                //Raise Exception
                return;
            }
            
            int row = this->mat.size();
            cout << row << endl;
            if (row > 0)
            {
                for (int i = 0; i < row; i++)
                {
                    this->mat.erase(this->mat.begin() + i);
                }
            }
            
            //Matrix ret_matrix;
            
            for (int i = 0; i < row_1; i++)
            {
                this->mat.push_back(vector<int>());
                for (int j = 0; j < col_2; j++)
                {
                    this->mat[i].push_back(0);
                }
            }
            
            for (int i = 0; i < row_1; i++)
            {
                for (int j = 0; j < col_2; j++)
                {
                    for (int k = 0; k < col_1; k++)
                    {
                        this->mat[i][j] += a.mat[i][k] * b.mat[k][j];
                    }
                }
            }
        }
        
        void print_matrix()
        {
            int row = this->mat.size();
            if (row == 0)
            {
                return;
            }
            int col = this->mat[0].size();
            
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << this->mat[i][j] << "\t";
                }
                cout << endl;
            }
        }
};

int main()
{
    matrix m1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    matrix m2 = {{1,2,3},{4,5,6},{7,8,9}};
    
    Matrix a(m1);
    Matrix b(m2);
    Matrix c;
    Matrix d;
    d.transpose_2(b);
    b.transpose();
    c.multiplication(b,a);
    c.print_matrix();
    cout << endl;
    d.print_matrix();
    cout << endl;
    b.print_matrix();
    
    return 0;
}
