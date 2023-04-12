#include "uart.h"

//VERY OPTIMIZABLE BY INTRODUCING INTERRUPTS

/*DHT 11 Comms is 40bit and around 4ms
 * Switching between */

/*		MCU SENDING OUT START SIGNAL
 *1. Default line state is Pulled high
 *2. MCU Pulls low for 20ms
 *3. MCU Pulls high and waits 20-40us for DHT response*/

/*		DHT RESPONSE SIGNAL
 *1. DHT sends out 80us LOW signal
 *2. DHT Pulls up for 80us
*/

/*		DHT DATA TRANSMISSION (occurs for each bit)
 *1. DHT Pulls LOW for 50us
 *2. DHT Pulls HIGH 26-28us (for a 0)
 *		OR
 *2. DHT Pulls HIGH 70us (for a 1)*/


/*Set pin as Open drain. The data line is pulled up by the module anyway
 *Pull LOW
 *Start systick
 */

int main()
{
	uart3_rxtx_init();



	while(1)
	{

	}
}





