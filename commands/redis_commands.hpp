#ifndef __VIVI_REDIS_COMMANDS_HPP__
#define __VIVI_REDIS_COMMANDS_HPP__

#include "redis_tx_commands.hpp"
#include "redis_key_commands.hpp"
#include "redis_string_commands.hpp"
#include "redis_list_commands.hpp"
#include "redis_set_commands.hpp"
#include "redis_set_commands.hpp"
#include "redis_hash_commands.hpp"
#include "redis_geo_commands.hpp"
#include "redis_pubsub_commands.hpp"
#include "redis_scripting_commands.hpp"
#include "redis_hyperloglog_commands.hpp"

USING_VIVI;

class RedisCommands : public RedisKeyCommands,
                      public RedisStringCommands {

};

#endif