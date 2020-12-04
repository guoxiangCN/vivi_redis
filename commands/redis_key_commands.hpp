#ifndef __VIVI_REDIS_KEY_COMMANDS_HPP__
#define __VIVI_REDIS_KEY_COMMANDS_HPP__

#include "commands_defs.hpp"
#include <vector>

NAMESPACE_VIVI_BEGIN

class RedisKeyCommands  {

public:
	RedisKeyCommands() = default;
	virtual ~RedisKeyCommands() = default;

	virtual bool exists(ByteArray key) = 0;

};

NAMESPACE_VIVI_END


#endif