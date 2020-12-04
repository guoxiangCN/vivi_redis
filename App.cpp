#pragma once

#include <string>
#include "redis_template.hpp"

USING_VIVI;


auto test() {
	auto rawPtr = new RedisTemplate<std::string, std::string>();
	std::shared_ptr<RedisTemplate<std::string, std::string>> redisTemplate(rawPtr);
	return redisTemplate->opsForValue();
}

int main(int argc, char** argv)
{
	try {
		auto x = test();
		x->set("a", "b");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	
	// RedisTemplate<int, int> intTemplate;
	// intTemplate.opsForValue()->set(1000, 2000);

	// RedisTemplate<int, int> tm2 = intTemplate;

	return 0;
}