# UEFI Redfish EDK2 Solution

*The initial version of UEFI Redfish EDK2 solution is moved to https://github.com/tianocore/edk2-staging/tree/UEFI-Redfish-obsolete*

This branch is used to develop **UEFI Redfish EDK2 solution** and the review process of code contributions. The code base of this development would keep rebasing to the edk2 master.
The initial code of UEFI Redfish edk2 solution was implemented and released in 2019.1. The follow up UEFI Redfish edk2 solution architecture changes were proposed in 2019.8 by HPE. The architecture change makes edk2 Redfish support more flexible and easier to be integrated to OEM edk2 in-house BIOS. The UEFI edk2 Redfish POC code implementation is working in progress by HPE.

**The Contributors:**\
Fu Siyuan <siyuan.fu@intel.com>\
Ye Ting <ting.ye@intel.com>\
Wang Fan <fan.wang@intel.com>\
Wu Jiaxin <jiaxin.wu@intel.com>\
Yao, Jiewen <jiewen.yao@intel.com>\
Chang Abner <abner.chang@hpe.com>\
Wang Nickle <nickle.wang@hpe.com>

**The Branch Owners:**\
Fu Siyuan <siyuan.fu@intel.com>\
Wang Fan <fan.wang@intel.com>\
Wu Jiaxin <jiaxin.wu@intel.com>\
Yao, Jiewen <jiewen.yao@intel.com>\
Chang Abner <abner.chang@hpe.com>\
Wang Nickle <nickle.wang@hpe.com>

## Introduction
UEFI Redfish is an efficient and secure solution for end users to remote control (in Out of band) and configure UEFI BIOS configurations by leveraging the Redfish RESTful API.  It's simple for end users to access the data from UEFI firmware defined in JSON format.

