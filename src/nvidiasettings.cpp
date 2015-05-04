#include "nvidiasettings.h"
#include <QMetaEnum>
#include <QDebug>
#include <QPair>

#include <X11/Xlib.h>
#include "NVCtrl/NVCtrl.h"
#include "NVCtrl/NVCtrlLib.h"

#include "nv-control-screen.h"

/*
 * This code has been heavily influenced by https://github.com/NVIDIA/nvidia-settings/blob/master/samples/nv-control-dvc.c
 */

NvidiaSettings::NvidiaSettings(QObject *parent) :
    QObject(parent)
{
}

void NvidiaSettings::setVibrance(int value)
{
    qDebug() << "[NvidiaSettings] setting vibrance to" << value;

    assign(NV_CTRL_DIGITAL_VIBRANCE, value);
}

void NvidiaSettings::resetVibrance()
{
    qDebug() << "[NvidiaSettings] vibrance reset";

    assign(NV_CTRL_DIGITAL_VIBRANCE, 0);
}

void NvidiaSettings::assign(NvAttribute attribute, int value)
{
    // Open a display connection, and make sure the NV-CONTROL X extension is present on the screen we want to use
    Display *dpy = XOpenDisplay(NULL);

    if (!dpy)
    {
        qCritical() << "[NvidiaSettings] cannot open display" << XDisplayName(NULL);
        return;
    }

    int screen = GetNvXScreen(dpy);
    int *dpy_ids;
    int len;

    // Get the list of enabled display devices on the X screen
    bool ret = XNVCTRLQueryTargetBinaryData(dpy, NV_CTRL_TARGET_TYPE_X_SCREEN, screen, 0, NV_CTRL_BINARY_DATA_DISPLAYS_ENABLED_ON_XSCREEN, (unsigned char **)&dpy_ids, &len);

    if (!ret)
    {
        qCritical() << "[NvidiaSettings] unable to determine enabled display devices for screen" << screen << "of" << XDisplayName(NULL);
        return;
    }

    // Set the attribute for every enabled display device
    for (int i = 1; i <= dpy_ids[0]; i++) {

        int dpy_id = dpy_ids[i];

        XNVCTRLSetTargetAttribute(dpy, NV_CTRL_TARGET_TYPE_DISPLAY, dpy_id, 0, attribute, value);
        XFlush(dpy);
    }
}
