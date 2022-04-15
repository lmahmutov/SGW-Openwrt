// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef SILABS_AF_ENDPOINT_CONFIG
#define SILABS_AF_ENDPOINT_CONFIG


// Fixed number of defined endpoints
#define FIXED_ENDPOINT_COUNT (2)


// Generated defaults
#if BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
0x09, 0xAC, 0x2F /* 0,Default value: Green Power,gpp functionality */, \
0xFF, 0xFF, 0xFF /* 3,Default value: Green Power,gpp active functionality */, \
0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39 /* 6,Default value: Green Power,gp link key */, \
  }
#else // ! BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
0x2F, 0xAC, 0x09 /* 0,Default value: Green Power,gpp functionality */, \
0xFF, 0xFF, 0xFF /* 3,Default value: Green Power,gpp active functionality */, \
0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39 /* 6,Default value: Green Power,gp link key */, \
  }
#endif // BIGENDIAN_CPU




// Generated attributes
#define GENERATED_ATTRIBUTES { \
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 0 / Basic / cluster revision*/\
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x03 } }, /* 1 / Basic / ZCL version*/\
    { 0x0007, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* 2 / Basic / power source*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 3 / Basic / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 4 / Identify / cluster revision*/\
    { 0x0000, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_WRITABLE), { (uint8_t*)0x0000 } }, /* 5 / Identify / identify time*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 6 / Identify / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 7 / Groups / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 8 / Scenes / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 9 / On/off / cluster revision*/\
    { 0x0000, ZCL_BOOLEAN_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 10 / On/off / on/off*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 11 / On/off / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 12 / Level Control / cluster revision*/\
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 13 / Level Control / current level*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 14 / Level Control / cluster revision*/\
    { 0x0000, ZCL_UTC_TIME_ATTRIBUTE_TYPE, 4, (ATTRIBUTE_MASK_WRITABLE|ATTRIBUTE_MASK_SINGLETON), { NULL } }, /* 15 / Time / time*/\
    { 0x0001, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_WRITABLE|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* 16 / Time / time status*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 17 / Time / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 18 / Over the Air Bootloading / cluster revision*/\
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00UL } }, /* 19 / Power Profile / total profile num*/\
    { 0x0001, ZCL_BOOLEAN_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 20 / Power Profile / multiple scheduling*/\
    { 0x0002, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x01 } }, /* 21 / Power Profile / energy formatting*/\
    { 0x0003, ZCL_BOOLEAN_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 22 / Power Profile / energy remote*/\
    { 0x0004, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_WRITABLE), { (uint8_t*)0x00 } }, /* 23 / Power Profile / schedule mode*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 24 / Power Profile / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 25 / Poll Control / cluster revision*/\
    { 0x0010, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x14 } }, /* 26 / Green Power / gpp max proxy table entries*/\
    { 0x0011, ZCL_LONG_OCTET_STRING_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0000 } }, /* 27 / Green Power / proxy table*/\
    { 0x0016, ZCL_BITMAP24_ATTRIBUTE_TYPE, 3, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)&(generatedDefaults[0]) } }, /* 28 / Green Power / gpp functionality*/\
    { 0x0017, ZCL_BITMAP24_ATTRIBUTE_TYPE, 3, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)&(generatedDefaults[3]) } }, /* 29 / Green Power / gpp active functionality*/\
    { 0x0022, ZCL_SECURITY_KEY_ATTRIBUTE_TYPE, 16, (ATTRIBUTE_MASK_WRITABLE|ATTRIBUTE_MASK_CLIENT), { (uint8_t*)&(generatedDefaults[6]) } }, /* 30 / Green Power / gp link key*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 31 / Green Power / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 32 / Color Control / cluster revision*/\
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 33 / Color Control / current hue*/\
    { 0x0001, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 34 / Color Control / current saturation*/\
    { 0x0002, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 35 / Color Control / remaining time*/\
    { 0x0003, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x616B } }, /* 36 / Color Control / current x*/\
    { 0x0004, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x607D } }, /* 37 / Color Control / current y*/\
    { 0x0007, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x00FA } }, /* 38 / Color Control / color temperature*/\
    { 0x0008, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x01 } }, /* 39 / Color Control / color mode*/\
    { 0x000F, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_WRITABLE), { (uint8_t*)0x00 } }, /* 40 / Color Control / color control options*/\
    { 0x0010, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0 } }, /* 41 / Color Control / number of primaries*/\
    { 0x4001, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x01 } }, /* 42 / Color Control / enhanced color mode*/\
    { 0x400A, ZCL_BITMAP16_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0019 } }, /* 43 / Color Control / color capabilities*/\
    { 0x400B, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 44 / Color Control / color temp physical min*/\
    { 0x400C, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0xFEFF } }, /* 45 / Color Control / color temp physical max*/\
    { 0x400D, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000UL } }, /* 46 / Color Control / couple color temp to level min-mireds*/\
    { 0x4010, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_WRITABLE), { (uint8_t*)0x0000UL } }, /* 47 / Color Control / start up color temperature mireds*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 48 / Color Control / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 49 / Illuminance Measurement / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 50 / Temperature Measurement / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 51 / Relative Humidity Measurement / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 52 / Occupancy Sensing / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 53 / IAS Zone / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 54 / Simple Metering / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 55 / Meter Identification / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 56 / Appliance Statistics / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 57 / Electrical Measurement / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 58 / Configuration Cluster / cluster revision*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 59 / MFGLIB Cluster / cluster revision*/\
  }


