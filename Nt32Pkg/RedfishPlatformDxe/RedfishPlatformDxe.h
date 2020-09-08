/** @file
  RedfishPlatformDxe is to fill the SMBIOS table 42 before EndofDxe phase. And meanwhile, 
  RedfishPlatformDxe is required to produce the RedfishCredentialProtocol for the consumer
  to get the Redfish credential Info and to restrict Redfish access from UEFI side. 

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <IndustryStandard/SmBios.h>
#include <IndustryStandard/RedfishHostInterface.h>
#include <Guid/EventGroup.h>
#include <Protocol/Smbios.h>
#include <Protocol/RedfishCredential.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/PrintLib.h>

#include <Guid/GlobalVariable.h>
#include <Guid/ImageAuthentication.h>

/**
  Retrieve platform's Redfish authentication information.

  This functions returns the Redfish authentication method together with the user Id and
  password. 
  - For AuthMethodNone, the UserId and Password could be used for HTTP header authentication
    as defined by RFC7235.
  - For AuthMethodRedfishSession, the UserId and Password could be used for Redfish 
    session login as defined by  Redfish API specification (DSP0266).  

  Callers are responsible for and freeing the returned string storage. 
  
  @param[in]   This                Pointer to EFI_REDFISH_CREDENTIAL_PROTOCOL instance.
  @param[out]  AuthMethod          Type of Redfish authentication method.  
  @param[out]  UserId              The pointer to store the returned UserId string.  
  @param[out]  Password            The pointer to store the returned Password string.  

  @retval EFI_SUCCESS              Get the authentication information successfully.
  @retval EFI_ACCESS_DENIED        SecureBoot is disabled after EndOfDxe.
  @retval EFI_INVALID_PARAMETER    This or AuthMethod or UserId or Password is NULL.
  @retval EFI_OUT_OF_RESOURCES     There are not enough memory resources.
  @retval EFI_UNSUPPORTED          Unsupported authentication method is found.

**/
EFI_STATUS
EFIAPI
RedfishCredentialGetAuthInfo (
  IN     EFI_REDFISH_CREDENTIAL_PROTOCOL    *This,
     OUT EFI_REDFISH_AUTH_METHOD            *AuthMethod,
     OUT CHAR8                              **UserId,
     OUT CHAR8                              **Password
  );

/**
  Notify the Redfish service provide to stop provide configuration service to this platform.

  This function should be called when the platfrom is about to leave the safe environment.
  It will notify the Redfish service provider to abort all logined session, and prohibit 
  further login with original auth info. GetAuthInfo() will return EFI_UNSUPPORTED once this
  function is returned.  

  @param[in]   This                Pointer to EFI_REDFISH_CREDENTIAL_PROTOCOL instance.

  @retval EFI_SUCCESS              Service has been stoped successfully.
  @retval EFI_INVALID_PARAMETER    This is NULL.
  @retval Others                   Some error happened.

**/
EFI_STATUS
EFIAPI
RedfishCredentialStopService (
  IN     EFI_REDFISH_CREDENTIAL_PROTOCOL    *This
  );
