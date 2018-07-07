#pragma once

#include "Exception.hh"

namespace gidway {
namespace engine {
namespace exceptions {

struct Workspace : Exception {
	using Exception::Exception;
};

} // namespace exceptions
} // namespace engine
} // namespace gidway
