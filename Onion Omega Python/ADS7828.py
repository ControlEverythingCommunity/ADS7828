# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# ADS7828
# This code is designed to work with the ADS7828_I2CAD8 I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7828_I2CAD8#tabs-0-product_tabset-2

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# ADS7828 address, 0x48(72)
# Send command byte
#		0x04(04)	channel-0 selected,  A/D Converter ON
data = [0x04]
i2c.write(0x48, data)

time.sleep(0.5)

# ADS7828 address, 0x48(72)
# Read data back from 0x00(00), 2 bytes
# raw_adc MSB, raw_adc LSB
data = i2c.readBytes(0x48, 0x00, 2)

# Convert the data to 12-bits
raw_adc = (data[0] & 0x0F) * 256 + data[1]

# Output data to screen
print "Digital value of analog input : %d" %raw_adc
