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
* Cpp file containing helper function initializations
*
*/
#pragma once

#include "Constants.h"
#include "Helpers.h"

void mainMenu();

int getLength(int num) {
	if (num == 0) {
		return 1;
	}
	int length = 0;
	while (num != 0) {
		length++;
		num /= 10;
	}
	return length;
}

int getLength(char str[MAX_NICK_LENGTH]) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

void set(char to[MAX_NICK_LENGTH], char from[MAX_NICK_LENGTH]) {
	int ind = 0;
	while (from[ind] != '\0') {
		to[ind] = from[ind];
		ind++;
	}
	to[ind] = '\0';
}

void set(char to[MAX_NICK_LENGTH], char from) {
	to[0] = from;
	to[1] = '\0';
}

void set(char* to, int from) {
	int ind = 0;

	while (from != 0) {
		to[ind] = (from % 10) + '0';
		from /= 10;
		ind++;
	}

	for (int i = 0; i < ind / 2; i++) {
		int temp = to[i];
		to[i] = to[ind - i - 1];
		to[ind - i - 1] = temp;
	}

	to[ind] = '\0';
}

//returns pointer to the bigger number between str1 and str2
char* biggerNumber(char* str1, char* str2) {
	if (getLength(str1) > getLength(str2)) {
		return str1;
	}
	else if (getLength(str1) < getLength(str2)) {
		return str2;
	}

	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] < str2[i]) {
			return str2;
		}
		else if (str1[i] > str2[i]) {
			return str1;
		}
		i++;
	}

	return str1;
}

bool equals(char* str1, char* str2) {
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return false;
		}
		i++;
	}
	return str1[i] == str2[i];
}

int getBiggestElement(int values[MAX_SIZE][MAX_SIZE], int N) {
	int biggest = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (values[i][j] > biggest) {
				biggest = values[i][j];
			}
		}
	}
	return biggest;
}