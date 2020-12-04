#include "Passport.h"

#include <iostream>
#include <algorithm>

unsigned int Passport::s_Comparable[7];
unsigned int Passport::s_CidNumber = 0;

Passport::ValidateFunc Passport::s_ValidationFuncs[7];
std::vector<std::string> Passport::s_ValidEyeColors;

static unsigned int passportStringToInt(std::string line) {
	return ((line[0] & 0xff) << 16) + ((line[1] & 0xff) << 8) + (line[2] & 0xff);
}

static int myStoi(std::string func, std::string s) {
	int value = 0;
	try {
		value = std::stoi(s);
	}
	catch(const std::exception& e){
		std::cout << "stoi error: " << func << s << std::endl;
	}
	return value;
}

static bool inRangeInt(int i, int min, int max) { return i >= min && i <= max; }

static bool validateByr(std::string s) { return s.length() == 4 && inRangeInt(myStoi("byr", s), 1920, 2002); }

static bool validateIyr(std::string s) { return s.length() == 4 && inRangeInt(myStoi("iyr", s), 2010, 2020); }

static bool validateEyr(std::string s) { return s.length() == 4 && inRangeInt(myStoi("eyr", s), 2020, 2030); }

static bool validateHgt(std::string s) { 
	std::string s0 = s.substr(s.length() - 2);
	
	if (s0 == "cm") {
		int value = myStoi("hgt", s.substr(0, s.length() - 2));
		return inRangeInt(value, 150, 193);
	}
	if (s0 == "in") {
		int value = myStoi("hgt", s.substr(0, s.length() - 2));
		return inRangeInt(value, 59, 76);
	}
	return false;
}

static bool validateHcl(std::string s) { 
	return s.length() == 7 && s[0] == '#' && s.find_first_not_of("0123456789abcdefABCDEF", 1) == std::string::npos;
}

static bool validateEcl(std::string s) { 
	return std::find(Passport::s_ValidEyeColors.begin(), Passport::s_ValidEyeColors.end(), s) != Passport::s_ValidEyeColors.end();
}

static bool validatePid(std::string s) { 
	return s.length() == 9 && s.find_first_not_of("0123456789", 1) == std::string::npos;
}

void Passport::initializeComparableMap() {
	s_CidNumber = passportStringToInt("cid");

	s_Comparable[0] = passportStringToInt("byr");
	s_Comparable[1] = passportStringToInt("iyr");
	s_Comparable[2] = passportStringToInt("eyr");
	s_Comparable[3] = passportStringToInt("hgt");
	s_Comparable[4] = passportStringToInt("hcl");
	s_Comparable[5] = passportStringToInt("ecl");
	s_Comparable[6] = passportStringToInt("pid");

	s_ValidationFuncs[0] = &validateByr;
	s_ValidationFuncs[1] = &validateIyr;
	s_ValidationFuncs[2] = &validateEyr;
	s_ValidationFuncs[3] = &validateHgt;
	s_ValidationFuncs[4] = &validateHcl;
	s_ValidationFuncs[5] = &validateEcl;
	s_ValidationFuncs[6] = &validatePid;

	s_ValidEyeColors.push_back("amb");
	s_ValidEyeColors.push_back("blu");
	s_ValidEyeColors.push_back("brn");
	s_ValidEyeColors.push_back("gry");
	s_ValidEyeColors.push_back("grn");
	s_ValidEyeColors.push_back("hzl");
	s_ValidEyeColors.push_back("oth");
}

void Passport::addLine(std::string line) {
	int seperatorIndex = 0;
	int lastIndex = 0;
	int lineLength = line.length();

	for(int i = 0; i < lineLength; i++) {
		char c = line[i];
		if (c == ':') seperatorIndex = i;

		int offset = (c == ' ') ? c = 1 : (i + 1 == lineLength) ? c = 0 : c = -1;

		//if (c == ' ' || i + 1 == lineLength) {
		if (offset > -1) {
			std::string keyentry = line.substr(lastIndex, seperatorIndex - lastIndex);
			unsigned int key = passportStringToInt(line.substr(lastIndex, seperatorIndex - lastIndex));
			std::string value = line.substr(seperatorIndex + 1, i - seperatorIndex - offset);
			m_Credentials[key] = value;
			lastIndex = i + 1;
		}
	}
}

bool Passport::validate0() {
	m_Credentials.erase(s_CidNumber);

	bool valid = m_Credentials.size() == 7;
	m_Credentials.clear();

	return valid;
}

bool Passport::isValid() {
	if (m_Credentials.size() != 7) return false;
	
	int valid = 0;
	for(int i = 0; i < 7; i++) {
		std::string value = m_Credentials[s_Comparable[i]];
		valid += s_ValidationFuncs[i](value);
	}

	return valid == 7;
}

bool Passport::validate1() {
	m_Credentials.erase(s_CidNumber);

	bool valid = isValid();
	m_Credentials.clear();

	return valid;
}
