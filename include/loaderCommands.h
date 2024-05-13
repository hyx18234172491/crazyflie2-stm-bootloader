/**
 *    ||        ____  _ __  ______
 * +------+    / __ )(_) /_/  ____/_________ ____  ____
 * | 0xBC |   / __ /  / __/ /    / ___/ __ `/_  / / _  \
 * +------+  / /_/ / / /_/ /___ / /  / /_/ / / /_/   __/
 *  ||  ||  /_____/_/\__/\____//_/   \__,_/ /___/ \___/
 *
 * CrazyLoader firmware
 *
 * Copyright (C) 2011-2013 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * loaderCommands.h - Define the structures of the commands parameters and returns
 */
#ifndef __LOADER_COMMANDS_H__
#define __LOADER_COMMANDS_H__

/* XXX: Protocol version has to be increased each time a command is
 * added or modified!
 */
#define PROTOCOL_VERSION 0x10

#define CPUID_LEN 12

/******* GetInfo ******/
#define CMD_GET_INFO 0x10
// #define CMD_GET_INFO_ACK 0x10
#define CMD_GET_INFO_ACK 0x20
//Parameters ... void
//Returns:
typedef struct {
  short pageSize; // 2 bytes
  short nBuffPages;
  short nFlashPages;
  short flashStart;
  // short  cpuId[CPUID_LEN];
  unsigned short cpuId;
  char version;
} __attribute__((__packed__)) GetInfoReturns_t;

/****** SetAddress ****/
#define CMD_SET_ADDRESS 0x11

//Parameters:
typedef struct {
  char address[5];
} __attribute__((__packed__)) SetAddressParameters_t;
//Returns ... void

/******* GetInfo ******/
#define CMD_GET_MAPPING 0x12
// #define CMD_GET_MAPPING_ACK 0x12
#define CMD_GET_MAPPING_ACK 0x22
//Parameters ... void
//Returns:
typedef struct {
  char mapping[6];
} __attribute__((__packed__)) GetMappingReturns_t;

/****** LoadBuffer ****/
#define CMD_LOAD_BUFFER 0x14
#define CMD_LOAD_BUFFER_SWARM 0x51
//Parameters:
typedef struct {
  unsigned short page;
  unsigned short address;
} __attribute__((__packed__)) LoadBufferParameters_t;
//Returns ... void

/****** ReadBuffer ****/
#define CMD_READ_BUFFER 0x15
#define CMD_READ_BUFFER_ACK 0x15
// #define CMD_READ_BUFFER_ACK 0x25
//Parameters:
typedef struct {
  unsigned short page;
  unsigned short address;
} __attribute__((__packed__)) ReadBufferParameters_t;
//Returns ... Same as parameters but with data

/****** WriteFlash ****/
#define CMD_WRITE_FLASH 0x18
#define CMD_WRITE_FLASH_SWARM 0x52
// #define CMD_WRITE_FLASH_ACK 0x18  
#define CMD_WRITE_FLASH_ACK 0x28  
//Parameters:
typedef struct {
  unsigned short bufferPage;
  unsigned short flashPage;
  unsigned short nPages;
} __attribute__((__packed__)) WriteFlashParameters_t;
//Returns ... Same as parameters but with data
typedef struct {
  char  done;
  unsigned char error;
  unsigned short cpuid;
} __attribute__((__packed__)) WriteFlashReturns_t;

#define CMD_FLASH_STATUS 0x19
#define CMD_FLASH_STATUS_ACK 0x19 
// #define CMD_FLASH_STATUS_ACK 0x29 
//Parameters ... void
//Returns:
typedef struct {
  unsigned char  done;
  unsigned char error;
} __attribute__((__packed__)) FlashStatusReturns_t;

/****** ReadBuffer ****/
#define CMD_READ_FLASH 0x1C
#define CMD_READ_FLASH_ACK 0x1C  
// #define CMD_READ_FLASH_ACK 0x2C  
//Parameters:
typedef struct {
  unsigned short page;
  unsigned short address;
} __attribute__((__packed__)) ReadFlashParameters_t;


/****** 查看当前是否有缺失 ****/
#define CMD_QUERY_IS_LOSS 0x31
#define CMD_QUERY_IS_LOSS_ACK 0x32

typedef struct {
  unsigned short is_loss;
} __attribute__((__packed__))QUERY_IS_LOSS_t;

//Returns ... Same as parameters but with data



#endif /* __LOADER_COMMANDS_H__ */
