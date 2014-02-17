/* Copyright (c) 2014, Neutrinocoin Developers */
/* See LICENSE for licensing information */

/**
 * \file neutrinocoin.h
 * \brief Headers for neutrinocoin.cpp
 **/

#ifndef TOR_NEUTRINOCOIN_H
#define TOR_NEUTRINOCOIN_H

#ifdef __cplusplus
extern "C" {
#endif

    char const* neutrinocoin_tor_data_directory(
    );

    char const* neutrinocoin_service_directory(
    );

    int check_interrupted(
    );

#ifdef __cplusplus
}
#endif

#endif

