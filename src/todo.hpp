#pragma once

#include <QObject>
#include <QString>
#include <QtQml/qqmlregistration.h>

namespace app
{

    class Todo : public QObject
    {
        Q_OBJECT
        QML_ELEMENT
        Q_PROPERTY(QString message READ message CONSTANT FINAL)

      public:
        using QObject::QObject;

        [[nodiscard]] auto message() const noexcept -> QString;
    };

} // namespace app
