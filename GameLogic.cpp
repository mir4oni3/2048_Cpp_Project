/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Miroslav Stoyanovski
* @idnumber 5MI0600195
* @compiler VC
*
* Cpp file containing game logic function initializations
*
*/
#pragma once

#include "GameLogic.h"
#include "Constants.h"
#include <iostream>
#include "Leaderboard.h"
#include "MainMenu.h"
#include "Print.h"

//checks if there are no possible moves
//if adjacent cells to values[i][j] are all different from values[i][j] for every i,j then gameEnd
bool gameEnd(int values[MAX_SIZE][MAX_SIZE], int N) {
	for (int i = 0; i < N - 1; i++) {

		if (values[i][N - 1] == 0 || values[N - 1][i] == 0 || values[N - 1][N - 1] == 0) {
			return false;
		}
		if (values[i][N - 1] == values[i + 1][N - 1]) {
			return false;
		}
		if (values[N - 1][i] == values[N - 1][i + 1]) {
			return false;
		}
		for (int j = 0; j < N - 1; j++) {
			if (values[i][j] == 0) {
				return false;
			}
			if (values[i][j] == values[i][j + 1] || values[i][j] == values[i + 1][j]) {
				return false;
			}
		}

	}
	return true;
}

void spawnNumber(int values[MAX_SIZE][MAX_SIZE], int N) {
	//keeps indices of free spots
	int freeSpacesI[MAX_SIZE * MAX_SIZE];
	int freeSpacesJ[MAX_SIZE * MAX_SIZE];
	int ind = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (values[i][j] == 0) { // finds free spots
				freeSpacesI[ind] = i;
				freeSpacesJ[ind] = j;
				ind++;
			}
		}
	}
	if (ind == 0) { // no free spots
		return;
	}

	srand(time(0)); //randomizes rand() seed
	int randomIndex = rand() % ind; //selects one of the indices of the free spots at random

	//10% chance to fill free spot with 4 and 90% chance to fill free spot with 2
	values[freeSpacesI[randomIndex]][freeSpacesJ[randomIndex]] = (rand() % 10 == 0) ? 4 : 2;
}

bool moveLeft(int values[MAX_SIZE][MAX_SIZE], int N) {
	bool moved = false;
	for (int i = 0; i < N; i++) {
		//move all values to the left without merging
		for (int j = 1; j < N; j++) {
			if (values[i][j] == 0) {
				continue;
			}
			int k = j - 1;
			while (k >= 0 && values[i][k] == 0) {
				moved = true;
				values[i][k] = values[i][k + 1];
				values[i][k + 1] = 0;
				k--;
			}
		}

		//combine equal adjacent tiles (merge)
		for (int j = 0; j < N - 1; j++) {
			if (values[i][j] != 0 && values[i][j] == values[i][j + 1]) {
				moved = true;
				values[i][j] *= 2;
				values[i][j + 1] = 0;
				for (int k = j + 1; k < N - 1; k++) {
					values[i][k] = values[i][k + 1];
					values[i][k + 1] = 0;
				}

			}
		}
	}
	return moved;
}

bool moveDown(int values[MAX_SIZE][MAX_SIZE], int N) {
	bool moved = false;
	for (int i = 0; i < N; i++) {
		//move all values to the bottom without merging
		for (int j = N - 1; j >= 0; j--) {
			if (values[j][i] == 0) {
				continue;
			}
			int k = j + 1;
			while (k < N && values[k][i] == 0) {
				moved = true;
				values[k][i] = values[k - 1][i];
				values[k - 1][i] = 0;
				k++;
			}
		}

		//combine equal adjacent tiles (merge)
		for (int j = N - 1; j >= 1; j--) {
			if (values[j][i] != 0 && values[j][i] == values[j - 1][i]) {
				moved = true;
				values[j][i] *= 2;
				values[j - 1][i] = 0;
				for (int k = j - 1; k >= 1; k--) {
					values[k][i] = values[k - 1][i];
					values[k - 1][i] = 0;
				}
			}
		}

	}
	return moved;
}

