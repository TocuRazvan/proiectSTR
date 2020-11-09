/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2020. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_OKBUTTON                   2       /* control type: command, callback function: START_APLICATIE */
#define  PANEL_AMPLITUDINE_TR             3       /* control type: scale, callback function: (none) */
#define  PANEL_GRAFIC_SEMNAL_IESIR_3      4       /* control type: graph, callback function: (none) */
#define  PANEL_GRAFIC_SEMNAL_IESIR_2      5       /* control type: graph, callback function: (none) */
#define  PANEL_GRAFIC_SEMNAL_IESIRE       6       /* control type: graph, callback function: (none) */
#define  PANEL_GRAFIC_SEMNAL_INTRARE      7       /* control type: graph, callback function: (none) */
#define  PANEL_B_RAMPA                    8       /* control type: scale, callback function: (none) */
#define  PANEL_A_RAMPA                    9       /* control type: scale, callback function: (none) */
#define  PANEL_PERIOADA                   10      /* control type: scale, callback function: (none) */
#define  PANEL_REFRESH_GRAFIC             11      /* control type: command, callback function: refresh_grafice */
#define  PANEL_STOP_APLICATIE             12      /* control type: command, callback function: QuitCallback */
#define  PANEL_PICTUREBUTTON_3            13      /* control type: pictButton, callback function: start_semnal_sinusoidal */
#define  PANEL_PICTUREBUTTON_2            14      /* control type: pictButton, callback function: start_semnal_rampa */
#define  PANEL_PICTUREBUTTON              15      /* control type: pictButton, callback function: start_semnal_treapta */
#define  PANEL_DECORATION                 16      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_3               17      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_4               18      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_5               19      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_6               20      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_7               21      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_8               22      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_9               23      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_10              24      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_11              25      /* control type: deco, callback function: (none) */
#define  PANEL_TIMER                      26      /* control type: timer, callback function: ESANTIONARE */
#define  PANEL_DECORATION_2               27      /* control type: deco, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ESANTIONARE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK refresh_grafice(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK START_APLICATIE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK start_semnal_rampa(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK start_semnal_sinusoidal(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK start_semnal_treapta(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
