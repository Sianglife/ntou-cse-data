/*	Date: 2024/11/12
	Author: 黃鈺翔
	Description: 暗棋遊戲
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 4
#define WIDTH 8

int chessRank[HEIGHT][WIDTH];
int chessColor[HEIGHT][WIDTH];

//function prototypes
void shuffling(int intArray[], int N) {
	// 產生 0 到 N-1 的隨機序列
	int *used = calloc(N, sizeof(int)); // 產生長度N，記錄是否使用過的陣列，預設為0代表未使用，1代表已使用
	for (int i = 0; i < N; i++) {
		intArray[i] = rand() % N; // 隨機產生0到N-1的數字
		while (used[intArray[i]] == 1) { 
			// 如果該數字已使用過，則重新產生
			intArray[i] = rand() % N;
		}
		used[intArray[i]] = 1; // 標記該數字為已使用
	}
}
int getRank(int number) {
	// 輸入棋號，取得棋子的階級
	if (number == 0 || number == 16) {
		return 1;
	} else if (number == 1 || number == 2 || number == 17 || number == 18) {
		return 2;
	} else if (number == 3 || number == 4 || number == 19 || number == 20) {
		return 3;
	} else if (number == 5 || number == 6 || number == 21 || number == 22) {
		return 4;
	} else if (number == 7 || number == 8 || number == 23 || number == 24) {
		return 5;
	} else if (number == 9 || number == 10 || number == 25 || number == 26) {
		return 6;
	} else if (number >= 11 && number <= 15 || number >= 27 && number <=32) {
		return 7;
	}
	return -1;
}
int getColor(int number) {
	// 輸入棋號，取得棋子的顏色
	if (number >= 0 && number <=15) {
		return 0;
	} else if (number >= 16 && number <= 32) {
		return 1;
	}
	return -1;
}
void printBoard() {
	// 輸出棋盤
	printf("┌──┬──┬──┬──┬──┬──┬──┬──┐\n"); // 頭部
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("|"); // 行頭
			if (chessColor[i][j] == 0) {
				// 黑棋
				if (chessRank[i][j] == 1) {
					printf("將");
				} else if (chessRank[i][j] == 2) {
					printf("士");
				} else if (chessRank[i][j] == 3) {
					printf("象");
				} else if (chessRank[i][j] == 4) {
					printf("車");
				} else if (chessRank[i][j] == 5) {
					printf("馬");
				} else if (chessRank[i][j] == 6) {
					printf("包");
				} else if (chessRank[i][j] == 7) {
					printf("卒");
				}
			} else if (chessColor[i][j] == 1) {
				// 紅棋
				if (chessRank[i][j] == 1) {
					printf("帥");
				} else if (chessRank[i][j] == 2) {
					printf("仕");
				} else if (chessRank[i][j] == 3) {
					printf("相");
				} else if (chessRank[i][j] == 4) {
					printf("硨");
				} else if (chessRank[i][j] == 5) {
					printf("傌");
				} else if (chessRank[i][j] == 6) {
					printf("炮");
				} else if (chessRank[i][j] == 7) {
					printf("兵");
				}
			}
		}
		printf("|\n"); // 行尾
		if (i != HEIGHT - 1) {
			printf("├──┼──┼──┼──┼──┼──┼──┼──┤\n"); // 行間隔
		}
	}
	printf("└──┴──┴──┴──┴──┴──┴──┴──┘\n");	// 尾部
}

int main() {
	srand((unsigned int)time(NULL));
	int piece[WIDTH * HEIGHT];
	shuffling(piece, WIDTH * HEIGHT);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			chessRank[i][j] = getRank(piece[i * WIDTH + j]);
			chessColor[i][j] = getColor(piece[i * WIDTH + j]);
		}
	}
	printBoard();
	return 0;
}