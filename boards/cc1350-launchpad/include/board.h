/*
 * SPDX-FileCopyrightText: 2021 Jean Pierre Dudey
 * SPDX-License-Identifier: LGPL-2.1-only
 */

#pragma once

/**
 * @ingroup         boards_cc1350_launchpad
 * @{
 *
 * @file
 * @brief           Board specific definitions for TI CC1350 LaunchPad
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 */

#include "periph/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    xtimer configuration
 * @{
 */
#define XTIMER_WIDTH        (16)
#define XTIMER_BACKOFF      (25)
#define XTIMER_ISR_BACKOFF  (20)
/** @} */

/**
 * @name    On-board button configuration
 * @{
 */
#define BTN0_PIN            GPIO_PIN(0, 13)
#define BTN0_MODE           GPIO_IN_PU

#define BTN1_PIN            GPIO_PIN(0, 14)
#define BTN1_MODE           GPIO_IN_PU
/** @} */

/**
 * @brief   On-board LED configuration and controlling
 * @{
 */
#define LED0_PIN            GPIO_PIN(0, 6)          /**< Red   */
#define LED1_PIN            GPIO_PIN(0, 7)          /**< Green */

#define LED0_ON             gpio_set(LED0_PIN)
#define LED0_OFF            gpio_clear(LED0_PIN)
#define LED0_TOGGLE         gpio_toggle(LED0_PIN)

#define LED1_ON             gpio_set(LED1_PIN)
#define LED1_OFF            gpio_clear(LED1_PIN)
#define LED1_TOGGLE         gpio_toggle(LED1_PIN)
/** @} */

#ifdef __cplusplus
}
#endif

/** @} */
