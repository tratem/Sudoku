#include <iostream>
#include <random>
#include <chrono>
#define MATRIX_SIZE 10

using namespace std;

bool check_box(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_row(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

bool check_column(int matrix[MATRIX_SIZE][MATRIX_SIZE], int r, int c);

void print_puzzle(int matrix[MATRIX_SIZE][MATRIX_SIZE]);    

bool puzzle_generator(int matrix[MATRIX_SIZE][MATRIX_SIZE], chrono::seconds timeout);

void level_generator(int user_matrix[MATRIX_SIZE][MATRIX_SIZE], char difficulty);

int main()
{
    int matrix_solved[MATRIX_SIZE][MATRIX_SIZE] = {0}, user_matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
    char level;

    if (!puzzle_generator(matrix_solved,  chrono::seconds(10)))
    {
        return 0;
    }
    
    //copy matrix
    for (int i = 1; i < MATRIX_SIZE; i++) 
    {
        for (int j = 1; j < MATRIX_SIZE; j++) 
        {
            user_matrix[i][j] = matrix_solved[i][j];
        }
    }

    cout << "The puzzle has been successfully generated. Please select level: [E]asy, [M]edium, or [H]ard: ";
    cin >> level;
    while ((toupper(level)!='E') && (toupper(level)!='M') && (toupper(level)!='H'))
    {
        cout << "Invalid input! Please choose [E]asy, [M]edium, or [H]ard: " << endl;
        cin >> level;
    }

    level_generator(user_matrix, toupper(level));
}

void level_generator(int user_matrix[MATRIX_SIZE][MATRIX_SIZE], char level)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 9);
    int a, b;
    int hard_gen = 58 + dis(gen); //generatates the number of hidden elements for the hardes difficulty 
    if (level == 'E')
    {
        for (int i = 0; i < 28; i++)
        {
            a = dis(gen);
            b = dis(gen);
            user_matrix[a][b] = 0;
        }
    }
    else if (level == 'M')
    {
        for (int i = 0; i < 45; i++)
        {
            a = dis(gen);
            b = dis(gen);
            user_matrix[a][b] = 0;
        }
    }
    else if (level == 'H')
    {
        for (int i = 0; i < hard_gen; i++)
        {
            a = dis(gen);
            b = dis(gen);
            while (user_matrix[a][b] == 0)
            {
                a = dis(gen);
                b = dis(gen);
            }
            user_matrix[a][b] = 0;
        }
    }
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
            if (matrix[i][j] == 0)
                cout << "_  ";
            else 
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