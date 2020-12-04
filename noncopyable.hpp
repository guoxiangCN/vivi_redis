#ifndef __VIVI_NONCOPYABLE_HPP__
#define __VIVI_NONCOPYABLE_HPP__


#include "port.hpp"

NAMESPACE_VIVI_BEGIN

class noncopyable {

protected:
	noncopyable() = default;
	~noncopyable() = default;
	noncopyable(const noncopyable&) = delete;
	noncopyable& operator=(const noncopyable&) = delete;

};

NAMESPACE_VIVI_END


#endif