// Cluster function static arrays
#define GENERATED_FUNCTION_ARRAYS \
const EmberAfGenericClusterFunction emberAfFuncArrayIdentifyClusterServer[] = { (EmberAfGenericClusterFunction)emberAfIdentifyClusterServerInitCallback,(EmberAfGenericClusterFunction)emberAfIdentifyClusterServerAttributeChangedCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayOnOffClusterServer[] = { (EmberAfGenericClusterFunction)emberAfOnOffClusterServerInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayLevelControlClusterServer[] = { (EmberAfGenericClusterFunction)emberAfLevelControlClusterServerInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayTimeClusterServer[] = { (EmberAfGenericClusterFunction)emberAfTimeClusterServerInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayOtaBootloadClusterServer[] = { (EmberAfGenericClusterFunction)emberAfOtaBootloadClusterServerInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayColorControlClusterServer[] = { (EmberAfGenericClusterFunction)emberAfColorControlClusterServerInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArrayIasZoneClusterClient[] = { (EmberAfGenericClusterFunction)emberAfIasZoneClusterClientInitCallback}; \
const EmberAfGenericClusterFunction emberAfFuncArraySimpleMeteringClusterClient[] = { (EmberAfGenericClusterFunction)emberAfSimpleMeteringClusterClientDefaultResponseCallback}; \


// Clusters definitions
#define GENERATED_CLUSTERS { \
    { 0x0000, (EmberAfAttributeMetadata*)&(generatedAttributes[0]), 1, 0, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0000, (EmberAfAttributeMetadata*)&(generatedAttributes[1]), 3, 0, (CLUSTER_MASK_SERVER), NULL,  },    \
    { 0x0003, (EmberAfAttributeMetadata*)&(generatedAttributes[4]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0003, (EmberAfAttributeMetadata*)&(generatedAttributes[5]), 2, 4, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION| CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION), emberAfFuncArrayIdentifyClusterServer, },    \
    { 0x0004, (EmberAfAttributeMetadata*)&(generatedAttributes[7]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0005, (EmberAfAttributeMetadata*)&(generatedAttributes[8]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0006, (EmberAfAttributeMetadata*)&(generatedAttributes[9]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0006, (EmberAfAttributeMetadata*)&(generatedAttributes[10]), 2, 3, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayOnOffClusterServer, },    \
    { 0x0008, (EmberAfAttributeMetadata*)&(generatedAttributes[12]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0008, (EmberAfAttributeMetadata*)&(generatedAttributes[13]), 2, 3, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayLevelControlClusterServer, },    \
    { 0x000A, (EmberAfAttributeMetadata*)&(generatedAttributes[15]), 3, 0, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayTimeClusterServer, },    \
    { 0x0019, (EmberAfAttributeMetadata*)&(generatedAttributes[18]), 1, 2, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayOtaBootloadClusterServer, },    \
    { 0x001A, (EmberAfAttributeMetadata*)&(generatedAttributes[19]), 6, 7, (CLUSTER_MASK_SERVER), NULL,  },    \
    { 0x0020, (EmberAfAttributeMetadata*)&(generatedAttributes[25]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0300, (EmberAfAttributeMetadata*)&(generatedAttributes[32]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0300, (EmberAfAttributeMetadata*)&(generatedAttributes[33]), 16, 26, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayColorControlClusterServer, },    \
    { 0x0400, (EmberAfAttributeMetadata*)&(generatedAttributes[49]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0402, (EmberAfAttributeMetadata*)&(generatedAttributes[50]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0405, (EmberAfAttributeMetadata*)&(generatedAttributes[51]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0406, (EmberAfAttributeMetadata*)&(generatedAttributes[52]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0500, (EmberAfAttributeMetadata*)&(generatedAttributes[53]), 1, 2, (CLUSTER_MASK_CLIENT| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayIasZoneClusterClient, },    \
    { 0x0702, (EmberAfAttributeMetadata*)&(generatedAttributes[54]), 1, 2, (CLUSTER_MASK_CLIENT| CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION), emberAfFuncArraySimpleMeteringClusterClient, },    \
    { 0x0B01, (EmberAfAttributeMetadata*)&(generatedAttributes[55]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0B03, (EmberAfAttributeMetadata*)&(generatedAttributes[56]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0B04, (EmberAfAttributeMetadata*)&(generatedAttributes[57]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0xFC01, (EmberAfAttributeMetadata*)&(generatedAttributes[58]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0xFC02, (EmberAfAttributeMetadata*)&(generatedAttributes[59]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0021, (EmberAfAttributeMetadata*)&(generatedAttributes[26]), 6, 27, (CLUSTER_MASK_CLIENT), NULL,  },    \
  }


// Endpoint types
#define GENERATED_ENDPOINT_TYPES {        \
    { (EmberAfCluster*)&(generatedClusters[0]), 27, 81 }, \
    { (EmberAfCluster*)&(generatedClusters[27]), 1, 27 }, \
  }


// Cluster manufacturer codes
#define GENERATED_CLUSTER_MANUFACTURER_CODES {      \
{0x0019, 0x1002}, \
{0x001A, 0x1002}, \
  }
#define GENERATED_CLUSTER_MANUFACTURER_CODE_COUNT (2)

// Attribute manufacturer codes
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODES {      \
{0x00, 0x00} \
  }
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODE_COUNT (0)


// Largest attribute size is needed for various buffers
#define ATTRIBUTE_LARGEST (16)
// Total size of singleton attributes
#define ATTRIBUTE_SINGLETONS_SIZE (13)

// Total size of attribute storage
#define ATTRIBUTE_MAX_SIZE 108

// Array of endpoints that are supported
#define FIXED_ENDPOINT_ARRAY { 1, 242 }

// Array of profile ids
#define FIXED_PROFILE_IDS { 260, 41440 }

// Array of device ids
#define FIXED_DEVICE_IDS { 7, 97 }

// Array of device versions
#define FIXED_DEVICE_VERSIONS { 1, 1 }

// Array of endpoint types supported on each endpoint
#define FIXED_ENDPOINT_TYPES { 0, 1 }

// Array of networks supported on each endpoint
#define FIXED_NETWORKS { 0, 0 }


#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_DECLARATIONS \
  void emberAfPluginDeviceTableInitCallback(void); \
  void emberAfPluginTrustCenterNwkKeyUpdatePeriodicInitCallback(void); \
  void emberAfPluginGatewayRelayMqttInitCallback(void); \
  void emberAfPluginCommandRelayInitCallback(void); \
  void emberAfPluginGreenPowerClientInitCallback(void); \
  void emberAfPluginReportingInitCallback(void); \
  void emberAfPluginTransportMqttInitCallback(void); \
  void emberAfPluginCountersInitCallback(void); \


#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_CALLS \
  emberAfPluginDeviceTableInitCallback(); \
  emberAfPluginTrustCenterNwkKeyUpdatePeriodicInitCallback(); \
  emberAfPluginGatewayRelayMqttInitCallback(); \
  emberAfPluginCommandRelayInitCallback(); \
  emberAfPluginGreenPowerClientInitCallback(); \
  emberAfPluginReportingInitCallback(); \
  emberAfPluginTransportMqttInitCallback(); \
  emberAfPluginCountersInitCallback(); \


#define EMBER_AF_GENERATED_PLUGIN_NCP_INIT_FUNCTION_DECLARATIONS \
  void emberAfPluginNcpConfigurationNcpInitCallback(bool memoryAllocation); \
  void emberAfPluginAddressTableNcpInitCallback(bool memoryAllocation); \


#define EMBER_AF_GENERATED_PLUGIN_NCP_INIT_FUNCTION_CALLS \
  emberAfPluginNcpConfigurationNcpInitCallback(memoryAllocation); \
  emberAfPluginAddressTableNcpInitCallback(memoryAllocation); \


#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_DECLARATIONS \
  void emberAfPluginDeviceTableStackStatusCallback(EmberStatus status); \
  void emberAfPluginGreenPowerClientStackStatusCallback(EmberStatus status); \
  void emberAfPluginReportingStackStatusCallback(EmberStatus status); \
  void emberAfPluginConcentratorStackStatusCallback(EmberStatus status); \
  void emberAfPluginNetworkCreatorSecurityStackStatusCallback(EmberStatus status); \
  void emberAfPluginNetworkSteeringStackStatusCallback(EmberStatus status); \


#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_CALLS \
  emberAfPluginDeviceTableStackStatusCallback(status); \
  emberAfPluginGreenPowerClientStackStatusCallback(status); \
  emberAfPluginReportingStackStatusCallback(status); \
  emberAfPluginConcentratorStackStatusCallback(status); \
  emberAfPluginNetworkCreatorSecurityStackStatusCallback(status); \
  emberAfPluginNetworkSteeringStackStatusCallback(status); \


#define EMBER_AF_GENERATED_PLUGIN_MESSAGE_SENT_FUNCTION_DECLARATIONS \
  void emberAfPluginConcentratorMessageSentCallback( \
  EmberOutgoingMessageType type, \
  uint16_t indexOrDestination, \
  EmberApsFrame *apsFrame, \
  EmberStatus status, \
  uint16_t messageLength, \
  uint8_t *messageContents); \


#define EMBER_AF_GENERATED_PLUGIN_MESSAGE_SENT_FUNCTION_CALLS \
  emberAfPluginConcentratorMessageSentCallback( \
  type, \
  indexOrDestination, \
  apsFrame, \
  status, \
  messageLength, \
  messageContents); \


#define EMBER_AF_GENERATED_PLUGIN_ZDO_MESSAGE_RECEIVED_FUNCTION_DECLARATIONS \
  void emberAfPluginIasZoneClientZdoMessageReceivedCallback( \
  EmberNodeId sender, \
  EmberApsFrame* apsFrame, \
  uint8_t* message, \
  uint16_t length); \


#define EMBER_AF_GENERATED_PLUGIN_ZDO_MESSAGE_RECEIVED_FUNCTION_CALLS \
  emberAfPluginIasZoneClientZdoMessageReceivedCallback( \
  sender, \
  apsFrame, \
  message, \
  length); \


// Generated data for the command discovery
#define GENERATED_COMMANDS { \
    { 0x0000, 0x00, COMMAND_MASK_INCOMING_SERVER }, /* Basic / ResetToFactoryDefaults */ \
    { 0x0003, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Identify / Identify */ \
    { 0x0003, 0x00, COMMAND_MASK_OUTGOING_SERVER | COMMAND_MASK_INCOMING_CLIENT }, /* Identify / IdentifyQueryResponse */ \
    { 0x0003, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Identify / IdentifyQuery */ \
    { 0x0004, 0x00, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / AddGroup */ \
    { 0x0004, 0x01, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / ViewGroup */ \
    { 0x0004, 0x02, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / GetGroupMembership */ \
    { 0x0004, 0x03, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / RemoveGroup */ \
    { 0x0004, 0x04, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / RemoveAllGroups */ \
    { 0x0004, 0x05, COMMAND_MASK_OUTGOING_CLIENT }, /* Groups / AddGroupIfIdentifying */ \
    { 0x0005, 0x00, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / AddScene */ \
    { 0x0005, 0x01, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / ViewScene */ \
    { 0x0005, 0x02, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / RemoveScene */ \
    { 0x0005, 0x03, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / RemoveAllScenes */ \
    { 0x0005, 0x04, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / StoreScene */ \
    { 0x0005, 0x05, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / RecallScene */ \
    { 0x0005, 0x06, COMMAND_MASK_OUTGOING_CLIENT }, /* Scenes / GetSceneMembership */ \
    { 0x0006, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / Off */ \
    { 0x0006, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / On */ \
    { 0x0006, 0x02, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / Toggle */ \
    { 0x0008, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / MoveToLevel */ \
    { 0x0008, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / Move */ \
    { 0x0008, 0x02, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / Step */ \
    { 0x0008, 0x03, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / Stop */ \
    { 0x0008, 0x04, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / MoveToLevelWithOnOff */ \
    { 0x0008, 0x05, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / MoveWithOnOff */ \
    { 0x0008, 0x06, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / StepWithOnOff */ \
    { 0x0008, 0x07, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Level Control / StopWithOnOff */ \
    { 0x0019, 0x00, COMMAND_MASK_OUTGOING_SERVER }, /* Over the Air Bootloading / ImageNotify */ \
    { 0x0019, 0x02, COMMAND_MASK_OUTGOING_SERVER }, /* Over the Air Bootloading / QueryNextImageResponse */ \
    { 0x0019, 0x05, COMMAND_MASK_OUTGOING_SERVER }, /* Over the Air Bootloading / ImageBlockResponse */ \
    { 0x0019, 0x07, COMMAND_MASK_OUTGOING_SERVER }, /* Over the Air Bootloading / UpgradeEndResponse */ \
    { 0x001A, 0x00, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfileNotification */ \
    { 0x001A, 0x01, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfileResponse */ \
    { 0x001A, 0x02, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfileStateResponse */ \
    { 0x001A, 0x04, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfilesStateNotification */ \
    { 0x001A, 0x06, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / EnergyPhasesScheduleRequest */ \
    { 0x001A, 0x07, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / EnergyPhasesScheduleStateResponse */ \
    { 0x001A, 0x08, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / EnergyPhasesScheduleStateNotification */ \
    { 0x001A, 0x09, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfileScheduleConstraintsNotification */ \
    { 0x001A, 0x0A, COMMAND_MASK_OUTGOING_SERVER }, /* Power Profile / PowerProfileScheduleConstraintsResponse */ \
    { 0x0020, 0x00, COMMAND_MASK_OUTGOING_CLIENT }, /* Poll Control / CheckInResponse */ \
    { 0x0020, 0x00, COMMAND_MASK_INCOMING_CLIENT }, /* Poll Control / CheckIn */ \
    { 0x0020, 0x01, COMMAND_MASK_OUTGOING_CLIENT }, /* Poll Control / FastPollStop */ \
    { 0x0021, 0x00, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpNotificationResponse */ \
    { 0x0021, 0x01, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpPairing */ \
    { 0x0021, 0x02, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpProxyCommissioningMode */ \
    { 0x0021, 0x06, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpResponse */ \
    { 0x0021, 0x0A, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpSinkTableResponse */ \
    { 0x0021, 0x0B, COMMAND_MASK_INCOMING_CLIENT }, /* Green Power / GpProxyTableRequest */ \
    { 0x0300, 0x00, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveToHue */ \
    { 0x0300, 0x01, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveHue */ \
    { 0x0300, 0x02, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / StepHue */ \
    { 0x0300, 0x03, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveToSaturation */ \
    { 0x0300, 0x04, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveSaturation */ \
    { 0x0300, 0x05, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / StepSaturation */ \
    { 0x0300, 0x06, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveToHueAndSaturation */ \
    { 0x0300, 0x07, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveToColor */ \
    { 0x0300, 0x08, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveColor */ \
    { 0x0300, 0x09, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Color Control / StepColor */ \
    { 0x0300, 0x0A, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveToColorTemperature */ \
    { 0x0300, 0x47, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / StopMoveStep */ \
    { 0x0300, 0x4B, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / MoveColorTemperature */ \
    { 0x0300, 0x4C, COMMAND_MASK_INCOMING_SERVER }, /* Color Control / StepColorTemperature */ \
    { 0x0500, 0x00, COMMAND_MASK_OUTGOING_CLIENT }, /* IAS Zone / ZoneEnrollResponse */ \
    { 0x0500, 0x00, COMMAND_MASK_INCOMING_CLIENT }, /* IAS Zone / ZoneStatusChangeNotification */ \
    { 0x0500, 0x01, COMMAND_MASK_INCOMING_CLIENT }, /* IAS Zone / ZoneEnrollRequest */ \
    { 0x0501, 0x00, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / Arm */ \
    { 0x0501, 0x00, COMMAND_MASK_INCOMING_CLIENT }, /* IAS ACE / ArmResponse */ \
    { 0x0501, 0x01, COMMAND_MASK_INCOMING_CLIENT }, /* IAS ACE / GetZoneIdMapResponse */ \
    { 0x0501, 0x01, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / Bypass */ \
    { 0x0501, 0x02, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / Emergency */ \
    { 0x0501, 0x02, COMMAND_MASK_INCOMING_CLIENT }, /* IAS ACE / GetZoneInformationResponse */ \
    { 0x0501, 0x03, COMMAND_MASK_INCOMING_CLIENT }, /* IAS ACE / ZoneStatusChanged */ \
    { 0x0501, 0x03, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / Fire */ \
    { 0x0501, 0x04, COMMAND_MASK_INCOMING_CLIENT }, /* IAS ACE / PanelStatusChanged */ \
    { 0x0501, 0x04, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / Panic */ \
    { 0x0501, 0x05, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / GetZoneIdMap */ \
    { 0x0501, 0x06, COMMAND_MASK_INCOMING_SERVER }, /* IAS ACE / GetZoneInformation */ \
    { 0x0702, 0x00, COMMAND_MASK_INCOMING_CLIENT }, /* Simple Metering / GetProfileResponse */ \
    { 0x0702, 0x01, COMMAND_MASK_INCOMING_CLIENT }, /* Simple Metering / RequestMirror */ \
    { 0x0702, 0x02, COMMAND_MASK_INCOMING_CLIENT }, /* Simple Metering / RemoveMirror */ \
    { 0x0702, 0x03, COMMAND_MASK_INCOMING_CLIENT }, /* Simple Metering / RequestFastPollModeResponse */ \
    { 0x0702, 0x0C, COMMAND_MASK_INCOMING_CLIENT }, /* Simple Metering / SupplyStatusResponse */ \
    { 0x0B03, 0x00, COMMAND_MASK_OUTGOING_CLIENT }, /* Appliance Statistics / LogRequest */ \
    { 0x0B03, 0x01, COMMAND_MASK_OUTGOING_CLIENT }, /* Appliance Statistics / LogQueueRequest */ \
    { 0xFC01, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* Configuration Cluster / SetToken */ \
    { 0xFC01, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* Configuration Cluster / LockTokens */ \
    { 0xFC01, 0x02, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* Configuration Cluster / ReadTokens */ \
    { 0xFC01, 0x03, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* Configuration Cluster / UnlockTokens */ \
    { 0xFC02, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* MFGLIB Cluster / stream */ \
    { 0xFC02, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* MFGLIB Cluster / tone */ \
    { 0xFC02, 0x02, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_MANUFACTURER_SPECIFIC }, /* MFGLIB Cluster / rxMode */ \
  }
#define EMBER_AF_GENERATED_COMMAND_COUNT (93)

// Command manufacturer codes
#define GENERATED_COMMAND_MANUFACTURER_CODES {      \
{0x0056, 0x1002}, \
{0x0057, 0x1002}, \
{0x0058, 0x1002}, \
{0x0059, 0x1002}, \
{0x005A, 0x1002}, \
{0x005B, 0x1002}, \
{0x005C, 0x1002}, \
  }
#define GENERATED_COMMAND_MANUFACTURER_CODE_COUNT (7)


// Generated reporting configuration defaults
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS {\
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0006, 0x0000, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0008, 0x0000, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x001A, 0x0003, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x001A, 0x0004, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0300, 0x0000, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0300, 0x0001, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0300, 0x0003, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0300, 0x0004, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
  { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0300, 0x0007, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 }, \
}
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS_TABLE_SIZE (9)
#endif // SILABS_AF_ENDPOINT_CONFIG