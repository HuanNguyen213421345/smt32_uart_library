/****************************************************************
 *Include Library
 ***************************************************************/
#include "uart_lib.h"
#include "string.h"
#include "usart.h"
#include "uart_lib.h"
#include "gpio.h"
#include "stdint.h"
//#include "stm32f1xx_hal.h"

/****************************************************************
 *Definition
 ***************************************************************/
#define RXBUFFER_SIZE 10U
#define RXBUFFER_LINE 4U
/****************************************************************
 *Variable
 ***************************************************************/
uint8_t RX_BUFFER[RXBUFFER_LINE][RXBUFFER_SIZE] = {0};
static uint32_t rx_index = 0;
uint32_t line_length[RXBUFFER_LINE] = {0};
uint32_t received_line = 0;
/****************************************************************
 *Static Function
 ***************************************************************/
static void Uart_Library_Peripheral_Init(UART_HandleTypeDef *huart)
{
	MX_GPIO_Init();

	MX_USART1_UART_Init();
	if(huart == &huart1){
		MX_USART1_UART_Init();
	}
	else if(huart == &huart2){
		MX_USART2_UART_Init();
	}
	else if(huart == &huart3){
		MX_USART3_UART_Init();
	}

	HAL_UART_Receive_IT(huart,&RX_BUFFER[rx_index][0], 10);
}
/****************************************************************
 *API Function
 ***************************************************************/
void Uart_Library_System_Init(UART_HandleTypeDef *huart)
{
	Uart_Library_Peripheral_Init(huart);

	Uart_Print_String(huart,(uint8_t *)"Init success\n");
	Uart_Print_String(huart,(uint8_t *)"Please put your file\n");

}

void Uart_Print_String(UART_HandleTypeDef *huart, uint8_t *string)
{
	HAL_UART_Transmit(huart, string, strlen((char*) string), 1000);
}

void Uart_Print_String_FR_Callback(UART_HandleTypeDef *huart)
{
	for(uint8_t i=0;i<RXBUFFER_LINE;i++)
	{
		HAL_UART_Transmit(huart,RX_BUFFER[i], line_length[i] , 1000);
		HAL_UART_Transmit(huart,(uint8_t*) "\n",1,1000);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	line_length[rx_index] = RXBUFFER_SIZE;
	received_line++;
	if (received_line >= RXBUFFER_LINE)
	    {
			Uart_Print_String_FR_Callback(huart);
	        received_line = 0;
	        rx_index = 0;
	    }
	    else
	    {
	        rx_index++;
	    }
	HAL_UART_Receive_IT(huart,&RX_BUFFER[rx_index][0], 10);
}




























