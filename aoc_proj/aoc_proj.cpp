#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "PasswordEntry.h"
#include "TreeMap.h"
#include "Passport.h"
#include "BoardingPass.h"

int assignmnt0() {
	std::ifstream input("input_1.txt");
	std::string line;

	std::vector<int> collection;

	while (std::getline(input, line)) {
		int val = std::stoi(line.c_str());
		collection.push_back(val);
	}

	for (int i = 0; i < collection.size() - 1; i++) {
		for (int j = i + 1; j < collection.size(); j++) {

			if ((collection[i] + collection[j]) == 2020) {
				return (collection[i] * collection[j]);
			}
		}
	}
}

// Sucks ass
int assignmnt1() {
	std::ifstream input("input_1.txt");
	std::string line;

	std::vector<int> collection;

	while (std::getline(input, line)) {
		int val = std::stoi(line.c_str());
		collection.push_back(val);
	}

	for (int i = 0; i < collection.size() - 2; i++) {
		for (int j = i + 1; j < collection.size() - 1; j++) {
			for (int k = j + 2; k < collection.size(); k++) {

				if ((collection[i] + collection[j] + collection[k]) == 2020) {
					return (collection[i] * collection[j] * collection[k]);
				}
			}
		}
	}

}

int assignmnt2(){

	std::ifstream input("input_2.txt");
	std::string line;

	int i = 0;

	while (std::getline(input, line)) {
		PasswordEntry entry(line);
		i += entry.isValid0();
	}

	return i;
}

int assignmnt3() {

	std::ifstream input("input_2.txt");
	std::string line;

	int i = 0;

	while (std::getline(input, line)) {
		PasswordEntry entry(line);
		i += entry.isValid1();
	}

	return i;
}

unsigned int slope(TreeMap& map, int dx, int dy) {
	int pos[] = { 0,0 };
	int treeAmount = 0;
	while (pos[1] < map.getHeight()) {
		treeAmount += map.isTree(pos[0], pos[1]);

		pos[0] += dx;
		pos[1] += dy;
	}

	return treeAmount;
}

int assignmnt4(){
	std::ifstream input("input_3.txt");
	std::string line;
	
	TreeMap map;

	while (std::getline(input, line)) {
		map.addLine(line);
	}
	map.finalize();

	return slope(map, 3, 1);
}

unsigned int assignmnt5() {
	std::ifstream input("input_3.txt");
	std::string line;

	TreeMap map;

	while (std::getline(input, line)) {
		map.addLine(line);
	}
	map.finalize();

	return slope(map, 1, 1) * slope(map, 3, 1) * slope(map, 5, 1) * slope(map, 7, 1) * slope(map, 1, 2);
}

int assignmnt6() {
	std::ifstream input("input_4.txt");
	std::string line;

	Passport::initializeComparableMap();

	int i = 0;
	Passport curPassport;

	while (std::getline(input, line)) {
		if (line.length() == 0) i += curPassport.validate0();
		curPassport.addLine(line);
	}

	return i;
}

int assignmnt7() {
	std::ifstream input("input_4.txt");
	std::string line;

	Passport::initializeComparableMap();

	int i = 0;
	Passport curPassport;

	while (std::getline(input, line)) {
		if (line.length() == 0) i += curPassport.validate1();
		curPassport.addLine(line);
	}

	return i;
}

int assignmnt8() {

	std::ifstream input("input_5.txt");
	std::string line;

	int highestSeatId = -1;

	while (std::getline(input, line)) {
		BoardingPass pass(line);
		int col = pass.getCol();
		int row = pass.getRow();
		int seatId = (row * 8) + col;
		highestSeatId = seatId > highestSeatId ? seatId : highestSeatId;
	}
	return highestSeatId;
}

int assignmnt9() {
	std::ifstream input("input_5.txt");
	std::string line;

	std::vector<int> takenSeats;

	int highestSeatId = -1;

	while (std::getline(input, line)) {
		BoardingPass pass(line);
		int col = pass.getCol();
		int row = pass.getRow();
		int seatId = (row * 8) + col;
		takenSeats.push_back(seatId);
		highestSeatId = seatId > highestSeatId ? seatId : highestSeatId;
	}

	std::sort(takenSeats.begin(), takenSeats.end());
	for(int i = 0; i < takenSeats.size() - 1; i++) {
		int seatId = takenSeats[i];
		int nextSeatId = takenSeats[i + 1];
		if (seatId + 2 == nextSeatId) return seatId + 1;
	}

	return highestSeatId;
}

int main()
{
	// Day 1
	std::cout << "Assignment0: " << assignmnt0() << std::endl;
	std::cout << "Assignment1: " << assignmnt1() << std::endl;

	// Day 2
	std::cout << "Assignment2: " << assignmnt2() << std::endl;
	std::cout << "Assignment3: " << assignmnt3() << std::endl;

	// Day 3
	std::cout << "Assignment4: " << assignmnt4() << std::endl;
	std::cout << "Assignment5: " << assignmnt5() << std::endl;

	// Day 4
	std::cout << "Assignment6: " << assignmnt6() << std::endl;
	std::cout << "Assignment7: " << assignmnt7() << std::endl;

	// Day 5
	std::cout << "Assignment8: " << assignmnt8() << std::endl;
	std::cout << "Assignment9: " << assignmnt9() << std::endl;
}
