#define MICROPY_HW_BOARD_NAME       "MYH750"
#define MICROPY_HW_MCU_NAME         "STM32H750"

#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define FORCE_RESRT_MODE_1          (1)
#define MICROPY_HW_ENABLE_DCMI      (1)
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_PY_THREAD           (1)


// The board has an 8MHz HSE, the following gives 400MHz CPU speed
#define MICROPY_HW_CLK_PLLM (4)
#define MICROPY_HW_CLK_PLLN (400)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (4)
#define MICROPY_HW_CLK_PLLR (2)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M (4)
#define MICROPY_HW_CLK_PLL3N (120)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (5)
#define MICROPY_HW_CLK_PLL3R (2)

// UART config
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_A10)
#define MICROPY_HW_UART_REPL        PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

// LEDs
#define MICROPY_HW_LED1             (pin_C0)    // green
#define MICROPY_HW_LED2             (pin_C1)    // blue
#define MICROPY_HW_LED3             (pin_C2)   // red
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_FS              (1)

