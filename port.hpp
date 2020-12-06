#ifndef __VIVI_PORT_H__
#define __VIVI_PORT_H__


#define THROW throw
#define NOEXCEPT noexcept
#define INTERFACE

#define NAMESPACE_VIVI_BEGIN namespace vivi {
#define NAMESPACE_VIVI_END }
#define USING_NAMESPACE_VIVI using namespace vivi
#define _VIVI_ ::vivi::
#define _VIVI  ::vivi


#define NAMESPACE_VIVI_SUPPORT_BEGIN namespace vivi { namespace support {
#define NAMESPACE_VIVI_SUPPORT_END }}
#define USING_NAMESPACE_VIVI_SUPPORT using namespace vivi::support
#define _VIVI_GEO_ ::vivi::geo::
#define _VIVI_GEO  ::vivi::geo


typedef int vivi_errno_t;

#define VIVI_ERRNO_NOERR 0
#define VIVI_ERRNO_INVLIAD_ARGUMENT -1
#define VIVI_ERRNO_UNSUPPORT_COMMAND - 2

#include <iostream>

#endif