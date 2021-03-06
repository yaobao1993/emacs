/* Copyright    Massachusetts Institute of Technology    1985	*/

/*

Copyright 1985, 1986, 1987 by the Massachusetts Institute of Technology

Permission to use, copy, modify, and distribute this
software and its documentation for any purpose and without
fee is hereby granted, provided that the above copyright
notice appear in all copies and that both that copyright
notice and this permission notice appear in supporting
documentation, and that the name of M.I.T. not be used in
advertising or publicity pertaining to distribution of the
software without specific, written prior permission.
M.I.T. makes no representations about the suitability of
this software for any purpose.  It is provided "as is"
without express or implied warranty.

*/




/*
 * XMenu:	MIT Project Athena, X Window system menu package
 *
 *	XMenuChangeSelection - Change a menu selection.
 *
 *	Author:		Tony Della Fera, DEC
 *			December 19, 1985
 *
 */

#include "XMenuInt.h"
#include <string.h>

int
XMenuChangeSelection(Display *display, register XMenu *menu, register int p_num, register int s_num, char *data, int data_sw, char *label, int label_sw)
                     		/* previously opened display. */
                         	/* Menu object to be modified. */
                       		/* Pane number to be modified. */
                       		/* Selection number to modified. */
               			/* Data value. */
                		/* Change to new data value? */
                		/* Selection label. */
                 		/* Change to new label? */
{
    register XMPane *p_ptr;	/* XMPane pointer. */
    register XMSelect *s_ptr;	/* XMSelect pointer. */

    int label_length;		/* Label length in characters. */
    int label_width;		/* Label width in pixels. */

    /*
     * Check for NULL pointers!
     */
    if (label == NULL) {
	_XMErrorCode = XME_ARG_BOUNDS;
	return(XM_FAILURE);
    }

    /*
     * Find the right pane.
     */
    p_ptr = _XMGetPanePtr(menu, p_num);
    if (p_ptr == NULL) return(XM_FAILURE);

    /*
     * Find the right selection.
     */
    s_ptr = _XMGetSelectionPtr(p_ptr, s_num);
    if (s_ptr == NULL) return(XM_FAILURE);

    /*
     * Reset the label?
     */
    if (label_sw) {
	/*
	 * Determine label size.
	 */
	label_length = strlen(label);
	label_width = XTextWidth(menu->s_fnt_info, label, label_length);

	/*
	 * Change the selection data.
	 */
	s_ptr->label = label;
	s_ptr->label_width = label_width;
	s_ptr->label_length = label_length;

	/*
	 * Schedule a recompute.
	 */
	menu->recompute = 1;
    }

    /*
     * Reset the data?
     */
    if (data_sw) s_ptr->data = data;

    /*
     * Return successfully.
     */
    _XMErrorCode = XME_NO_ERROR;
    return(s_num);
}
