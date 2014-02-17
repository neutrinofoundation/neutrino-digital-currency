/* Copyright (c) 2014, Privatecoin Developers */
/* See LICENSE for licensing information */

/**
 * \file privatecoin.h
 * \brief Headers for privatecoin.cpp
 **/

#ifndef TOR_PRIVATECOIN_H
#define TOR_PRIVATECOIN_H

#ifdef __cplusplus
extern "C" {
#endif

    char const* privatecoin_tor_data_directory(
    );

    char const* privatecoin_service_directory(
    );

    int check_interrupted(
    );

#ifdef __cplusplus
}
#endif

#endif

