#ifndef PROCESSUTILS_H
#define PROCESSUTILS_H

#include "ProcessUtils.h"

#include <QByteArray>
#include <QString>

class ProcessUtils
{
public:
    ProcessUtils();
    ~ProcessUtils();

public:
    QByteArray runSystemCommand(QString v_oCommand, QStringList v_oArguments, int v_iMSecTimeout);
};

#endif // PROCESSUTILS_H
