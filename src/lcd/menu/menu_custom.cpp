/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//
// Custom User Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(CUSTOM_USER_MENUS)

#include "menu.h"
#include "../../gcode/queue.h"

#ifdef USER_SCRIPT_DONE
  #define _DONE_SCRIPT "\n" USER_SCRIPT_DONE
#else
  #define _DONE_SCRIPT ""
#endif

void _lcd_user_gcode(PGM_P const cmd) {
  queue.inject_P(cmd);
  #if ENABLED(USER_SCRIPT_AUDIBLE_FEEDBACK) && HAS_BUZZER
    ui.completion_feedback();
  #endif
  #if ENABLED(USER_SCRIPT_RETURN)
    ui.return_to_status();
  #endif
}

void menu_user() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);
  #if defined(USER_DESC_1) && defined(USER_GCODE_1)
    ACTION_ITEM_P(PSTR(USER_DESC_1), [](){ _lcd_user_gcode(PSTR(USER_GCODE_1 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_2) && defined(USER_GCODE_2)
    ACTION_ITEM_P(PSTR(USER_DESC_2), [](){ _lcd_user_gcode(PSTR(USER_GCODE_2 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_3) && defined(USER_GCODE_3)
    ACTION_ITEM_P(PSTR(USER_DESC_3), [](){ _lcd_user_gcode(PSTR(USER_GCODE_3 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_4) && defined(USER_GCODE_4)
    ACTION_ITEM_P(PSTR(USER_DESC_4), [](){ _lcd_user_gcode(PSTR(USER_GCODE_4 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_5) && defined(USER_GCODE_5)
    ACTION_ITEM_P(PSTR(USER_DESC_5), [](){ _lcd_user_gcode(PSTR(USER_GCODE_5 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_6) && defined(USER_GCODE_6)
    ACTION_ITEM_P(PSTR(USER_DESC_6), [](){ _lcd_user_gcode(PSTR(USER_GCODE_6 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_7) && defined(USER_GCODE_7)
    ACTION_ITEM_P(PSTR(USER_DESC_7), [](){ _lcd_user_gcode(PSTR(USER_GCODE_7 _DONE_SCRIPT)); });
  #endif
  #if defined(USER_DESC_8) && defined(USER_GCODE_8)
    ACTION_ITEM_P(PSTR(USER_DESC_8), [](){ _lcd_user_gcode(PSTR(USER_GCODE_8 _DONE_SCRIPT)); });
  #endif
  END_MENU();
}

#endif // HAS_LCD_MENU && CUSTOM_USER_MENUS