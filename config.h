/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 LeafLabs LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *****************************************************************************/

/**
 *  @file config.h
 *
 *  @brief bootloader settings and macro defines
 *
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "common.h"



/* Speed controls for strobing the LED pin */
#define BLINK_FAST 0x50000
#define BLINK_SLOW 0x100000


// The USB clock is the same for all boards
#define RCC_APB1ENR_USB_CLK   0x00800000

// Clocks for the backup domain registers
#define RCC_APB1ENR_PWR_CLK   0x10000000
#define RCC_APB1ENR_BKP_CLK   0x08000000


#ifndef ALT0_MSG_STR
#define ALT0_MSG_STR "STM32duino bootloader v1.0  ERROR. Upload to RAM not supported."
#endif

#ifndef ALT1_MSG_STR
#define ALT1_MSG_STR "STM32duino bootloader v1.0  Upload to Flash 0x8005000"
#endif

#ifndef ALT2_MSG_STR
#define ALT2_MSG_STR "STM32duino bootloader v1.0  Upload to Flash 0x8002000"
#endif

#ifndef ALT3_MSG_STR
#define ALT3_MSG_STR "STM32duino bootloader v1.0  Upload to Flash 0x8001800"
#endif

// Jump locations for legacy bootloader (0x8005000) and new / smaller bootloder (0x8002000)
#define USER_CODE_FLASH0X8005000    ((u32)0x08005000)
#define USER_CODE_FLASH0X8002000    ((u32)0x08002000)
#define USER_CODE_FLASH0X8001800    ((u32)0x08001800)

#define LARGEST_FLASH_PAGE_SIZE 0x800

// Upload to RAM has been removed / depreacted so these values a not used any more
#define USER_CODE_RAM               ((u32)0x20000C00)

// RAM_END, set ram end to the end of ram on the device wth the least RAM (STM32F103C)
#define RAM_END                     ((u32)0x20005000)

/* Porting information Please read.

    These defineds are use to setup the hardware of the GPIO.
    See http://www.st.com/web/en/resource/technical/document/reference_manual/CD00171190.pdf

    Two GPIO pins need to be defined, the LED and the Button.

    For each pin, the following is required

    LED_BANK, this is the GPIO port, e.g. GPIOA,GPIOB, GPIOC etc etc etc
    LED_PIN, this is the pin number e.g PB1 = 1
    LED_ON_STATE is whether the pin needs to be 1 or 0 for the LED to be lit, this is needed because on some boards the led is wired between Vcc and the Pin
    instead of from the pin to GND

    BUTTON_BANK   Port name of the pin used for the button
    #define BUTTON_PIN
    #define BUTTON_PRESSED_STATE 1
*/

#if defined TARGET_MAPLE_MINI

    #define HAS_MAPLE_HARDWARE 1

    #define LED_BANK         GPIOB
    #define LED_PIN          1
    #define LED_ON_STATE     1

    /* On the Mini, BUT is PB8 */
    #define BUTTON_BANK      GPIOB
    #define BUTTON_PIN           8
    #define BUTTON_PRESSED_STATE 1

    /* USB Disc Pin Setup.   USB DISC is PB9 */
    #define USB_DISC_BANK       GPIOB
    #define USB_DISC_PIN            9

#elif defined TARGET_MAPLE_REV3

    #warning "Target MAPLE_REV3"

// Flag that this type of board has the custom maple disconnect hardware
    #define HAS_MAPLE_HARDWARE 1

    #define LED_BANK         GPIOB
    #define LED_PIN              1
    #define LED_ON_STATE     1

    #define BUTTON_BANK      GPIOB
    #define BUTTON_PIN           8
    #define BUTTON_PRESSED_STATE 1

    /* USB Disc Pin Setup.   USB DISC is PB9 */
    #define USB_DISC_BANK         GPIOB
    #define USB_DISC_PIN              9

#elif defined TARGET_MAPLE_REV5

// Flag that this type of board has the custom maple disconnect hardware
    #define HAS_MAPLE_HARDWARE 1

    #define LED_BANK         GPIOA
    #define LED_PIN              5
    #define LED_ON_STATE     0

    /* On the Mini, BUT is PB8 */
    #define BUTTON_BANK      GPIOC
    #define BUTTON_PIN           9

    /* USB Disc Pin Setup.   USB DISC is PB9 */
    #define USB_DISC_BANK         GPIOB
    #define USB_DISC_PIN              9

#elif defined TARGET_GENERIC_F103_PC13


    #define LED_BANK            GPIOC
    #define LED_PIN             13
    #define LED_ON_STATE        0

// Use Boot1 PB2 as the button, as hardly anyone uses this pin as GPIO
// Need to set the button input mode to just CR_INPUT and not CR_INPUT_PU_PD because the external pullup on the jumplink is very weak
	#define BUTTON_INPUT_MODE 	CR_INPUT
    #define BUTTON_BANK GPIOB
    #define BUTTON_PIN 2
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_STINKFAN


    #define XTAL16M


#elif defined TARGET_GENERIC_F103_PG15

    #define LED_BANK            GPIOG
    #define LED_PIN             15
    #define LED_ON_STATE        1

    // Button (if you have one)
    #define BUTTON_BANK GPIOC
    #define BUTTON_PIN 14
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PD2

    #define LED_BANK            GPIOD
    #define LED_PIN             2
    #define LED_ON_STATE        1

    // Button (if you have one)
    #define BUTTON_BANK GPIOC
    #define BUTTON_PIN 14
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PD1

    #define LED_BANK            GPIOD
    #define LED_PIN             1
    #define LED_ON_STATE        1

    // Button (if you have one)
    #define BUTTON_BANK GPIOC
    #define BUTTON_PIN 14
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PA1

    #define LED_BANK            GPIOA
    #define LED_PIN             1
    #define LED_ON_STATE        1

    // Button (if you have one)
    #define BUTTON_BANK GPIOC
    #define BUTTON_PIN 14
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PA1_BUTTON_PA8

    #define LED_BANK            GPIOA
    #define LED_PIN             1
    #define LED_ON_STATE        1

    #define BUTTON_BANK GPIOA
    #define BUTTON_PIN 8
    #define BUTTON_PRESSED_STATE 0

