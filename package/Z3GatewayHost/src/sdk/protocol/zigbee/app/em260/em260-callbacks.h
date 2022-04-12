/***************************************************************************//**
 * @file
 * @brief EZSP stack callbacks header
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

#ifndef EM260_CALLBACKS_H
#define EM260_CALLBACKS_H
bool setCallbackQueueBufferLength(uint16_t requiredLength, bool extendOnly);
uint8_t getCallbackQueueByte(uint16_t index);
void setCallbackQueueByte(uint16_t index, uint8_t byte);
bool addToCallbackQueue(uint8_t *callback,
                        uint8_t callbackLength);
bool addToCallbackQueueExtended(uint8_t *callback,
                                uint8_t callbackLength,
                                EmberMessageBuffer buffer,
                                uint8_t *additionalData,
                                uint8_t additionalDataLength);
uint16_t findInCallbackQueue(uint16_t frameId, uint16_t index);
void writeLqiAndRssi(uint8_t *loc);
extern EmberMessageBuffer callbackQueue;
extern uint16_t callbackQueueLength;
extern uint16_t callbackQueueBufferLength;
extern bool callbackOverflow;
extern bool uartSynchCallbacks;

#endif //EM260_CALLBACKS_H
