#include "todo.hpp"

namespace app
{

auto Todo::message() const -> QString
{
    return QStringLiteral("Hello, Qt!");
}

} // namespace app
