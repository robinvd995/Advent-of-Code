#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

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

int main()
{
	std::cout << "Assignment0: " << assignmnt0() << std::endl;
	std::cout << "Assignment1: " << assignmnt1() << std::endl;
}

