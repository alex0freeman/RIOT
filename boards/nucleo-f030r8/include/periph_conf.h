/*
 * SPDX-FileCopyrightText: 2016 Inria
 * SPDX-License-Identifier: LGPL-2.1-only
 */

#pragma once

/**
 * @ingroup     boards_nucleo-f030r8
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the nucleo-f030r8 board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      José Ignacio Alamos <jialamos@uc.cl>
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

/* This board provides an LSE */
#ifndef CONFIG_BOARD_HAS_LSE
#define CONFIG_BOARD_HAS_LSE        1
#endif

/* This board provides an HSE */
#ifndef CONFIG_BOARD_HAS_HSE
#define CONFIG_BOARD_HAS_HSE        1
#endif

#include "periph_cpu.h"
#include "clk_conf.h"
#include "cfg_i2c1_pb8_pb9.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name   Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM1,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB2ENR_TIM1EN,
        .bus      = APB2,
        .irqn     = TIM1_CC_IRQn
    }
};

#define TIMER_0_ISR         (isr_tim1_cc)

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name   UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev        = USART2,
        .rcc_mask   = RCC_APB1ENR_USART2EN,
        .rx_pin     = GPIO_PIN(PORT_A, 3),
        .tx_pin     = GPIO_PIN(PORT_A, 2),
        .rx_af      = GPIO_AF1,
        .tx_af      = GPIO_AF1,
        .bus        = APB1,
        .irqn       = USART2_IRQn
    },
    {
        .dev        = USART1,
        .rcc_mask   = RCC_APB2ENR_USART1EN,
        .rx_pin     = GPIO_PIN(PORT_A, 10),
        .tx_pin     = GPIO_PIN(PORT_A, 9),
        .rx_af      = GPIO_AF1,
        .tx_af      = GPIO_AF1,
        .bus        = APB2,
        .irqn       = USART1_IRQn
    }
};

#define UART_0_ISR          (isr_usart2)
#define UART_1_ISR          (isr_usart1)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name    PWM configuration
 * @{
 */
static const pwm_conf_t pwm_config[] = {
    {
        .dev      = TIM3,
        .rcc_mask = RCC_APB1ENR_TIM3EN,
        .chan     = { { .pin = GPIO_PIN(PORT_B, 4) /* D5 */, .cc_chan = 0},
                      { .pin = GPIO_PIN(PORT_B, 5) /* D4 */, .cc_chan = 1},
                      { .pin = GPIO_UNDEF,                   .cc_chan = 0},
                      { .pin = GPIO_UNDEF,                   .cc_chan = 0} },
        .af       = GPIO_AF1,
        .bus      = APB1
    },
    {
        .dev      = TIM15,
        .rcc_mask = RCC_APB2ENR_TIM15EN,
        .chan     = { { .pin = GPIO_PIN(PORT_B, 14), .cc_chan = 0},
                      { .pin = GPIO_PIN(PORT_B, 15), .cc_chan = 1},
                      { .pin = GPIO_UNDEF,           .cc_chan = 0},
                      { .pin = GPIO_UNDEF,           .cc_chan = 0} },
        .af       = GPIO_AF1,
        .bus      = APB2
    }
};

#define PWM_NUMOF           ARRAY_SIZE(pwm_config)
/** @} */

/**
 * @name   SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI1,
        .mosi_pin = GPIO_PIN(PORT_A, 7),
        .miso_pin = GPIO_PIN(PORT_A, 6),
        .sclk_pin = GPIO_PIN(PORT_A, 5),
        .cs_pin   = GPIO_PIN(PORT_A, 4),
        .mosi_af  = GPIO_AF0,
        .miso_af  = GPIO_AF0,
        .sclk_af  = GPIO_AF0,
        .cs_af    = GPIO_AF0,
        .rccmask  = RCC_APB2ENR_SPI1EN,
        .apbbus   = APB2
    },
    {
        .dev      = SPI2,
        .mosi_pin = GPIO_PIN(PORT_B, 15),
        .miso_pin = GPIO_PIN(PORT_B, 14),
        .sclk_pin = GPIO_PIN(PORT_B, 13),
        .cs_pin   = GPIO_PIN(PORT_B, 12),
        .mosi_af  = GPIO_AF0,
        .miso_af  = GPIO_AF0,
        .sclk_af  = GPIO_AF0,
        .cs_af    = GPIO_AF0,
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1
    },
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */

/**
 * @name   ADC configuration
 * @{
 */
static const adc_conf_t adc_config[] = {
    { GPIO_PIN(PORT_A, 0), 0 },
    { GPIO_PIN(PORT_A, 1), 1 },
    { GPIO_PIN(PORT_A, 4), 4 },
    { GPIO_PIN(PORT_B, 0), 8 },
    { GPIO_PIN(PORT_C, 1), 11 },
    { GPIO_PIN(PORT_C, 0), 10 }
};

#define ADC_NUMOF           ARRAY_SIZE(adc_config)
/** @} */

#ifdef __cplusplus
}
#endif

/** @} */
