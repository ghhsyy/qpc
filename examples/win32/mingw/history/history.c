/*****************************************************************************
* Model: history.qm
* File:  ./history.c
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::history.c} ..........................................................*/
#include "qep_port.h"
#include "qassert.h"
#include "history.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Q_DEFINE_THIS_FILE

/*${SMs::ToastOven} ........................................................*/
typedef struct {
/* protected: */
    QHsm super;
/* private state histories */
    QStateHandler his_doorClosed;
} ToastOven;

/* protected: */
static QState ToastOven_initial(ToastOven * const me, QEvt const * const e);
static QState ToastOven_doorClosed(ToastOven * const me, QEvt const * const e);
static QState ToastOven_heating(ToastOven * const me, QEvt const * const e);
static QState ToastOven_toasting(ToastOven * const me, QEvt const * const e);
static QState ToastOven_baking(ToastOven * const me, QEvt const * const e);
static QState ToastOven_off(ToastOven * const me, QEvt const * const e);
static QState ToastOven_doorOpen(ToastOven * const me, QEvt const * const e);
static QState ToastOven_final(ToastOven * const me, QEvt const * const e);


static ToastOven l_oven; /* the only instance of the ToastOven class */

/* global-scope definitions -----------------------------------------*/
QHsm * const the_oven = (QHsm *)&l_oven;       /* the opaque pointer */

/*${SMs::ToastOven_ctor} ...................................................*/
void ToastOven_ctor(void) {
    ToastOven *me = &l_oven;
    QHsm_ctor(&me->super, Q_STATE_CAST(&ToastOven_initial));
}
/*${SMs::ToastOven} ........................................................*/
/*${SMs::ToastOven::SM} ....................................................*/
static QState ToastOven_initial(ToastOven * const me, QEvt const * const e) {
    /* ${SMs::ToastOven::SM::initial} */
    (void)e; /* avoid compiler warning */
    /* state history attributes */
    me->his_doorClosed = Q_STATE_CAST(&ToastOven_off);
    return Q_TRAN(&ToastOven_doorOpen);
}
/*${SMs::ToastOven::SM::doorClosed} ........................................*/
static QState ToastOven_doorClosed(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorClosed} */
        case Q_ENTRY_SIG: {
            printf("door-Closed;");
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed} */
        case Q_EXIT_SIG: {
            me->his_doorClosed = QHsm_state(me); /* save history */
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::initial} */
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&ToastOven_off);
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::TERMINATE} */
        case TERMINATE_SIG: {
            status_ = Q_TRAN(&ToastOven_final);
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::OPEN} */
        case OPEN_SIG: {
            status_ = Q_TRAN(&ToastOven_doorOpen);
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::TOAST} */
        case TOAST_SIG: {
            status_ = Q_TRAN(&ToastOven_toasting);
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::BAKE} */
        case BAKE_SIG: {
            status_ = Q_TRAN(&ToastOven_baking);
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::OFF} */
        case OFF_SIG: {
            status_ = Q_TRAN(&ToastOven_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::doorClosed::heating} ...............................*/
static QState ToastOven_heating(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorClosed::heating} */
        case Q_ENTRY_SIG: {
            printf("heater-On;");
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::ToastOven::SM::doorClosed::heating} */
        case Q_EXIT_SIG: {
            printf("heater-Off;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_doorClosed);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::doorClosed::heating::toasting} .....................*/
static QState ToastOven_toasting(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorClosed::heating::toasting} */
        case Q_ENTRY_SIG: {
            printf("toasting;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_heating);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::doorClosed::heating::baking} .......................*/
static QState ToastOven_baking(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorClosed::heating::baking} */
        case Q_ENTRY_SIG: {
            printf("baking;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_heating);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::doorClosed::off} ...................................*/
static QState ToastOven_off(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorClosed::off} */
        case Q_ENTRY_SIG: {
            printf("toaster-Off;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_doorClosed);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::doorOpen} ..........................................*/
static QState ToastOven_doorOpen(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::doorOpen} */
        case Q_ENTRY_SIG: {
            printf("door-Open,lamp-On;");
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::ToastOven::SM::doorOpen} */
        case Q_EXIT_SIG: {
            printf("lamp-Off;");
            status_ = Q_HANDLED();
            break;
        }
        /* ${SMs::ToastOven::SM::doorOpen::CLOSE} */
        case CLOSE_SIG: {
            status_ = Q_TRAN_HIST(me->his_doorClosed);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${SMs::ToastOven::SM::final} .............................................*/
static QState ToastOven_final(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* ${SMs::ToastOven::SM::final} */
        case Q_ENTRY_SIG: {
            printf("-> final\nBye!Bye!\n");
            _exit(0);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

