/** @file
  UEFI Shell based application for unit testing the SafeIntLib.

  Copyright (c) 2017, Microsoft Corporation

  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**/

#include "SafeIntLibUnitTests.h"

#define UNIT_TEST_APP_NAME        L"Int Safe Lib Unit Test Application"
#define UNIT_TEST_APP_VERSION     L"0.1"

//
// Conversion function tests:
//
UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  UINT8       Result;

  //
  // Positive UINT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeInt8ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  CHAR8       Result;

  //
  // Positive INT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeInt8ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  UINT16      Result;

  //
  // Positive UINT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeInt8ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToUint32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  UINT32      Result;

  //
  // Positive UINT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToUint32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeInt8ToUint32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToUintn (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  UINTN       Result;

  //
  // Positive UINT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToUintn (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToUintn (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINTN_ERROR, Result);

  Status = SafeInt8ToUintn (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8ToUint64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Operand;
  UINT64      Result;

  //
  // Positive UINT8 should result in just a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt8ToUint64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Negative number should result in an error status
  //
  Operand = (-56);
  Status = SafeInt8ToUint64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeInt8ToUint64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint8ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT8       Operand;
  INT8        Result;

  //
  // Operand <= 0x7F (MAX_INT8) should result in a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint8ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Operand larger than 0x7f should result in an error status
  //
  Operand = 0xaf;
  Status = SafeUint8ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeUint8ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint8ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT8       Operand;
  CHAR8       Result;

  //
  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.
  //

  //
  // Operand <= 0x7F (MAX_INT8) should result in a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint8ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Operand larger than 0x7f should result in an error status
  //
  Operand = 0xaf;
  Status = SafeUint8ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeUint8ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  INT8        Result;

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt16ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  Operand = (-35);
  Status = SafeInt16ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-35), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = 0x1234;
  Status = SafeInt16ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Operand = (-17835);
  Status = SafeInt16ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt16ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  CHAR8       Result;

  //
  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.
  //

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt16ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-35);
  Status = SafeInt16ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = 0x1234;
  Status = SafeInt16ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (-17835);
  Status = SafeInt16ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeInt16ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  UINT8       Result;

  //
  // If Operand is between 0 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt16ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = 0x1234;
  Status = SafeInt16ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Operand = (-17835);
  Status = SafeInt16ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeInt16ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  UINT16      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeInt16ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-17835);
  Status = SafeInt16ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeInt16ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToUint32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  UINT32      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeInt16ToUint32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-17835);
  Status = SafeInt16ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeInt16ToUint32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToUintn (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  UINTN       Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeInt16ToUintn (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-17835);
  Status = SafeInt16ToUintn (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINTN_ERROR, Result);

  Status = SafeInt16ToUintn (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16ToUint64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Operand;
  UINT64      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeInt16ToUint64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-17835);
  Status = SafeInt16ToUint64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeInt16ToUint64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Operand;
  INT8        Result;

  //
  // If Operand is <= MAX_INT8, it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint16ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5b5b);
  Status = SafeUint16ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeUint16ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is <= MAX_INT8, it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint16ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5b5b);
  Status = SafeUint16ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeUint16ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Operand;
  UINT8       Result;

  //
  // If Operand is <= MAX_UINT8 (0xff), it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeUint16ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5b5b);
  Status = SafeUint16ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint16ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16ToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Operand;
  INT16       Result;

  //
  // If Operand is <= MAX_INT16 (0x7fff), it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeUint16ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabab);
  Status = SafeUint16ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeUint16ToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  INT8        Result;

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt32ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  Operand = (-57);
  Status = SafeInt32ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-57), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeInt32ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeInt32ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt32ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt32ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-57);
  Status = SafeInt32ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (0x5bababab);
  Status = SafeInt32ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeInt32ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeInt32ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  UINT8       Result;

  //
  // If Operand is between 0 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt32ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-57);
  Status = SafeInt32ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Operand = (0x5bababab);
  Status = SafeInt32ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeInt32ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeInt32ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  INT16       Result;

  //
  // If Operand is between MIN_INT16 and MAX_INT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b5b;
  Status = SafeInt32ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b5b, Result);

  Operand = (-17857);
  Status = SafeInt32ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-17857), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeInt32ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeInt32ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeInt32ToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  UINT16      Result;

  //
  // If Operand is between 0 and MAX_UINT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeInt32ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-17857);
  Status = SafeInt32ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Operand = (0x5bababab);
  Status = SafeInt32ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeInt32ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeInt32ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToUint32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  UINT32      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeInt32ToUint32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-1537977259);
  Status = SafeInt32ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeInt32ToUint32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32ToUint64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Operand;
  UINT64      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeInt32ToUint64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-1537977259);
  Status = SafeInt32ToUint64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeInt32ToUint64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  INT8        Result;

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint32ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeUint32ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeUint32ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint32ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeUint32ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeUint32ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  UINT8       Result;

  //
  // If Operand is <= MAX_UINT8, then it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeUint32ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUint32ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint32ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  INT16       Result;

  //
  // If Operand is <= MAX_INT16, then it's a cast
  //
  Result = 0;
  Operand = 0x5bab;
  Status = SafeUint32ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUint32ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeUint32ToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  UINT16      Result;

  //
  // If Operand is <= MAX_UINT16, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeUint32ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUint32ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUint32ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32ToInt32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Operand;
  INT32       Result;

  //
  // If Operand is <= MAX_INT32, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeUint32ToInt32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUint32ToInt32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeUint32ToInt32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  INT8        Result;

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeIntnToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  Operand = (-53);
  Status = SafeIntnToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-53), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeIntnToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeIntnToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeIntnToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is between MIN_INT8 and MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeIntnToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-53);
  Status = SafeIntnToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (0x5bababab);
  Status = SafeIntnToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeIntnToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeIntnToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  UINT8       Result;

  //
  // If Operand is between 0 and MAX_UINT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeIntnToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeIntnToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeIntnToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeIntnToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  INT16       Result;

  //
  // If Operand is between MIN_INT16 and MAX_INT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5bab;
  Status = SafeIntnToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bab, Result);

  Operand = (-23467);
  Status = SafeIntnToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-23467), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeIntnToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeIntnToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeIntnToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  UINT16      Result;

  //
  // If Operand is between 0 and MAX_UINT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeIntnToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5bababab);
  Status = SafeIntnToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Operand = (-1537977259);
  Status = SafeIntnToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeIntnToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToUintn (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  UINTN       Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeIntnToUintn (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-1537977259);
  Status = SafeIntnToUintn (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINTN_ERROR, Result);

  Status = SafeIntnToUintn (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeIntnToUint64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INTN        Operand;
  UINT64      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeIntnToUint64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-1537977259);
  Status = SafeIntnToUint64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeIntnToUint64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  INT8        Result;

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUintnToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabab);
  Status = SafeUintnToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeUintnToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUintnToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabab);
  Status = SafeUintnToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeUintnToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  UINT8       Result;

  //
  // If Operand is <= MAX_UINT8, then it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeUintnToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabab);
  Status = SafeUintnToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUintnToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  INT16       Result;

  //
  // If Operand is <= MAX_INT16, then it's a cast
  //
  Result = 0;
  Operand = 0x5bab;
  Status = SafeUintnToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabab);
  Status = SafeUintnToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeUintnToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  UINT16      Result;

  //
  // If Operand is <= MAX_UINT16, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeUintnToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUintnToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUintnToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUintnToInt32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINTN       Operand;
  INT32       Result;

  //
  // If Operand is <= MAX_INT32, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeUintnToInt32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xabababab);
  Status = SafeUintnToInt32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeUintnToInt32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  INT8        Result;

  //
  // If Operand is between MIN_INT8 and  MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt64ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  Operand = (-37);
  Status = SafeInt64ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-37), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt64ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is between 0 and  MAX_INT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeInt64ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (-37);
  Status = SafeInt64ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand = (0x5babababefefefef);
  Status = SafeInt64ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeInt64ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  UINT8       Result;

  //
  // If Operand is between 0 and  MAX_UINT8 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeInt64ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeInt64ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  INT16       Result;

  //
  // If Operand is between MIN_INT16 and  MAX_INT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5bab;
  Status = SafeInt64ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bab, Result);

  Operand = (-23467);
  Status = SafeInt64ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-23467), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeInt64ToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  UINT16      Result;

  //
  // If Operand is between 0 and  MAX_UINT16 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeInt64ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeInt64ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToInt32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  INT32       Result;

  //
  // If Operand is between MIN_INT32 and  MAX_INT32 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeInt64ToInt32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  Operand = (-1537977259);
  Status = SafeInt64ToInt32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-1537977259), Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToInt32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToInt32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeInt64ToInt32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToUint32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  UINT32      Result;

  //
  // If Operand is between 0 and  MAX_UINT32 inclusive, then it's a cast
  //
  Result = 0;
  Operand = 0xabababab;
  Status = SafeInt64ToUint32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0x5babababefefefef);
  Status = SafeInt64ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Operand =  (-6605562033422200815);
  Status = SafeInt64ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeInt64ToUint32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64ToUint64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Operand;
  UINT64      Result;

  //
  // If Operand is non-negative, then it's a cast
  //
  Result = 0;
  Operand = 0x5babababefefefef;
  Status = SafeInt64ToUint64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5babababefefefef, Result);

  //
  // Otherwise should result in an error status
  //
  Operand =  (-6605562033422200815);
  Status = SafeInt64ToUint64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeInt64ToUint64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToInt8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  INT8        Result;

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint64ToInt8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToInt8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeUint64ToInt8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToChar8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  CHAR8       Result;

  // CHAR8 is typedefed as char, which by default is signed, but is
  // also allowed to be unsigned.

  //
  // If Operand is <= MAX_INT8, then it's a cast
  //
  Result = 0;
  Operand = 0x5b;
  Status = SafeUint64ToChar8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5b, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToChar8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeUint64ToChar8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToUint8 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  UINT8       Result;

  //
  // If Operand is <= MAX_UINT8, then it's a cast
  //
  Result = 0;
  Operand = 0xab;
  Status = SafeUint64ToUint8 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToUint8 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint64ToUint8 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToInt16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  INT16       Result;

  //
  // If Operand is <= MAX_INT16, then it's a cast
  //
  Result = 0;
  Operand = 0x5bab;
  Status = SafeUint64ToInt16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToInt16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeUint64ToInt16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToUint16 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  UINT16      Result;

  //
  // If Operand is <= MAX_UINT16, then it's a cast
  //
  Result = 0;
  Operand = 0xabab;
  Status = SafeUint64ToUint16 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToUint16 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUint64ToUint16 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToInt32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  INT32       Result;

  //
  // If Operand is <= MAX_INT32, then it's a cast
  //
  Result = 0;
  Operand = 0x5bababab;
  Status = SafeUint64ToInt32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5bababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToInt32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeUint64ToInt32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToUint32 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  UINT32      Result;

  //
  // If Operand is <= MAX_UINT32, then it's a cast
  //
  Result = 0;
  Operand = 0xabababab;
  Status = SafeUint64ToUint32 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xabababab, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToUint32 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeUint64ToUint32 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64ToInt64 (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Operand;
  INT64       Result;

  //
  // If Operand is <= MAX_INT64, then it's a cast
  //
  Result = 0;
  Operand = 0x5babababefefefef;
  Status = SafeUint64ToInt64 (Operand, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x5babababefefefef, Result);

  //
  // Otherwise should result in an error status
  //
  Operand = (0xababababefefefef);
  Status = SafeUint64ToInt64 (Operand, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Status = SafeUint64ToInt64 (Operand, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

//
// Addition function tests:
//
UNIT_TEST_STATUS
EFIAPI
TestSafeUint8Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT8       Augend;
  UINT8       Addend;
  UINT8       Result;

  //
  // If the result of addition doesn't overflow MAX_UINT8, then it's addition
  //
  Result = 0;
  Augend = 0x3a;
  Addend = 0x3a;
  Status = SafeUint8Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x74, Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0xab;
  Addend = 0xbc;
  Status = SafeUint8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint8Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Augend;
  UINT16      Addend;
  UINT16      Result;

  //
  // If the result of addition doesn't overflow MAX_UINT16, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a;
  Addend = 0x3a3a;
  Status = SafeUint16Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7474, Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0xabab;
  Addend = 0xbcbc;
  Status = SafeUint16Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUint16Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Augend;
  UINT32      Addend;
  UINT32      Result;

  //
  // If the result of addition doesn't overflow MAX_UINT32, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a3a3a;
  Addend = 0x3a3a3a3a;
  Status = SafeUint32Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x74747474, Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0xabababab;
  Addend = 0xbcbcbcbc;
  Status = SafeUint32Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeUint32Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Augend;
  UINT64      Addend;
  UINT64      Result;

  //
  // If the result of addition doesn't overflow MAX_UINT64, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a3a3a12121212;
  Addend = 0x3a3a3a3a12121212;
  Status = SafeUint64Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7474747424242424, Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0xababababefefefef;
  Addend = 0xbcbcbcbcdededede;
  Status = SafeUint64Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeUint64Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Augend;
  INT8        Addend;
  INT8        Result;

  //
  // If the result of addition doesn't overflow MAX_INT8
  // and doesn't underflow MIN_INT8, then it's addition
  //
  Result = 0;
  Augend = 0x3a;
  Addend = 0x3a;
  Status = SafeInt8Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x74, Result);

  Augend = (-58);
  Addend = (-58);
  Status = SafeInt8Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-116), Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0x5a;
  Addend = 0x5a;
  Status = SafeInt8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Augend = (-90);
  Addend = (-90);
  Status = SafeInt8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt8Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;

}

