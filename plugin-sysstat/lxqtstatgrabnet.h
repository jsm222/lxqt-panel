#ifndef LXQTSTATGRABNET_H
#define LXQTSTATGRABNET_H
#include "lxqtstatgrabbase.h"
class LXQtStatGrabNet: public LXQtStatGrabBase
{
    Q_OBJECT
public:
    LXQtStatGrabNet(QObject *parent);
    ~LXQtStatGrabNet();
    QStringList sources();
    int updateInterval() const;
    void setUpdateInterval(int msec);
    void stopUpdating();
    void statgrab_init() const;
     void monitorDefaultSource();
     sg_network_io_stats *mPrevious=NULL;
public slots:
    void timeout();
signals:
    void update(unsigned long long received, unsigned long long transmitted);
};

#endif // LXQTSTATGRABNET_H
