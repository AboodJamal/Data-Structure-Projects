#include<iostream>
#include"Stack.h"
#include"Vertor.h"
#include"DoublyCircularList.h"
#include"Martyr.h"
#include<string>
#include <fstream>
#include <cstring>  
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;




int stringToInt(const std::string& str) {
	int result = 0;
	bool isNegative = false;
	size_t i = 0;

	// Check for negative sign
	if (str[0] == '-') {
		isNegative = true;
		i = 1;
	}

	for (; i < str.length(); ++i) {
		if (isdigit(str[i])) {
			result = result * 10 + (str[i] - '0');
		}
		else {
			// Handle non-digit characters or invalid input here
			throw invalid_argument("Invalid input: non-digit character found.");
		}
	}

	return isNegative ? -result : result;
}

void removeSpaces(string& str) {
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void trimEndWhitespace(std::string& str) {
	size_t endpos = str.find_last_not_of(" \t\n\r\f\v");
	if (endpos != std::string::npos) {
		str = str.substr(0, endpos + 1);
	}
	else {
		// If the entire string is whitespace, make the string empty
		str.clear();
	}
}


/*string* split(string& text)
{
	int length = text.length();
	string* parts = new string[5];
	int k = 0;
	while (k != 5)
	{
		parts[k] = "                                                                              ";
		k++;
	}
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		//if (i==0 && text[0] == 39) continue;
		int j = 0;
		while (text[i] != ',')
		{
			parts[count][j] = text[i];
			i++;
			j++;

			if (text[i] == NULL)
				return parts;
		}
		trimEndWhitespace(parts[count]);
		count++;
	}
	return parts;
}*/