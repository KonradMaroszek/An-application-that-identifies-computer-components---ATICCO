#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

class SystemInfo
{
public:
    enum Unit {B, KB, MB, GB, TB};

    static unsigned long double getRAMSize(Unit v_unit);
    static unsigned long double getRAMLoad();
    static unsigned int getProcessorLoad();

private:
    static bool initCpuCounter();
};

#endif // SYSTEMINFO_H
