/*************************************************************************//**
 *****************************************************************************
 * @file   list.c
 * @brief  list()
 * @author Tsengkasing
 * @date   2016
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

/*****************************************************************************
 *                                list
 *****************************************************************************/
/**
 * Show all files under the current directory.
 * 
 * @param pathname  The full path of the current directory.
 * 
 * @return File descriptor if successful, otherwise -1.
 *****************************************************************************/
PUBLIC int list(const char *pathname, void* buf)
{
	MESSAGE msg;

	msg.type	= LIST;

	msg.PATHNAME	= (void*)pathname;
	msg.BUF 	= buf;
	msg.NAME_LEN	= strlen(pathname);

	send_recv(BOTH, TASK_FS, &msg);
	//assert(msg.type == SYSCALL_RET);

	return msg.FD;
}

