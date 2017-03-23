#include "lxqtstatgrabbase.h"


LXQtStatGrabBase::LXQtStatGrabBase(QObject* parent)
    :QObject(parent)
{
    mTimer= new QTimer(this);
    mTimer->setSingleShot(false);
    mTimer->setInterval(1000);
    connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));

}

LXQtStatGrabBase::~LXQtStatGrabBase()
{
}


int LXQtStatGrabBase::updateInterval() const {
    return mTimer->interval();
}
void LXQtStatGrabBase::setUpdateInterval(int msec) {
    mTimer->setInterval(msec);
    mTimer->start();
}

void LXQtStatGrabBase::stopUpdating() {
    mTimer->stop();
}




QString LXQtStatGrabBase::monitoredSource() const
{
    return mSource;

}

void LXQtStatGrabBase::setMonitoredSource(const QString &Source)
{
    if (monitoredSource() != Source)
    {

        mSource = Source;
        emit monitoredSourceChanged(Source);
    }
}

void LXQtStatGrabBase::monitorDefaultSource()
{
    QString oldSource = monitoredSource();
    if (monitoredSource() != oldSource)
        emit monitoredSourceChanged(monitoredSource());
}



