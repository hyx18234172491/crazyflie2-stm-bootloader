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
 */
#include "cpuid.h"


// void cpuidSetId(char *array) {
//     unsigned int cpuid = 0x1;
//     // 将每个字节存储到数组中
//     array[0] = (cpuid >> 24) & 0xFF; // 最高字节
//     array[1] = (cpuid >> 16) & 0xFF; // 第二高字节
//     array[2] = (cpuid >> 8) & 0xFF;  // 第三高字节
//     array[3] = (cpuid >> 0) & 0xFF;  // 最低字节
// }
unsigned short cpuidGetId()
{
  return 2;
}


int cpuIdGetFlashSize()
{
  return *((short*)(0x1FFFF7E0));
}