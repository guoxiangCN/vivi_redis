#ifndef __VIVI_HOST_AND_PORT_HPP__
#define __VIVI_HOST_AND_PORT_HPP__

#include "../port.hpp"
#include <string>
#include <sstream>
#include <initializer_list>

NAMESPACE_VIVI_SUPPORT_BEGIN

class HostAndPort {
public:

	HostAndPort()
		: m_host(""), m_port(-1) {}

	HostAndPort(const char* host, int port)
		: m_host(host), m_port(port) {}

	HostAndPort(const std::string& host, int port)
		: m_host(host), m_port(port) {}

	HostAndPort(std::string&& host, int port)
		: m_host(std::move(host)), m_port(port) {}

	HostAndPort(std::initializer_list<std::string> list)
	{
		auto it = list.begin();
		m_host = *it++;
		m_port = std::stoi(*it);
	}

	std::string getHost() const
	{
		return m_host;
	}

	int getPort() const
	{
		return m_port;
	}

	std::string toString() const
	{
		std::stringstream ss;
		ss << "Host:" << m_host << ", Port:" << m_port;
		return ss.str();
	}

	bool operator==(const HostAndPort& o)
	{
		return (m_host == o.m_host) && (m_port = o.m_port);
	}

	bool operator!=(const HostAndPort& o)
	{
		return !this->operator==(o);
	}

	static vivi_errno_t parseString(const std::string& str, HostAndPort& hostAndPort)
	{
		try {
			size_t idx = str.find_last_of(':', std::string::npos);
			if (idx != std::string::npos)
			{
				std::string host = str.substr(0, idx);
				std::string port = str.substr(idx + 1);
				hostAndPort.m_host = std::move(host);
				hostAndPort.m_port = std::stoi(port);
				return VIVI_ERRNO_NOERR;
			}
		}
		catch (const std::exception& ignore) {
		}
		return VIVI_ERRNO_INVLIAD_ARGUMENT;
	}
public:

private:
	std::string m_host;
	int m_port;
};


NAMESPACE_VIVI_SUPPORT_END


#endif