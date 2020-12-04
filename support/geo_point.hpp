#ifndef __VIVI_GEO_POINT_HPP__
#define __VIVI_GEO_POINT_HPP__

#include "../port.hpp"

NAMESPACE_VIVI_BEGIN

class GeoPoint {
public:
	GeoPoint(double x, double y) 
		: m_x(x), m_y(y) 
	{
	}

	GeoPoint(const GeoPoint& p) 
	{
		m_x = p.m_x;
		m_y = p.m_y;
	}

	GeoPoint& operator=(const GeoPoint& p) 
	{
		m_x = p.m_x;
		m_y = p.m_y;
	}

	double getX() const { return m_x; }

	double getY() const { return m_y; }

private:
	double m_x;
	double m_y;
};

NAMESPACE_VIVI_END

#endif