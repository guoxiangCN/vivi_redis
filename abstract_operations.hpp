#ifndef __VIVI_ABSTRACT_OPERATIONS_HPP__
#define __VIVI_ABSTRACT_OPERATIONS_HPP__

#include "port.hpp"
#include "vivi_exception.hpp"
#include "redis_connection.hpp"
// #include "redis_template.hpp"

#include <memory>
#include <functional>

NAMESPACE_VIVI_BEGIN

template<typename K, typename V>
class RedisTemplate;

template<typename K, typename V>
class AbsractOperations {
public:
	
	/*
	 * Construct a AbstractOpertions with a weak_ptr to observer the RedisTemplate.
	 */
	AbsractOperations(std::weak_ptr<RedisTemplate<K, V>> wpRedisTemplate) : m_redisTempalte(wpRedisTemplate) {}


	/*
	 * Get the smart pointer of RedisTemplate.
	 * A exception will be throw if the oberserved RedisTemplate was out of lifecycle.
	 */
	std::shared_ptr<RedisTemplate<K, V>> getRedisTemplate() {
		auto sharedPtr = m_redisTempalte.lock();
		if (!sharedPtr)
		{
			THROW ViviException("Current operation is out of lifecycle of RedisTemplate<K,V>");
		}
		return sharedPtr;
	}

	/*
	 * Execute a RedisAction given.
	 */
	template<typename T>
	T execute(std::function<T(RedisConnectionPtr)> redisAction, bool exposeConnection) {
		auto rt = this->getRedisTemplate();
		return rt->execute(redisAction, exposeConnection);
	}



protected:
	std::weak_ptr<RedisTemplate<K, V>> m_redisTempalte;
};

NAMESPACE_VIVI_END

#endif