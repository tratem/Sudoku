#include <iostream>
#include <ctime>
#define MATRIX_SIZE 10

using namespace std;

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos);

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos);

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos);

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
    int pos;
    for (int i = 1; i < MATRIX_SIZE; i++)
    {
        for (int j = 1; j < MATRIX_SIZE; j++)
        {
            pos = i * 10 + j;
            matrix[i][j] = rand() % 9 + 1; 
            if ((check_box(matrix, pos)) || (check_row(matrix, pos)) || (check_column(matrix, pos)))
            {
                j--;
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

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos)
{
    int r = pos / 10;
    int c = pos % 10;
    for (int i = 1; i < r; i++)
    {
        if (matrix[r][c] == matrix [i][c])
        {
            return true;
        }
    }
    return false;
}

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos)
{
    int r = pos / 10;
    int c = pos % 10;
    for (int i = 1; i < c; i++)
    {
        if (matrix[r][c] == matrix [r][i])
        {
            return true;
        }
    }
    return false;
}

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int pos)
{ 
    int r = pos / 10;
    int c = pos % 10;

    if (r <= 3 && c <= 3)
    {
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
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
        for (int i = 1; i <= r; i++)
        {
            for (int j = 4; j <= c; j++)
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
        for (int i = 1; i <= r; i++)
        {
            for (int j = 7; j <= c; j++)
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
        for (int i = 4; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
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
        for (int i = 4; i <= r; i++)
        {
            for (int j = 4; j <= c; j++)
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
        for (int i = 4; i <= r; i++)
        {
            for (int j = 7; j <= c; j++)
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
        for (int i = 7; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
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
        for (int i = 7; i <= r; i++)
        {
            for (int j = 4; j <= c; j++)
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
        for (int i = 7; i <= r; i++)
        {
            for (int j = 7; j <= c; j++)
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