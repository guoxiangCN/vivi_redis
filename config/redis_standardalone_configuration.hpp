#ifndef __VIVI_REDIS_STANDARDALONE_CONFIGURATION_HPP__
#define __VIVI_REDIS_STANDARDALONE_CONFIGURATION_HPP__

#include "../port.hpp"
#include "redis_configuration.hpp"

#define _DEFAULT_HOST_		"localhost"
#define _DEFAULT_PORT_		(9379)
#define _DEFAULT_DATABASE_	(0)

NAMESPACE_VIVI_BEGIN

	/*
	 * RedisStandaloneConfiguration do not support dynamic database switch, the
	 * database must be specified in the config.
	 */
	class RedisStandaloneConfiguration : public RedisConfiguration,
	public WithHostAndPort, public WithPassword, public WithDatabaseIndex {
	public:

		RedisStandaloneConfiguration() {}

		RedisStandaloneConfiguration(const std::string& hostName)
			: m_hostName(hostName), m_port(_DEFAULT_PORT_), m_database(_DEFAULT_DATABASE_) {}

		RedisStandaloneConfiguration(const std::string& hostName, int port)
			: m_hostName(hostName), m_port(port), m_database(_DEFAULT_DATABASE_) {}

		~RedisStandaloneConfiguration() {}

		// overrides from WithHostAndPort

		void setHostName(const std::string& hostName) override
		{
			m_hostName = hostName;
		}

		std::string getHostName() override
		{
			return m_hostName;
		}

		void setPort(int port)override
		{
			m_port = port;
		}

		int getPort() override
		{
			return m_port;
		}

		// overrides from WithPassword

		void setUsername(const std::string& userName) override
		{
			m_username = userName;
		}
		std::string getUsername()  override
		{
			return m_username;
		}

		void setPassword(const std::string& password)override
		{
			m_password = password;
		}

		std::string getPassword()override
		{
			return m_password;
		}

		// overrides from WithDatabaseIndex

		void setDatabase(int dbIndex) override
		{
			m_database = dbIndex;
		}

		int getDatabase() override
		{
			return m_database;
		}

	private:
		std::string m_hostName{ _DEFAULT_HOST_ };
		int m_port{ _DEFAULT_PORT_ };
		int m_database{ _DEFAULT_DATABASE_ };
		std::string m_username;
		std::string m_password;
};

NAMESPACE_VIVI_END
#endif