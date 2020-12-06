#ifndef __VIVI_NODE_TYPE_HPP__
#define __VIVI_NODE_TYPE_HPP__

#include "../port.hpp"

NAMESPACE_VIVI_SUPPORT_BEGIN


enum class NodeType {
	MASTER,
	SLAVE,
	INVALID,	// not exist
};

NAMESPACE_VIVI_SUPPORT_END


#endif