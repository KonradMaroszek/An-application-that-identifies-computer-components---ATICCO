#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "IPHLPAPI.lib")

#include <iphlpapi.h>

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

#include <windows.h>
#include <wlanapi.h>
#include <Windot11.h>           // for DOT11_SSID struct
#include <objbase.h>
#include <wtypes.h>

//#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")

////////////////////////////////////////////////

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

///* Note: could also use malloc() and free() */
///
/// ////////////////////////
///
////* #include <windows.h>
#include <wlanapi.h>
#include <Windot11.h>           // for DOT11_SSID struct
#include <objbase.h>
#include <wtypes.h>

//#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")*/

#include "resourceCollectors/NetworkInformationCollector.h"

NetworkInformationCollector::NetworkInformationCollector() :
    ResourceCollector()

{

}

NetworkInformationCollector::~NetworkInformationCollector()
{

}

void NetworkInformationCollector::run()
{
            // Declare and initialize variables.
QString name;
                HANDLE hClient = NULL;
                DWORD dwMaxClient = 2;      //
                DWORD dwCurVersion = 0;
                DWORD dwResult = 0;
                DWORD dwRetVal = 0;

                unsigned int i, k;

                // variables used for WlanEnumInterfaces

                PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
                PWLAN_INTERFACE_INFO pIfInfo = NULL;

                // variables used for WlanQueryInterfaces for opcode = wlan_intf_opcode_current_connection
                PWLAN_CONNECTION_ATTRIBUTES pConnectInfo = NULL;
                DWORD connectInfoSize = sizeof(WLAN_CONNECTION_ATTRIBUTES);
                WLAN_OPCODE_VALUE_TYPE opCode = wlan_opcode_value_type_invalid;

                dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
                if (dwResult != ERROR_SUCCESS)
                {
                    wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
                    return;
                    // You can use FormatMessage here to find out why the function failed
                }

                dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
                if (dwResult != ERROR_SUCCESS)
                {
                    wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
                    return;
                    // You can use FormatMessage here to find out why the function failed
                } else
                {
                    for (i = 0; i < (int) pIfList->dwNumberOfItems; i++)
                    {
                        pIfInfo = (WLAN_INTERFACE_INFO *) & pIfList->InterfaceInfo[i];

                        // If interface state is connected, call WlanQueryInterface
                        // to get current connection attributes
                        if (pIfInfo->isState == wlan_interface_state_connected) {
                            dwResult = WlanQueryInterface(hClient,
                                                          &pIfInfo->InterfaceGuid,
                                                          wlan_intf_opcode_current_connection,
                                                          NULL,
                                                          &connectInfoSize,
                                                          (PVOID *) &pConnectInfo,
                                                          &opCode);

                            if (dwResult != ERROR_SUCCESS) {
                                wprintf(L"WlanQueryInterface failed with error: %u\n", dwResult);
                                dwRetVal = 1;
                                // You can use FormatMessage to find out why the function failed
                            } else {

                                name = QString::fromWCharArray(pIfInfo->strInterfaceDescription);
                                emit networkNameCollected(name);

                                if (pConnectInfo->wlanAssociationAttributes.dot11Ssid.uSSIDLength == 0)
                                    wprintf(L"\n");
                                else {
                                    QString ssid = "";

                                    for (k = 0;
                                         k < pConnectInfo->wlanAssociationAttributes.dot11Ssid.uSSIDLength;
                                         k++) {


                                         wchar_t  sa = (int) pConnectInfo->wlanAssociationAttributes.dot11Ssid.ucSSID[k];
                                        ssid+= sa;
                                    }
                                    emit networkSSIDCollected(ssid);
                                }


                                emit networkTypeOfConnectionCollected(QString::number(pConnectInfo->wlanAssociationAttributes.wlanSignalQuality) + " %");

                                break;
                            }
                        }
                    }

                }
                if (pConnectInfo != NULL) {
                    WlanFreeMemory(pConnectInfo);
                    pConnectInfo = NULL;
                }

                if (pIfList != NULL) {
                    WlanFreeMemory(pIfList);
                    pIfList = NULL;
                }
        /* Declare and initialize variables */

           DWORD dwSize = 0;
            dwRetVal = 0;

            i = 0;

           // Set the flags to pass to GetAdaptersAddresses
           ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

           // default to unspecified address family (both)
           ULONG family = AF_UNSPEC;

           LPVOID lpMsgBuf = NULL;

           PIP_ADAPTER_ADDRESSES pAddresses = NULL;
           ULONG outBufLen = 0;
           ULONG Iterations = 0;

           PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
           PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
           PIP_ADAPTER_ANYCAST_ADDRESS pAnycast = NULL;
           PIP_ADAPTER_MULTICAST_ADDRESS pMulticast = NULL;
           IP_ADAPTER_DNS_SERVER_ADDRESS *pDnServer = NULL;
           IP_ADAPTER_PREFIX *pPrefix = NULL;

           if (false) {
               printf(" Usage: getadapteraddresses family\n");
               printf("        getadapteraddresses 4 (for IPv4)\n");
               printf("        getadapteraddresses 6 (for IPv6)\n");
               printf("        getadapteraddresses A (for both IPv4 and IPv6)\n");
               exit(1);
           }

           if (true)
               family = AF_INET;
           else if (false)
               family = AF_INET6;

           printf("Calling GetAdaptersAddresses function with family = ");
           if (family == AF_INET)
               printf("AF_INET\n");
           if (family == AF_INET6)
               printf("AF_INET6\n");
           if (family == AF_UNSPEC)
               printf("AF_UNSPEC\n\n");

           // Allocate a 15 KB buffer to start with.
           outBufLen = WORKING_BUFFER_SIZE;

           do {

               pAddresses = (IP_ADAPTER_ADDRESSES *) MALLOC(outBufLen);
               if (pAddresses == NULL) {
                   printf
                       ("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
                   exit(1);
               }

               dwRetVal =
                   GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

               if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
                   FREE(pAddresses);
                   pAddresses = NULL;
               } else {
                   break;
               }

               Iterations++;

           } while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

           if (dwRetVal == NO_ERROR) {
               // If successful, output some information from the data we received
               pCurrAddresses = pAddresses;
               while (pCurrAddresses)
               {
                   QString name2 = QString::fromWCharArray(pCurrAddresses->Description);

                   if (name2.contains(name))
                   {
                       emit networkCardNameCollected(QString::fromWCharArray(pCurrAddresses->FriendlyName));
                       emit networkDNSNameCollected(QString::fromWCharArray(pCurrAddresses->DnsSuffix));
                       break;
                   }

                    pCurrAddresses = pCurrAddresses->Next;

               }
           } else {
               printf("Call to GetAdaptersAddresses failed with error: %d\n",
                      dwRetVal);
               if (dwRetVal == ERROR_NO_DATA)
                   printf("\tNo addresses were found for the requested parameters\n");
               else {

                   if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                           FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                           NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                           // Default language
                           (LPTSTR) & lpMsgBuf, 0, NULL)) {
                       printf("\tError: %s", lpMsgBuf);
                       LocalFree(lpMsgBuf);
                       if (pAddresses)
                           FREE(pAddresses);
                       exit(1);
                   }
               }
           }

           if (pAddresses) {
               FREE(pAddresses);
           }

}
