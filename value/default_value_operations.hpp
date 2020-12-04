#ifndef __DEFAULT_VALUE_OPERATIONS_HPP__
#define __DEFAULT_VALUE_OPERATIONS_HPP__

#include "../port.hpp"
#include "../abstract_operations.hpp"
#include "value_operations.hpp"

#include <memory>

NAMESPACE_VIVI_BEGIN

template<typename K, typename V>
class RedisTemplate;


template<typename K, typename V>
class DefaultValueOperations : public _VIVI_ AbsractOperations<K,V>, public _VIVI_  ValueOperations<K,V> {
public:

	DefaultValueOperations(std::shared_ptr<RedisTemplate<K, V>> rt)
		: AbsractOperations<K, V>(std::weak_ptr<RedisTemplate<K, V>>(rt)) {

	}

	~DefaultValueOperations() = default;

	void set(K key, V value) override 
	{
		std::function<V(RedisConnectionPtr)> redisAction = [](RedisConnectionPtr ptr)-> V {
			std::cout << "call back RedisConnectionPtr  " << std::endl;
			return V();
		};
		this->execute(redisAction, false);
	}

	void set(K key, V value, std::chrono::milliseconds timeout) override
	{

	}

    bool setIfAbsent(K key, V value) override
	{
		return false;
	}

	V get(K key) override
	{
		return V();
	}

	int64_t increment(K key, long delta) override
	{
		return 0L;
	}

};

NAMESPACE_VIVI_END

#endif
