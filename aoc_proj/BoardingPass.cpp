#include "BoardingPass.h"

#include <math.h>

int BoardingPass::getCol() {
	std::string s = m_Data.substr(7, 3);
	return decode(s, 'R');
}

int BoardingPass::getRow() {
	std::string s = m_Data.substr(0, 7);
	return decode(s, 'B');
}

int BoardingPass::decode(std::string data, char bt) {
	int size = data.length();

	int val = 0;
	for (int i = 0; i < size; i++) {
		int powr = powl(2, (int)(size - i - 1));
		val += powr * (bt == data[i]);
	}

	return val;
}
