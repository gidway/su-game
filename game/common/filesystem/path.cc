// Copyright (C) 2018 Gidway // wwww.gidway.net
#include "path.hh"

#include <string>

namespace gidway {
namespace filesystem {

path::path (void) {}
path::path (const path & _path) {}
path::path (const std::string & _path) {}

path & path::operator / (const path & _path) { return *this; }
path & path::operator / (const std::string & _path) { return *this; }

path & path::operator + (const path & _path) { return *this; }
path & path::operator + (const std::string & _path) { return *this; }

const char * path::c_str (void) const { return ""; }

std::string path::str (void) const { return {}; }

} // namespace filesystem
} // namespace gidway
