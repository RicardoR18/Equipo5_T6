/**
	\file
	\brief
		This is a starter file to implement a function able to produce an accurate delay
		using the PIT module.

	\author J. Luis Pizano Escalante, luispizano@iteso.mx
				Ricardo Ruiz Ambriz
				Erick Luna
	\date	17/09/2018
 */


#include "MK64F12.h"
#include "PIT.h"
#include "NVIC.h"
#include "GPIO.h"
#include "Bits.h"

#define SYSTEM_CLOCK (21000000U)
#define DELAY (1.0F)
/*Delay const values
 * 0.5s
 * 0.5s
 * 0.125s
 * 0.001s
 * 0.0001s
 * 0.00001s
 * 0.000001s
 * */

void PIT0_IRQHandler(void);
int main(void)
{
	uint8_t pit_inter_status = FALSE;


	gpio_pin_control_register_t pin_control_register_bit_d_0 = GPIO_MUX1;
	gpio_pin_control_register_t pin_control_register_bit_b_21 = GPIO_MUX1;

	//Configure a pin and Blue Led as GPIOs
	GPIO_clock_gating(GPIO_B);
	GPIO_pin_control_register(GPIO_B, bit_21, &pin_control_register_bit_b_21);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT, bit_21);
	GPIO_clear_pin(GPIO_B, bit_21);

	GPIO_clock_gating(GPIO_D);
	GPIO_pin_control_register(GPIO_D, bit_0, &pin_control_register_bit_d_0);
	GPIO_data_direction_pin(GPIO_D,GPIO_OUTPUT, bit_0);
	GPIO_set_pin(GPIO_D, bit_0);
	//Enable global interrupts, PIT0 interrupt and its priority
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_10);
	NVIC_global_enable_interrupts;
	//Initialize PIT0
	PIT_clock_gating();
	PIT_enable();
	PIT_enable_interrupt(PIT_0);
	PIT_delay(PIT_0, SYSTEM_CLOCK, DELAY);
	PIT_CH_enable(PIT_0);

	for(;;) {

		do
		{
			pit_inter_status =  PIT_get_interrupt_flag_status();
		}
		while(FALSE == pit_inter_status);

		GPIO_toogle_pin(GPIO_D, bit_0);
		GPIO_toogle_pin(GPIO_B, bit_21);

		PIT_clear_interrupt_flag();

	}

	return 0;
}
