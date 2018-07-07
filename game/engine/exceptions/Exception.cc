#include "Exception.hh"

#include <string>

namespace gidway {
namespace engine {

Exception::Exception (const char* message)
	: msg_(message)
{
}

Exception::Exception (const std::string& message)
	: msg_(message)
{
}

Exception::~Exception (void) noexcept(true)
{
}

const char* Exception::what (void) const throw () {
	return msg_.c_str();
}

} // namespace engine
} // namespace gidway

