/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
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
 */

#include <stdio.h>
#include <string.h>

#include STM32_HAL_H

#include "py/nlr.h"
#include "py/runtime.h"

#if MICROPY_HW_HAS_UGFX

#include "pin.h"
#include "ugfx.h"
#include "gfx.h"

#include "genhdr/pins.h"
#include "bufhelper.h"

/// \moduleref pyb
/// \class UGFX - uGFX based driver for LCDs
///
/// The UGFX class is used to control a wide range of LCDs, as defined in 
/// the config headers.
///
/// The connections must also be configured in the configuration 
/// header files
///
///     lcd = pyb.UGFX()     # if pyskin is in the Y position
///
/// Then you can use:
///
///     lcd.light(True)                       # turn the backlight on
///     lcd.write('Hello world!\n',10,10)     # print text to the screen
///



systemticks_t gfxSystemTicks(void)
{
	return HAL_GetTick();
}
 
systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
{
	return ms;
}

typedef struct _pyb_ugfx_obj_t {
    mp_obj_base_t base;

    // hardware control for the LCD
	// configured in headers - makes things faster
    //SPI_HandleTypeDef *spi;
    //const pin_obj_t *pin_cs1;
    //const pin_obj_t *pin_rst;
    //const pin_obj_t *pin_a0;
    //const pin_obj_t *pin_bl;

} pyb_ugfx_obj_t;



/// \classmethod \constructor(skin_position)
///
/// Construct an UGFX object.
STATIC mp_obj_t pyb_ugfx_make_new(const mp_obj_type_t *type, mp_uint_t n_args, mp_uint_t n_kw, const mp_obj_t *args) {
    // check arguments
    mp_arg_check_num(n_args, n_kw, 0, 0, false);

    // get LCD position
    //const char *lcd_id = mp_obj_str_get_str(args[0]);

    // create lcd object
    pyb_ugfx_obj_t *ugfx = m_new_obj(pyb_ugfx_obj_t);
    ugfx->base.type = &pyb_ugfx_type;
	
	gfxInit();

	return ugfx;
}
/*
/// \method contrast(value)
///
/// Set the contrast of the LCD.  Valid values are between 0 and 47.
STATIC mp_obj_t pyb_lcd_contrast(mp_obj_t self_in, mp_obj_t contrast_in) {
    pyb_lcd_obj_t *self = self_in;
    int contrast = mp_obj_get_int(contrast_in);
    if (contrast < 0) {
        contrast = 0;
    } else if (contrast > 0x2f) {
        contrast = 0x2f;
    }
    lcd_out(self, LCD_INSTR, 0x81); // electronic volume mode set
    lcd_out(self, LCD_INSTR, contrast); // electronic volume register set
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(pyb_lcd_contrast_obj, pyb_lcd_contrast);
*/
/*
/// \method light(value)
///
/// Turn the backlight on/off.  True or 1 turns it on, False or 0 turns it off.
STATIC mp_obj_t pyb_lcd_light(mp_obj_t self_in, mp_obj_t value) {
    pyb_lcd_obj_t *self = self_in;
    if (mp_obj_is_true(value)) {
        self->pin_bl->gpio->BSRRL = self->pin_bl->pin_mask; // set pin high to turn backlight on
    } else {
        self->pin_bl->gpio->BSRRH = self->pin_bl->pin_mask; // set pin low to turn backlight off
    }
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(pyb_lcd_light_obj, pyb_lcd_light);
*/
/*
/// \method write(str)
///
/// Write the string `str` to the screen.  It will appear immediately.
STATIC mp_obj_t pyb_lcd_write(mp_obj_t self_in, mp_obj_t str) {
    pyb_lcd_obj_t *self = self_in;
    mp_uint_t len;
    const char *data = mp_obj_str_get_data(str, &len);
    //lcd_write_strn(self, data, len);
	//gwinPrintf(GW1,data);
	font_t font12 = gdispOpenFont("DejaVuSans12");
	gdispDrawString(60, 60, data, font12, HTML2COLOR(0xFFFF00));
	gdispCloseFont(font12);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(pyb_lcd_write_obj, pyb_lcd_write);
*/
/*
/// \method fill(colour)
///
/// Fill the screen with the given colour (0 or 1 for white or black).
///
/// This method writes to the hidden buffer.  Use `show()` to show the buffer.
STATIC mp_obj_t pyb_lcd_fill(mp_obj_t self_in, mp_obj_t col_in) {
    pyb_lcd_obj_t *self = self_in;
    int col = mp_obj_get_int(col_in);
    if (col) {
        col = 0xff;
    }
    memset(self->pix_buf, col, LCD_PIX_BUF_BYTE_SIZE);
    memset(self->pix_buf2, col, LCD_PIX_BUF_BYTE_SIZE);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(pyb_lcd_fill_obj, pyb_lcd_fill);
*/

/// \method text(str, x, y, colour)
///
/// Draw the given text to the position `(x, y)` using the given colour (0 or 1).
///
/// This method writes to the hidden buffer.  Use `show()` to show the buffer.
STATIC mp_obj_t pyb_ugfx_text(mp_uint_t n_args, const mp_obj_t *args) {
    // extract arguments
    //pyb_ugfx_obj_t *self = args[0];
    mp_uint_t len;
    const char *data = mp_obj_str_get_data(args[1], &len);
    int x0 = mp_obj_get_int(args[2]);
    int y0 = mp_obj_get_int(args[3]);
    int col = mp_obj_get_int(args[4]);

    font_t font = gdispOpenFont("ui2");  //TODO: save fotn handle globally or in lcd object
	gdispDrawString(x0, y0, data, font, col);	
	gdispCloseFont(font);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(pyb_ugfx_text_obj, 5, 5, pyb_ugfx_text);


STATIC const mp_map_elem_t pyb_ugfx_locals_dict_table[] = {
    // instance methods
//    { MP_OBJ_NEW_QSTR(MP_QSTR_command), (mp_obj_t)&pyb_lcd_command_obj },
//    { MP_OBJ_NEW_QSTR(MP_QSTR_contrast), (mp_obj_t)&pyb_lcd_contrast_obj },
 //   { MP_OBJ_NEW_QSTR(MP_QSTR_light), (mp_obj_t)&pyb_lcd_light_obj },
//    { MP_OBJ_NEW_QSTR(MP_QSTR_write), (mp_obj_t)&pyb_lcd_write_obj },
//    { MP_OBJ_NEW_QSTR(MP_QSTR_fill), (mp_obj_t)&pyb_lcd_fill_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_text), (mp_obj_t)&pyb_ugfx_text_obj },
	
	//class constants
    { MP_OBJ_NEW_QSTR(MP_QSTR_RED),        MP_OBJ_NEW_SMALL_INT(Red) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_BLUE),       MP_OBJ_NEW_SMALL_INT(Blue) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_GREEN),      MP_OBJ_NEW_SMALL_INT(Green) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_BLACK),      MP_OBJ_NEW_SMALL_INT(Black) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_WHITE),      MP_OBJ_NEW_SMALL_INT(White) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_YELLOW),     MP_OBJ_NEW_SMALL_INT(Yellow) },

};

STATIC MP_DEFINE_CONST_DICT(pyb_ugfx_locals_dict, pyb_ugfx_locals_dict_table);

const mp_obj_type_t pyb_ugfx_type = {
    { &mp_type_type },
    .name = MP_QSTR_UGFX,
    .make_new = pyb_ugfx_make_new,
    .locals_dict = (mp_obj_t)&pyb_ugfx_locals_dict,
};

#endif // MICROPY_HW_HAS_UGFX
