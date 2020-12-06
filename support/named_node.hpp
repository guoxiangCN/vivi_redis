#ifndef __VIVI_NAMED_NODE_HPP__
#define __VIVI_NAMED_NODE_HPP__

#include "../port.hpp"
#include <string>

NAMESPACE_VIVI_SUPPORT_BEGIN

class NamedNode {
public:
	NamedNode() {}
	virtual ~NamedNode() {}
	virtual std::string getName() = 0;
};

NAMESPACE_VIVI_SUPPORT_END


#endif