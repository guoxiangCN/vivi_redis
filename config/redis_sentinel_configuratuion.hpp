#ifndef __VIVI_REDIS_SENTINEL_CONFIGURATION_HPP__
#define __VIVI_REDIS_SENTINEL_CONFIGURATION_HPP__

#include "../port.hpp"
#include "redis_configuration.hpp"

#include <set>
#include <string>

NAMESPACE_VIVI_BEGIN
USING_NAMESPACE_VIVI;


class RedisSentinelConfiguration : public RedisConfiguration, public SentinelConfiguration {
public:
	RedisSentinelConfiguration(){}
	~RedisSentinelConfiguration(){}
};

NAMESPACE_VIVI_END


#endif