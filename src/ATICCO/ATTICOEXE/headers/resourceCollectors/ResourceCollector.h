#ifndef RESOURCEUSAGE_H
#define RESOURCEUSAGE_H

#include <QThread>
#include "utils/ProcessUtils.h"

class ResourceCollector : public QThread
{
   Q_OBJECT
public:
   ResourceCollector();
   virtual ~ResourceCollector();

public:
   int getId() const;

protected:
   QString getValueFromCommandForKey(QString key, QByteArray command = nullptr);

private:
    virtual void run() override = 0;

signals:
    void canDeleteMe(int);

protected:
    QByteArray systemCommandResult;
    ProcessUtils processUtils;
    int id;

private:
    static int idCounter;
};

#endif // RESOURCEUSAGE_H
