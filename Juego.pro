QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Balas.cpp \
    bombas.cpp \
    bullet.cpp \
    bullet_parabolico.cpp \
    button.cpp \
    enemy.cpp \
    enemy_rango.cpp \
    enemy_tanque.cpp \
    estructura.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    player.cpp \
    regalo.cpp \
    score.cpp

HEADERS += \
    Balas.h \
    bombas.h \
    bullet.h \
    bullet_parabolico.h \
    button.h \
    enemy.h \
    enemy_rango.h \
    enemy_tanque.h \
    estructura.h \
    game.h \
    health.h \
    movimientoprb.h \
    player.h \
    regalo.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

DISTFILES +=
