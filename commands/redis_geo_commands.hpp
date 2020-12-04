#ifndef __VIVI_REDIS_GEO_COMMANDS_HPP__
#define __VIVI_REDIS_GEO_COMMANDS_HPP__

#include "../port.hpp"
#include "../support/geo_point.hpp"

#include <cstddef>

NAMESPACE_VIVI_BEGIN

class RedisGeoCommands {
public:

	virtual int64_t geoAdd(ByteArray key, GeoPoint point, ByteArray member) = 0;

protected:
	RedisGeoCommands() = default;
	virtual ~RedisGeoCommands() = default;
};

NAMESPACE_VIVI_END

#endif