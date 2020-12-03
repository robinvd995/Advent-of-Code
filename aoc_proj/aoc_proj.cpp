#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "PasswordEntry.h"
#include "TreeMap.h"

int assignmnt0() {
	std::ifstream input("input_1_1.txt");
	std::string line;

	std::vector<int> collection;

	while (std::getline(input, line)) {
		int val = std::stoi(line.c_str());
		collection.push_back(val);
	}

	int index = 0;
	for (int i = index; i < collection.size(); i++) {

		int val0 = collection[i];
		for (int j = index; j < collection.size(); j++) {
			if (i == j) continue;

			int val1 = collection[j];

			if ((val0 + val1) == 2020) {
				return (val0 * val1);
			}
		}
		index++;
	}
}

int assignmnt1() {
	std::ifstream input("input_1_1.txt");
	std::string line;

	std::vector<int> collection;

	while (std::getline(input, line)) {
		int val = std::stoi(line.c_str());
		collection.push_back(val);
	}

	int index = 0;
	for (int i = index; i < collection.size(); i++) {

		int val0 = collection[i];
		for (int j = index + 1; j < collection.size(); j++) {

			int val1 = collection[j];
			for (int k = index + 2; k < collection.size(); k++) {

				int val2 = collection[k];

				if ((val0 + val1 + val2) == 2020) {
					return (val0 * val1 * val2);
				}
			}
		}
		index++;
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

int main()
{
	std::cout << "Assignment0: " << assignmnt0() << std::endl;
	std::cout << "Assignment1: " << assignmnt1() << std::endl;
	std::cout << "Assignment2: " << assignmnt2() << std::endl;
	std::cout << "Assignment3: " << assignmnt3() << std::endl;
	std::cout << "Assignment4: " << assignmnt4() << std::endl;
	std::cout << "Assignment5: " << assignmnt5() << std::endl;
}
