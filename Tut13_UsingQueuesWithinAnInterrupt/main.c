
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include "io.h"
#include"init_external_interrupt.h"

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include"queue.h"


/*The Priorties of the system*/
#define PIN_OUTPUT			(tskIDLE_PRIORITY + 1)

/*The Prototypes of functions of tasks*/
static void pin_output( void *pvParameters );

/*Create the handle*/
xQueueHandle myhandle;



int main( void )
{
	/*Function to initialize the i/os*/
	Init_io();
	Init_External_Interrupt();

	/*The tasks of the system*/
	xTaskCreate( pin_output, ( signed char * ) "output",
			configMINIMAL_STACK_SIZE, NULL,
			PIN_OUTPUT, NULL );

	/*Specify the size of msg*/
	myhandle=xQueueCreate(1,sizeof(char*));

	/*Start the Scheduler*/
	vTaskStartScheduler();
	return 0;
}



static void pin_output( void *pvParameters)
{
	unsigned char port_value;
	while(1)
	{
		xQueueReceiveFromISR(myhandle, &port_value, portMAX_DELAY);
		output(port_value);
		//vTaskDelay(10);
	}
}

ISR (INT0_vect)
{
	unsigned char port_value;
	port_value=input();
	xQueueSend (myhandle,&port_value,portMAX_DELAY);
}

