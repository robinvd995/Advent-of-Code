#pragma once

#include <string>

class BoardingPass {

public:
	BoardingPass(std::string data)
		: m_Data(data)
	{}

	int getCol();
	int getRow();

private:
	int decode(std::string data, char bt);
	std::string m_Data;

};

