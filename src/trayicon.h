#ifndef TRAYICON_H
#define TRAYICON_H

#include <KStatusNotifierItem>

class Settings;

class TrayIcon: public KStatusNotifierItem
{
    Q_OBJECT

public:
    explicit TrayIcon(QObject *parent=0);
    virtual ~TrayIcon();

};

#endif // TRAYICON_H
