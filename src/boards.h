/* ************************************************************************
*   File: boards.h                                      Part of CircleMUD *
*  Usage: header file for bulletin boards                                 *
*                                                                         *
*  All rights reserved.  See license.doc for complete information.        *
*                                                                         *
*  Copyright (C) 1993, 94 by the Trustees of the Johns Hopkins University *
*  CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.               *
************************************************************************ */

#define NUM_OF_BOARDS  4 /* change if needed! */
#define MAX_BOARD_MESSAGES  60      /* arbitrary -- change if needed */
#define MAX_MESSAGE_LENGTH 4096 /* arbitrary -- change if needed */

#define INDEX_SIZE    ((NUM_OF_BOARDS*MAX_BOARD_MESSAGES) + 5)

#define BOARD_MAGIC 1048575 /* arbitrary number - see modify.c */

struct board_msginfo {
   int slot_num;     /* pos of message in "master index" */
   char *heading;     /* pointer to message's heading */
   int level;        /* level of poster */
   int heading_len;  /* size of header (for file write) */
   int message_len;  /* size of message text (for file write) */
};

struct board_info_type {
   obj_vnum vnum; /* vnum of this board */
   int read_lvl; /* min level to read messages on this board */
   int write_lvl; /* min level to write messages on this board */
   int remove_lvl; /* min level to remove messages from this board */
   char filename[50]; /* file to save this board to */
   obj_rnum rnum; /* rnum of this board */
};

#define BOARD_VNUM(i) (board_info[i].vnum)
#define READ_LVL(i) (board_info[i].read_lvl)
#define WRITE_LVL(i) (board_info[i].write_lvl)
#define REMOVE_LVL(i) (board_info[i].remove_lvl)
#define FILENAME(i) (board_info[i].filename)
#define BOARD_RNUM(i) (board_info[i].rnum)

#define NEW_MSG_INDEX(i) (msg_index[i][num_of_msgs[i]])
#define MSG_HEADING(i, j) (msg_index[i][j].heading)
#define MSG_SLOTNUM(i, j) (msg_index[i][j].slot_num)
#define MSG_LEVEL(i, j) (msg_index[i][j].level)

int Board_display_msg(int board_type, struct char_data *ch, char *arg, struct obj_data *board);
int Board_show_board(int board_type, struct char_data *ch, char *arg, struct obj_data *board);
int Board_remove_msg(int board_type, struct char_data *ch, char *arg, struct obj_data *board);
int Board_write_message(int board_type, struct char_data *ch, char *arg, struct obj_data *board);
void Board_save_board(int board_type);
void Board_load_board(int board_type);
void Board_reset_board(int board_type);
void Board_clear_board(int board_type);
void Board_clear_all(void);
