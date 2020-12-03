#pragma once

#include <string>
#include <vector>

class TreeMap {

public:
	TreeMap() : m_LineWidth(0){}

	void addLine(std::string line) { m_Data.push_back(line); }
	void finalize() { m_LineWidth = m_Data[0].length(); }

	int getHeight() { return m_Data.size(); }

	bool isTree(int x, int y);
private:
	const char m_TreeChar = '#';

	std::vector<std::string> m_Data;

	int m_LineWidth;
};
