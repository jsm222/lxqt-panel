#include "lxqtstatgrabcpu.h"

LXQtStatGrabCpu::LXQtStatGrabCpu(QObject* parent)
    : LXQtStatGrabBase(parent)
{
LXQtStatGrabCpu::statgrab_init();
}
void LXQtStatGrabCpu::statgrab_init() const{
    sg_init(0);
}

void LXQtStatGrabCpu::timeout()
{
    size_t count;
    size_t entries,entries2;
    if(prev == NULL) {
        prev = sg_get_cpu_stats_r(&count);
        return;
    }
    sg_cpu_percents *current=sg_get_cpu_percents_r(
                sg_get_cpu_stats_diff_between(sg_get_cpu_stats_r(&count),prev, &entries),&entries2);
    emit update(
                static_cast<float>(current->user),
                static_cast<float>(current->nice),
                static_cast<float>(current->kernel),
                static_cast<float>(current->iowait+current->swap));

    prev = sg_get_cpu_stats_r(&count);

    sg_free_cpu_percents(current);

}
LXQtStatGrabCpu::~LXQtStatGrabCpu() {
    sg_free_cpu_stats(prev);
}

QStringList LXQtStatGrabCpu::sources()  {
    QStringList ret;
    ret<< QStringLiteral("cpu");
    return ret;
}
void LXQtStatGrabCpu::monitorDefaultSource() {
    mSource = "cpu";
}
