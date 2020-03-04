#ifndef KEYCHECKER_H
#define KEYCHECKER_H

#include <QKeyEvent>
#include <QObject>

class KeyChecker : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);

};

#endif // KEYCHECKER_H
