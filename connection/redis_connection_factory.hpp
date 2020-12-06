#ifndef __VIVI_REDIS_CONNECTION_FACTORY_HPP__
#define __VIVI_REDIS_CONNECTION_FACTORY_HPP__

#include "../port.hpp"
#include "../noncopyable.hpp"
#include "redis_connection.hpp"

NAMESPACE_VIVI_BEGIN
USING_NAMESPACE_VIVI;

class INTERFACE RedisConnectionFactory {
public:

	virtual RedisConnectionPtr getConnection() = 0;

	// get sentinel connection TODO

	// get cluster connection  TODO

protected:
	RedisConnectionFactory() = default;
	virtual ~RedisConnectionFactory() = default;
};


NAMESPACE_VIVI_END

#endif