#ifndef __VIVI_STRING_UTILS_HPP__
#define __VIVI_STRING_UTILS_HPP__

#include "../port.hpp"

#include <set>
#include <string>
#include <vector>

NAMESPACE_VIVI_SUPPORT_BEGIN

static inline std::string& strip(std::string& s, const std::string& chars = " ")
{
	s.erase(0, s.find_first_not_of(chars.c_str()));
	s.erase(s.find_last_not_of(chars.c_str()) + 1);
	return s;
}


static inline void split(const std::string& source, std::vector<std::string>& tokens, const std::string& delimiters = " ")
{
	std::string::size_type lastPos = source.find_first_not_of(delimiters, 0);
	std::string::size_type pos = source.find_first_of(delimiters, lastPos);
	while (pos != std::string::npos || lastPos != std::string::npos)
	{
		tokens.push_back(source.substr(lastPos, pos - lastPos));
		lastPos = source.find_first_not_of(delimiters, pos);
		pos = source.find_first_of(delimiters, lastPos);
	}
}

NAMESPACE_VIVI_SUPPORT_END

#endif