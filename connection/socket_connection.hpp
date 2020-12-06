#ifndef __VIVI_SOCKET_CONNECTION_HPP__
#define __VIVI_SOCKET_CONNECTION_HPP__

#include "../port.hpp"
#include "../noncopyable.hpp"
#include <memory>

NAMESPACE_VIVI_BEGIN

class SocketConnection : public std::enable_shared_from_this<SocketConnection>, 
						 public _VIVI_ noncopyable {
public:


private:
	const int m_fd;
	bool m_broken = false;
};

NAMESPACE_VIVI_END

#endif