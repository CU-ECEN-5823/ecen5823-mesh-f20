/***************************************************************************
 * @file  node.h was switch.h from Silabs soc-btmest-switch example code
 * @brief node module header file
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
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>
#include "native_gecko.h"


/*******************************************************************************
   Public Macros and Definitions
*******************************************************************************/

#define OFF         0   ///< Set switch state to off
#define ON          1   ///< Set switch state to on


/***************************************************************************//**
 * Switch node initialization.
 * This is called at each boot if provisioning is already done.
 * Otherwise this function is called after provisioning is completed.
 ******************************************************************************/
void node_init(void);



/***************************************************************************//**
 * This function change the switch position and send it to the server.
 *
 * @param[in] position  Defines switch position change, possible values are
 *                      0 = OFF (released), 1 = ON (pressed)
 *
 ******************************************************************************/
void change_switch_position(uint8_t position);



/***************************************************************************//**
 *  Handling of message retransmission timer events.
 *
 *  @param[in] pEvt  Pointer to incoming event.
 ******************************************************************************/
void handle_retrans_timer_evt(struct gecko_cmd_packet *pEvt);



#endif /* SWITCH_H */
