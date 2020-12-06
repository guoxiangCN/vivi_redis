#ifndef __POOLED_OBJECT_HPP__
#define __POOLED_OBJECT_HPP__

#include "../port.hpp"
#include <memory>
#include <cstddef>

NAMESPACE_VIVI_BEGIN

template<typename T>
class PooledObject {
public:

	virtual std::shared_ptr<T> getObject() = 0;

	virtual uint64_t getCreateTime() = 0;

	virtual uint64_t getActiveTimeMillis() = 0;

	virtual uint64_t getBorrowedCount() = 0;

	virtual uint64_t getIdleTimeMillis() = 0;

	virtual uint64_t getLastBorrowTime() = 0;

	virtual uint64_t getLastReturnTime() = 0;

	virtual uint64_t getLastUsedTime() = 0;

	virtual bool allocate() = 0;

	virtual bool deallocate() = 0;

	virtual void invalidate() = 0;

	virtual void markAbandoned() = 0;

	virtual void markReturning() = 0;

protected:
	PooledObject() = default;
	virtual ~PooledObject() = default;
};

NAMESPACE_VIVI_END	

#endif