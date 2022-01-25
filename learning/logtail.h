#ifndef LOGTAIL_H
#define LOGTAIL_H

#include <QObject>
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <iostream>

class LogTail : public QProcess
{
    Q_OBJECT

public:
    LogTail(QString fn= QString());
    ~LogTail();

public slots:
    void logOutput();
};

#endif // LOGTAIL_H
