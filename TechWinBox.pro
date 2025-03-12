QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CheckboxWidget.cpp \
    CpFileName.cpp \
    DragDropLabel.cpp \
    Language/test1widget.cpp \
    Language/test2widget.cpp \
    QrcFeatureWidget.cpp \
    Language/language.cpp \
    main.cpp \
    widget.cpp \

HEADERS += \
    CheckboxWidget.h \
    CpFileName.h \
    DragDropLabel.h \
    Language/test1widget.h \
    Language/test2widget.h \
    QrcFeatureWidget.h \
    Language/language.h \
    widget.h\

TRANSLATIONS += translations/zh_CN.ts \
                translations/en_US.ts \
                translations/fr_FR.ts  # 新增的法语翻译文件
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
