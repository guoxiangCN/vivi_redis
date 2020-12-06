#ifndef __VIVI_GEO_OPERATIONS_HPP__
#define __VIVI_GEO_OPERATIONS_HPP__

#include "../port.hpp"
#include "../support/geo_point.hpp"

#include <map>
#include <cstddef>


NAMESPACE_VIVI_BEGIN

USING_NAMESPACE_VIVI_SUPPORT;

/*
 * @brief Geo operations.
 */
template<typename K, typename M>
class GeoOperations {

public:

	/*
	 * @brief Add the member with point to the key.
	 * @param key : redis key.
	 * @param point: the point.
	 * @param member: the member.
	 */
	virtual int64_t add(K key, const GeoPoint& point, M member) = 0;

	/*
	 * @brief 
	 * @param memberCoordiateMap 
	 */
	virtual int64_t add(K key, const std::map<M, GeoPoint> &memberCoordiateMap) = 0;

protected:
	GeoOperations() = default;
	virtual ~GeoOperations() = default;
};

NAMESPACE_VIVI_END


#endif