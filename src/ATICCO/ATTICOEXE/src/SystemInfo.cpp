#include <TCHAR.h>
#include <pdh.h>
#include <Windows.h>
#include <SystemInfo.h>
#include <cmath>
#include <QString>

#define UNIT_MULTIPELR 1024

static PDH_HQUERY cpuQuery;
static PDH_HCOUNTER cpuTotal;

unsigned long double SystemInfo::getRAMSize(SystemInfo::Unit v_unit)
{
    MEMORYSTATUSEX memory_status;

    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);

    unsigned long double result;

    if (GlobalMemoryStatusEx(&memory_status))
    {
       result = (double)memory_status.ullTotalPhys / (double)pow(UNIT_MULTIPELR, (int) v_unit);
    } else
    {
       result = NULL;
    }

    return result;
}

unsigned long double SystemInfo::getRAMLoad()
{
    MEMORYSTATUSEX memory_status;

    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);

    unsigned long double result;

    if (GlobalMemoryStatusEx(&memory_status))
    {
       result = (double)memory_status.dwMemoryLoad;
    } else
    {
       result = NULL;
    }

    return result;
}

bool SystemInfo::initCpuCounter()
{
    PdhOpenQuery(NULL, NULL, &cpuQuery);
    PdhAddEnglishCounter(cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &cpuTotal);
    PdhCollectQueryData(cpuQuery);

    return true;
}

unsigned int SystemInfo::getProcessorLoad()
{
    static bool inited = initCpuCounter();
    Q_UNUSED(inited);

    PDH_FMT_COUNTERVALUE counterVal;

    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);

    return ceil(counterVal.doubleValue);
}
