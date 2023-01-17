#pragma once

#include "Constants.h"
#include "Helpers.h"
#include <fstream>
#include <iostream>
#include "Print.h"
#include "Leaderboard.h"

void sortByScore(char leaderboard[2 * (LEADERBOARD_SIZE + 1)][MAX_NICK_LENGTH], int N) {
	//current game nick and score are at the end of the array

	for (int i = 0; i < N - 2; i += 2) {
		if (N != 2 && equals(leaderboard[i], leaderboard[N - 2])) {
			//in case of two instances of same username, save the higher score
			set(leaderboard[i + 1], biggerNumber(leaderboard[i + 1], leaderboard[N - 1]));

			//"cut off" last two elements to remove duplicate scores
			set(leaderboard[N - 2], '\0');
			set(leaderboard[N - 1], '\0');
			N -= 2;
		}
	}

	//array is already sorted except last 2 elements(nick and score from current game)
	//sort
	for (int i = N - 3; i >= 1; i -= 2) {
		if (equals(leaderboard[i + 2], biggerNumber(leaderboard[i], leaderboard[i + 2]))) {//leaderboard[i+2]>leaderboard[i]
			char temp[MAX_NICK_LENGTH];

			set(temp, leaderboard[i]);
			set(leaderboard[i], leaderboard[i + 2]);
			set(leaderboard[i + 2], temp);

			set(temp, leaderboard[i - 1]);
			set(leaderboard[i - 1], leaderboard[i + 1]);
			set(leaderboard[i + 1], temp);
		}
	}
}

//update leaderboard with current game results
void addToLeaderboard(char nick[MAX_NICK_LENGTH], int N, int score) {
	char leaderboard[2 * (LEADERBOARD_SIZE + 1)][MAX_NICK_LENGTH];
	for (int i = 0; i < 2 * (LEADERBOARD_SIZE + 1); i++) {
		set(leaderboard[i], '\0');
	}

	//add previous scores from file to array
	char filename[17] = "leaderboard .txt";
	filename[11] = ((N % 10) + '0'); //10x10 is represented by leaderboard0.txt
	std::ifstream fileRead(filename);
	int ind = 0;
	while (fileRead) {
		char str[MAX_NICK_LENGTH];
		fileRead.getline(str, MAX_NICK_LENGTH);
		set(leaderboard[ind], str);
		ind++;
	}
	if (ind > 0) {
		ind--;
	}

	fileRead.close();

	//add current score to array
	set(leaderboard[ind], nick);
	set(leaderboard[ind + 1], score);
	ind += 2;

	//sort array
	sortByScore(leaderboard, ind);

	//write top scores to file (determined by LEADERBOARD_SIZE constant)
	std::ofstream fileWrite(filename);
	for (int i = 0; i < LEADERBOARD_SIZE * 2; i++) {
		if (leaderboard[i][0] == '\0') {
			break;
		}
		fileWrite << leaderboard[i] << "\n";
	}
	fileWrite.close();
}

void leaderboard() {
	int dim;
	do {
		std::cout << "Enter leaderboard dimension (" << MIN_SIZE << "<=dim<=" << MAX_SIZE << "): " << std::endl;
		std::cin >> dim;
	} while (dim < 4 || dim > 10);

	std::cout << std::endl << "Leaderboard:" << std::endl;

	char filename[17] = "leaderboard .txt";
	filename[11] = (dim % 10) + '0'; // 10x10 board is represented by leaderboard0.txt

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "No games have been played yet." << std::endl << std::endl;
		mainMenu();
		return;
	}

	printLeaderboardBorder();
	while (file) {
		char name[MAX_NICK_LENGTH];
		file.getline(name, MAX_NICK_LENGTH);

		if (name[0] == '\0') {
			break;
		}

		char score[MAX_NICK_LENGTH];
		file.getline(score, MAX_NICK_LENGTH);

		printLeaderboardValue(name, score);
		printLeaderboardBorder();
	}
	file.close();
	mainMenu();
}