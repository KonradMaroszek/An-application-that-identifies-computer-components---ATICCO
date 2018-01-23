#include "resourceCollectors/NetworkUsageCollector.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "IPHLPAPI.lib")

#include <iphlpapi.h>

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

//#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

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

NetworkUsageCollector::NetworkUsageCollector() :
    ResourceCollector()
{

}

NetworkUsageCollector::~NetworkUsageCollector()
{

}

void NetworkUsageCollector::run()
{

    QString desc;

    // Declare and initialize variables.

        HANDLE hClient = NULL;
        DWORD dwMaxClient = 2;      //
        DWORD dwCurVersion = 0;
        DWORD dwResult = 0;

        unsigned int i;

        // variables used for WlanEnumInterfaces

        PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
        PWLAN_INTERFACE_INFO pIfInfo = NULL;

        // variables used for WlanQueryInterfaces for opcode = wlan_intf_opcode_current_connection
        PWLAN_CONNECTION_ATTRIBUTES pConnectInfo = NULL;

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
            return;
        } else
        {
            bool isConnected = false;

            for (i = 0; i < (int) pIfList->dwNumberOfItems; i++)
            {
                pIfInfo = (WLAN_INTERFACE_INFO *) & pIfList->InterfaceInfo[i];

                switch (pIfInfo->isState)
                {
                   case wlan_interface_state_connected:
                        isConnected = true;
                        break;
                }

                if (isConnected)
                {
                    desc = QString::fromWCharArray(pIfInfo->strInterfaceDescription);
                    qDebug(desc.toLatin1());
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



    int outOctes = 0;
    int inOctes = 0;

    while (true)
    {
    // Declare and initialize variables.

        DWORD dwSize = 0;
        DWORD dwRetVal = 0;

        unsigned int i, j;

        /* variables used for GetIfTable and GetIfEntry */
        MIB_IFTABLE *pIfTable;
        MIB_IFROW *pIfRow;

        // Allocate memory for our pointers.
        pIfTable = (MIB_IFTABLE *) MALLOC(sizeof (MIB_IFTABLE));
        if (pIfTable == NULL)
        {
            printf("Error allocating memory needed to call GetIfTable\n");
            return ;
        }
        // Make an initial call to GetIfTable to get the
        // necessary size into dwSize
        dwSize = sizeof (MIB_IFTABLE);
        if (GetIfTable(pIfTable, &dwSize, FALSE) == ERROR_INSUFFICIENT_BUFFER)
        {
            FREE(pIfTable);
            pIfTable = (MIB_IFTABLE *) MALLOC(dwSize);
            if (pIfTable == NULL)
            {
                return ;
            }
        }

        if ((dwRetVal = GetIfTable(pIfTable, &dwSize, FALSE)) == NO_ERROR)
        {
            for (i = 0; i < pIfTable->dwNumEntries; i++)
            {
                pIfRow = (MIB_IFROW *) & pIfTable->table[i];

                QString desc2 = "";

                for (j = 0; j < pIfRow->dwDescrLen; j++)
                    desc2 += pIfRow->bDescr[j];

                desc = desc.replace(" ", "");
                desc2 = desc2.replace(" ", "");

                if (desc2.contains(desc))
                {

                    if (inOctes == 0)
                    {
                        inOctes = pIfRow->dwInOctets;
                        outOctes = pIfRow->dwOutOctets;
                    }

                    long long result = (pIfRow->dwInOctets - inOctes + pIfRow->dwOutOctets - outOctes) * 8 * 100 / pIfRow->dwSpeed;

                    emit networkUsageCollected(result);
                    emit networkInBytesCollected(QString::number(pIfRow->dwInOctets - inOctes) + " bytes /s");
                    emit networkOutBytesCollected(QString::number(pIfRow->dwOutOctets - outOctes) + " bytes /s");

                    sleep(1);

                    inOctes = pIfRow->dwInOctets;
                    outOctes = pIfRow->dwOutOctets;

                    break;
                }

            }
        } else
        {
            if (pIfTable != NULL)
            {
                FREE(pIfTable);
                pIfTable = NULL;
            }
            continue;
        }
        if (pIfTable != NULL)
        {
            FREE(pIfTable);
            pIfTable = NULL;
        }
    }
}
