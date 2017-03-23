set(PLUGIN "sysstat")

if(SYSSTAT_PLUGIN_USE_STATGRAB)
    find_library(STATGRAB_LIB statgrab)
    set(HEADERS
        lxqtstatgrabbase.h
        lxqtstatgrabcpu.h
        lxqtstatgrabmem.h
        lxqtstatgrabnet.h
)
    set(SOURCES
        lxqtstatgrabbase.cpp
        lxqtstatgrabcpu.cpp
        lxqtstatgrabmem.cpp
        lxqtstatgrabnet.cpp
)
elseif(SYSSTAT_PLUGIN_USE_LIBSYSSTAT)
    find_package(SysStat-Qt5 REQUIRED)
    add_definitions("-DUSE_LIBSYSSTAT=1")
endif()

set(HEADERS
    ${HEADERS}
    lxqtsysstat.h
    lxqtsysstatconfiguration.h
    lxqtsysstatcolours.h
    lxqtsysstatutils.h
)

set(SOURCES
    ${SOURCES}
    lxqtsysstat.cpp
    lxqtsysstatconfiguration.cpp
    lxqtsysstatcolours.cpp
    lxqtsysstatutils.cpp
)

set(UIS
    lxqtsysstatconfiguration.ui
    lxqtsysstatcolours.ui
)

if(SYSSTAT_PLUGIN_USE_STATGRAB)
    set(LIBRARIES ${STATGRAB_LIB})
elseif(SYSSTAT_PLUGIN_USE_LIBSYSSTAT )
   set(LIBRARIES sysstat-qt5)
endif()

BUILD_LXQT_PLUGIN(${PLUGIN})
