#pragma once

#include <string>

class PasswordEntry {

public:
	PasswordEntry(std::string entry) { decode(entry); }

	bool isValid0();
	bool isValid1();

private:
	void decode(std::string entry);

private:
	int m_Min;
	int m_Max;
	char m_Char;
	std::string m_Password;
};