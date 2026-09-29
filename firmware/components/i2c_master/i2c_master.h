/* MIT License
   Copyright (c) 2026 teomanshalom
*/
#pragma once
#include "esp_err.h"
#include "driver/i2c.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t i2c_master_init(i2c_port_t port, gpio_num_t sda_io, gpio_num_t scl_io, int clk_speed_hz);
esp_err_t i2c_master_deinit(i2c_port_t port);

/* Scan bus: fills found_addrs array with addresses and returns count (max_addrs). */
int i2c_master_scan(i2c_port_t port, uint8_t *found_addrs, size_t max_addrs);

/* Transfer: tx may be NULL if only reading; rx may be NULL if only writing.
   rx_len bytes will be read if rx != NULL. Timeout in ms. */
esp_err_t i2c_master_transfer(i2c_port_t port, uint8_t slave_addr,
                              const uint8_t *tx, size_t tx_len,
                              uint8_t *rx, size_t rx_len,
                              TickType_t ticks_to_wait);

#ifdef __cplusplus
}
#endif
