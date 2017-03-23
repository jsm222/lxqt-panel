#ifndef LXQTSTATGRABCPU_H
#define LXQTSTATGRABCPU_H
#include "lxqtstatgrabbase.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
class LXQtStatGrabCpu: public LXQtStatGrabBase
{
    Q_OBJECT
public:
    LXQtStatGrabCpu(QObject *parent);
    ~LXQtStatGrabCpu();
    QStringList sources();
    int updateInterval() const;
    void setUpdateInterval(int msec);
    void stopUpdating();
    void statgrab_init() const;
    void monitorDefaultSource();
private:
    sg_cpu_stats *prev=NULL;
public slots:
    void timeout();
signals:
    void update(float user, float nice, float system, float other);
};

#endif // LXQTSTATGRABCPU_H
