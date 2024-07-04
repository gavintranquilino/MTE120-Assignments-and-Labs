#include <iostream>
#include <fstream>
#include <stack>
#include <cmath>

const unsigned N = 8;

struct Square
{
    unsigned x;
    unsigned y;
    Square(unsigned x_i, unsigned y_i): x(x_i), y(y_i) {}
};

void drawBoard(std::stack<Square>& stack, std::ofstream& fileOut);
bool isSafe(unsigned row, unsigned col, std::stack<Square>& stack);
bool solve(std::stack<Square>& stack, unsigned row);

int main()
{
    std::stack<Square> stack;
    std::ofstream outputFile;

    outputFile.open("board.txt");

    if (!outputFile)
    {
        std::cout << "Unable to open file\n";
        return 1;
    }

    solve(stack, 0);
    drawBoard(stack, outputFile);

    outputFile.close();
    return 0;
}

void drawBoard(std::stack<Square>& stack, std::ofstream& fileOut)
{
    bool board[N][N] = {0};

    // load queen positions to array
    while(!stack.empty())
    {
        Square queen = stack.top();
        board[queen.x][queen.y] = 1;
        stack.pop();
    }

    // print board
    for (int row=0; row<N; row++)
    {
        std::cout << row << " | ";
        for (int col=0; col<N; col++)
        {
            std::cout << board[row][col] << ' ';
            fileOut << board[row][col] << ' ';
        }
        std::cout << '\n';
        fileOut << '\n';
    }
}

bool isSafe(unsigned row, unsigned col, std::stack<Square>& stack) 
{
    std::stack<Square> temp = stack;

    while (!temp.empty())
    {
        Square queen = temp.top();
        temp.pop();

        // diagonal check || column check
        if ((abs(queen.x - row) == abs(queen.y - col)) || (queen.y == col))
        {
            return false;
        }
    }

    return true;
}

bool solve(std::stack<Square>& stack, unsigned row)
{
    // base case (if looking at last row) or (if looking at last row on 3x3 grid) or (looking at last row on 2x2 grid):
    if (row == N || (row == 2 && N == 3) || (row == 1 && N == 2))
    {
        return true;
    }

    // recursive case:
    else
    {
        for (unsigned col=0; col<N; col++)
        {
            if (isSafe(row, col, stack))
            {
                std::cout << '(' << row << ", " << col << ')' << '\n';
                stack.push(Square(row, col));

                // check next row below, if not safe on any, then pop the last queen and find a new queen location
                if (solve(stack, row+1)) 
                {
                    return true;
                }

                std::cout << "GO BACK" << '\n';
                stack.pop(); // backtrack if solve from above failed (row != N)
            }            
        }
        return false;
    }
}