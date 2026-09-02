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
                translations/zh_TW.ts \
                translations/en_US.ts \
                translations/fr_FR.ts \
                translations/de_DE.ts \
                translations/ja_JP.ts \
                translations/ko_KR.ts \
                translations/ru_RU.ts \
                translations/es_ES.ts \
                translations/it_IT.ts \
                translations/pt_PT.ts \
                translations/pt_BR.ts \
                translations/ar_SA.ts \
                translations/he_IL.ts \
                translations/hi_IN.ts \
                translations/th_TH.ts \
                translations/vi_VN.ts \
                translations/id_ID.ts \
                translations/ms_MY.ts \
                translations/tr_TR.ts \
                translations/pl_PL.ts \
                translations/cs_CZ.ts \
                translations/hu_HU.ts \
                translations/ro_RO.ts \
                translations/nl_NL.ts \
                translations/da_DK.ts \
                translations/fi_FI.ts \
                translations/sv_SE.ts \
                translations/nb_NO.ts \
                translations/hr_HR.ts \
                translations/el_GR.ts \
                translations/uk_UA.ts \
                translations/bg_BG.ts \
                translations/sk_SK.ts \
                translations/sl_SI.ts \
                translations/et_EE.ts \
                translations/lv_LV.ts \
                translations/lt_LT.ts
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
