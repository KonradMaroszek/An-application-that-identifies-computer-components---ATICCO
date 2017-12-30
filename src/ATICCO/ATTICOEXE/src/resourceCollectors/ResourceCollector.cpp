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

QString ResourceCollector::getValueFromCommandForKey(QString key)
{
    QString systemCommandResultString (systemCommandResult);
    QStringList systemCommandResultsList = systemCommandResultString.split("\n");

    QRegularExpression regularExpression("^(("+key+"=).*)*$");

    int indexOfString = systemCommandResultsList.indexOf(regularExpression);
    QString stringWithResult = systemCommandResultsList.takeAt(indexOfString);

    int indexOfResultStart = stringWithResult.indexOf(key);
    indexOfResultStart = stringWithResult.indexOf("=", indexOfResultStart);

    QString result = stringWithResult.remove(0, indexOfResultStart+1);

    return result;
}
