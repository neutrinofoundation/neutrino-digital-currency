/* Copyright (c) 2009-2010 Satoshi Nakamoto
   Copyright (c) 2009-2012 The Bitcoin developers
   Copyright (c) 2014 The Privatecoin developers */
/* See LICENSE for licensing information */

#include "privatecoin.h"

#include <boost/filesystem.hpp>
#include <boost/thread/thread.hpp>
#include <string>
#include <cstring>

static boost::filesystem::path GetDefaultDataDir()
{
    namespace fs = boost::filesystem;
    // Windows < Vista: C:\Documents and Settings\Username\Application Data\Bitcoin
    // Windows >= Vista: C:\Users\Username\AppData\Roaming\Bitcoin
    // Mac: ~/Library/Application Support/Bitcoin
    // Unix: ~/.bitcoin
#ifdef _WIN32
    // Windows
    return GetSpecialFolderPath(CSIDL_APPDATA) / "Privatecoin";
#else
    fs::path pathRet;
    char* pszHome = getenv("HOME");
    if (pszHome == NULL || strlen(pszHome) == 0)
        pathRet = fs::path("/");
    else
        pathRet = fs::path(pszHome);
#if defined(__darwin__) || defined(__APPLE__)
    // Mac
    pathRet /= "Library/Application Support";
    fs::create_directory(pathRet);
    return pathRet / "Privatecoin";
#else
    // Unix
    return pathRet / ".privatecoin";
#endif
#endif
}

char const* privatecoin_tor_data_directory(
) {
    static std::string const retrieved = (
        GetDefaultDataDir(
        ) / "tor"
    ).string(
    );
    return retrieved.c_str(
    );
}

char const* privatecoin_service_directory(
) {
    static std::string const retrieved = (
        GetDefaultDataDir(
        ) / "onion"
    ).string(
    );
    return retrieved.c_str(
    );
}

int check_interrupted(
) {
    return boost::this_thread::interruption_requested(
    ) ? 1 : 0;
}
