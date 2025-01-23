#include <stdio.h>

#define BOARD_SIZE 8

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void clearBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void moveBishop(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (x + i < BOARD_SIZE && y + i < BOARD_SIZE) board[x + i][y + i] = 'B';
        if (x - i >= 0 && y + i < BOARD_SIZE) board[x - i][y + i] = 'B';
        if (x + i < BOARD_SIZE && y - i >= 0) board[x + i][y - i] = 'B';
        if (x - i >= 0 && y - i >= 0) board[x - i][y - i] = 'B';
    }
}

void moveRook(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[x][i] = 'R';
        board[i][y] = 'R';
    }
}

void moveQueen(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    moveBishop(board, x, y);
    moveRook(board, x, y);
    board[x][y] = 'Q';
}

void moveKnight(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    for (int i = 0; i < 8; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            board[newX][newY] = 'N';
        }
    }
}

void moveBishopRecursive(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int dx, int dy) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) return;
    board[x][y] = 'B';
    moveBishopRecursive(board, x + dx, y + dy, dx, dy);
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    clearBoard(board);

    // Exemplo de Movimentação do Bispo
    printf("Movimentação do Bispo:\n");
    moveBishop(board, 4, 4);
    printBoard(board);

    // Exemplo de Movimentação da Torre
    clearBoard(board);
    printf("Movimentação da Torre:\n");
    moveRook(board, 4, 4);
    printBoard(board);

    // Exemplo de Movimentação da Rainha
    clearBoard(board);
    printf("Movimentação da Rainha:\n");
    moveQueen(board, 4, 4);
    printBoard(board);

    // Exemplo de Movimentação do Cavalo
    clearBoard(board);
    printf("Movimentação do Cavalo:\n");
    moveKnight(board, 4, 4);
    printBoard(board);

    // Movimentação Recursiva do Bispo
    clearBoard(board);
    printf("Movimentação Recursiva do Bispo:\n");
    moveBishopRecursive(board, 4, 4, 1, 1);
    moveBishopRecursive(board, 4, 4, 1, -1);
    moveBishopRecursive(board, 4, 4, -1, 1);
    moveBishopRecursive(board, 4, 4, -1, -1);
    printBoard(board);

    return 0;
}
