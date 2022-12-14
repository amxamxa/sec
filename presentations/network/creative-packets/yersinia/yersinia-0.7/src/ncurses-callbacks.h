/* ncurses_callbacks.h
 * Definitions for the ncurses callbacks
 *
 * $Id: ncurses-callbacks.h 2 2006-04-03 21:04:25Z tomac $ 
 *
 * Yersinia
 * By David Barroso <tomac@wasahero.org> and Alfredo Andres <slay@wasahero.org>
 * Copyright 2005 Alfredo Andres and David Barroso
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __NCURSES_CALLBACKS_H__
#define __NCURSES_CALLBACKS_H__

#if defined(USE_NCURSES) && !defined(RENAMED_NCURSES)
#include <ncurses.h>
#else
#include <curses.h>
#endif

#ifdef HAVE_PANEL_H
#include <panel.h>
#endif

#include <ctype.h>

#include "thread-util.h"
#include "terminal-defs.h"
#include "admin.h"
#include "interfaces.h"
#include "attack.h"

#include "parser.h"


#define ERRORMSG_SIZE   512
#define NCURSES_MIN_ROWS 25
#define NCURSES_MIN_COLS 80
#define NCURSES_REFRESH_TIME 2
#define NCURSES_BWINDOW_SIZE 7

#define NCURSES_KEY_TIMEOUT 250

#define KEY_CTRL_L 12

#define PARAM_SCREEN   10
#define LIST_FILECAPS  9
#define LIST_ATTACKS   8
#define IFACE_SCREEN   7
#define MAIN_SCREEN    6
#define SEC_SCREEN     5
#define ATTACK_SCREEN  4
#define INFO_SCREEN    3
#define HELP_SCREEN    2
#define SPLASH_SCREEN  1

#define INFO_HEIGHT    13 
#define INFO_WIDTH     44
#define MAX_PAD_HEIGHT 40 
#define MAX_PAD_WIDTH  70

#define VIEW_HEIGHT 15
#define VIEW_WIDTH 68

#if defined (TIOCGWINSZ) && defined (HAVE_NCURSES_RESIZETERM)
#define CAN_RESIZE 1
#endif

u_int8_t pointer[MAX_PROTOCOLS];
WINDOW *info_window;

void    ncurses_c_refresh_mwindow(u_int8_t, WINDOW *, u_int8_t, struct term_node *);
void    ncurses_c_refresh_bwindow(u_int8_t, WINDOW *, struct term_node *);
void    ncurses_c_refresh(void);
void    ncurses_c_engine(WINDOW *[], PANEL *[], struct term_node *);
void    ncurses_c_edit_bwindow(u_int8_t, WINDOW *, WINDOW *, struct term_node *);
int8_t  ncurses_c_learn_packet(u_int8_t, u_int8_t, struct term_node *);
int8_t  ncurses_c_set_status_line(char *);
int8_t  ncurses_c_term_resize(struct term_node *);
int8_t  ncurses_c_north(u_int8_t, u_int32_t, u_int32_t *, u_int32_t *, u_int8_t *, u_int32_t *);
int8_t  ncurses_c_south(u_int8_t, u_int32_t, u_int32_t *, u_int32_t *, u_int8_t *, u_int32_t *);
int8_t  ncurses_c_east(u_int8_t, u_int32_t, u_int32_t *, u_int32_t *, u_int8_t *, u_int32_t *);
int8_t  ncurses_c_west(u_int8_t, u_int32_t, u_int32_t *, u_int32_t *, u_int8_t *, u_int32_t *);

void resizeHandler(int);

/* Global stuff */
extern void   thread_error(char *, int8_t);
extern u_int32_t uptime;
extern struct term_tty *tty_tmp;
extern int8_t parser_write_config_file(struct term_tty *);


extern int8_t parser_get_formated_inet_address(u_int32_t, char *, u_int16_t);

/* Terminal stuff */
extern struct terminals *terms;
extern int8_t term_add_node(struct term_node **, int8_t, int32_t, pthread_t);

/* Attack stuff */
extern int8_t attack_stp_learn_packet(void);
extern int8_t attack_launch(struct term_node *, u_int16_t, u_int16_t, struct attack_param *, u_int8_t);
extern int8_t attack_kill_th(struct term_node *, pthread_t );
extern int8_t attack_init_params(struct term_node *, struct attack_param *, u_int8_t);
extern int8_t attack_filter_all_params(struct attack_param *, u_int8_t, u_int8_t *);
extern void   attack_free_params(struct attack_param *, u_int8_t);

#endif
/* vim:set tabstop=4:set expandtab:set shiftwidth=4:set textwidth=78: */
