#include "PasswordEntry.h"

bool PasswordEntry::isValid0() {
	int charcount = 0;
	for( auto it = m_Password.cbegin(); it != m_Password.cend(); ++it ){
		if (*it == m_Char) charcount++;
	}
	return charcount >= m_Min && charcount <= m_Max;
}

bool PasswordEntry::isValid1() {
	return (m_Password[m_Min - 1] == m_Char) ^ (m_Password[m_Max - 1] == m_Char);
}

void PasswordEntry::decode(std::string entry) {
	char seperators[3] = { '-', ' ', ':' };
	int indices[3] = { 0, 0, 0 };
	int i = 0;
	int j = 0;
	for (auto it = entry.cbegin(); it != entry.cend(); ++it) {
		if(*it == seperators[j]){
			indices[j] = i;
			if (j++ == 3) break;
		}
		i++;
	}

	m_Min = std::stoi(entry.substr(0, indices[0]));
	m_Max = std::stoi(entry.substr(indices[0] + 1, indices[1] - indices[0]));
	m_Char = entry[indices[2] - 1];
	m_Password = entry.substr(indices[2] + 1);
}
