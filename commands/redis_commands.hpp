#ifndef __VIVI_REDIS_COMMANDS_HPP__
#define __VIVI_REDIS_COMMANDS_HPP__

#include "../port.hpp"
#include "redis_tx_commands.hpp"
#include "redis_key_commands.hpp"
#include "redis_string_commands.hpp"
#include "redis_list_commands.hpp"
#include "redis_set_commands.hpp"
#include "redis_zset_commands.hpp"
#include "redis_hash_commands.hpp"
#include "redis_geo_commands.hpp"
#include "redis_pubsub_commands.hpp"
#include "redis_scripting_commands.hpp"
#include "redis_hyperloglog_commands.hpp"

USING_NAMESPACE_VIVI;

/*
 * @brief RedisCommands is an interface with all operations of redis.
 */
class RedisCommands : public RedisKeyCommands,
                      public RedisStringCommands {

protected:
    RedisCommands() = default;
    virtual ~RedisCommands() = default;
};

#endif