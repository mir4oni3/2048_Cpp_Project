#pragma once

#include "Constants.h"

void sortByScore(char leaderboard[2 * (LEADERBOARD_SIZE + 1)][MAX_NICK_LENGTH], int N);

void addToLeaderboard(char nick[MAX_NICK_LENGTH], int N, int score);

void leaderboard();