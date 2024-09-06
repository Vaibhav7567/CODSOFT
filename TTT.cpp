#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    return 0;
}

void switchPlayer() {
    if (currentPlayer == 1) {
        currentPlayer = 2;
        currentMarker = 'O';
    } else {
        currentPlayer = 1;
        currentMarker = 'X';
    }
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    while (markerP1 != 'X' && markerP1 != 'O') {
        cout << "Invalid marker! Please choose either X or O: ";
        cin >> markerP1;
    }

    currentPlayer = 1;
    currentMarker = markerP1;

    char markerP2 = (markerP1 == 'X') ? 'O' : 'X';

    drawBoard();
    int playerWon = 0;

    for (int i = 0; i < 9; i++) {
        cout << "It's Player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid move! Try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();
        playerWon = checkWinner();

        if (playerWon == 1) {
            cout << "Player 1 wins!" << endl;
            break;
        } else if (playerWon == 2) {
            cout << "Player 2 wins!" << endl;
            break;
        }


        if (currentPlayer == 1) {
            currentPlayer = 2;
            currentMarker = markerP2;
        } else {
            currentPlayer = 1;
            currentMarker = markerP1;
        }
    }

    if (playerWon == 0) {
        cout << "It's a draw!" << endl;
    }
}


int main() {
    char playAgain;
    do {
        char initialBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = initialBoard[i][j];
            }
        }
        game();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
