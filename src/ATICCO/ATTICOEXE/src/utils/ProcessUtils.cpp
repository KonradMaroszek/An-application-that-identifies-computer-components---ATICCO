#include "utils/ProcessUtils.h"

#include <QProcess>

ProcessUtils::ProcessUtils()
{
}

ProcessUtils::~ProcessUtils()
{
}

QByteArray ProcessUtils::runSystemCommand(QString v_oCommand, QStringList v_oArguments, int v_iMSecTimeout)
{
    QProcess process;

    process.setProcessChannelMode (QProcess::MergedChannels);
    process.start (v_oCommand);
    process.waitForStarted ();
    std::string arguments = v_oArguments.join(" ").toStdString();
    process.write(arguments.c_str());
    process.closeWriteChannel();

    bool bFinished = process.waitForFinished(v_iMSecTimeout);

    if (!bFinished)
    {
        return "Command finished with TIMEOUT";
    }

    QByteArray oStdOutput = process.readAllStandardOutput();
    QByteArray oStdError = process.readAllStandardError();

    return oStdOutput;
}
