#ifndef APP_TODO_HPP_INCLUDED
#define APP_TODO_HPP_INCLUDED

#include <QObject>
#include <QString>
#include <QtQml/qqmlregistration.h>

namespace app
{

class Todo : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString message READ message CONSTANT)

  public:
    using QObject::QObject;

    [[nodiscard]] auto message() const -> QString;
};

} // namespace app

#endif // APP_TODO_HPP_INCLUDED
