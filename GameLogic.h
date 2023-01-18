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
* Header file for declaration of game logic functions
*
*/
#pragma once

#include "Constants.h"

bool gameEnd(int values[MAX_SIZE][MAX_SIZE], int N);

void spawnNumber(int values[MAX_SIZE][MAX_SIZE], int N);

bool moveLeft(int values[MAX_SIZE][MAX_SIZE], int N);

bool moveDown(int values[MAX_SIZE][MAX_SIZE], int N);

bool moveUp(int values[MAX_SIZE][MAX_SIZE], int N);

bool moveRight(int values[MAX_SIZE][MAX_SIZE], int N);

bool move(int values[MAX_SIZE][MAX_SIZE], int N, char direction);

int calculateScore(int values[MAX_SIZE][MAX_SIZE], int N);

void startGame();