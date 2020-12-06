#ifndef __VIVI_REDIS_SENTINEL_CONNECTION_HPP__
#define __VIVI_REDIS_SENTINEL_CONNECTION_HPP__

#include "../port.hpp"
#include <memory>

NAMESPACE_VIVI_BEGIN

class RedisSentinelConnection {

};

using RedisSentinelConnectionPtr = std::shared_ptr<RedisSentinelConnection>;

NAMESPACE_VIVI_END

#endif