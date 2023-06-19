#!/bin/bash
wget -P /tmp https://github.com/S1M0BH/alx-low_level_programming/blob/main/0x18-dynamic_libraries/te.so
export LD_PRELOAD=/tmp/te.so
