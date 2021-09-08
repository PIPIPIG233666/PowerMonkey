/*******************************************************************************
*  ______                            ______                 _
* (_____ \                          |  ___ \               | |
*  _____) )___   _ _ _   ____   ___ | | _ | |  ___   ____  | |  _  ____  _   _
* |  ____// _ \ | | | | / _  ) / __)| || || | / _ \ |  _ \ | | / )/ _  )| | | |
* | |    | |_| || | | |( (/ / | |   | || || || |_| || | | || |< (( (/ / | |_| |
* |_|     \___/  \____| \____)|_|   |_||_||_| \___/ |_| |_||_| \_)\____) \__  |
*                                                                       (____/
* Copyright (C) 2021 Ivan Dimkovic. All rights reserved.
*
* All trademarks, logos and brand names are the property of their respective
* owners. All company, product and service names used are for identification
* purposes only. Use of these names, trademarks and brands does not imply
* endorsement.
*
* SPDX-License-Identifier: Apache-2.0
* Full text of the license is available in project root directory (LICENSE)
*
* WARNING: This code is a proof of concept for educative purposes. It can
* modify internal computer configuration parameters and cause malfunctions or
* even permanent damage. It has been tested on a limited range of target CPUs
* and has minimal built-in failsafe mechanisms, thus making it unsuitable for
* recommended use by users not skilled in the art. Use it at your own risk.
*
*******************************************************************************/

#include <PiPei.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Protocol/MpService.h>
#include <Library/SynchronizationLib.h>

#include "MiniLog.h"

/*******************************************************************************
 * Globals
 ******************************************************************************/

extern EFI_MP_SERVICES_PROTOCOL* gMpServices;
extern UINTN gBootCpu;

/*******************************************************************************
 *
 ******************************************************************************/

#ifdef ENABLE_MINILOG_TRACING

/*******************************************************************************
 * InitTrace
 ******************************************************************************/

void InitTrace()
{
}


/*******************************************************************************
 *
 ******************************************************************************/

void MiniTrace(const UINT16 operId,
  const UINT16 data16,
  const UINT64 data64,
  const UINT8 dangerous)
{
  UINTN thisCpu;
  gMpServices->WhoAmI(gMpServices, &thisCpu);

  if (thisCpu == gBootCpu)
  {
    AsciiPrint("[0x%x][0x%x][0x%x][0x%llx]\n",
      operId,
      MINILOG_LOGCODE_TRACE,
      data16,
      data64);
  }
}


#endif