#include "TreeMap.h"

bool TreeMap::isTree(int x, int y) {
	std::string line = m_Data[y];
	char c = line[x % m_LineWidth];
	return c == m_TreeChar;
}
