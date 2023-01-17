#pragma once

#include "Constants.h"

void mainMenu();

int getLength(int num);

int getLength(char str[MAX_NICK_LENGTH]);

void set(char to[MAX_NICK_LENGTH], char from[MAX_NICK_LENGTH]);

void set(char to[MAX_NICK_LENGTH], char from);

void set(char* to, int from);

char* biggerNumber(char* str1, char* str2);

bool equals(char* str1, char* str2);

int getBiggestElement(int values[MAX_SIZE][MAX_SIZE], int N);