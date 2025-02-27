#pragma once

// enable debugging for the Piwik tracker
#define PIWIK_TRACKER_DEBUG 1

#include <QObject>
#include <libraries/piwiktracker/piwiktracker.h>

class MetricsService : public QObject
{
    Q_OBJECT

public:
    explicit MetricsService(QObject *parent = 0);
    void sendVisitIfEnabled(const QString &path = QString(),
                            const QString &actionName = QString());
    void sendVisit(const QString &path = QString(),
                   const QString &actionName = QString());
    void sendEventIfEnabled(
            const QString& path,
            const QString& eventCategory,
            const QString& eventAction,
            const QString& eventName = "",
            int eventValue = 0);
    void sendHeartbeat();
    static MetricsService *instance();
    static MetricsService *createInstance(QObject *parent = 0);
    void sendLocaleEvent();

private:
    PiwikTracker * _piwikTracker;
    bool _firstHeartbeat;

signals:

public slots:
};
