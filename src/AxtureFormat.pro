#-------------------------------------------------
#
# Project created by QtCreator 2020-01-12T19:58:36
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AxtureFormat
TEMPLATE = app


SOURCES += main.cpp\
    html/htmlparser.cpp \
    qui/props/mconnection.cpp \
    qui/props/mconnections.cpp \
    util/fileutils.cpp \
    util/rsingleton.cpp \
    util/rutil.cpp \
    html/htmlstruct.cpp \
    qui/qtstruct.cpp \
    qui/qtoutput.cpp \
    head.cpp \
    css/cssparsemethod.cpp \
    css/cssparser.cpp \
    css/cssstruct.cpp \
    qui/qrc/qrcoutput.cpp \
    qui/qrc/qrcparsemethod.cpp \
    qui/qss/qssoutput.cpp \
    qui/qss/qssparsemethod.cpp \
    html/gumboparsemethod.cpp \
    html/gumbonodewrapper.cpp \
    qui/formatproperty.cpp \
    qui/exportui.cpp \
    qui/props/mdomwidget.cpp \
    qui/props/mproperty.cpp \
    qui/props/mrect.cpp \
    qui/props/mrow.cpp \
    qui/props/mcolumn.cpp \
    qui/props/mitem.cpp \
    qui/props/mdomresource.cpp \
    qui/props/mattribute.cpp \
    clientoperate.cpp \
    global.cpp \
    viewdelegate.cpp \
    viewmodel.cpp \
    util/threadpool.cpp \
    switchtask.cpp \
    logoutputer.cpp \
    template/generateprojectfile.cpp

HEADERS  += \
    html/htmlparser.h \
    qui/props/mconnection.h \
    qui/props/mconnections.h \
    util/fileutils.h \
    util/rsingleton.h \
    util/rutil.h \
    html/htmlstruct.h \
    qui/qtstruct.h \
    qui/qtoutput.h \
    head.h \
    css/cssparsemethod.h \
    css/cssparser.h \
    css/cssstruct.h \
    qui/qrc/qrcoutput.h \
    qui/qrc/qrcparsemethod.h \
    qui/qss/qssoutput.h \
    qui/qss/qssparsemethod.h \
    html/gumboparsemethod.h \
    html/gumbonodewrapper.h \
    qui/formatproperty.h \
    qui/exportui.h \
    qui/props/mrect.h \
    qui/props/mdomwidget.h \
    qui/props/mproperty.h \
    qui/props/mrow.h \
    qui/props/mcolumn.h \
    qui/props/mitem.h \
    qui/props/mdomresource.h \
    qui/props/mattribute.h \
    clientoperate.h \
    global.h \
    viewdelegate.h \
    viewmodel.h \
    util/threadpool.h \
    switchtask.h \
    util/windumpfile.h \
    logoutputer.h \
    template/generateprojectfile.h

FORMS    += \
    clientoperate.ui \
    logoutputer.ui

RC_ICONS = logo.ico

DEPENDLIB_PATH=$$PWD/../3rdPartyLib/

INCLUDEPATH+="$$DEPENDLIB_PATH/include/gumbo"
LIBS+="$$DEPENDLIB_PATH/lib/shared/debug/gumbo.lib"

RESOURCES += \
    images.qrc

#支持windows xp运行
win32 {
    QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
    QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01

    DEFINES += _ATL_XP_TARGETING
    QMAKE_CFLAGS += /D_USING_V140_SDK71_
    QMAKE_CXXFLAGS += /D_USING_V140_SDK71_
    LIBS += -L$$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib)
    INCLUDEPATH += $$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include)
}
