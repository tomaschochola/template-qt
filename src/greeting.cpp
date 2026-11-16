#include "greeting.hpp"

using namespace Qt::StringLiterals;

namespace app {

    auto Greeting::message() const noexcept -> QString {
        return u"Hello, world!"_s;
    }

} // namespace app
