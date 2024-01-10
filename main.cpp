#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#define MATRIX_SIZE 10

using namespace std;

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

void print_puzzle(int matrix[MATRIX_SIZE][MATRIX_SIZE]);    

bool puzzle_generator(int matrix[MATRIX_SIZE][MATRIX_SIZE], chrono::seconds timeout);

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

    puzzle_generator(matrix,  chrono::seconds(5));
    print_puzzle (matrix);
}

bool puzzle_generator(int matrix[MATRIX_SIZE][MATRIX_SIZE], chrono::seconds timeout)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 9);

    auto start_time = chrono::steady_clock::now();
    auto elapsed_time = chrono::steady_clock::now() - start_time;

    for (int i = 1; i < MATRIX_SIZE; i++)
    {
        for (int j = 1; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = dis(gen);
            if ((check_box(matrix, i, j)) || (check_row(matrix, i, j)) || (check_column(matrix, i, j)))
            {
                if (j > 2)
                {
                    j -= 2;
                }
                else
                    j--;
            }

            elapsed_time = chrono::steady_clock::now() - start_time;

            if (elapsed_time >= timeout)
            {
                cout << "Puzzle generation unsuccessful";
                return false;
            }
        }
    }
    return true;
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
    int startRow = (r - 1) / 3 * 3 + 1;
    int startCol = (c - 1) / 3 * 3 + 1;

    for (int i = startRow; i <= startRow + 2; i++)
    {
        for (int j = startCol; j <= startCol + 2; j++)
        {
            if ((matrix[r][c] == matrix[i][j]) && (r != i) && (c != j))
            {
                return true;
            }
        }
    }

    return false;
}