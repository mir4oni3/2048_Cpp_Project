#pragma once

#include "Constants.h"

void printBorder(int N, int width);

void printValues(int values[MAX_SIZE], int N, int width);

void print(int values[MAX_SIZE][MAX_SIZE], int N, int score);

void printLeaderboardBorder();

void printLeaderboardValue(char name[MAX_NICK_LENGTH], char score[MAX_NICK_LENGTH]);