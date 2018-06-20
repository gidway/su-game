// Copyright (C) 2018 Gidway // wwww.gidway.net
#pragma once

#include <string>

namespace gidway {
namespace filesystem {

class path final {
public:
	path (void);
	path (const path & _path);
	path (const std::string & _path);

	path & operator / (const path & _path);
	path & operator / (const std::string & _path);

	path & operator + (const path & _path);
	path & operator + (const std::string & _path);

	const char * c_str (void) const;

	std::string str (void) const;

	inline operator const char* (void) const {
		return c_str();
	}

}; // class final

} // namespace filesystem
} // namespace gidway
