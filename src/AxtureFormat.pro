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
        widget.cpp \
    html/htmlparser.cpp \
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
    qui/props/mdomresource.cpp

HEADERS  += widget.h \
    html/htmlparser.h \
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
    qui/props/mdomresource.h

FORMS    += widget.ui


DEPENDLIB_PATH=$$PWD/../3rdPartyLib/

message($$DEPENDLIB_PATH)

INCLUDEPATH+="$$DEPENDLIB_PATH/include/gumbo"
LIBS+="$$DEPENDLIB_PATH/lib/shared/debug/gumbo.lib"