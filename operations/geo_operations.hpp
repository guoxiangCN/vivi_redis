#ifndef __VIVI_GEO_OPERATIONS_HPP__
#define __VIVI_GEO_OPERATIONS_HPP__

#include "../port.hpp"
#include "../support/geo/geo_point.hpp"

#include <map>
#include <cstddef>


NAMESPACE_VIVI_BEGIN

/*
 * @brief Geo相关的命令集合.
 */
template<typename K, typename M>
class GeoOperations {

public:

	/*
	 * @brief 添加一个成员到指定的坐标处.
	 * @param key redis的key
	 * @param point 坐标点
	 * @param member 成员
	 */
	virtual int64_t add(K key, const GeoPoint& point, M member) = 0;

	/*
	 * @brief 添加一组成员到指定的坐标处.
	 * @param memberCoordiateMap  成员和对应坐标的映射.
	 */
	virtual int64_t add(K key, const std::map<M, GeoPoint> memberCoordiateMap) = 0;

protected:
	GeoOperations() = default;
	virtual ~GeoOperations() = default;
};

NAMESPACE_VIVI_END


#endif