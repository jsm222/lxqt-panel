#ifndef LXQTSTATGRABBASE_H
#define LXQTSTATGRABBASE_H
extern "C" {
#include <statgrab.h>
}
#include <QTimer>
#include <QObject>
class LXQtStatGrabBase: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval RESET stopUpdating NOTIFY updateIntervalChanged)
    Q_PROPERTY(QString monitoredSource READ monitoredSource WRITE setMonitoredSource RESET monitorDefaultSource NOTIFY monitoredSourceChanged)
    LXQtStatGrabBase(QObject *parent);
    ~LXQtStatGrabBase();
    virtual QStringList sources()=0;
    virtual void statgrab_init() const=0;
    QStringList mSources;
    QString mSource;
    QTimer *mTimer;

public slots:
    int updateInterval() const;
    void setUpdateInterval(int msec);
    void stopUpdating();
    virtual void timeout()=0;

    QString monitoredSource() const;
    void setMonitoredSource(const QString &Source);
    void monitorDefaultSource();
signals:
    void updateIntervalChanged(int msec);
    void monitoredSourceChanged(QString);

};

#endif // LXQTSTATGRABBASE_H
