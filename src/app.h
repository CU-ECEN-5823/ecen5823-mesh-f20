/***************************************************************************//**
 * @file  app.h from Silabs soc-btmest-switch example code
 * @brief app header file
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

#ifndef APP_H
#define APP_H

#include <gecko_configuration.h>

// DOS, added to enable #define to control whether a publisher or a subscriber
// is implemented.
#include <src/ble_mesh_device_type.h>



/***************************************************************************//**
 * Main application code.
 * @param[in] pConfig  Pointer to stack configuration.
 ******************************************************************************/
void appMain(const gecko_configuration_t *pConfig);



#endif /* APP_H */
