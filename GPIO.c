/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	18/02/2019
	\todo
	    Interrupts are not implemented in this API implementation.
 */
#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"

uint8_t GPIO_clock_gating(gpio_port_name_t port_name)
{
	switch(port_name)/** Selecting the GPIO for clock enabling*/
			{
				case GPIO_A: /** GPIO A is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA; /** Bit 9 of SIM_SCGC5 is  set*/
					break;
				case GPIO_B: /** GPIO B is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTB; /** Bit 10 of SIM_SCGC5 is set*/
					break;
				case GPIO_C: /** GPIO C is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTC; /** Bit 11 of SIM_SCGC5 is set*/
					break;
				case GPIO_D: /** GPIO D is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTD; /** Bit 12 of SIM_SCGC5 is set*/
					break;
				case GPIO_E: /** GPIO E is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTE; /** Bit 13 of SIM_SCGC5 is set*/
					break;
				default: /**If doesn't exist the option*/
					return(FALSE);
			}// end switch
	/**Successful configuration*/
	return(TRUE);
}// end function

uint8_t GPIO_pin_control_register(gpio_port_name_t port_name, uint8_t pin,const gpio_pin_control_register_t*  pinControlRegister)
{

	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			PORTA->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_B:/** GPIO B is selected*/
			PORTB->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_C:/** GPIO C is selected*/
			PORTC->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_D:/** GPIO D is selected*/
			PORTD->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_E: /** GPIO E is selected*/
			PORTE->PCR[pin]= *pinControlRegister;
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
		}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_write_port(gpio_port_name_t port_name, uint32_t data)
{
	switch(port_name)
			{
			case GPIO_A:/** GPIO A is selected*/
				GPIOA->PDOR = data;
				break;
			case GPIO_B:/** GPIO B is selected*/
				GPIOB->PDOR = data;
				break;
			case GPIO_C:/** GPIO C is selected*/
				GPIOC->PDOR = data;
				break;
			case GPIO_D:/** GPIO D is selected*/
				GPIOD->PDOR = data;
				break;
			case GPIO_E: /** GPIO E is selected*/
				GPIOE->PDOR = data;
			default:/**If doesn't exist the option*/
				return (FALSE);
			break;
			}
		/**Successful configuration*/
}

uint32_t GPIO_read_port(gpio_port_name_t port_name)
{
	switch(port_name)
		{
			case GPIO_A: /**GPIO A is selected*/
				/**Returns all the GPIOA*/
				return (GPIOA->PDIR);
				break;
			case GPIO_B: /**GPIO B is selected*/
				/**Returns all the GPIOB*/
				return (GPIOB->PDIR);
				break;
			case GPIO_C: /**GPIO C is selected*/
				/**Returns all the GPIOC*/
				return (GPIOC->PDIR);
				break;
			case GPIO_D: /**GPIO D is selected*/
				/**Returns all the GPIOD*/
				return (GPIOD->PDIR);
				break;
			case GPIO_E: /**GPIO E is selected*/
				/**Returns all the GPIOE*/
				return (GPIOE->PDIR);
				break;
			default:/**If doesn't exist the option*/
				return(FALSE);
			break;
		}
	return(TRUE);
}

uint8_t GPIO_read_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
			{
				case GPIO_A: /**GPIO A is selected*/

					return (GPIOA->PDIR) & (1 << pin);
					break;
				case GPIO_B: /**GPIO B is selected*/

					return (GPIOB->PDIR)  & (1 << pin);
					break;
				case GPIO_C: /**GPIO C is selected*/

					return (GPIOC->PDIR)  & (1 << pin);
					break;
				case GPIO_D: /**GPIO D is selected*/

					return (GPIOD->PDIR)  & (1 << pin);
					break;
				case GPIO_E: /**GPIO E is selected*/

					return (GPIOE->PDIR)  & (1 << pin);
					break;
				default:/**If doesn't exist the option*/
					return(FALSE);
				break;
			}
	return(TRUE);
}

