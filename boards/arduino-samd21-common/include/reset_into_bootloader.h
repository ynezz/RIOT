/*
 * Copyright (C) 2017 Petr Stetiar <ynezz@true.cz>
 *               2015 Arduino LLC.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_arduino-samd21-common
 * @{
 *
 * @file
 * @brief       Common implementations for Arduino SAMD21 boards
 *
 * @author      Petr Stetiar <ynezz@true.cz>
 *
 * @}
 */

#ifndef RESET_INTO_BOOTLOADER_H
#define RESET_INTO_BOOTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Resets the MCU into Arduino bootloader
 */
void reset_into_bootloader(void);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* RESET_INTO_BOOTLOADER_H */
/** @} */
