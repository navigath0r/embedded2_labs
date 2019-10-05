#include "CardReader.hpp"

int CardReader::getCardNumber()
{
	std::string swipe_path = "/dev/swipe";

	std::ifstream read_swipe(swipe_path);

	if(!read_swipe.is_open())
    {
        std::cerr << "Unable to open card number generator" << std::endl;
        return -1;
    }

    // read value  
    read_swipe >> this->card_number_str;
}

int CardReader::validateCardNumber()
{
	int card_number_int = std::stoi(this->card_number_str);
	int card_number_digits[15];
	int partial_checksum = 0;


	for (int i = 0; i++; i < 15)
	{
		card_number_digits[15-i] = static_cast<int>(floor(card_number_int / pow(10, i))) % 10;
	}

	for (int i = 14; i -= 2; i > 0)
	{
		if(card_number_digits[i] * 2 < 9)
		{
			partial_checksum += card_number_digits[i];
		}
		else
		{
			partial_checksum += card_number_digits[i] % 10 + card_number_digits[i] / 10 % 10;
		}
	}

	if (partial_checksum + card_number_digits[15] % 10 == 0)
	{
		std::cout << card_number_str;
	}
	else
	{
		logError();
	}
}

int CardReader::logError()
{
	std::string log_file_path = "/home/cardreader.log";

	std::ofstream log_file(log_file_path);

	if(!log_file.is_open())
    {
        std::cerr << "Unable to open " << log_file_path << std::endl;
        return -1;
    }

    std::chrono::system_clock::time_point error_timestamp_chrono = std::chrono::system_clock::now();
    std::time_t error_timestamp = std::chrono::system_clock::to_time_t(error_timestamp_chrono);

    log_file << "Wrong card number: " << this->card_number_str << " at " << error_timestamp << std::endl;
}