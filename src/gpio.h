/***************************************************************************//**
 * @file  gpio.h was buttons.h from Silabs soc-btmest-switch example code
 * @brief gpio header file
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

#ifndef BUTTONS_H
#define BUTTONS_H



/*******************************************************************************
 * External signal definitions. These are used to signal button press events
 * from GPIO interrupt handler to application.
 ******************************************************************************/

#define EXT_SIGNAL_PB0_PRESS             0x01
#define EXT_SIGNAL_PB0_RELEASE           0x02
#define EXT_SIGNAL_PB1_PRESS             0x04
#define EXT_SIGNAL_PB1_RELEASE           0x08



/***************************************************************************//**
 * Button initialization. Configure pushbuttons PB0, PB1 as inputs.
 ******************************************************************************/
void button_init(void);

/***************************************************************************//**
 * Enable button interrupts for PB0, PB1. Both GPIOs are configured to trigger
 * an interrupt on the rising and falling edges + enable input glitch filtering.
 ******************************************************************************/
void enable_button_interrupts(void);



#endif /* BUTTONS_H */
