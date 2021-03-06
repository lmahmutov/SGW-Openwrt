/***************************************************************************//**
 * @file
 * @brief Header file for RAIL Ram Modem Reconfiguration functionality
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef __CI_RMR_H__
#define __CI_RMR_H__

#include <stdint.h>
#include <stdbool.h>

#include "rail_types.h"
#include "em_device.h"

// General structure of Commands
// <command> <args> <help text>
// u=uint8, v=uint16, w=uint32, s=int32, b=string, ?=Anything, *=0 or more of previous
#define RMR_CI_COMMANDS                                                                                                                                                      \
  RAILCMD_SEPARATOR("RAM Modem Reconfiguration Commands")                                                                                                                    \
  RAILCMD_ENTRY("writeRmrStructure", "uvuw*", CI_writeRmrStructure, "This command should only be called by Simplicity Studio and not directly from the CI.")                 \
  RAILCMD_ENTRY("updateConfigurationPointer", "uvu", CI_updateConfigurationPointer, "This command should only be called by Simplicity Studio and not directly from the CI.") \
  RAILCMD_ENTRY("reconfigureModem", "", CI_reconfigureModem, "This command should only be called by Simplicity Studio and not directly from the CI.")                        \
  RAILCMD_SEPARATOR("End of RAM Modem Reconfiguration Commands") // Please keep this line below last RAILCMD_ENTRY

// Prototypes of CLI functions
#define RAILCMD_ENTRY(command, args, callback, helpStr) \
  extern void callback(int argc, char **argv);
#define RAILCMD_SEPARATOR(string) /* no-op */
RMR_CI_COMMANDS
#undef  RAILCMD_ENTRY
#undef  RAILCMD_SEPARATOR

/**
 * @enum RAIL_RMR_StructureIndex_t
 * @brief Identifier for each structure used during reconfiguration
 **/
RAIL_ENUM(RAIL_RMR_StructureIndex_t)
{
  RMR_STRUCT_PHY_INFO,
  RMR_STRUCT_IRCAL_CONFIG,
  RMR_STRUCT_MODEM_CONFIG,
  RMR_STRUCT_FRAME_TYPE_CONFIG,
  RMR_STRUCT_FRAME_LENGTH_LIST,
  RMR_STRUCT_FRAME_CODING_TABLE,
  RMR_STRUCT_CHANNEL_CONFIG_ATTRIBUTES,
  RMR_STRUCT_CHANNEL_CONFIG_ENTRY,
  RMR_STRUCT_CONV_DECODE_BUFFER,
};
#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RMR_STRUCT_PHY_INFO                  ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_PHY_INFO)
#define RMR_STRUCT_IRCAL_CONFIG              ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_IRCAL_CONFIG)
#define RMR_STRUCT_MODEM_CONFIG              ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_MODEM_CONFIG)
#define RMR_STRUCT_FRAME_TYPE_CONFIG         ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_FRAME_TYPE_CONFIG)
#define RMR_STRUCT_FRAME_LENGTH_LIST         ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_FRAME_LENGTH_LIST)
#define RMR_STRUCT_FRAME_CODING_TABLE        ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_FRAME_CODING_TABLE)
#define RMR_STRUCT_CHANNEL_CONFIG_ATTRIBUTES ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_CHANNEL_CONFIG_ATTRIBUTES)
#define RMR_STRUCT_CHANNEL_CONFIG_ENTRY      ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_CHANNEL_CONFIG_ENTRY)
#define RMR_STRUCT_CONV_DECODE_BUFFER        ((RAIL_RMR_StructureIndex_t) RMR_STRUCT_CONV_DECODE_BUFFER)
#endif //DOXYGEN_SHOULD_SKIP_THIS

#define RMR_STRUCT_NULL 255

/**
 * @enum RAIL_RMR_CommandArguments_t
 * @brief RAIL enum for the reconfiguration command arguments
 **/
RAIL_ENUM(RAIL_RMR_CommandArguments_t) {
  RMR_CI_RESPONSE,
  RMR_CI_RMR_STRUCTURE,
  RMR_CI_OFFSET,
  RMR_CI_COUNT,
  RMR_CI_DATA_START,
};
#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Self-referencing defines minimize compiler complaints when using RAIL_ENUM
#define RMR_CI_RESPONSE      ((RAIL_RMR_CommandArguments_t) RMR_CI_RESPONSE)
#define RMR_CI_RMR_STRUCTURE ((RAIL_RMR_CommandArguments_t) RMR_CI_RMR_STRUCTURE)
#define RMR_CI_OFFSET        ((RAIL_RMR_CommandArguments_t) RMR_CI_OFFSET)
#define RMR_CI_COUNT         ((RAIL_RMR_CommandArguments_t) RMR_CI_COUNT)
#define RMR_CI_DATA_START    ((RAIL_RMR_CommandArguments_t) RMR_CI_DATA_START)
#endif //DOXYGEN_SHOULD_SKIP_THIS

// Ram Modem Reconfiguration buffer sizes.
#define RMR_PHY_INFO_LEN 11
#define RMR_IRCAL_LEN 26
#define RMR_MODEM_CONFIG_LEN 256
#define RMR_FRAMETYPE_LEN 8
#define RMR_FRAME_LENGTH_LIST_LEN 8
#define RMR_ENTRYATTR_LEN 1
// HACK: Don't give room for a frame coding table on Lynx
#define RMR_FRAME_CODING_TABLE_LEN 640
#define RMR_CONV_DECODE_BUFFER_LEN 64
#define RMR_ARGUMENT_BUFFER_SIZE 10

#endif //__CI_RMR_H__
