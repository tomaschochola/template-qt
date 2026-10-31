#include "todo.hpp"

using namespace Qt::StringLiterals;

namespace app
{

    auto Todo::message() const noexcept -> QString
    {
        return u"Hello, world!"_s;
    }

} // namespace app
