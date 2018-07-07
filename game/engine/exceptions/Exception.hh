#pragma once

#include <exception>
#include <string>

namespace gidway {
namespace engine {

class Exception: public ::std::exception
{
public:
	virtual ~Exception (void) noexcept(true);

	Exception (const char* message);
	Exception (const std::string& message);

	virtual const char* what (void) const throw ();

protected:
	std::string msg_;
};

namespace exceptions {
	using Exception = ::gidway::engine::Exception;
} // namespace exceptions

} // namespace engine
} // namespace gidway
