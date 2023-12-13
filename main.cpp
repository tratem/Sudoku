#include <iostream>
#include <ctime>
#define MATRIX_SIZE 10

using namespace std;

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

void print_puzzle(int matrix[MATRIX_SIZE][MATRIX_SIZE]);    

void puzzle_generator(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

    puzzle_generator(matrix);
    print_puzzle (matrix);
}

void puzzle_generator(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    srand(time(0));

    for (int blockRow = 0; blockRow < 3; blockRow++) 
    {
        for (int blockCol = 0; blockCol < 3; blockCol++) 
        {
            for (int i = 1; i <= 3; i++) 
            {
                for (int j = 1; j <= 3; j++) 
                {
                    matrix[blockRow * 3 + i][blockCol * 3 + j] = rand() % 9 + 1;
                    if ((check_box(matrix, blockRow * 3 + i , blockCol * 3 + j)) || (check_row(matrix, blockRow * 3 + i , blockCol * 3 + j)) || (check_column(matrix, blockRow * 3 + i , blockCol * 3 + j)))
                    {
                        j--;
                    }
                    print_puzzle(matrix);
                }
            }
        }
    }
}

void print_puzzle(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    cout << "PUZZLE: " << endl;
    for (int i = 1; i < MATRIX_SIZE; i++)
    {
        for (int j = 1; j < MATRIX_SIZE; j++)
        {
            cout << matrix[i][j] << "  " ;
            if ((j % 3 == 0) && (j != 9))
            {
                cout << "| ";
            }
        }
        if ((i % 3 == 0) && (i != 9))
        {
            cout << endl;
            for (int j = 0; j < 29; j++)
            {
                cout <<"_";
            }
        }
        cout << endl;
    }
}

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c)
{
    for (int i = 1; i < r; i++)
    {
        if (matrix[r][c] == matrix [i][c])
        {
            return true;
        }
    }
    return false;
}

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c)
{
    for (int i = 1; i < c; i++)
    {
        if (matrix[r][c] == matrix [r][i])
        {
            return true;
        }
    }
    return false;
}

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c)
{ 
    if (r <= 3 && c <= 3)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 3 && c <= 6)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 4; j <= 6; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 3 && c <= 9)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 7; j <= 9; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 6 && c <= 3)
    {
        for (int i = 4; i <= 6; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 6 && c <= 6)
    {
        for (int i = 4; i <= 6; i++)
        {
            for (int j = 4; j <= 6; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 6 && c <= 9)
    {
        for (int i = 4; i <= 6; i++)
        {
            for (int j = 7; j <= 9; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 9 && c <= 3)
    {
        for (int i = 7; i <= 9; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 9 && c <= 6)
    {
        for (int i = 7; i <= 9; i++)
        {
            for (int j = 4; j <= 6; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    else if (r <= 9 && c <= 9)
    {
        for (int i = 7; i <= 9; i++)
        {
            for (int j = 7; j <= 9; j++)
            {
                if ((matrix[r][c] == matrix [i][j]) && (r != i) && (c != j))
                {
                    return true;
                }
            }
        }
    }

    return false;
}