# if you’re not sure which board tag you need, make show_boards
# and use make show_submenu for board subs
# will dump a full list:
# -------------------------
# atmegang            Arduino NG or older
# bt                  Arduino BT
# chiwawa             Arduino Industrial 101
# circuitplay32u4cat  Adafruit Circuit Playground
# diecimila           Arduino Duemilanove or Diecimila
# esplora             Arduino Esplora
# ethernet            Arduino Ethernet
# fio                 Arduino Fio
# gemma               Arduino Gemma
# leonardoeth         Arduino Leonardo ETH
# leonardo            Arduino Leonardo
# lilypad             LilyPad Arduino
# LilyPadUSB          LilyPad Arduino USB
# megaADK             Arduino Mega ADK
# mega                Arduino/Genuino Mega or Mega 2560
# micro               Arduino/Genuino Micro
# mini                Arduino Mini
# nano                Arduino Nano
# one                 Linino One
# pro                 Arduino Pro or Pro Mini
# robotControl        Arduino Robot Control
# robotMotor          Arduino Robot Motor
# uno                 Arduino/Genuino Uno
# unowifi             Arduino Uno WiFi
# yunmini             Arduino Yún Mini
# yun                 Arduino Yún

# --- mega2560 ide 1.0
#BOARD_TAG    = mega2560
#ARDUINO_PORT = /dev/ttyACM0
#include /usr/share/arduino/Arduino.mk

# --- mega2560 ide 1.6
#BOARD_TAG    = mega
#BOARD_SUB    = atmega2560
#MONITOR_PORT = /dev/ttyACM0
#ARDUINO_DIR  = /where/you/installed/arduino-1.6.5
#include /usr/share/arduino/Arduino.mk

#BOARD_TAG = pro
#$BOARD_SUB = 8MHzatmega328
#BOARD_TAG    = uno
# BOARD_TAG    = mega

# -- uno
#BOARD_TAG = uno
#ARDUINO_PORT = /dev/ttyACM*

#BOARD_TAG    = ethernet
#ARDUINO_PORT = /dev/ttyUSB*

#
# I had to use the "old" boatloader with the nano i have
# jsa -2023
# --- nano
BOARD_TAG    = nano
BOARD_SUB    = atmega328old
MONITOR_PORT = /dev/ttyUSB0
#ARDUINO_DIR  = /where/you/installed/arduino-1.6.5
#include /usr/share/arduino/Arduino.mk


AVRDUDE_CONF   = /etc/avrdude.conf
# ARDUINO_DIR = /usr/share/arduino is the default
ARDUINO_DIR = /opt/arduino-sdk

#ARDUINO_LIB_PATH = ${ARDUINO_DIR}/libraries

#ARDMK_DIR = ../lib/Arduino-Makefile
ARDMK_DIR = ../lib/Arduino-Makefile
#ARDUINO_LIBS = Ethernet 


# old config for ethernet card 1
# ARDUINO_LIBS = Ethernet SPI Servo avr-stl-jsa-patched/include jsa-arduino-utils/src


#now for ethernet2

#ARDUINO_LIBS = Ethernet2-adafruit/src Ethernet2-adafruit/src/utility SPI Servo avr-stl-jsa-patched/include gsd_arduino_utils/src lib/ArduinoSTL/src

#ARDUINO_LIBS = SPI Servo Wire ArduinoSTL
ARDUINO_LIBS = SPI Servo Wire SoftwareSerial

# SoftwareSerial SoftwareSerial/utility
USER_LIB_PATH := $(realpath ../lib)
#USER_LIB_PATH := $(realpath ./avr-stl-1.1.1/include)
#USER_LIB_PATH = ./avr-stl
#USER_LIBS = ./avr-stl

CPPFLAGS := -Wno-reorder -Wno-sign-compare -Wno-unused-variable \
-Wno-unused-local-typedefs --std=c++11  -Wno-char-subscripts \
-Wno-strict-aliasing -Os -Wall #\
# -Werror

#-Werror is no good due to library issues

#include /usr/local/arduino/Arduino.mk
#include /usr/share/arduino/Arduino.mk
include ${ARDMK_DIR}/Arduino.mk

#include arduino_custom.mk
#LIBRARYPATH = ./avr-stl

#USER_LIB_PATH := ${PWD}/avr-stl
