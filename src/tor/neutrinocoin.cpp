/* Copyright (c) 2009-2010 Satoshi Nakamoto
   Copyright (c) 2009-2012 The Bitcoin developers
   Copyright (c) 2014 The Neutrinocoin developers */
/* See LICENSE for licensing information */

#include "neutrinocoin.h"

#include <boost/filesystem.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
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
    return GetSpecialFolderPath(CSIDL_APPDATA) / "Neutrinocoin";
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
    return pathRet / "Neutrinocoin";
#else
    // Unix
    return pathRet / ".neutrinocoin";
#endif
#endif
}

char const* neutrinocoin_tor_data_directory(
) {
    static std::string const retrieved = (
        GetDefaultDataDir(
        ) / "tor"
    ).string(
    );
    return retrieved.c_str(
    );
}

char const* neutrinocoin_service_directory(
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

static boost::mutex initializing;

static std::auto_ptr<boost::unique_lock<boost::mutex> > uninitialized(
    new boost::unique_lock<boost::mutex>(
        initializing
    )
);

void set_initialized(
) {
    uninitialized.reset();
}

void wait_initialized(
) {
    boost::unique_lock<boost::mutex> checking(initializing);
}
