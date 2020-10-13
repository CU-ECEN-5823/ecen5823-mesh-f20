/***************************************************************************
 * @file  gpio.c was buttons.c from Silabs soc-btmest-switch example code
 * @brief gpio implementation file
 *
 * @editor    Awesome Student, Awesome.Student@Colorado.edu
 * @date      Sep 15, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment10-AwesomeStudent
 * @due        Sep 18, 2020
 *
 * @resources  Utilized Silicon Labs' BT mesh v1.7 library
 *
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "hal-config.h"
#include "native_gecko.h"
#include <gpiointerrupt.h>
#include <em_rtcc.h>
#include <src/gpio.h>
#include "app_timer.h"




/*******************************************************************************
 * Button initialization. Configure pushbuttons PB0, PB1 as inputs.
 ******************************************************************************/
void button_init(void)
{
  // configure pushbutton PB0 and PB1 as inputs, with pull-up enabled
  GPIO_PinModeSet(BSP_BUTTON0_PORT, BSP_BUTTON0_PIN, gpioModeInputPull, 1);
//  GPIO_PinModeSet(BSP_BUTTON1_PORT, BSP_BUTTON1_PIN, gpioModeInputPull, 1);

}

/***************************************************************************//**
 * This is a callback function that is invoked each time a GPIO interrupt
 * in one of the pushbutton inputs occurs. Pin number is passed as parameter.
 *
 * @param[in] pin  Pin number where interrupt occurs
 *
 * @note This function is called from ISR context and therefore it is
 *       not possible to call any BGAPI functions directly. The button state
 *       change is signaled to the application using gecko_external_signal()
 *       that will generate an event gecko_evt_system_external_signal_id
 *       which is then handled in the main loop.
 ******************************************************************************/
void button_interrupt(uint8_t pin)
{
    // pin = BSP_BUTTON0_PIN for PB0
	// pin = BSP_BUTTON1_PIN for PB1
	//
	// edit #1
	// Add appropriate code to call gecko_external_signal() for PB0 press
	// and release. See gpio.h for external signal #defines



} // button_interrupt()



/*******************************************************************************
 * Enable button interrupts for PB0, PB1. Both GPIOs are configured to trigger
 * an interrupt on the rising and falling edges + enable input glitch filtering.
 * See the main board schematic for how the push buttons are connected.
 * The PB input value behaves this way:
 *
 * GPIO = 1  ---------+                 +-------------------------
 *                    |                 |
 *      = 0           +-----------------+
 *                    |                 |
 *                    v                 v
 *                    pressed           released
 *
 ******************************************************************************/
void enable_button_interrupts(void)
{

    // See: ./platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
	//
    // We can't write our own GPIO_EVEN_IRQHandler() and GPIO_ODD_IRQHandler()
	// routines because these are defined in this file. SiLabs has built an
	// ISR function registration and dispatching system. Don't know why?
	//
	// The calling sequence is:
	//
	//    GPIO_EVEN_IRQHandler() {
	//       iflags = GPIO_IntGetEnabled() & 0x00005555;
	//       GPIO_IntClear(iflags);
	//       GPIOINT_IRQDispatcher(iflags);
	//    }
	//
	//    GPIOINT_IRQDispatcher(iflags) {
	//       calls functions in table gpioCallbacks[ ] array
	//    }
	//
	//    We use GPIOINT_CallbackRegister() to place pointers to functions
	//    (known as callbacks) into the gpioCallbacks[ ] array

  GPIOINT_Init();

  /* configure interrupt for PB0 and PB1, both falling and rising edges */
  GPIO_ExtIntConfig(BSP_BUTTON0_PORT, BSP_BUTTON0_PIN, BSP_BUTTON0_PIN,
                    true, true, true);

//  GPIO_ExtIntConfig(BSP_BUTTON1_PORT, BSP_BUTTON1_PIN, BSP_BUTTON1_PIN,
//                   true, true, true);


  /* register the callback function that is invoked when interrupt occurs */
  GPIOINT_CallbackRegister(BSP_BUTTON0_PIN, button_interrupt);
//  GPIOINT_CallbackRegister(BSP_BUTTON1_PIN, button_interrupt);

} // enable_button_interrupts()



