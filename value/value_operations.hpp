#ifndef __VIVI_VALUE_OPERATIONS_HPP__
#define __VIVI_VALUE_OPERATIONS_HPP__

#include "../port.hpp"

#include <chrono>
#include <cstddef>

NAMESPACE_VIVI_BEGIN

template<typename K, typename V>
class ValueOperations : public _VIVI_ noncopyable {
public:

	ValueOperations() = default;

	virtual ~ValueOperations() = default;

	virtual void set(K key, V value) = 0;

	virtual void set(K key, V value, std::chrono::milliseconds timeout) = 0;

	virtual bool setIfAbsent(K key, V value) = 0;

	virtual V get(K key) = 0;

	virtual int64_t increment(K key, long delta) = 0;

};

NAMESPACE_VIVI_END

#endif