#ifndef __VIVI_REDIS_CONFIGURATION_HPP__
#define __VIVI_REDIS_CONFIGURATION_HPP__

#include "../port.hpp"
#include "../support/named_node.hpp"
#include "../support/redis_node.hpp"

#include <set>
#include <string>
#include <type_traits>


NAMESPACE_VIVI_BEGIN

USING_NAMESPACE_VIVI;
USING_NAMESPACE_VIVI_SUPPORT;

class WithHostAndPort {
public:
	virtual void setHostName(const std::string& hostName) = 0;
	virtual std::string getHostName() = 0;
	virtual void setPort(int port) = 0;
	virtual int getPort() = 0;
protected:
	WithHostAndPort() = default;
	virtual ~WithHostAndPort() = default;
};

class WithAuthentication {
public:
	virtual void setUsername(const std::string& userName) = 0;
	virtual std::string getUsername() = 0;
	virtual void setPassword(const std::string& password) = 0;
	virtual std::string getPassword() = 0;
protected:
	WithAuthentication() = default;
	virtual ~WithAuthentication() = default;
};

class WithPassword : public WithAuthentication {
protected:
	WithPassword() = default;
	virtual ~WithPassword() = default;
};

class WithDatabaseIndex {
public:
	virtual void setDatabase(int dbIndex) = 0;
	virtual int getDatabase() = 0;
protected:
	WithDatabaseIndex() = default;
	virtual ~WithDatabaseIndex() = default;
};

class SentinelConfiguration : public WithDatabaseIndex, public WithPassword {
public:
	virtual void setMaster(const NamedNode& master) = 0;
	virtual NamedNode getMaster() = 0;
	virtual std::set<RedisNode> getSentinels() = 0;
	virtual std::string getDataNodeUsername() { return this->getUsername(); }
	virtual std::string getDataNodePassword() { return this->getPassword(); }
	virtual void setSentinelPassword(const std::string& pwd) = 0;
	virtual std::string getSentinelPassword() = 0;
protected:
	SentinelConfiguration() = default;
	virtual ~SentinelConfiguration() = default;
};

class ClusterConfiguration : public WithPassword {
public:
	virtual std::set<RedisNode> getClusterNodes() = 0;
	virtual int getMaxRedirects() = 0;
protected:
	ClusterConfiguration() = default;
	virtual ~ClusterConfiguration() = default;
};

class RedisConfiguration {
public:
	//static bool isAuthenticationAward(RedisConfiguration& cfg)
	//{
	//	// return std::is_
	//}
protected:
	RedisConfiguration() = default;
	virtual ~RedisConfiguration() = default;
};

NAMESPACE_VIVI_END


#endif