/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd and/or its subsidiary(-ies).
** Copyright (C) 2014 BlackBerry Limited. All rights reserved.
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSystems module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#ifndef QBATTERYINFO_MAC_P_H
#define QBATTERYINFO_MAC_P_H

#include <qbatteryinfo.h>

#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

class QBatteryInfoPrivate : public QObject
{
    Q_OBJECT

public:
    QBatteryInfoPrivate(QBatteryInfo *parent);
    QBatteryInfoPrivate(int batteryIndex, QBatteryInfo *parent);
    ~QBatteryInfoPrivate();

    int batteryCount();
    int batteryIndex() const;
    bool isValid();
    int level(int battery);
    int level();
    int currentFlow(int battery);
    int currentFlow();
    int cycleCount(int battery);
    int cycleCount();
    int maximumCapacity(int battery);
    int maximumCapacity();
    int remainingCapacity(int battery);
    int remainingCapacity();
    int remainingChargingTime(int battery);
    int remainingChargingTime();
    int voltage(int battery);
    int voltage();

    QBatteryInfo::ChargerType chargerType();
    QBatteryInfo::ChargingState chargingState(int battery);
    QBatteryInfo::ChargingState chargingState();
    QBatteryInfo::LevelStatus levelStatus(int battery);
    QBatteryInfo::LevelStatus levelStatus();
    void getBatteryInfo();
    QBatteryInfo::ChargingState currentChargingState();
    QBatteryInfo::Health health(int battery);
    QBatteryInfo::Health health();
    float temperature(int battery);
    float temperature();

    void setBatteryIndex(int batteryIndex);

Q_SIGNALS:
    void batteryCountChanged(int count);
    void batteryIndexChanged(int batteryIndex);
    void validChanged(bool isValid);
    void chargerTypeChanged(QBatteryInfo::ChargerType type);
    void chargingStateChanged(QBatteryInfo::ChargingState state);
    void levelChanged(int level);
    void currentFlowChanged(int flow);
    void cycleCountChanged(int cycleCount);
    void remainingCapacityChanged(int capacity);
    void remainingChargingTimeChanged(int seconds);
    void voltageChanged(int voltage);
    void levelStatusChanged(QBatteryInfo::LevelStatus levelStatus);
    void healthChanged(QBatteryInfo::Health health);
    void temperatureChanged(float temperature);

protected:
    void connectNotify(const QMetaMethod &signal);
    void disconnectNotify(const QMetaMethod &signal);

private Q_SLOTS:
private:
    QBatteryInfo * const q_ptr;
    Q_DECLARE_PUBLIC(QBatteryInfo)

    int batteryLevelCache;
    QBatteryInfo::ChargingState currentChargingStateCache;
    QBatteryInfo::LevelStatus levelStatusCache;


    QBatteryInfo::LevelStatus currentLevelStatus;
    QBatteryInfo::ChargingState curChargeState;
    QBatteryInfo::ChargerType curChargeType;

    int currentBatLevel;
    int currentVoltage;
    int dischargeRate;
    int capacity;
    int currentCapacity;
    int timeToFull;
    int remainingEnergy;
    int numberOfBatteries;
    int index;

//    int batteryCounts;
    QMap<int, int> currentFlows; // <battery ID, current value> pair
    QMap<int, int> voltages;
    QMap<int, int> remainingCapacities;
    QMap<int, int> remainingChargingTimes;
    QMap<int, int> maximumCapacities;
    QMap<int, QBatteryInfo::ChargingState> chargingStates;
    QBatteryInfo::ChargerType currentChargerType;
    QMap<int, QBatteryInfo::LevelStatus> levelStatuss;

    void initialize();
};

QT_END_NAMESPACE

#endif // QBATTERYINFO_MAC_P_H
