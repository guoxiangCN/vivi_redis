#ifndef __VIVI_GEO_OPERATIONS_HPP__
#define __VIVI_GEO_OPERATIONS_HPP__

#include "../port.hpp"
#include "../support/geo/geo_point.hpp"

#include <map>
#include <cstddef>


NAMESPACE_VIVI_BEGIN

/*
 * @brief Geo��ص������.
 */
template<typename K, typename M>
class GeoOperations {

public:

	/*
	 * @brief ���һ����Ա��ָ�������괦.
	 * @param key redis��key
	 * @param point �����
	 * @param member ��Ա
	 */
	virtual int64_t add(K key, const GeoPoint& point, M member) = 0;

	/*
	 * @brief ���һ���Ա��ָ�������괦.
	 * @param memberCoordiateMap  ��Ա�Ͷ�Ӧ�����ӳ��.
	 */
	virtual int64_t add(K key, const std::map<M, GeoPoint> memberCoordiateMap) = 0;

protected:
	GeoOperations() = default;
	virtual ~GeoOperations() = default;
};

NAMESPACE_VIVI_END


#endif