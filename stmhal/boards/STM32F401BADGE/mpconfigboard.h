#define MICROPY_HW_BOARD_NAME       "F401BADGE"
#define MICROPY_HW_MCU_NAME         "STM32F401xE"
#define MICROPY_PY_SYS_PLATFORM     "pybadge"

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (1)
#define MICROPY_HW_HAS_LCD          (1)
#define MICROPY_HW_ENABLE_RNG       (0)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (1)

#define MICROPY_BOARD_EARLY_INIT    STM32F4BADGE_board_early_init
void STM32F4BADGE_board_early_init(void);



// HSE is 16MHz, CPU freq set to 84MHz
#define MICROPY_HW_CLK_PLLM (16)
#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV4)
#define MICROPY_HW_CLK_PLLQ (7)


// The pyboard has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// UART config
#define MICROPY_HW_UART2_PORT (GPIOD)
#define MICROPY_HW_UART2_PINS (GPIO_PIN_5 | GPIO_PIN_6)
#define MICROPY_HW_UART6_PORT (GPIOC)
#define MICROPY_HW_UART6_PINS (GPIO_PIN_6 | GPIO_PIN_7)

// UART 2 connects to the external UART headers
#define MICROPY_HW_UART_REPL        PYB_UART_2
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C busses
#define MICROPY_HW_I2C1_SCL (pin_B6)    // arduino connector
#define MICROPY_HW_I2C1_SDA (pin_B7)    // 

// SPI busses
#define MICROPY_HW_SPI1_NAME "X"
#define MICROPY_HW_SPI1_NSS  (pin_A4) // X5
#define MICROPY_HW_SPI1_SCK  (pin_A5) // X6
#define MICROPY_HW_SPI1_MISO (pin_A6) // X7
#define MICROPY_HW_SPI1_MOSI (pin_A7) // X8
#define MICROPY_HW_SPI2_NAME "Y"
#define MICROPY_HW_SPI2_NSS  (pin_B12) // Y5
#define MICROPY_HW_SPI2_SCK  (pin_D3) // Y6
#define MICROPY_HW_SPI2_MISO (pin_B14) // Y7
#define MICROPY_HW_SPI2_MOSI (pin_B15) // Y8

// NEED TO SORT OUT PIN AF 5/6 issue
#define MICROPY_HW_SPI3_NAME "Z"     //For the screen
#define MICROPY_HW_SPI3_NSS  (pin_A15)
#define MICROPY_HW_SPI3_SCK  (pin_B3) 
//#define MICROPY_HW_SPI3_MISO (pin_B4) 
#define MICROPY_HW_SPI3_MOSI (pin_B5) 

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_E4)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLDOWN)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (1)

// LEDs (x2)

#define MICROPY_HW_LED1             (pin_E15) //LED A
#define MICROPY_HW_LED2             (pin_B10) //LED B
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (pin->gpio->BSRRL = pin->pin_mask)
#define MICROPY_HW_LED_OFF(pin)     (pin->gpio->BSRRH = pin->pin_mask)

// SD card detect switch
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_D15)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)

// USB config
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)