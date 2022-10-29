/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 */

#include "stm32f4xx.h"

#include "main.h"
#include "hardware.h"
#include "interface.h"

#include "pt/pt.h"
struct pt i2cPT;

uint8_t flags = 0;

void TIM4_IRQHandler(void) { // base time = 1ms
	CLEAR_TIM4_IFLAG;
	flags |= timeBase;
}

int main(void) {
	static uint32_t counter = 0;

	PT_INIT(&i2cPT);
	initHW();

	while(1) {
		if (flags & timeBase) {
			flags &= ~timeBase;
			// do everything you want every 1ms
			counter++;
		}
	}
}