bool moveUp(int values[MAX_SIZE][MAX_SIZE], int N) {
	bool moved = false;
	for (int i = 0; i < N; i++) {
		//move all values to the top without merging
		for (int j = 1; j < N; j++) {
			if (values[j][i] == 0) {
				continue;
			}
			int k = j - 1;
			while (k >= 0 && values[k][i] == 0) {
				moved = true;
				values[k][i] = values[k + 1][i];
				values[k + 1][i] = 0;
				k--;
			}
		}

		//combine equal adjacent tiles (merge)
		for (int j = 0; j < N - 1; j++) {
			if (values[j][i] != 0 && values[j][i] == values[j + 1][i]) {
				moved = true;
				values[j][i] *= 2;
				values[j + 1][i] = 0;
				for (int k = j + 1; k < N - 1; k++) {
					values[k][i] = values[k + 1][i];
					values[k + 1][i] = 0;
				}
			}
		}
	}
	return moved;
}

bool moveRight(int values[MAX_SIZE][MAX_SIZE], int N) {
	bool moved = false;
	for (int i = 0; i < N; i++) {
		//move all values to the right without merging
		for (int j = N - 1; j >= 0; j--) {
			if (values[i][j] == 0) {
				continue;
			}
			int k = j + 1;
			while (k < N && values[i][k] == 0) {
				moved = true;
				values[i][k] = values[i][k - 1];
				values[i][k - 1] = 0;
				k++;
			}
		}

		//combine equal adjacent tiles (merge)
		for (int j = N - 1; j >= 1; j--) {
			if (values[i][j] != 0 && values[i][j] == values[i][j - 1]) {
				moved = true;
				values[i][j] *= 2;
				values[i][j - 1] = 0;
				for (int k = j - 1; k >= 1; k--) {
					values[i][k] = values[i][k - 1];
					values[i][k - 1] = 0;
				}

			}
		}
	}
	return moved;
}

bool move(int values[MAX_SIZE][MAX_SIZE], int N, char direction) {
	//cases other than w,a,s,d are impossible to enter this function
	switch (direction) {
	case 'w':
		return moveUp(values, N);
		break;
	case 's':
		return moveDown(values, N);
		break;
	case 'a':
		return moveLeft(values, N);
		break;
	case 'd':
		return moveRight(values, N);
		break;
	}
	return false;
}

int calculateScore(int values[MAX_SIZE][MAX_SIZE], int N) {
	int score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			score += values[i][j];
		}
	}
	return score;
}

void startGame() {
	std::cout << "Enter your nickname:" << std::endl;
	char nick[MAX_NICK_LENGTH];
	std::cin.ignore();
	std::cin.getline(nick, MAX_NICK_LENGTH);

	int N = 0;
	do {
		std::cout << "Enter dimension (" << MIN_SIZE << " <= N <= " << MAX_SIZE << "):" << std::endl;
		std::cin >> N;
	} while (N < MIN_SIZE || N > MAX_SIZE);

	int values[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			values[i][j] = 0; //sets initial zero values in every cell
		}
	}

	//spawn two inital numbers
	spawnNumber(values, N);
	spawnNumber(values, N);
	int score = calculateScore(values, N);

	//char[] is used instead of char to prevent entering more than one symbol
	// keeps direction (w,a,s,d) and terminating zero
	char direction[MAX_NICK_LENGTH] = " ";

	while (!gameEnd(values, N)) {
		bool check = false; //true if input is invalid
		do {
			print(values, N, score);
			if (check) {
				std::cout << "Invalid input!" << std::endl;
			}
			check = true; // input is invalid if there is more than one iteration of the do-while loop
			std::cout << "Enter direction (w,a,s,d): " << std::endl;
			std::cin >> direction;
		} while (direction[0] != 'a' && direction[0] != 's' && direction[0] != 'd' && direction[0] != 'w');

		if (move(values, N, direction[0])) { //move returns true if there are cells that moved
			spawnNumber(values, N);
			score = calculateScore(values, N);
		}
	}

	print(values, N, score);
	std::cout << "Game over!" << std::endl;
	addToLeaderboard(nick, N, score);

	mainMenu();
}