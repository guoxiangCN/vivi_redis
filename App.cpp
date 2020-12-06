#pragma once

#include <map>
#include <string>

#include "redis_template.hpp"
#include "support/geo_point.hpp"
#include "support/host_and_port.hpp"
#include "connection/redis_connection.hpp"

USING_NAMESPACE_VIVI;

extern void Add(int a, int b);


auto test() {
	auto rawPtr = new RedisTemplate<std::string, std::string>();
	std::shared_ptr<RedisTemplate<std::string, std::string>> redisTemplate(rawPtr);
	return redisTemplate->opsForValue();
}

void testHostAndPort()
{
	
	HostAndPort hostAndPort;
	std::cout << hostAndPort.toString() << std::endl;

	int err =  HostAndPort::parseString("127.0.0.1: aaaa", hostAndPort);
	if (err)
	{
		std::cout << "error to parse" << std::endl;
	}
	else {
		std::cout << hostAndPort.toString() << std::endl;
	}
	

}

int main(int argc, char** argv)
{
	Add(1, 2);

	// std::map<GeoPoint, int> xmap;
	// xmap.insert({ GeoPoint(1,2), 1999 });

	// GeoPoint x(1, 2);
	// std::hash<GeoPoint>::_Do_hash(x);

	testHostAndPort();


	try {
		auto rawPtr = new RedisTemplate<std::string, std::string>();
		std::shared_ptr<RedisTemplate<std::string, std::string>> redisTemplate(rawPtr);
		redisTemplate->opsForValue()->set("a", "b");
		redisTemplate->opsForGeo()->add("location", GeoPoint{ 1,2 }, "wuzong");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	// RedisTemplate<int, int> intTemplate;
	// intTemplate.opsForValue()->set(1000, 2000);

	// RedisTemplate<int, int> tm2 = intTemplate;

	return 0;
}