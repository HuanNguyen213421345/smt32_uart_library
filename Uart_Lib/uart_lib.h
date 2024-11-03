#ifndef UART_LIB_H_
#define UART_LIB_H_
#include "stdint.h"
#include "stm32f1xx_hal.h"


void Uart_Print_String(UART_HandleTypeDef *huart,uint8_t *string);
void Uart_Library_System_Init(UART_HandleTypeDef *huart);
void Uart_Print_String_FR_Callback(UART_HandleTypeDef *huart);

#endif