UNIT_TEST_STATUS
EFIAPI
TestSafeChar8Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  CHAR8       Augend;
  CHAR8       Addend;
  CHAR8       Result;

  //
  // If the result of addition doesn't overflow MAX_INT8
  // and doesn't underflow MIN_INT8, then it's addition
  //
  Result = 0;
  Augend = 0x3a;
  Addend = 0x3a;
  Status = SafeChar8Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x74, Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0x5a;
  Addend = 0x5a;
  Status = SafeChar8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Augend = 0x85;
  Addend = 58;
  Status = SafeChar8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Augend = 58;
  Addend = 0x85;
  Status = SafeChar8Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeChar8Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;

}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Augend;
  INT16       Addend;
  INT16       Result;

  //
  // If the result of addition doesn't overflow MAX_INT16
  // and doesn't underflow MIN_INT16, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a;
  Addend = 0x3a3a;
  Status = SafeInt16Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7474, Result);

  Augend = (-14906);
  Addend = (-14906);
  Status = SafeInt16Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-29812), Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0x5a5a;
  Addend = 0x5a5a;
  Status = SafeInt16Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Augend = (-23130);
  Addend = (-23130);
  Status = SafeInt16Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeInt16Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Augend;
  INT32       Addend;
  INT32       Result;

  //
  // If the result of addition doesn't overflow MAX_INT32
  // and doesn't underflow MIN_INT32, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a3a3a;
  Addend = 0x3a3a3a3a;
  Status = SafeInt32Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x74747474, Result);

  Augend = (-976894522);
  Addend = (-976894522);
  Status = SafeInt32Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-1953789044), Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0x5a5a5a5a;
  Addend = 0x5a5a5a5a;
  Status = SafeInt32Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Augend = (-1515870810);
  Addend = (-1515870810);
  Status = SafeInt32Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeInt32Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64Add (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Augend;
  INT64       Addend;
  INT64       Result;

  //
  // If the result of addition doesn't overflow MAX_INT64
  // and doesn't underflow MIN_INT64, then it's addition
  //
  Result = 0;
  Augend = 0x3a3a3a3a3a3a3a3a;
  Addend = 0x3a3a3a3a3a3a3a3a;
  Status = SafeInt64Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7474747474747474, Result);

  Augend = (-4195730024608447034);
  Addend = (-4195730024608447034);
  Status = SafeInt64Add (Augend, Addend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-8391460049216894068), Result);

  //
  // Otherwise should result in an error status
  //
  Augend = 0x5a5a5a5a5a5a5a5a;
  Addend = 0x5a5a5a5a5a5a5a5a;
  Status = SafeInt64Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Augend = (-6510615555426900570);
  Addend = (-6510615555426900570);
  Status = SafeInt64Add (Augend, Addend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Status = SafeInt64Add (Augend, Addend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

//
// Subtraction function tests:
//
UNIT_TEST_STATUS
EFIAPI
TestSafeUint8Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT8       Minuend;
  UINT8       Subtrahend;
  UINT8       Result;

  //
  // If Minuend >= Subtrahend, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a;
  Subtrahend = 0x3b;
  Status = SafeUint8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x1f, Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = 0x5a;
  Subtrahend = 0x6d;
  Status = SafeUint8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint8Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Minuend;
  UINT16      Subtrahend;
  UINT16      Result;

  //
  // If Minuend >= Subtrahend, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a;
  Subtrahend = 0x3b3b;
  Status = SafeUint16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x1f1f, Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = 0x5a5a;
  Subtrahend = 0x6d6d;
  Status = SafeUint16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUint16Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Minuend;
  UINT32      Subtrahend;
  UINT32      Result;

  //
  // If Minuend >= Subtrahend, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a5a5a;
  Subtrahend = 0x3b3b3b3b;
  Status = SafeUint32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x1f1f1f1f, Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = 0x5a5a5a5a;
  Subtrahend = 0x6d6d6d6d;
  Status = SafeUint32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeUint32Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Minuend;
  UINT64      Subtrahend;
  UINT64      Result;

  //
  // If Minuend >= Subtrahend, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a5a5a5a5a5a5a;
  Subtrahend = 0x3b3b3b3b3b3b3b3b;
  Status = SafeUint64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x1f1f1f1f1f1f1f1f, Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = 0x5a5a5a5a5a5a5a5a;
  Subtrahend = 0x6d6d6d6d6d6d6d6d;
  Status = SafeUint64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeUint64Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Minuend;
  INT8        Subtrahend;
  INT8        Result;

  //
  // If the result of subtractions doesn't overflow MAX_INT8 or
  // underflow MIN_INT8, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a;
  Subtrahend = 0x3a;
  Status = SafeInt8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x20, Result);

  Minuend = 58;
  Subtrahend = 78;
  Status = SafeInt8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-20), Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = (-80);
  Subtrahend = 80;
  Status = SafeInt8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Minuend = (80);
  Subtrahend = (-80);
  Status = SafeInt8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt8Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeChar8Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  CHAR8       Minuend;
  CHAR8       Subtrahend;
  CHAR8       Result;

  //
  // If the result of subtractions doesn't overflow MAX_INT8 or
  // underflow MIN_INT8, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a;
  Subtrahend = 0x3a;
  Status = SafeChar8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x20, Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = 58;
  Subtrahend = 78;
  Status = SafeChar8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Minuend = 0x85;
  Subtrahend = 80;
  Status = SafeChar8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Minuend = (80);
  Subtrahend = 0x85;
  Status = SafeChar8Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeChar8Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Minuend;
  INT16       Subtrahend;
  INT16       Result;

  //
  // If the result of subtractions doesn't overflow MAX_INT16 or
  // underflow MIN_INT16, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a;
  Subtrahend = 0x3a3a;
  Status = SafeInt16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x2020, Result);

  Minuend = 0x3a3a;
  Subtrahend = 0x5a5a;
  Status = SafeInt16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-8224), Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = (-31354);
  Subtrahend = 31354;
  Status = SafeInt16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Minuend = (31354);
  Subtrahend = (-31354);
  Status = SafeInt16Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeInt16Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Minuend;
  INT32       Subtrahend;
  INT32       Result;

  //
  // If the result of subtractions doesn't overflow MAX_INT32 or
  // underflow MIN_INT32, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a5a5a;
  Subtrahend = 0x3a3a3a3a;
  Status = SafeInt32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x20202020, Result);

  Minuend = 0x3a3a3a3a;
  Subtrahend = 0x5a5a5a5a;
  Status = SafeInt32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-538976288), Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = (-2054847098);
  Subtrahend = 2054847098;
  Status = SafeInt32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Minuend = (2054847098);
  Subtrahend = (-2054847098);
  Status = SafeInt32Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeInt32Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64Sub (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Minuend;
  INT64       Subtrahend;
  INT64       Result;

  //
  // If the result of subtractions doesn't overflow MAX_INT64 or
  // underflow MIN_INT64, then it's subtraction
  //
  Result = 0;
  Minuend = 0x5a5a5a5a5a5a5a5a;
  Subtrahend = 0x3a3a3a3a3a3a3a3a;
  Status = SafeInt64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x2020202020202020, Result);

  Minuend = 0x3a3a3a3a3a3a3a3a;
  Subtrahend = 0x5a5a5a5a5a5a5a5a;
  Status = SafeInt64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL ((-2314885530818453536), Result);

  //
  // Otherwise should result in an error status
  //
  Minuend = (-8825501086245354106);
  Subtrahend = 8825501086245354106;
  Status = SafeInt64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Minuend = (8825501086245354106);
  Subtrahend = (-8825501086245354106);
  Status = SafeInt64Sub (Minuend, Subtrahend, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Status = SafeInt64Sub (Minuend, Subtrahend, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

//
// Multiplication function tests:
//
UNIT_TEST_STATUS
EFIAPI
TestSafeUint8Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT8       Multiplicand;
  UINT8       Multiplier;
  UINT8       Result;

  //
  // If the result of multiplication doesn't overflow MAX_UINT8, it will succeed
  //
  Result = 0;
  Multiplicand = 0x12;
  Multiplier = 0xa;
  Status = SafeUint8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xb4, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x12;
  Multiplier = 0x23;
  Status = SafeUint8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT8_ERROR, Result);

  Status = SafeUint8Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint16Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT16      Multiplicand;
  UINT16      Multiplier;
  UINT16      Result;

  //
  // If the result of multiplication doesn't overflow MAX_UINT16, it will succeed
  //
  Result = 0;
  Multiplicand = 0x212;
  Multiplier = 0x7a;
  Status = SafeUint16Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0xfc94, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x1234;
  Multiplier = 0x213;
  Status = SafeUint16Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT16_ERROR, Result);

  Status = SafeUint16Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint32Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT32      Multiplicand;
  UINT32      Multiplier;
  UINT32      Result;

  //
  // If the result of multiplication doesn't overflow MAX_UINT32, it will succeed
  //
  Result = 0;
  Multiplicand = 0xa122a;
  Multiplier = 0xd23;
  Status = SafeUint32Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x844c9dbe, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0xa122a;
  Multiplier = 0xed23;
  Status = SafeUint32Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT32_ERROR, Result);

  Status = SafeUint32Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeUint64Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  UINT64      Multiplicand;
  UINT64      Multiplier;
  UINT64      Result;

  //
  // If the result of multiplication doesn't overflow MAX_UINT64, it will succeed
  //
  Result = 0;
  Multiplicand = 0x123456789a;
  Multiplier = 0x1234567;
  Status = SafeUint64Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x14b66db9745a07f6, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x123456789a;
  Multiplier = 0x12345678;
  Status = SafeUint64Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (UINT64_ERROR, Result);

  Status = SafeUint64Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt8Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT8        Multiplicand;
  INT8        Multiplier;
  INT8        Result;

  //
  // If the result of multiplication doesn't overflow MAX_INT8 and doesn't
  // underflow MIN_UINT8, it will succeed
  //
  Result = 0;
  Multiplicand = 0x12;
  Multiplier = 0x7;
  Status = SafeInt8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7e, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x12;
  Multiplier = 0xa;
  Status = SafeInt8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT8_ERROR, Result);

  Status = SafeInt8Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeChar8Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  CHAR8       Multiplicand;
  CHAR8       Multiplier;
  CHAR8       Result;

  //
  // If the result of multiplication doesn't overflow MAX_INT8 and doesn't
  // underflow MIN_UINT8, it will succeed
  //
  Result = 0;
  Multiplicand = 0x12;
  Multiplier = 0x7;
  Status = SafeChar8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7e, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x12;
  Multiplier = 0xa;
  Status = SafeChar8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Multiplicand = 0x85;
  Multiplier = 5;
  Status = SafeChar8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Multiplicand = 5;
  Multiplier = 0x85;
  Status = SafeChar8Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (CHAR8_ERROR, Result);

  Status = SafeChar8Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt16Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT16       Multiplicand;
  INT16       Multiplier;
  INT16       Result;

  //
  // If the result of multiplication doesn't overflow MAX_INT16 and doesn't
  // underflow MIN_UINT16, it will succeed
  //
  Multiplicand = 0x123;
  Multiplier = 0x67;
  Result = 0;
  Status = SafeInt16Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x7515, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x123;
  Multiplier = 0xab;
  Status = SafeInt16Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT16_ERROR, Result);

  Status = SafeInt16Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt32Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT32       Multiplicand;
  INT32       Multiplier;
  INT32       Result;

  //
  // If the result of multiplication doesn't overflow MAX_INT32 and doesn't
  // underflow MIN_UINT32, it will succeed
  //
  Result = 0;
  Multiplicand = 0x123456;
  Multiplier = 0x678;
  Status = SafeInt32Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x75c28c50, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x123456;
  Multiplier = 0xabc;
  Status = SafeInt32Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT32_ERROR, Result);

  Status = SafeInt32Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}