#elif defined TARGET_GENERIC_F103_PB9

    #define LED_BANK            GPIOB
    #define LED_PIN             9
    #define LED_ON_STATE        1

    // Button (if you have one)
    #define BUTTON_BANK GPIOC
    #define BUTTON_PIN 14
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PE2

    #define LED_BANK            GPIOE
    #define LED_PIN             2
    #define LED_ON_STATE        1

#elif defined TARGET_GENERIC_F103_PA9

    #define LED_BANK            GPIOA
    #define LED_PIN             9
    #define LED_ON_STATE        1

#elif defined TARGET_GENERIC_F103_PE5

    #define LED_BANK            GPIOE
    #define LED_PIN             5
    #define LED_ON_STATE        1

    #define BUTTON_BANK GPIOD
    #define BUTTON_PIN 2
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PE5_BUTTON_PA0

    #define LED_BANK            GPIOE
    #define LED_PIN             5
    #define LED_ON_STATE        1

    #define BUTTON_BANK GPIOA
    #define BUTTON_PIN 0
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_GENERIC_F103_PB7

    #define LED_BANK            GPIOB
    #define LED_PIN             7
    #define LED_ON_STATE        1

#elif defined TARGET_GENERIC_F103_PB0

    #define LED_BANK            GPIOB
    #define LED_PIN         0
    #define LED_ON_STATE        1
    #define BOOTLOADER_WAIT 30

#elif defined TARGET_STBEE

    #define HAS_MAPLE_HARDWARE  1

    #define LED_BANK        GPIOD
    #define LED_PIN         4
    #define LED_ON_STATE        0

    /* BUTTON is PA0 (pull down) */
    #define BUTTON_BANK     GPIOA
    #define BUTTON_PIN      0
    #define BUTTON_PRESSED_STATE    1

    /* USB Disc Pin Setup.   USB DISC is PD3 */
    #define USB_DISC_BANK           GPIOD
    #define USB_DISC_PIN                3

    /* CRISTAL 12MHz */
    #define XTAL12M     1

#elif defined TARGET_NAZE32

    #define LED_BANK            GPIOB
    #define LED_PIN             3
    #define LED_ON_STATE        0

#elif defined TARGET_GENERIC_F103_PB12

    #define LED_BANK            GPIOB
    #define LED_PIN             12
    #define LED_ON_STATE        1
    #define BOOTLOADER_WAIT 10

    #define BUTTON_BANK      GPIOB
    #define BUTTON_PIN           2
    #define BUTTON_PRESSED_STATE 1

#elif defined TARGET_HYTINY_STM32F103T

    #define HAS_MAPLE_HARDWARE 1


    #define LED_BANK            GPIOA
    #define LED_PIN             1
    #define LED_ON_STATE        0
    #define BOOTLOADER_WAIT 30

    /* USB Disc Pin Setup.   USB DISC is PA0 */
    #define USB_DISC_BANK       GPIOA
    #define USB_DISC_PIN            0

#elif defined TARGET_DSO138

    #define LED_BANK            GPIOA
    #define LED_PIN             15
    #define LED_ON_STATE        0

    // "OK" Button
    #define BUTTON_BANK GPIOB
    #define BUTTON_PIN 15
    #define BUTTON_PRESSED_STATE 0

#elif defined TARGET_GD32F1_FRANKENMAPLE

    #define HAS_MAPLE_HARDWARE 1

    #define LED_BANK         GPIOC
    #define LED_PIN          13
    #define LED_ON_STATE     1


    /*
    #define BUTTON_BANK      GPIOB
    #define BUTTON_PIN           8
    #define BUTTON_PRESSED_STATE 1
    */

    /* USB Disc Pin Setup.   USB DISC is PB9 */
    #define USB_DISC_BANK       GPIOB
    #define USB_DISC_PIN        9

    /* CRISTAL 12MHz */
    #define XTAL12M     1

#elif defined TARGET_GD32F1_GENERIC_F103_PC13

    #define LED_BANK            GPIOC
    #define LED_PIN             13
    #define LED_ON_STATE        0

    // Button (if you have one)

//  #define BUTTON_BANK GPIOC
//  #define BUTTON_PIN 14
//  #define BUTTON_PRESSED_STATE 1

    /* CRISTAL 12MHz */
    #define XTAL12M     1


#else
    #error "No config for this target"
#endif

// Check if button pulldown should be enabled 
// Default to True as this was the default prior to needing to disable it
// in order to use the boot1 pin on the Blue Pill which has a very week pullup
#ifndef BUTTON_INPUT_MODE
	#define BUTTON_INPUT_MODE 	CR_INPUT_PU_PD
#endif

#define STARTUP_BLINKS 5
#ifndef BOOTLOADER_WAIT
#ifdef BUTTON_BANK
    #define BOOTLOADER_WAIT 6
#else
    #define BOOTLOADER_WAIT 30
#endif
#endif

// defines for USB (DONT CHANGE)
#define VEND_ID0 0xAF
#define VEND_ID1 0x1E
#define PROD_ID0 0x03
#define PROD_ID1 0x00

// Value to place in RTC backup register 10 for persistent bootloader mode
#define RTC_BOOTLOADER_FLAG 0x424C
#define RTC_BOOTLOADER_JUST_UPLOADED 0x424D
#endif
