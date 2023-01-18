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
* Cpp file containing main function initialization
*
*/
#include <iostream>
#include "GameLogic.h"
#include "Leaderboard.h"

void mainMenu() {
	std::cout << "MAIN MENU:" << std::endl;
	std::cout << "1. Start game" << std::endl;
	std::cout << "2. Leaderboard" << std::endl;
	std::cout << "3. Quit" << std::endl;
	char choice = ' ';
	std::cin >> choice;
	switch (choice) {
	case '1':
		startGame();
		break;
	case '2':
		leaderboard();
		break;
	case '3':
		return;
	default:
		mainMenu();
	}
}