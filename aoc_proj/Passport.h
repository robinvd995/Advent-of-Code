#pragma once

#include <map>
#include <string>
#include <vector>

class Passport {

public:
	Passport() {}

	static void initializeComparableMap();

	void addLine(std::string line);
	bool validate0();
	bool validate1();

	static std::vector<std::string> s_ValidEyeColors;

private:
	bool isValid();

	typedef bool(*ValidateFunc)(std::string);
	static ValidateFunc s_ValidationFuncs[];

	static unsigned int s_Comparable[];
	static unsigned int s_CidNumber;

	std::map<unsigned int, std::string> m_Credentials;

};