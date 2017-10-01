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

#include <stdio.h>

#include "cpu.h"
#include "periph/pm.h"
#include "periph/flashpage.h"

extern const uint32_t _sfixed;

/* Minimum bootloader size in SAMD21 family is 512 bytes (RM section 22.6.5) */
#define MINIMUM_BOOTLOADER_SIZE_ADDR 0x200 + 4
#define APPLICATION_START_ADDR ((volatile uint32_t)(&_sfixed) + 4)

__attribute__ ((noreturn, long_call, section(".ramfunc")))
void reset_into_bootloader(void)
{
    int page = flashpage_page((void *) APPLICATION_START_ADDR);

    __disable_irq();

    /* Check if we're using linker script without bootloader */
    if (APPLICATION_START_ADDR < MINIMUM_BOOTLOADER_SIZE_ADDR) {
        goto reboot;
    }

    flashpage_write(page, NULL);

reboot:
    pm_reboot();
    while (1) {}
}

int _reboot_bootloader_handler(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    reset_into_bootloader();
    return 0;
}
