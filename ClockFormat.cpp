#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>

//shows current date and time on current system
time_t currentTime = time(0);

//creates ltm pointer
tm* ltm = localtime(&currentTime);

//sets variables with pointer for cleaner look
int hourMil = ltm->tm_hour;
int minMil = ltm->tm_min;
int secMil = ltm->tm_sec;

void printNTimes(char c, int n) { //function to print border around clock
	std::cout << std::string(n, c);
}
void printClock() {
	//prints clock header
	std::cout << "*      12-Hour Clock     *" << "   " << "*      24-Hour Clock     *" << std::endl;
	if ((hourMil) > 12) { //adjusts 24 hour clock to 12hour clock if necessary and prints 12 hour clock
		int newHour = (hourMil) % 12;
		std::cout << std::setfill(' ') << std::setw(8) << std::left << "*";
		std::cout << std::right;
		std::cout << std::setfill('0') << std::setw(2) << newHour << ":";
		std::cout << std::setfill('0') << std::setw(2) << minMil << ":";
		std::cout << std::setfill('0') << std::setw(2) << secMil << " PM      *";
	}
	else {
		std::cout << std::setfill(' ') << std::setw(8) << std::left << "*";
		std::cout << std::right;
		std::cout << std::setfill('0') << std::setw(2) << hourMil << ":";
		std::cout << std::setfill('0') << std::setw(2) << minMil << ":";
		std::cout << std::setfill('0') << std::setw(2) << secMil;
		if (hourMil < 12) { //sets appropriate AM/PM settings
			std::cout << " AM      *";
		}
		else { //allows 12 noon to be represented as PM
			std::cout << " PM      *";
		}
	}
	//prints 24 hour clock
	std::cout << std::setfill(' ') << std::setw(12) << std::left << "   *";
	std::cout << std::right;
	std::cout << std::setfill('0') << std::setw(2) << hourMil << ":";
	std::cout << std::setfill('0') << std::setw(2) << minMil << ":";
	std::cout << std::setfill('0') << std::setw(2) << secMil << "        *" << std::endl;
}

void displayMenu() { //displays menu options for userinput
	std::cout << "* 1 - Add One Hour";
	std::cout << std::setfill(' ') << std::setw(8) << "*" << std::endl;
	std::cout << "* 2 - Add One Minute";
	std::cout << std::setfill(' ') << std::setw(6) << "*" << std::endl;
	std::cout << "* 3 - Add One Second";
	std::cout << std::setfill(' ') << std::setw(6) << "*" << std::endl;
	std::cout << "* 4 - Exit Program";
	std::cout << std::setfill(' ') << std::setw(8) << "*" << std::endl;
}

void runClock() {
	int userInput = 0;
	int n = 26;
	char c = '*';
	while (1) { //while true for an infinite loop until exited
		system("cls"); //clears screen for clean display
		printNTimes(c, n); //sets border
		std::cout << "   ";
		printNTimes(c, n); //sets border
		std::cout << std::endl;
		if (_kbhit()) { //if the keyboard is hit, then activates user input responses
			std::cin >> userInput;
			if (userInput == 1) {
				userInput = 1; //assigns userinput to 1
				hourMil += 1;
			}
			else if (userInput == 2) {
				userInput = 2; //assigns userinput to 2
				minMil += 1;
			}
			else if (userInput == 3) {
				userInput = 3; //assigns userinput to 3
				secMil += 1;
			}
			else {
				userInput = 4; //assigns userinput to 4
				break;
			}
		}
		if (secMil >= 60) { //disallows seconds to run over 59
			secMil = secMil % 60;
			minMil = minMil + 1;
		}
		if (minMil >= 60) { //disallows minutes to run over 59
			minMil = minMil % 60;
			hourMil = hourMil + 1;
		}
		if (hourMil >= 24) { //disallows hours to run over 23
			hourMil = hourMil % 24;
		}
		printClock(); //prints local time clock without userinput changes
		printNTimes(c, n); //sets border
		std::cout << "   ";
		printNTimes(c, n); //sets border
		std::cout << std::endl;
		printNTimes(c, n); //sets display border
		std::cout << std::endl;
		displayMenu(); //displays menu
		printNTimes(c, n); //sets display border
		++secMil;
		Sleep(1000); //delays loop for one second
	}
}