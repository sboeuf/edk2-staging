/** @file
  The implementation for Redfish Platform Configuration application.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/DebugLib.h>
#include <Protocol/ShellParameters.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/NetLib.h>

UINTN  Argc;
CHAR16 **Argv;

EFI_GUID gRedfishServiceGuid = { 0x3fb208ac, 0x2185, 0x498c, { 0xbf, 0x46, 0xdc, 0x23, 0xda, 0x58, 0x7b, 0x55 } };

/**

  This function parse application ARG.

  @return Status
**/
EFI_STATUS
GetArg (
  VOID
  )
{
  EFI_STATUS                    Status;
  EFI_SHELL_PARAMETERS_PROTOCOL *ShellParameters;

  Status = gBS->HandleProtocol (
                  gImageHandle,
                  &gEfiShellParametersProtocolGuid,
                  (VOID**)&ShellParameters
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Argc = ShellParameters->Argc;
  Argv = ShellParameters->Argv;
  return EFI_SUCCESS;
}

/**

  This function print the help message.

**/
VOID
PrintHelp (
  VOID
  )
{
  Print (L"\n");
  Print (L"Format (Only Ipv4 Address is supported):\n");
  Print (L"RedfishPlatformConfig.efi -s HostIpAddress HostIpMask RedfishServiceIpAddress RedfishServiceIpMask RedfishServiceIpPort\n");
  Print (L"OR:\n");
  Print (L"RedfishPlatformConfig.efi -a RedfishServiceIpAddress RedfishServiceIpMask RedfishServiceIpPort\n");
  Print (L"\n");
}

/**
  The user Entry Point for Application. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.  
  @param[in] SystemTable    A pointer to the EFI System Table.
  
  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS    Status;
  RETURN_STATUS ReturnStatus;
  
  UINT8             HostIpAssignmentType;
  EFI_IPv4_ADDRESS  HostIpAddress;
  EFI_IPv4_ADDRESS  HostIpMask;
  EFI_IPv4_ADDRESS  RedfishServiceIpAddress;
  EFI_IPv4_ADDRESS  RedfishServiceIpMask;
  UINT16            RedfishServiceIpPort;
  CHAR16            *Pointer;

  Pointer = NULL;

  Status = GetArg();
  if (EFI_ERROR(Status)) {
    return Status;
  }

  //
  // Format is like :
  // RedfishPlatformConfig.efi -s HostIpAddress HostIpMask RedfishServiceIpAddress RedfishServiceIpMask RedfishServiceIpPort
  // RedfishPlatformConfig.efi -a RedfishServiceIpAddress RedfishServiceIpMask RedfishServiceIpPort
  //
  if (Argc != 7 && Argc != 5) {
    
    PrintHelp();
    return EFI_UNSUPPORTED;
  }

  if (StrCmp(Argv[1], L"-s") == 0) {

    HostIpAssignmentType = 1;

    Status = NetLibStrToIp4 (Argv[2], &HostIpAddress);
    if (EFI_ERROR (Status)) {
      PrintHelp();
      return Status;
    }
    Status = NetLibStrToIp4 (Argv[3], &HostIpMask);
    if (EFI_ERROR (Status)) { 
      PrintHelp();
      return Status;
    }
    Status = NetLibStrToIp4 (Argv[4], &RedfishServiceIpAddress);
    if (EFI_ERROR (Status)) { 
      PrintHelp();
      return Status;
    }
    Status = NetLibStrToIp4 (Argv[5], &RedfishServiceIpMask);
    if (EFI_ERROR (Status)) {  
      PrintHelp();
      return Status;
    }
    ReturnStatus = StrDecimalToUintnS (Argv[6], &Pointer, (UINTN *)&RedfishServiceIpPort);
    if (RETURN_ERROR (ReturnStatus)) { 
      PrintHelp();
      return Status;
    }

    Status = gRT->SetVariable (
                    L"HostIpAssignmentType",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (UINT8),
                    &HostIpAssignmentType
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"HostIpAddress",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &HostIpAddress
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"HostIpMask",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &HostIpMask
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpAddress",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &RedfishServiceIpAddress
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpMask",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &RedfishServiceIpMask
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpPort",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (UINT16),
                    &RedfishServiceIpPort
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Print (L"\n");
    Print (L"HostIpAssignmentType is Static!\n");
    Print (L"HostIpAddress: %s has been set Successfully!\n", Argv[2]);
    Print (L"HostIpMask: %s has been set Successfully!\n", Argv[3]);
    Print (L"RedfishServiceIpAddress: %s has been set Successfully!\n", Argv[4]);
    Print (L"RedfishServiceIpMask: %s has been set Successfully!\n", Argv[5]);
    Print (L"RedfishServiceIpPort: %s has been set Successfully!\n", Argv[6]);
    Print (L"Please Restart!\n");
    
  } else if (StrCmp(Argv[1], L"-a") == 0) {

    HostIpAssignmentType = 3;
    
    Status = NetLibStrToIp4 (Argv[2], &RedfishServiceIpAddress);
    if (EFI_ERROR (Status)) {
      PrintHelp();
      return Status;
    }
    Status = NetLibStrToIp4 (Argv[3], &RedfishServiceIpMask);
    if (EFI_ERROR (Status)) { 
      PrintHelp();
      return Status;
    }
    ReturnStatus = StrDecimalToUintnS (Argv[4], &Pointer, (UINTN *)&RedfishServiceIpPort);
    if (RETURN_ERROR (ReturnStatus)) { 
      PrintHelp();
      return Status;
    }

    Status = gRT->SetVariable (
                    L"HostIpAssignmentType",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (UINT8),
                    &HostIpAssignmentType
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpAddress",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &RedfishServiceIpAddress
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpMask",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (EFI_IPv4_ADDRESS),
                    &RedfishServiceIpMask
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Status = gRT->SetVariable (
                    L"RedfishServiceIpPort",
                    &gRedfishServiceGuid,
                    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                    sizeof (UINT16),
                    &RedfishServiceIpPort
                    );
    if (EFI_ERROR (Status)) { 
      return Status;
    }

    Print (L"\n");
    Print (L"HostIpAssignmentType is Auto!\n");
    Print (L"RedfishServiceIpAddress: %s has been set Successfully!\n", Argv[2]);
    Print (L"RedfishServiceIpMask: %s has been set Successfully!\n", Argv[3]);
    Print (L"RedfishServiceIpPort: %s has been set Successfully!\n", Argv[4]);
    Print (L"Please Restart!\n");
  } else if (StrCmp(Argv[1], L"-h") == 0 || StrCmp(Argv[1], L"-help") == 0) {

    PrintHelp();
  } else {

    PrintHelp();
    return EFI_UNSUPPORTED;
  }
  
  return EFI_SUCCESS;
}