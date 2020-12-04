#ifndef __VIVI_REDIS_CONNECTION_HPP__
#define __VIVI_REDIS_CONNECTION_HPP__

#include "port.hpp"
#include "noncopyable.hpp"
#include <memory>

NAMESPACE_VIVI_BEGIN

class RedisConnection : public std::enable_shared_from_this<RedisConnection>, _VIVI_ noncopyable {

};


NAMESPACE_VIVI_END

#endif