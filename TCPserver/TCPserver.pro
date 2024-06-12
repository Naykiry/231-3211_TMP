QT -= gui
QT += core
QT += network
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    aes.cpp \
    chordmethod.cpp \
    database.cpp \
    functionsforserver.cpp \
    main.cpp \
    sha384.cpp \
    tcpserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    aes.h \
    chordmethod.h \
    database.h \
    functionsforserver.h \
    sha384.h \
    tcpserver.h








