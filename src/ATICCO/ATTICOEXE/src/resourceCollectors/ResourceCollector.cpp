#include "resourceCollectors/ResourceCollector.h"
#include "QRegularExpression"

int ResourceCollector::idCounter = 0;

ResourceCollector::ResourceCollector() :id(++idCounter)
{

}

ResourceCollector::~ResourceCollector()
{

}

int ResourceCollector::getId() const
{
    return id;
}

QString ResourceCollector::getValueFromCommandForKey(QString key, QByteArray command)
{
    QString systemCommandResultString;

    if (command != nullptr)
    {
        systemCommandResultString = command;
    } else
    {
        systemCommandResultString = systemCommandResult;
    }

    QStringList systemCommandResultsList = systemCommandResultString.split("\n");

    QRegularExpression regularExpression("^(("+key+"=).*)*$");

    int indexOfString = systemCommandResultsList.indexOf(regularExpression);

    QString stringWithResult;

    if (indexOfString != -1)
    {
       stringWithResult = systemCommandResultsList.takeAt(indexOfString);
    } else
    {
        return "";
    }


    int indexOfResultStart = stringWithResult.indexOf(key);

    if (indexOfResultStart != -1)
    {
        indexOfResultStart = stringWithResult.indexOf("=", indexOfResultStart);
    }
    else
    {
        return "";
    }

    if (indexOfResultStart == -1)
    {
        return "";
    }

    QString result = stringWithResult.remove(0, indexOfResultStart+1);

    return result;
}
