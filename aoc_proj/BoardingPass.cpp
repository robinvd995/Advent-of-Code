#include "BoardingPass.h"

#include <math.h>

int BoardingPass::getCol() {
	return decode(m_Data.substr(7, 3), 'R');
}

int BoardingPass::getRow() {
	return decode(m_Data.substr(0, 7), 'B');
}

int BoardingPass::decode(std::string data, char bt) {
	int size = data.length();

	int val = 0;
	for (int i = 0; i < size; i++) {
		val += pow(2, (size - i - 1)) * (bt == data[i]);
	}

	return val;
}
