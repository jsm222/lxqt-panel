#include "lxqtstatgrabmem.h"

LXQtStatGrabMem::LXQtStatGrabMem(QObject* parent)
    : LXQtStatGrabBase(parent)
{
LXQtStatGrabMem::statgrab_init();
}
void LXQtStatGrabMem::statgrab_init() const{
   sg_init(0);
}

void LXQtStatGrabMem::timeout()
{
    size_t entries;
    if(mSource==QString("memory")) {
    sg_mem_stats * memstat;

    memstat=sg_get_mem_stats(&entries);
    float memtotal = static_cast<float>(memstat->total);
    emit    update(
                static_cast<float>(memstat->used)/memtotal,
                static_cast<float>(0.00),
                static_cast<float>(memstat->cache)/memtotal);
    }
    if(mSource==QString("swap")) {
        sg_swap_stats *swap = sg_get_swap_stats(&entries);
        emit    swapUpdate(static_cast<float>(swap->used)/static_cast<float>(swap->total));
    }

}
LXQtStatGrabMem::~LXQtStatGrabMem() {

}
void LXQtStatGrabMem::monitorDefaultSource() {
    mSource = "memory";
}

QStringList LXQtStatGrabMem::sources()  {
    QStringList ret;
    ret << "memory" << "swap";
    return ret;
}


