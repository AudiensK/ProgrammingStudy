#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

// 初始化棋盘
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE * 4 - 1; k++) {
                printf("-");
            }
            printf("\n");
        }
    }
}

// 检查是否有玩家获胜
bool checkWin(char board[SIZE][SIZE], char player) {
    // 检查行
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // 检查列
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // 检查对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// 检查是否平局
bool isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard(board);

    while (!gameOver) {
        printBoard(board);

        int row, col;
        printf("玩家 %c 的回合，请输入行和列 (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // 调整为0索引
        row--;
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("玩家 %c 获胜！\n", currentPlayer);
                gameOver = true;
            } else if (isDraw(board)) {
                printBoard(board);
                printf("平局！\n");
                gameOver = true;
            } else {
                // 切换玩家
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("无效的移动，请重试。\n");
        }
    }

    return 0;
}    