void GPIO_set_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
				{
				case GPIO_A:/** GPIO A is selected*/
					GPIOA->PSOR = (1 << pin);
					break;
				case GPIO_B:/** GPIO B is selected*/
					GPIOB->PSOR = (1 << pin);
					break;
				case GPIO_C:/** GPIO C is selected*/
					GPIOC->PSOR = (1 << pin);
					break;
				case GPIO_D:/** GPIO D is selected*/
					GPIOD->PSOR = (1 << pin);
					break;
				case GPIO_E: /** GPIO E is selected*/
					GPIOE->PSOR= (1 << pin);
				default:/**If doesn't exist the option*/
					return(FALSE);
				break;
				}
			/**Successful configuration*/

}

void GPIO_clear_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
					{
					case GPIO_A:/** GPIO A is selected*/
						GPIOA->PCOR = (1 << pin);
						break;
					case GPIO_B:/** GPIO B is selected*/
						GPIOB->PCOR = (1 << pin);
						break;
					case GPIO_C:/** GPIO C is selected*/
						GPIOC->PCOR = (1 << pin);
						break;
					case GPIO_D:/** GPIO D is selected*/
						GPIOD->PCOR = (1 << pin);
						break;
					case GPIO_E: /** GPIO E is selected*/
						GPIOE->PCOR= (1 << pin);
					default:/**If doesn't exist the option*/
						return(FALSE);
					break;
					}
				/**Successful configuration*/

}

void GPIO_toogle_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
						{
						case GPIO_A:/** GPIO A is selected*/
							GPIOA->PTOR = (1 << pin);
							break;
						case GPIO_B:/** GPIO B is selected*/
							GPIOB->PTOR = (1 << pin);
							break;
						case GPIO_C:/** GPIO C is selected*/
							GPIOC->PTOR = (1 << pin);
							break;
						case GPIO_D:/** GPIO D is selected*/
							GPIOD->PTOR = (1 << pin);
							break;
						case GPIO_E: /** GPIO E is selected*/
							GPIOE->PTOR= (1 << pin);
						default:/**If doesn't exist the option*/
							return(FALSE);
						break;
						}
					/**Successful configuration*/
				return(TRUE);
}

void GPIO_data_direction_port(gpio_port_name_t port_name ,uint32_t direction)
{
	switch(port_name)
		{
			case GPIO_A:/** GPIO A is selected*/
				GPIOA->PDDR |= direction;/*The PDDR is equal to the specific direction*/
				break;
			case GPIO_B:/** GPIO B is selected*/
				GPIOB->PDDR |= direction;/*The PDDR is equal to the specific direction*/
				break;
			case GPIO_C:/** GPIO C is selected*/
				GPIOC->PDDR |= direction;/*The PDDR is equal to the specific direction*/
				break;
			case GPIO_D:/** GPIO D is selected*/
				GPIOD->PDDR |= direction;/*The PDDR is equal to the specific direction*/
				break;
			case GPIO_E: /** GPIO E is selected*/
				GPIOE->PDDR |= direction;/*The PDDR is equal to the specific direction*/
				break;
			default:/**If doesn't exist the option*/
				return(FALSE);
				break;
		}
		/**Successful configuration*/
		return(TRUE);
}

void GPIO_data_direction_pin(gpio_port_name_t port_name, uint8_t state, uint8_t pin)
{
	switch(port_name)
						{
						case GPIO_A:/** GPIO A is selected*/
							GPIOA->PDDR |= (state << pin);
							break;
						case GPIO_B:/** GPIO B is selected*/
							GPIOB->PDDR |= (state << pin);
							break;
						case GPIO_C:/** GPIO C is selected*/
							GPIOC->PDDR |= (state << pin);
							break;
						case GPIO_D:/** GPIO D is selected*/
							GPIOD->PDDR |= (state << pin);
							break;
						case GPIO_E: /** GPIO E is selected*/
							GPIOE->PDDR |= (state << pin);
						default:/**If doesn't exist the option*/
							return(FALSE);
						break;
						}
					/**Successful configuration*/
				return(TRUE);
}



