#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream input("input_1_1.txt");
	std::string line;
	
	std::vector<int> collection;

	while (std::getline(input, line)) {
		int val = std::stoi(line.c_str());
		collection.push_back(val);
	}

	int index = 0;
	for(int i = index; i < collection.size(); i++) {

		int val0 = collection[i];
		for(int j = index; j < collection.size(); j++){
			if (i == j) continue;

			int val1 = collection[j];

			if((val0 + val1) == 2020) {
				std::cout << (val0 * val1) << std::endl;
			}
		}
		index++;
	}
}
