#ifndef __VIVI_REDIS_NODE_HPP__
#define __VIVI_REDIS_NODE_HPP__

#include "../port.hpp"
#include "node_type.hpp"
#include "named_node.hpp"


#include <string>

NAMESPACE_VIVI_SUPPORT_BEGIN

USING_NAMESPACE_VIVI;
USING_NAMESPACE_VIVI_SUPPORT;

/*
 * @brief RedisNode
 */
class RedisNode : public NamedNode {
protected:
	RedisNode() : m_type(NodeType::INVALID), m_port(0) {}
public:

	RedisNode(const std::string& host, int port)
		: m_host(host), m_port(port), m_type(NodeType::INVALID){}

	std::string getName() override { return m_name; }

	std::string getHost() const { return m_host; }

	int getPort() const { return m_port; }

	void setName(const std::string& name) {
		m_name = name;
	}

	std::string getId() const { return m_id;  }

	NodeType getType() const { return m_type; }

	std::string getMasterId() const { return m_masterId; }

	bool isMaster() const {
		return m_type == NodeType::MASTER;
	}

	bool isSlave() const {
		return m_type == NodeType::SLAVE;
	}

	bool operator<(const RedisNode& r) const
	{
		if (&r == this) return false;
		return m_host < r.m_host || m_port < r.m_port || m_name < r.m_name;
	}

private:
	std::string m_id;
	std::string m_name;
	std::string m_host;
	int m_port;
	NodeType m_type;
	std::string m_masterId;
};



NAMESPACE_VIVI_SUPPORT_END

#endif