UNIT_TEST_STATUS
EFIAPI
TestSafeInt64Mult (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS  Status;
  INT64       Multiplicand;
  INT64       Multiplier;
  INT64       Result;

  //
  // If the result of multiplication doesn't overflow MAX_INT64 and doesn't
  // underflow MIN_UINT64, it will succeed
  //
  Result = 0;
  Multiplicand = 0x123456789;
  Multiplier = 0x6789abcd;
  Status = SafeInt64Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_NOT_EFI_ERROR (Status);
  UT_ASSERT_EQUAL (0x75cd9045220d6bb5, Result);

  //
  // Otherwise should result in an error status
  //
  Multiplicand = 0x123456789;
  Multiplier = 0xa789abcd;
  Status = SafeInt64Mult (Multiplicand, Multiplier, &Result);
  UT_ASSERT_EQUAL (RETURN_BUFFER_TOO_SMALL, Status);
  UT_ASSERT_EQUAL (INT64_ERROR, Result);

  Status = SafeInt64Mult (Multiplicand, Multiplier, NULL);
  UT_ASSERT_EQUAL (RETURN_INVALID_PARAMETER, Status);

  return UNIT_TEST_PASSED;
}



/**

  Main fuction sets up the unit test environment

**/
EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;
  UNIT_TEST_FRAMEWORK       *Fw = NULL;
  UNIT_TEST_SUITE           *ConversionTestSuite;
  UNIT_TEST_SUITE           *AdditionSubtractionTestSuite;
  UNIT_TEST_SUITE           *MultiplicationTestSuite;
  CHAR16  ShortName[100];
  ShortName[0] = L'\0';

  UnicodeSPrint (&ShortName[0], sizeof (ShortName), L"%a", gEfiCallerBaseName);
  DEBUG ((DEBUG_INFO, "%s v%s\n", UNIT_TEST_APP_NAME, UNIT_TEST_APP_VERSION));

  //
  // Start setting up the test framework for running the tests.
  //
  Status = InitUnitTestFramework (&Fw, UNIT_TEST_APP_NAME, ShortName, UNIT_TEST_APP_VERSION);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed in InitUnitTestFramework. Status = %r\n", Status));
    goto EXIT;
  }

  ///
  // Test the conversion functions
  //
  Status = CreateUnitTestSuite (
             &ConversionTestSuite,
             Fw,
             L"Int Safe Conversions Test Suite",
             L"Common.IntSafe.Convert",
             NULL, NULL
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed in CreateUnitTestSuite for Conversions Test Suite\n"));
    Status = EFI_OUT_OF_RESOURCES;
    goto EXIT;
  }
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToUint8",    L"Common.IntSafe.Convert.TestSafeInt8ToUint8",    TestSafeInt8ToUint8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToChar8",    L"Common.IntSafe.Convert.TestSafeInt8ToChar8",    TestSafeInt8ToChar8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToUint16",   L"Common.IntSafe.Convert.TestSafeInt8ToUint16",   TestSafeInt8ToUint16,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToUint32",   L"Common.IntSafe.Convert.TestSafeInt8ToUint32",   TestSafeInt8ToUint32,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToUintn",    L"Common.IntSafe.Convert.TestSafeInt8ToUintn",    TestSafeInt8ToUintn,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt8ToUint64",   L"Common.IntSafe.Convert.TestSafeInt8ToUint64",   TestSafeInt8ToUint64,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint8ToInt8",    L"Common.IntSafe.Convert.TestSafeUint8ToInt8",    TestSafeUint8ToInt8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint8ToChar8",   L"Common.IntSafe.Convert.TestSafeUint8ToChar8",   TestSafeUint8ToChar8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToInt8",    L"Common.IntSafe.Convert.TestSafeInt16ToInt8",    TestSafeInt16ToInt8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToChar8",   L"Common.IntSafe.Convert.TestSafeInt16ToChar8",   TestSafeInt16ToChar8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToUint8",   L"Common.IntSafe.Convert.TestSafeInt16ToUint8",   TestSafeInt16ToUint8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToUint16",  L"Common.IntSafe.Convert.TestSafeInt16ToUint16",  TestSafeInt16ToUint16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToUint32",  L"Common.IntSafe.Convert.TestSafeInt16ToUint32",  TestSafeInt16ToUint32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToUintn",   L"Common.IntSafe.Convert.TestSafeInt16ToUintn",   TestSafeInt16ToUintn,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt16ToUint64",  L"Common.IntSafe.Convert.TestSafeInt16ToUint64",  TestSafeInt16ToUint64,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint16ToInt8",   L"Common.IntSafe.Convert.TestSafeUint16ToInt8",   TestSafeUint16ToInt8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint16ToChar8",  L"Common.IntSafe.Convert.TestSafeUint16ToChar8",  TestSafeUint16ToChar8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint16ToUint8",  L"Common.IntSafe.Convert.TestSafeUint16ToUint8",  TestSafeUint16ToUint8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint16ToInt16",  L"Common.IntSafe.Convert.TestSafeUint16ToInt16",  TestSafeUint16ToInt16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToInt8",    L"Common.IntSafe.Convert.TestSafeInt32ToInt8",    TestSafeInt32ToInt8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToChar8",   L"Common.IntSafe.Convert.TestSafeInt32ToChar8",   TestSafeInt32ToChar8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToUint8",   L"Common.IntSafe.Convert.TestSafeInt32ToUint8",   TestSafeInt32ToUint8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToInt16",   L"Common.IntSafe.Convert.TestSafeInt32ToInt16",   TestSafeInt32ToInt16,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToUint16",  L"Common.IntSafe.Convert.TestSafeInt32ToUint16",  TestSafeInt32ToUint16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToUint32",  L"Common.IntSafe.Convert.TestSafeInt32ToUint32",  TestSafeInt32ToUint32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToUintn",   L"Common.IntSafe.Convert.TestSafeInt32ToUintn",   TestSafeInt32ToUintn,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt32ToUint64",  L"Common.IntSafe.Convert.TestSafeInt32ToUint64",  TestSafeInt32ToUint64,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToInt8",   L"Common.IntSafe.Convert.TestSafeUint32ToInt8",   TestSafeUint32ToInt8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToChar8",  L"Common.IntSafe.Convert.TestSafeUint32ToChar8",  TestSafeUint32ToChar8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToUint8",  L"Common.IntSafe.Convert.TestSafeUint32ToUint8",  TestSafeUint32ToUint8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToInt16",  L"Common.IntSafe.Convert.TestSafeUint32ToInt16",  TestSafeUint32ToInt16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToUint16", L"Common.IntSafe.Convert.TestSafeUint32ToUint16", TestSafeUint32ToUint16, NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToInt32",  L"Common.IntSafe.Convert.TestSafeUint32ToInt32",  TestSafeUint32ToInt32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint32ToIntn",   L"Common.IntSafe.Convert.TestSafeUint32ToIntn",   TestSafeUint32ToIntn,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToInt8",     L"Common.IntSafe.Convert.TestSafeIntnToInt8",     TestSafeIntnToInt8,     NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToChar8",    L"Common.IntSafe.Convert.TestSafeIntnToChar8",    TestSafeIntnToChar8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToUint8",    L"Common.IntSafe.Convert.TestSafeIntnToUint8",    TestSafeIntnToUint8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToInt16",    L"Common.IntSafe.Convert.TestSafeIntnToInt16",    TestSafeIntnToInt16,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToUint16",   L"Common.IntSafe.Convert.TestSafeIntnToUint16",   TestSafeIntnToUint16,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToInt32",    L"Common.IntSafe.Convert.TestSafeIntnToInt32",    TestSafeIntnToInt32,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToUint32",   L"Common.IntSafe.Convert.TestSafeIntnToUint32",   TestSafeIntnToUint32,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToUintn",    L"Common.IntSafe.Convert.TestSafeIntnToUintn",    TestSafeIntnToUintn,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeIntnToUint64",   L"Common.IntSafe.Convert.TestSafeIntnToUint64",   TestSafeIntnToUint64,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToInt8",    L"Common.IntSafe.Convert.TestSafeUintnToInt8",    TestSafeUintnToInt8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToChar8",   L"Common.IntSafe.Convert.TestSafeUintnToChar8",   TestSafeUintnToChar8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToUint8",   L"Common.IntSafe.Convert.TestSafeUintnToUint8",   TestSafeUintnToUint8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToInt16",   L"Common.IntSafe.Convert.TestSafeUintnToInt16",   TestSafeUintnToInt16,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToUint16",  L"Common.IntSafe.Convert.TestSafeUintnToUint16",  TestSafeUintnToUint16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToInt32",   L"Common.IntSafe.Convert.TestSafeUintnToInt32",   TestSafeUintnToInt32,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToUint32",  L"Common.IntSafe.Convert.TestSafeUintnToUint32",  TestSafeUintnToUint32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToIntn",    L"Common.IntSafe.Convert.TestSafeUintnToIntn",    TestSafeUintnToIntn,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUintnToInt64",   L"Common.IntSafe.Convert.TestSafeUintnToInt64",   TestSafeUintnToInt64,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToInt8",    L"Common.IntSafe.Convert.TestSafeInt64ToInt8",    TestSafeInt64ToInt8,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToChar8",   L"Common.IntSafe.Convert.TestSafeInt64ToChar8",   TestSafeInt64ToChar8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToUint8",   L"Common.IntSafe.Convert.TestSafeInt64ToUint8",   TestSafeInt64ToUint8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToInt16",   L"Common.IntSafe.Convert.TestSafeInt64ToInt16",   TestSafeInt64ToInt16,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToUint16",  L"Common.IntSafe.Convert.TestSafeInt64ToUint16",  TestSafeInt64ToUint16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToInt32",   L"Common.IntSafe.Convert.TestSafeInt64ToInt32",   TestSafeInt64ToInt32,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToUint32",  L"Common.IntSafe.Convert.TestSafeInt64ToUint32",  TestSafeInt64ToUint32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToIntn",    L"Common.IntSafe.Convert.TestSafeInt64ToIntn",    TestSafeInt64ToIntn,    NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToUintn",   L"Common.IntSafe.Convert.TestSafeInt64ToUintn",   TestSafeInt64ToUintn,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeInt64ToUint64",  L"Common.IntSafe.Convert.TestSafeInt64ToUint64",  TestSafeInt64ToUint64,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToInt8",   L"Common.IntSafe.Convert.TestSafeUint64ToInt8",   TestSafeUint64ToInt8,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToChar8",  L"Common.IntSafe.Convert.TestSafeUint64ToChar8",  TestSafeUint64ToChar8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToUint8",  L"Common.IntSafe.Convert.TestSafeUint64ToUint8",  TestSafeUint64ToUint8,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToInt16",  L"Common.IntSafe.Convert.TestSafeUint64ToInt16",  TestSafeUint64ToInt16,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToUint16", L"Common.IntSafe.Convert.TestSafeUint64ToUint16", TestSafeUint64ToUint16, NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToInt32",  L"Common.IntSafe.Convert.TestSafeUint64ToInt32",  TestSafeUint64ToInt32,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToUint32", L"Common.IntSafe.Convert.TestSafeUint64ToUint32", TestSafeUint64ToUint32, NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToIntn",   L"Common.IntSafe.Convert.TestSafeUint64ToIntn",   TestSafeUint64ToIntn,   NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToUintn",  L"Common.IntSafe.Convert.TestSafeUint64ToUintn",  TestSafeUint64ToUintn,  NULL, NULL, NULL);
  AddTestCase (ConversionTestSuite, L"Test SafeUint64ToInt64",  L"Common.IntSafe.Convert.TestSafeUint64ToInt64",  TestSafeUint64ToInt64,  NULL, NULL, NULL);

  //
  // Test the addition and subtraction functions
  //
  Status = CreateUnitTestSuite (
             &AdditionSubtractionTestSuite,
             Fw,
             L"Int Safe Add/Subtract Test Suite",
             L"Common.IntSafe.AddSubtract",
             NULL,
             NULL
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed in CreateUnitTestSuite for Int Safe Add/Subtract Test Suite\n"));
    Status = EFI_OUT_OF_RESOURCES;
    goto EXIT;
  }
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint8Add",  L"Common.IntSafe.AddSubtract.TestSafeUint8Add",  TestSafeUint8Add,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint16Add", L"Common.IntSafe.AddSubtract.TestSafeUint16Add", TestSafeUint16Add, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint32Add", L"Common.IntSafe.AddSubtract.TestSafeUint32Add", TestSafeUint32Add, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUintnAdd",  L"Common.IntSafe.AddSubtract.TestSafeUintnAdd",  TestSafeUintnAdd,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint64Add", L"Common.IntSafe.AddSubtract.TestSafeUint64Add", TestSafeUint64Add, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt8Add",   L"Common.IntSafe.AddSubtract.TestSafeInt8Add",   TestSafeInt8Add,   NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeChar8Add",  L"Common.IntSafe.AddSubtract.TestSafeChar8Add",  TestSafeChar8Add,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt16Add",  L"Common.IntSafe.AddSubtract.TestSafeInt16Add",  TestSafeInt16Add,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt32Add",  L"Common.IntSafe.AddSubtract.TestSafeInt32Add",  TestSafeInt32Add,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeIntnAdd",   L"Common.IntSafe.AddSubtract.TestSafeIntnAdd",   TestSafeIntnAdd,   NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt64Add",  L"Common.IntSafe.AddSubtract.TestSafeInt64Add",  TestSafeInt64Add,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint8Sub",  L"Common.IntSafe.AddSubtract.TestSafeUint8Sub",  TestSafeUint8Sub,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint16Sub", L"Common.IntSafe.AddSubtract.TestSafeUint16Sub", TestSafeUint16Sub, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint32Sub", L"Common.IntSafe.AddSubtract.TestSafeUint32Sub", TestSafeUint32Sub, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUintnSub",  L"Common.IntSafe.AddSubtract.TestSafeUintnSub",  TestSafeUintnSub,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeUint64Sub", L"Common.IntSafe.AddSubtract.TestSafeUint64Sub", TestSafeUint64Sub, NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt8Sub",   L"Common.IntSafe.AddSubtract.TestSafeInt8Sub",   TestSafeInt8Sub,   NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeChar8Sub",  L"Common.IntSafe.AddSubtract.TestSafeChar8Sub",  TestSafeChar8Sub,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt16Sub",  L"Common.IntSafe.AddSubtract.TestSafeInt16Sub",  TestSafeInt16Sub,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt32Sub",  L"Common.IntSafe.AddSubtract.TestSafeInt32Sub",  TestSafeInt32Sub,  NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeIntnSub",   L"Common.IntSafe.AddSubtract.TestSafeIntnSub",   TestSafeIntnSub,   NULL, NULL, NULL);
  AddTestCase (AdditionSubtractionTestSuite, L"Test SafeInt64Sub",  L"Common.IntSafe.AddSubtract.TestSafeInt64Sub",  TestSafeInt64Sub,  NULL, NULL, NULL);

  //
  // Test the multiplication functions
  //
  Status = CreateUnitTestSuite (
             &MultiplicationTestSuite,
             Fw,
             L"Int Safe Multiply Test Suite",
             L"Common.IntSafe.Multiply",
             NULL, NULL
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed in CreateUnitTestSuite for Int Safe Multiply Test Suite\n"));
    Status = EFI_OUT_OF_RESOURCES;
    goto EXIT;
  }
  AddTestCase (MultiplicationTestSuite, L"Test SafeUint8Mult",  L"Common.IntSafe.Multiply.TestSafeUint8Mult",  TestSafeUint8Mult,  NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeUint16Mult", L"Common.IntSafe.Multiply.TestSafeUint16Mult", TestSafeUint16Mult, NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeUint32Mult", L"Common.IntSafe.Multiply.TestSafeUint32Mult", TestSafeUint32Mult, NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeUintnMult",  L"Common.IntSafe.Multiply.TestSafeUintnMult",  TestSafeUintnMult,  NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeUint64Mult", L"Common.IntSafe.Multiply.TestSafeUint64Mult", TestSafeUint64Mult, NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeInt8Mult",   L"Common.IntSafe.Multiply.TestSafeInt8Mult",   TestSafeInt8Mult,   NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeChar8Mult",  L"Common.IntSafe.Multiply.TestSafeChar8Mult",  TestSafeChar8Mult,  NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeInt16Mult",  L"Common.IntSafe.Multiply.TestSafeInt16Mult",  TestSafeInt16Mult,  NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeInt32Mult",  L"Common.IntSafe.Multiply.TestSafeInt32Mult",  TestSafeInt32Mult,  NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeIntnMult",   L"Common.IntSafe.Multiply.TestSafeIntnMult",   TestSafeIntnMult,   NULL, NULL, NULL);
  AddTestCase (MultiplicationTestSuite, L"Test SafeInt64Mult",  L"Common.IntSafe.Multiply.TestSafeInt64Mult",  TestSafeInt64Mult,  NULL, NULL, NULL);

  //
  // Execute the tests.
  //
  Status = RunAllTestSuites (Fw);

EXIT:
  if (Fw) {
    FreeUnitTestFramework (Fw);
  }

  return Status;
}
