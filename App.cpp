#pragma once

#include <string>
#include "redis_template.hpp"
#include "support/geo/geo_point.hpp"
#include <map>

USING_NAMESPACE_VIVI;
USING_NAMESPACE_VIVI_GEO;


auto test() {
	auto rawPtr = new RedisTemplate<std::string, std::string>();
	std::shared_ptr<RedisTemplate<std::string, std::string>> redisTemplate(rawPtr);
	return redisTemplate->opsForValue();
}

int main(int argc, char** argv)
{

	std::map<GeoPoint, int> xmap;
	xmap.insert({ GeoPoint(1,2), 1999 });

	GeoPoint x(1, 2);
	// std::hash<GeoPoint>::_Do_hash(x);

	std::function<void()> f = []() {

	};


	try {
		auto rawPtr = new RedisTemplate<std::string, std::string>();
		std::shared_ptr<RedisTemplate<std::string, std::string>> redisTemplate(rawPtr);
		redisTemplate->opsForValue()->set("a", "b");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	// RedisTemplate<int, int> intTemplate;
	// intTemplate.opsForValue()->set(1000, 2000);

	// RedisTemplate<int, int> tm2 = intTemplate;

	return 0;
}