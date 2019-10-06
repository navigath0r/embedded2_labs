#include "CardReader.hpp"

int main()
{
	CardReader card;

	while(1)
	{
		
		card.getCardNumber();

		if(!card.getCardNumberStr().empty())
		{
			card.validateCardNumber();
		}
	}

	return 0;
}