One of the design goals for UEFI Redfish edk2 solution is to provide a scalable implementation which allow users to easily add/remove/modify each independent Redfish BIOS-owned resource (RedfishBiosDxe & RedfishBootInfoDxe [[1]](#[1])). This is done by extracting the generic logic to a single UEFI driver model driver (RedfishConfigDxe).

Below is the block diagram of UEFI Redfish edk2 solution. [[1]](#[1]) in the figure refers to the sub-project of UEFI Redfish edk2 solution.

![UEFI Redfish final Solution Layout](https://github.com/tianocore/edk2-staging/blob/UEFI_Redfish/Images/RedfishDriverStack.png?raw=true)

## EFI Redfish Driver Stacks 
Below are items defined in UEFI Redfish edk2 project.

### EFI Redfish Host Interface DXE Driver

The abstract DXE driver to create SMBIOS type 42 record through EFI SMBIOS protocol according to device descriptor and protocol type data (defined in SMBIOS type 42h) provided by platform level Redfish host interface library. On edk2 open source implementation (**EmulatorPkg**), SMBIOS type 42 data is retrieved from EFI variable which is created using RedfishPlatformConfig.efi under EFI shell. OEM may provide its own PlatformHostInterfaceLib instance for the platform-specific implementation. ***([D1] in above figure)***

### EFI Refish Credential DXE Driver (***UEFI spec ECR is required***)

Generic EFI Redfish Credential DXE driver which incorporates with RedfishPlatformCredentialLib to acquire the Redfish service credential. On edk2 open source implementation, the credential is hard coded using the fixed Account/Password. OEM may provide its own RedfishPlatformCredentialLib instance for platform-specific implementation. ***([D2] in above figure)***

### EFI REST EX UEFI Driver for Redfish service

Network based ***([D18] in above figure)*** EFI REST EX UEFI driver instance for communicating with Redfish service. ***([D3] in above figure)*** 

### EFI Redfish Discover UEFI Driver

EFI Redfish Discover Protocol implementation (UEFI spec 2.8, section 31.1). Only support Redfish service discovery over Redfish Host Interface.  ***([D4] in above figure)***

### EFI Redfish Config UEFI Driver (***UEFI spec ECR is required***)

This is the centralized manager of EFI Redfish feature drivers.  ***([D5] in above figure)***

### EFI BIOS Config To Redfish Dxe Driver (***UEFI spec ECR is required***)

This is the DXE driver as the interface between EFI Redfish feature drivers and HII framework. Consume/apply BIOS settings from/to Redfish service through EFI Keyword Handler Protocol or EFI Config Routing Protocol. ***([D16] in above figure)***

### EFI REST JSON Structure DXE Driver

EFI REST JSON Structure DXE implementation (UEFI spec 2.8, section 29.7.3). ***([D6] in above figure)***

### EFI Redfish REST JSON C Structure Drivers

EFI Redfish REST JSON to C Structure converter implementations (UEFI spec 2.8, section 31.2).***([D7] in above figure)***

### EFI Source Coding Drivers (***UEFI spec ECR is required***)

The centrlized driver which provide compress and decomparess algorithms for UEFI system, such as gzip, brotli, LZMA and etc. UEFI Redfish edk2 solution could leverage EFI Source Coding Protocol to (de)compress the payload using gzip algorithm. ***([D14] in above figure)***

## BIOS Resource Provisioning Drivers
In order to align with the ongoing discussion in Redfish Host Interface Working Group regards to BIOS Redfish resource provisioning, two additional EFI protocols are added to EDK2 Redfish POC architecture. With these two EFI protocols introduced, the payload format of BIOS Redfish resource and the transport for provisioning BIOS resource could be OEM implementation-specific (e.g. provisioning BIOS resource through IPMI protocol over the particular transport such as KCS style transport). For EDK2 open source, the payload format of BIOS provisioning resource is in HTTP-JSON format, the transport for delivering BIOS resource is HTTP over EFI network stack.

### EFI BIOS Resource Provision Generation Protocol (***UEFI spec ECR is required***)
The protocol instance provided by OEM to generate BIOS Redfish resource in the particular format for the Redfish BIOS resource provisioning. ***([D8] in above figure)***

### EFI BIOS Resource Provision Transport Layer Protocol (***UEFI spec ECR is required***)
The protocol instance of transport provided by OEM to deliver BIOS Redfish resource for the BIOS resource provisioning. ***([D9] in above figure)***

## EFI Redfish Feature Drivers (***UEFI spec ECR is required***)
EFI Redfish Feature Driver is Redfish schema based driver. Each feature driver manipulates Redfish property based on the particular Redfish data model. The feature driver consumes the BIOS-owned Redfish properties and applies it to BIOS configurations (HII options). The feature driver also update BIOS-owned Redfish properties according to HII options. Currently we have two EFI Redfish feature drivers.  
* **RedfishBiosDxe**
  This driver exchanges the BIOS configurations based on Redfish BIOS data model and the HII options. ***([D10] in above figure)***
* **RedfishBootInfoDxe**
  This driver exchanges the BIOS configurations based on Redfish ComputerSystem data model and the HII options.***([D11] in above figure)***

The ultimate goal [[1]](#[1]) is to auto-generate EFI Redfish feature driver for each of Redfish schemas. 

## Configuration Items via UEFI Redfish
* x-uefi-keyword, for example the [ISCSI Boot Keywords](http://www.uefi.org/confignamespace).
* HII Opcodes/Questions marked with REST_SYTLE flag or in REST_SYTLE formset.
* BootOrder/BootNext variables.

## EFI Redfish Libraries
  The following libraries are related to UEFI Redfish edk2 solution.

  * **RedfishPkg\Library\DxeRedfishLib**  
  Library to Create/Read/Update/Delete (CRUD) resources and provide basic query abilities by using [URI/RedPath](https://github.com/DMTF/libredfish) [[2]](#[2]).

  * **RedfishPkg\Library\BaseJsonLib**  
  Library to encode/decode JSON data.

## Platform Components for edk2 EmulatorPkg:
  * **RedfishPlatformCredentialLib**  
  Platform implementation of acquiring credential for building up the communication between BIOS and Redfish service. ***([D12] in above figure)***

  * **RedfishPlatformHostInterfaceLib**  
  Platform implementation which provides the information of building up SMBIOS type 42h record. ***([D13] in above figure)***

  * **RedfishPlatformBiosResourceDxe**  
  Platform level DXE driver which provides the OEM Redfish properties in certain Redfish resource. ***([D17] in above figure)***

## Miscellaneous:
   * **BaseTools**  
   VfrCompile changes to support Rest Style Formset/Flag.

   * **MdePkg**
   Headers related to Rest Style Formset/Flag.

   * **Redfish Profile Simulator**  
   1) A guidance and a patch to enable UEFI support for Redfish Profile Simulator.  
   2) An user guide for how to configure UEFI Redfish through Postman 
   (**RedfishTool\PostmanToConfigUefiRedfish UserGuide\UserGuide.md**).

## <a name="[1]">Auto-Generated EFI Redfish Feature Drivers</a>

Auto-generate EFI Redfish feature driver source code to incorporate with auto-generated EFI Redfish REST JSON to C Structure converter library to map HII option to Redfish property defined in the specific Redfish schema. 

![UEFI BIOS Configuration to Redfish Layout](https://github.com/tianocore/edk2-staging/blob/UEFI_Redfish/Images/BiosConfigurationToRedfish.png?raw=true)

### Bios Configuration to Redfish Property

Incorporate Redfish standard system management with edk2 HII infrastructure in order to increase the interoperability among systems and the capability of remote management on UEFI based firmware configurations. 

  The way to acheive this is by defining the relationship between HII option and the property in Redfish schema in HII UNI file. With the EDK2 multi-language support, we define a special language called "x-uefi-redfish" and describe the mapping between HII option and property in schema. This is an example:
  ```C
  #string STR_BOOT_SOURCE_OVERRIDE_ENABLED_PROMPT     #language x-uefi-redfish-ComputerSystem.v1_0_0   "/Boot/BootSourceOverrideEnabled"
  #string STR_BOOT_SOURCE_OVERRIDE_MODE_PROMPT        #language x-uefi-redfish-ComputerSystem.v1_0_0   "/Boot/BootSourceOverrideMode"
  #string STR_BOOT_SOURCE_OVERRIDE_TARGET_PROMPT      #language x-uefi-redfish-ComputerSystem.v1_0_0   "/Boot/BootSourceOverrideTarget"
  ```

### x-uefi-redfish configure language
  * Language format
     `x-uefi-redfish-$(NAMESPACE)`, where `$(NAMESPACE)` is the combination of Redfish ResourceTypeName and schema version. For example, if the HII option is mapped to the property in Processor.v1_0_0. The x-uefi-redfish configure language is declared as: `x-uefi-redfish-Processor.v1_0_0`
  * String format
    - The string declared with `x-uefi-redfish` configure language is a path to the property in Redfish resource.
    - The root of path is the Redfish resource type indicated in x-uefi-redfish configure language.
    - The path is relative to root of Redfish resource type, not related to Redfish service root.
    - Property in collection object: `{NUM}`
      ```C
      #string STR_MEMORY_1_BASE_MODULE_TYPE_PROMPT         #language x-uefi-redfish-Memory.v1_7_1   "/Memory/{1}/BaseModuleType"
      #string STR_MEMORY_2_BASE_MODULE_TYPE_PROMPT         #language x-uefi-redfish-Memory.v1_7_1   "/Memory/{2}/BaseModuleType"
      #string STR_MEMORY_3_BASE_MODULE_TYPE_PROMPT         #language x-uefi-redfish-Memory.v1_7_1   "/Memory/{3}/BaseModuleType"
      ```
    - Property in array object: `[NUM]`
      ```C
      #string STR_BOOT_ORDER_1_PROMPT                      #language x-uefi-redfish-ComputerSystem.v1_11_0   "/Boot/BootOrder/[1]/Boot0001"
      #string STR_BOOT_ORDER_2_PROMPT                      #language x-uefi-redfish-ComputerSystem.v1_11_0   "/Boot/BootOrder/[2]/Boot0002"
      #string STR_BOOT_ORDER_3_PROMPT                      #language x-uefi-redfish-ComputerSystem.v1_11_0   "/Boot/BootOrder/[3]/Boot0003"      
      ```
      
### EFI BIOS Config To Redfish Protocol (***UEFI spec ECR is required***)

This is the interface protocol that is used to retrieve the configuration from BIOS and update the configuration to BIOS while new future settings is applied from Redfish.

### EFI Resource Config Protocol (***UEFI spec ECR is required***)

This is the interface protocol which is used to communicate between collection type of feature driver and non-collection type of feature driver. As there are many feature drivers with different schema version, collection type of feature driver could utilize this protocol to find corresponding schema version of feature driver.

### Python program to generate Redfish feature drivers automatically

In order to generate Redfish feature drivers automatically, python program will consume the Redfish schema JSON file that is published by [DMTF Redfish](https://www.dmtf.org/standards/redfish).  By parsing the the schema in JSON format and combining with the Redfish JSON-CStructure, Redfish feature drivers could be generated to handle corresponding Redfish resource.

### Auto-selecting Redfish feature drivers

As there are many Redfish feature drivers and normally we will only support certain version of Redfish resource in our system, we need edk2 build tool to pick up necessary Redfish feature drivers during build process. In order to do this, edk2 build tool have to scan UNI files that are included in build process. By checking the supported `x-uefi-redfish` language, edk2 build tool could learn the information about target Redfish schema that would be supported by this driver. (e.g. `x-uefi-redfish-Memory.v1_7_1` refers to Memory schema with version 1.7.1) With this information, edk2 build tool could programmatically add corresponding Redfish feature drivers into target DSC/FDF file. Then the Redfish feature drivers to support Redfish resource are selected automatically. User does not need to include correct version of Redfish feature drivers manually.

## <a name="[2]">Remove the Dependence with libredfish Library</a>

Replaced by EFI Redfish Discover DXE driver and EFI REST EX UEFI Driver.

## Promote to edk2 Trunk
If a subset feature or a bug fix in this staging branch could meet below requirement, it could be promoted to edk2 trunk and removed from this staging branch:
* Meet all edk2 required quality criteria.
* Support both IA32 and X64 Platform.
* Work on [Redfish Profile Simulator](https://github.com/DMTF/Redfish-Profile-Simulator).
* Ready for product integration.

## Related Materials
1. DSP0270 - Redfish Host Interface Specification, 1.2.0
2. DSP0266 - Redfish Specification, 1.11.0
3. UEFI Configuration Namespace Registry - http://www.uefi.org/confignamespace
4. Redfish Schemas - https://redfish.dmtf.org/schemas/v1/
5. UEFI Specification - http://uefi.org/specifications

# Timeline
| Time | Event |
|:----:|:-----:|
| 2019.01 | Initial open source release of UEFI Redfish edk2 solution. |
| 2019.08 | UEFI Redfish edk2 solution re-architecture proposal in Tianocore design meeting |
| 2019.10 | Final solution of UEFI Redfish feature|
| 2020.08 | Update final solution of UEFI edk2 Redfish solution|
| 2020.?? | Contribute UEFI Redfish edk2 solution code to edk2-staging|
