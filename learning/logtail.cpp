#include "logtail.h"

LogTail::LogTail(QString fn)
{
    if(fn.isEmpty())
    {
        fn = "/home/laptop/learning/log/access.log";
    }

    connect (this, SIGNAL(readyReadStandardOutput()), this, SLOT(logOutput()));
    QStringList argv;
    argv << "-f" << fn;
    // We want to exec "tail -f filename"
    start("tail", argv);
    waitForFinished(-1);
}

LogTail::~LogTail()
{
    terminate();
}

void LogTail::logOutput()
{
    QByteArray bytes = readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    foreach( QString line , lines)
    {
        qDebug() << line;
    }
}
