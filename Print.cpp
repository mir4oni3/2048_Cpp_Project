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
* Cpp file containing printing function initializations
*
*/
#pragma once

#include <iostream>
#include "Constants.h"
#include "Helpers.h"
#include "Print.h"

// prints +---+---+ ... +---+
void printBorder(int N, int width) {
	for (int i = 0; i < N; i++) {
		std::cout << "+";
		for (int j = 0; j < width; j++) {
			std::cout << "-";
		}
	}
	std::cout << "+" << std::endl;
}

/*prints:
 | values[0] | values[1] | ...... | values[N-1] |
*/
void printValues(int values[MAX_SIZE], int N, int width) {
	for (int i = 0; i < N; i++) {
		std::cout << "|";

		int spaces = width - getLength(values[i]);//total number of spaces in cell
		int spaceCount = (spaces % 2 == 0) ? (spaces / 2) : (spaces / 2 + 1); // number of spaces before value
		for (int j = 0; j < spaceCount; j++) {
			std::cout << " ";
		}

		//print value(or space if value is 0)
		if (values[i] == 0) {
			std::cout << " ";
		}
		else {
			std::cout << values[i];
		}

		spaceCount = spaces / 2; // number of spaces after value
		for (int j = 0; j < spaceCount; j++) {
			std::cout << " ";
		}
	}
	std::cout << "|" << std::endl;
}

//prints whole board with borders and values
void print(int values[MAX_SIZE][MAX_SIZE], int N, int score) {
	int width = getLength(getBiggestElement(values, N)) + 2;
	for (int i = 0; i < N; i++) {
		printBorder(N, width);
		printValues(values[i], N, width);
	}
	printBorder(N, width);
	std::cout << "Score: " << score << std::endl;
}

// prints +----------+----+ (size according to MAX_NICK_LENGTH and MAX_SIZE constants)
void printLeaderboardBorder() {
	std::cout << '+';
	for (int i = 0; i < MAX_NICK_LENGTH; i++) {
		std::cout << '-';
	}
	std::cout << '+';
	for (int i = 0; i < MAX_SIZE; i++) {
		std::cout << '-';
	}
	std::cout << '+' << std::endl;
}

//prints     |    *nickname*    |  *score*  |      (size according to constants)
void printLeaderboardValue(char name[MAX_NICK_LENGTH], char score[MAX_NICK_LENGTH]) {
	std::cout << '|';
	int spaces = MAX_NICK_LENGTH - getLength(name);
	for (int i = 0; i < spaces / 2; i++) {
		std::cout << " ";
	}
	std::cout << name;
	int condition = (spaces % 2 == 0) ? (spaces / 2) : (spaces / 2 + 1);
	for (int i = 0; i < condition; i++) {
		std::cout << " ";
	}
	std::cout << '|';

	spaces = MAX_SIZE - getLength(score);
	condition = (spaces % 2 == 0) ? (spaces / 2) : (spaces / 2 + 1);
	for (int i = 0; i < spaces / 2; i++) {
		std::cout << " ";
	}
	std::cout << score;
	for (int i = 0; i < condition; i++) {
		std::cout << " ";
	}
	std::cout << "|" << std::endl;
}