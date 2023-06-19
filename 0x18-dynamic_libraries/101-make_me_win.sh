#!/bin/bash
wget -P /tmp https://github.com/S1M0BH/alx-low_level_programming/blob/main/0x18-dynamic_libraries/test.so
export LD_PRELOAD=/tmp/test.so