/* Copyright (c) 2014, Neutrino Foundation Inc */
/* See LICENSE for licensing information */

/**
 * \file neutrino.h
 * \brief Headers for neutrino.cpp
 **/

#ifndef TOR_NEUTRINO_H
#define TOR_NEUTRINO_H

#ifdef __cplusplus
extern "C" {
#endif

    char const* neutrino_tor_data_directory(
    );

    char const* neutrino_service_directory(
    );

    int check_interrupted(
    );

    int get_port();

    void set_initialized(
    );

    void wait_initialized(
    );

#ifdef __cplusplus
}
#endif

#endif

