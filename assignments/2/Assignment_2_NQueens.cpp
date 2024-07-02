#include <iostream>
#include <stack>

const unsigned N = 5;

struct Square
{
    unsigned x;
    unsigned y;
    Square(unsigned x_i, unsigned y_i): x(x_i), y(y_i) {}
};

void drawBoard(std::stack<Square> stack);

int main()
{
    std::stack<Square> stack;
    stack.push(Square(0, 0));
    stack.push(Square(2, 1));
    stack.push(Square(4, 2));
    stack.push(Square(1, 3));
    stack.push(Square(3, 4));

    drawBoard(stack);

    return 0;
}

void drawBoard(std::stack<Square> stack)
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
    for (int i=0; i<N; i++)
    {
        std::cout << i << " | ";
        for (int j=0; j<N; j++)
        {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}