/*
 * SPDX-FileCopyrightText: 2021 Gerson Fernando Budke
 * SPDX-License-Identifier: LGPL-2.1-only
 */

#pragma once

/**
 * @ingroup     boards_atxmega-a3bu-xplained
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the ATxmegaA3BU Xplained board.
 *
 * @author      Gerson Fernando Budke <nandojve@gmail.com>
 */
#include "mutex.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <avr/io.h>

#include "periph_cpu.h"

/**
 * @name    Timer peripheral configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev            = (void *)&TCC1,
        .pwr            = PWR_RED_REG(PWR_PORT_C, PR_TC1_bm),
        .type           = TC_TYPE_1,
        .int_lvl        = { CPU_INT_LVL_LOW,
                            CPU_INT_LVL_OFF,
                            CPU_INT_LVL_OFF,
                            CPU_INT_LVL_OFF },
    },
    {
        .dev            = (void *)&TCC0,
        .pwr            = PWR_RED_REG(PWR_PORT_C, PR_TC0_bm),
        .type           = TC_TYPE_0,
        .int_lvl        = { CPU_INT_LVL_LOW,
                            CPU_INT_LVL_LOW,
                            CPU_INT_LVL_LOW,
                            CPU_INT_LVL_LOW },
    }
};

#define TIMER_0_ISRA      TCC1_CCA_vect

#define TIMER_1_ISRA      TCC0_CCA_vect
#define TIMER_1_ISRB      TCC0_CCB_vect
#define TIMER_1_ISRC      TCC0_CCC_vect
#define TIMER_1_ISRD      TCC0_CCD_vect

#define TIMER_NUMOF       ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {   /* J1 */
        .dev            = &USARTC0,
        .pwr            = PWR_RED_REG(PWR_PORT_C, PR_USART0_bm),
        .rx_pin         = GPIO_PIN(PORT_C, 2),
        .tx_pin         = GPIO_PIN(PORT_C, 3),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin        = GPIO_UNDEF,
        .cts_pin        = GPIO_UNDEF,
#endif
        .rx_int_lvl     = CPU_INT_LVL_LOW,
        .tx_int_lvl     = CPU_INT_LVL_LOW,
        .dre_int_lvl    = CPU_INT_LVL_OFF,
    },
    {   /* J4 */
        .dev            = &USARTE0,
        .pwr            = PWR_RED_REG(PWR_PORT_E, PR_USART0_bm),
        .rx_pin         = GPIO_PIN(PORT_E, 2),
        .tx_pin         = GPIO_PIN(PORT_E, 3),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin        = GPIO_UNDEF,
        .cts_pin        = GPIO_UNDEF,
#endif
        .rx_int_lvl     = CPU_INT_LVL_LOW,
        .tx_int_lvl     = CPU_INT_LVL_LOW,
        .dre_int_lvl    = CPU_INT_LVL_OFF,
    },
};

/* interrupt function name mapping */
#define UART_0_RXC_ISR    USARTC0_RXC_vect    /* Reception Complete Interrupt */
#define UART_0_DRE_ISR    USARTC0_DRE_vect    /* Data Register Empty Interrupt */
#define UART_0_TXC_ISR    USARTC0_TXC_vect    /* Transmission Complete Interrupt */

#define UART_1_RXC_ISR    USARTE0_RXC_vect
#define UART_1_DRE_ISR    USARTE0_DRE_vect
#define UART_1_TXC_ISR    USARTE0_TXC_vect

#define UART_NUMOF        ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    {   /* J1 */
        .dev                = &TWIC,
        .pwr                = PWR_RED_REG(PWR_PORT_C, PR_TWI_bm),
        .sda_pin            = GPIO_PIN(PORT_C, 0),
        .scl_pin            = GPIO_PIN(PORT_C, 1),
        .speed              = I2C_SPEED_NORMAL,
        .int_lvl            = CPU_INT_LVL_LOW,
    },
};

#define I2C_0_ISR           TWIC_TWIM_vect

#define I2C_NUMOF           ARRAY_SIZE(i2c_config)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev            = &SPIC,
        .pwr            = PWR_RED_REG(PWR_PORT_C, PR_SPI_bm),
        .sck_pin        = GPIO_PIN(PORT_C, 7),
        .miso_pin       = GPIO_PIN(PORT_C, 6),
        .mosi_pin       = GPIO_PIN(PORT_C, 5),
        .ss_pin         = GPIO_PIN(PORT_C, 4),
    },
};

#define SPI_NUMOF         ARRAY_SIZE(spi_config)
/** @} */

#ifdef __cplusplus
}
#endif

#include "periph_conf_common.h"

/** @} */
