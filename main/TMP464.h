#ifndef TMP464_H_
#define TMP464_H_



#define TMP464_I2CADDR_ADD1 0x48  ///< TMP464 address chip 1 
#define TMP464_I2CADDR_ADD2 0x49  ///< TMP464 address chip 2

/*
 * The TMP464 registers
 */

#define TMP464_TEMP_REG             0x00         ///< Temperature register
#define TMP464_TEMP_DIE1            0x01
#define TMP464_TEMP_DIE2            0x02
#define TMP464_CONFIG_REG			0x30
#define TMP464_TEMP_HYST_REG			0x38
#define TMP464_LOCK_REG				0xC4
#define TMP464_MANUFACTURER_ID_REG		0xFE
#define TMP464_DEVICE_ID_REG			0xFF

/* Manufacturer and Device ID */
#define TMP464_MANUFACTURER_ID			0x5449
#define TMP464_DEVICE_ID			0x1468

/*
 * Constants: flags, masks, offsets, ids
 */

#define TMP468_CONFIG_RESERVE			BIT(0)
#define TMP468_CONFIG_SHUTDOWN 			BIT(5)
#define TMP468_CONFIG_ALL_CHANNELS 		GENMASK(15, 7)
#define TMP468_CONFIG_CONV_RATE_MASK 		GENMASK(4, 2)
#define TMP468_CONFIG_CONV_RATE_OFFSET 		2
#define TMP468_UNLOCK				0xEB19
#define TMP468_HYST_MASK			GENMASK(14, 7)

#define TMP468_MAX_TEMP				255000

esp_err_t TMP464_init(void);
bool TMP464_installed(void);
float TMP464_read_temperature(void);
float TMP464_read_temp_die1(void);
float TMP464_read_temp_die2(void);

#endif /* TMP464_H_ */
