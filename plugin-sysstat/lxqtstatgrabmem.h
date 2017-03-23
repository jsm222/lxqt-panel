#ifndef LXQTSTATGRABMEM_H
#define LXQTSTATGRABMEM_H
#include "lxqtstatgrabbase.h"
class LXQtStatGrabMem: public LXQtStatGrabBase
{
    Q_OBJECT
public:
    LXQtStatGrabMem(QObject *parent);
    ~LXQtStatGrabMem();
    QStringList sources();
    int updateInterval() const;
    void setUpdateInterval(int msec);
    void stopUpdating();
    void statgrab_init() const;
    void monitorDefaultSource();
public slots:
    void timeout();
signals:
    void update(float app, float buffered, float cached);
    void swapUpdate(float used);
};
#endif // LXQTSTATGRABMEM_H
