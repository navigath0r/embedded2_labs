#ifndef CARDREADER_HPP_
#define CARDREADER_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cmath>
#include <ctime>
#include <chrono>
#include <numeric>

class CardReader
{
private:
	std::string card_number_str = 0;

	int getCardNumber();
	int validateCardNumber();
	int logError();

public:
	CardReader();
	~CardReader();
};

#endif