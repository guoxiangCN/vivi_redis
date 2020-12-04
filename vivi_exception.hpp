#ifndef __VIVI_VIVI_EXCEPTION_HPP__
#define __VIVI_VIVI_EXCEPTION_HPP__

#include "port.hpp"
#include <stdexcept>

NAMESPACE_VIVI_BEGIN

class ViviException : public std::runtime_error {
public:
	ViviException(const std::string &What) : runtime_error(What) {}
};

NAMESPACE_VIVI_END


#endif