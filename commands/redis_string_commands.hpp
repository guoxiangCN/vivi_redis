#ifndef __VIVI_REDIS_STRING_COMMANDS_HPP__
#define __VIVI_REDIS_STRING_COMMANDS_HPP__

NAMESPACE_VIVI_BEGIN

class RedisStringCommands {

public:
	RedisStringCommands() = default;
	virtual ~RedisStringCommands() = default;

	virtual ByteArray get(ByteArray key) = 0;

};
NAMESPACE_VIVI_END


#endif
