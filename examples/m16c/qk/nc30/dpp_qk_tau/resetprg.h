/***********************************************************************/
/*                                                                     */
/*  FILE        :resetprg.h                                            */
/*  DATE        :Sat, May 03, 2008                                     */
/*  DESCRIPTION :include some headder files.                           */
/*  CPU GROUP   :25                                                    */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.8).     */
/*                                                                     */
/***********************************************************************/

/***************************************************************************
 *  COMPILER for R8C/Tiny
 *  Copyright(c) 2004 Renesas Technology Corp.
 *  And Renesas Solutions Corp.,All Rights Reserved.
 *
 *  resetprg.h : include any headder files
 *
 *  Function: include any Headder files and prototype difinition
 *
 * $Date: 2006/09/13 01:34:37 $
 * $Revision: 1.12 $
 **************************************************************************/

#ifndef __CSTARTDEF__
#define __CSTARTDEF__

#include "cstartdef.h"
#pragma STACKSIZE       __STACKSIZE__           //user stack
#pragma ISTACKSIZE      __ISTACKSIZE__          //interrupt stack

#pragma CREG    _flg_   flg
#pragma CREG    _isp_   isp
#pragma CREG    _sp_    sp
#pragma CREG    _sb_    sb
#pragma CREG    _fb_    fb
#pragma CREG    _intbh_ intbh
#pragma CREG    _intbl_ intbl
_UINT _flg_;
_UINT _sb_;
_UINT _fb_;
_UINT *_sp_;
_UINT *_isp_;
_UINT *_intbl_;
_UINT *_intbh_;

#define  DEF_BANKSELECT        _asm("    .glb    __BankSelect\n"\
                "__BankSelect    .equ    0BH")
#define  DEF_SBREGISTER         _asm("    .glb    __SB__\n"\
                "__SB__    .equ    0400H")

#if __STACKSIZE__ != 0
#define __F_value__    0x0080
#else
#define __F_value__    0x0000
#endif


#if __HEAPSIZE__ != 0
//extern        _UBYTE _far * _mbase;
extern  _UBYTE _far * _mnext;
extern  _UDWORD _msize;
//////////////////////////////////////////
// It's size of heap
// When you want to change size of heap,
// please change this line.
// When you change this line,
// you must modify the value using hex character.

extern _UBYTE heap_area[__HEAPSIZE__];

#pragma inline heap_init()
void heap_init(void)
{
/*      _mbase = &heap_area[0];*/
        _mnext = &heap_area[0];
        _msize = __HEAPSIZE__;
}

#endif
#pragma sectaddress    vector,ROMDATA
#endif
