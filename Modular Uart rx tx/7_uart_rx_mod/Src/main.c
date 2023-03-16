#include "uart.h"

/*READ FROM UART RX AND TURN ON LED WHEN RX READS 3*/

char key;

void utx(char* string, int len)
{
	for(int i = 0; i < len; i++)
	{
		uart3_tx(*string);
		string++;
	}
}

int main()
{
	uart3_rxtx_init();



	while(1)
	{
		key = '+';
		key = uart3_rx();
		if (key == '3')
		{
			utx("Key is correct", 14);
		}
		else if (key != '+')
			utx("Key is incorrect", 16);

	}
}





