#ifndef GENERIC_ORCONFIG_H_
#define GENERIC_ORCONFIG_H_

#if defined(_WIN32)
#  include "orconfig_win32.h"
#else
#  include "orconfig_posix.h"
#endif

#endif  // GENERIC_ORCONFIG_H_
