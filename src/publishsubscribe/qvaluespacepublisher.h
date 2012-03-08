/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSystems module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QVALUESPACEPUBLISHER_H
#define QVALUESPACEPUBLISHER_H

#include <qvaluespace.h>

#include <QtCore/qobject.h>
#include <QtCore/qstring.h>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

class QValueSpacePublisherPrivate;

class Q_PUBLISHSUBSCRIBE_EXPORT QValueSpacePublisher : public QObject
{
    Q_OBJECT

public:
    explicit QValueSpacePublisher(const QString &path, QObject *parent = 0);
    QValueSpacePublisher(QValueSpace::LayerOptions filter, const QString &path, QObject *parent = 0);
    QValueSpacePublisher(const QUuid &uuid, const QString &path, QObject *parent = 0);
    virtual ~QValueSpacePublisher();

    bool isConnected() const;
    void sync();
    QString path() const;

Q_SIGNALS:
    void interestChanged(const QString &attribute, bool interested);

public Q_SLOTS:
    void resetValue(const QString &name);
    void setValue(const QString &name, const QVariant &data);

protected:
    virtual void connectNotify(const char *);

private:
    Q_DISABLE_COPY(QValueSpacePublisher)
    QValueSpacePublisherPrivate *d_ptr;
};

QT_END_NAMESPACE
QT_END_HEADER

#endif // QVALUESPACEPUBLISHER_H
