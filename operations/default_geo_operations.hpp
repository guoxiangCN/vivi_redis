#ifndef __VIVI_DEFAULT_GEO_OPERATIONS_HPP__
#define __VIVI_DEFAULT_GEO_OPERATIONS_HPP__

#include "geo_operations.hpp"
#include "abstract_operations.hpp"

NAMESPACE_VIVI_BEGIN


template<typename K, typename M>
class DefaultGeoOperations : public _VIVI_ AbstractOperations<K,M>, public _VIVI_ GeoOperations<K, M> {
public:

	DefaultGeoOperations(std::shared_ptr<RedisTemplate<K, M>> rt) 
	: AbstractOperations<K,M>(std::weak_ptr<RedisTemplate<K, M>>(rt)){

	}

	~DefaultGeoOperations() = default;


	int64_t add(K key, const GeoPoint& point, M member) override 
	{
		std::cout << "DefaultGeoOpeartions@add(K,GeoPoint,M)" << std::endl;
		return 0;
	}

	int64_t add(K key, const std::map<M, GeoPoint>& memberCoordiateMap) override 
	{

		return 0;
	}

};



NAMESPACE_VIVI_END

#endif