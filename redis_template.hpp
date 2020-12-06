#ifndef __VIVI_REDIS_TEMPLATE_H__
#define __VIVI_REDIS_TEMPLATE_H__

#include "port.hpp"
#include "noncopyable.hpp"
#include "operations/hash_operations.hpp"
#include "operations/value_operations.hpp"
#include "operations/default_value_operations.hpp"
#include "operations/default_geo_operations.hpp"

#include <memory>
#include <functional>

NAMESPACE_VIVI_BEGIN

template<typename K, typename V>
class RedisTemplate : public _VIVI_ noncopyable, public std::enable_shared_from_this<RedisTemplate<K,V>> {

public:

	std::shared_ptr<ValueOperations<K,V>> opsForValue();

	std::shared_ptr<GeoOperations<K, V>> opsForGeo();

	template<typename HK, typename HV>
	std::shared_ptr<HashOperations<K, HK, HV>> opsForHash();

	template<typename T>
	T execute(std::function<T(RedisConnectionPtr)> redisAction, bool exposeConnection);

};


template<typename K, typename V>
std::shared_ptr<ValueOperations<K, V>> RedisTemplate<K, V>::opsForValue()
{
	auto x = this->shared_from_this();
	return std::shared_ptr<ValueOperations<K, V>>(new DefaultValueOperations<K, V>(x));
}


template<typename K, typename V>
template<typename HK, typename HV>
std::shared_ptr<HashOperations<K, HK, HV>> RedisTemplate<K, V>::opsForHash()
{
	// FIXME
	return std::make_shared<>();
}

template<typename K, typename V>
std::shared_ptr<GeoOperations<K,V>> RedisTemplate<K, V>::opsForGeo()
{
	auto x = this->shared_from_this();
	return std::shared_ptr<GeoOperations<K,V>>(new DefaultGeoOperations<K,V>(x));
}

template<typename K, typename V>
template<typename T>
T RedisTemplate<K, V>::execute(std::function<T(RedisConnectionPtr)> redisAction, bool exposeConnection)
{
	return redisAction(nullptr);
}

NAMESPACE_VIVI_END


#endif