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
* Header file for declaration of leaderboard functions
*
*/
#pragma once

#include "Constants.h"

void sortByScore(char leaderboard[2 * (LEADERBOARD_SIZE + 1)][MAX_NICK_LENGTH], int N);

void addToLeaderboard(char nick[MAX_NICK_LENGTH], int N, int score);

void leaderboard();