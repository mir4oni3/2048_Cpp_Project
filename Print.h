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
* Header file for declaration of printing functions
*
*/
#pragma once

#include "Constants.h"

void printBorder(int N, int width);

void printValues(int values[MAX_SIZE], int N, int width);

void print(int values[MAX_SIZE][MAX_SIZE], int N, int score);

void printLeaderboardBorder();

void printLeaderboardValue(char name[MAX_NICK_LENGTH], char score[MAX_NICK_LENGTH]);