#include<iostream>
using namespace std;

void Board(char board[3][3]){
   cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] <<endl;
   cout << "---+---+---" <<endl;
   cout << " " << board[1][0] << " | " << board[1][1]  << " | " << board[1][2]<< endl;
   cout << "---+---+---" <<endl;
   cout << " " << board[2][0] << " | " << board[2][1]  << " | " << board[2][2]<< endl;
   cout << "\n";
}

void makeMove(char board[3][3], char symbol) {
    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != '1' && board[row][col] != '2' && board[row][col] != '3' &&
        board[row][col] != '4' && board[row][col] != '5' && board[row][col] != '6' &&
        board[row][col] != '7' && board[row][col] != '8' && board[row][col] != '9') {
        cout << "Invalid move, try again." << endl;
        makeMove(board, symbol);
    } else {
        board[row][col] = symbol;
    }
}

bool checkWin(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char symbol = 'X';
    
    while (true) {
        Board(board);
        cout << "Player " << symbol << "'s turn." << endl;
        makeMove(board, symbol);

        if (checkWin(board, symbol)) {
            Board(board);
            cout << "Player " << symbol << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            Board(board);
            cout << "It's a draw!" << endl;
            break;
        }
        symbol = (symbol == 'X') ? 'O' : 'X';
        cout << "\n------------------------\n";
    }
        
    return 0;
}
    
