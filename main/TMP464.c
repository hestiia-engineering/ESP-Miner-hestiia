#include <stdio.h>
#include "esp_log.h"
#include "i2c_bitaxe.h"

#include "TMP464.h"

// I2C_MASTER_SCL_IO 48        /*!< GPIO number used for I2C master clock */
// I2C_MASTER_SDA_IO 47        /*!< GPIO number used for I2C master data  */

static i2c_master_dev_handle_t TMP464_dev_handle;

static const char *TAG = "Sensor_task";

/**
 * @brief Initialize the TMP464 sensor.
 *
 * @return esp_err_t ESP_OK on success, or an error code on failure.
 */
esp_err_t TMP464_init(void) {
    ESP_LOGI(TAG, "Init Sensor");
    return i2c_bitaxe_add_device(TMP464_I2CADDR_ADD1, &TMP464_dev_handle);
}

bool TMP464_installed(void)
{
    uint8_t data[2];
    esp_err_t result = ESP_OK;

    // read the configuration register
    ESP_LOGI(TAG, "Reading configuration register");
    result = i2c_bitaxe_register_read(TMP464_dev_handle, TMP464_CONFIG_REG, data, 2);
    ESP_LOGI(TAG, "Configuration = %02X %02X", data[0], data[1]);

    return (result == ESP_OK?true:false);
}

float TMP464_read_temperature(void)
{
    uint8_t data[2];
    uint16_t raw_value;
    float result;

    ESP_ERROR_CHECK(i2c_bitaxe_register_read(TMP464_dev_handle, TMP464_TEMP_REG, data, 2));
    ESP_LOGI(TAG, "Raw Temperature = %02X %02X", data[0], data[1]);

    raw_value = data[0] << 8 & data[1];
    result = raw_value * 0.0078125; 
    //ESP_LOGI(TAG, "Temperature[%d] = %d", device_index, data[0]);
    return result;
}