QT += core
QT -= gui

CONFIG += c++11

TARGET = cairo_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

LIBS += -lcups

CONFIG += link_pkgconfig
PKGCONFIG += cairo cairo-pdf cairo-svg cairo-png cairo-ps

HEADERS += \
    cairopp.h \
    cairopp_context.h \
    cairopp_surface.h
