#ifndef __VIVI_REDIS_SENTINEL_CONFIGURATION_HPP__
#define __VIVI_REDIS_SENTINEL_CONFIGURATION_HPP__

#include "../port.hpp"
#include "../vivi_exception.hpp"
#include "../support/string_utils.hpp"
#include "../support/host_and_port.hpp"
#include "redis_configuration.hpp"

#include <set>
#include <string>
#include <vector>
#include <algorithm>

#define _DEFAULT_MAX_REDIRECTS_ (8)

NAMESPACE_VIVI_BEGIN

class RedisClusterConfiguration : public RedisConfiguration, public ClusterConfiguration {
public:

	RedisClusterConfiguration() {}

	/*
	 * Construct a RedisClusterConfiguration with a given str formatted like 
	 * "127.0.0.1:6379,127.0.0.1:6380,127.0.0.1:6381".
	 * the master nodes required only, do not typo slave nodes of cluster nodes.
	 */
	RedisClusterConfiguration(const std::string& clusterStr)
	{
		setClusterNodes(clusterStr);
	}

	/*
	 * Destructor of RedisClusterConfiguration, nothing to do.
	 */
	~RedisClusterConfiguration() {}


	void setClusterNodes(const std::string& clusterStr)
	{
		std::vector<std::string> vec;
		vivi::support::split(clusterStr, vec, ",");
		if (vec.empty())
		{
			throw ViviException("cluster node strings was not configured.");
		}
		std::for_each(vec.begin(), vec.end(), [this](std::string& nodestr) {
			m_clusterNodes.insert(parseRedisNodeFromString(nodestr));
		});
	}

	// overrides from WithPassword

	void setUsername(const std::string& userName) override
	{
		m_username = userName;
	}

	std::string getUsername() override
	{
		return m_username;
	}

	void setPassword(const std::string& password) override
	{
		m_password = password;
	}

	std::string getPassword() override
	{
		return m_password;
	}

	// overrides from ClusterConfiguration

	std::set<RedisNode> getClusterNodes() override 
	{
		return m_clusterNodes;
	}

	int getMaxRedirects() override 
	{
		return m_maxRedirects;
	}

	void setMaxRedirects(int maxRedirects) 
	{
		m_maxRedirects = std::max(0, maxRedirects);
	}

private:
	RedisNode parseRedisNodeFromString(const std::string& str)
	{
		HostAndPort hostAndPort;
		if (HostAndPort::parseString(str, hostAndPort))
			throw ViviException("invalid cluster nodes and unable to parse.");
		return RedisNode(hostAndPort.getHost(), hostAndPort.getPort());
	}
private:
	std::set<RedisNode> m_clusterNodes;
	int m_maxRedirects{ _DEFAULT_MAX_REDIRECTS_ };
	std::string m_username;
	std::string m_password;
};

NAMESPACE_VIVI_END

#endif