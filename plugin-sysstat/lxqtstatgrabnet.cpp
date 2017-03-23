#include "lxqtstatgrabnet.h"
#include <QDebug>


LXQtStatGrabNet::LXQtStatGrabNet(QObject* parent)
    : LXQtStatGrabBase(parent)
{
LXQtStatGrabNet::statgrab_init();
}
void LXQtStatGrabNet::statgrab_init() const{
    sg_init(0);
}

void LXQtStatGrabNet::timeout()
{
    size_t entries;
    sg_network_io_stats *network_io_stats = sg_get_network_io_stats(&entries);
    for (int i=0; (unsigned)i<entries;i++) {
        if (QString(network_io_stats[i].interface_name) == mSource)  {
            if(mPrevious==NULL) {
             mPrevious = (sg_network_io_stats*)malloc(sizeof(sg_network_io_stats));
             *mPrevious = network_io_stats[i];
             return;
            }
            emit update(network_io_stats[i].rx-mPrevious->rx,network_io_stats[i].tx-mPrevious->tx);
            *mPrevious = network_io_stats[i];
            return;
        }
    }
}
LXQtStatGrabNet::~LXQtStatGrabNet() {
free(mPrevious);
}
void LXQtStatGrabNet::monitorDefaultSource() {
    mSource = "lo0";
}
QStringList LXQtStatGrabNet::sources()  {
    sg_init(0);
    size_t entries;
    QStringList ret;
    sg_network_iface_stats *network_iface_stats = NULL;
    if( NULL != ( network_iface_stats = sg_get_network_iface_stats(&entries) ) ) {
        // order entries alphabetically using the mountpoint //
        qsort( network_iface_stats, entries, sizeof(network_iface_stats[0]), &sg_network_iface_compare_name );
    for (int i=0; (unsigned)i<entries;i++) {
           ret << QString(network_iface_stats[i].interface_name);
    }
    }
    return ret;
}

