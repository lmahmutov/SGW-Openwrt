/***************************************************************************//**
 * # License
 * 
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is Third Party Software licensed by Silicon Labs from a third party
 * and is governed by the sections of the MSLA applicable to Third Party
 * Software and the additional terms set forth below.
 * 
 ******************************************************************************/

/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2016  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.34 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to Silicon Labs Norway, a subsidiary
of Silicon Labs Inc. whose registered office is 400 West Cesar Chavez,
Austin,  TX 78701, USA solely for  the purposes of creating  libraries 
for its  ARM Cortex-M3, M4F  processor-based devices,  sublicensed and 
distributed  under the  terms and conditions  of the  End User License  
Agreement supplied by Silicon Labs.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information

Licensor:                 SEGGER Software GmbH
Licensed to:              Silicon Laboratories Norway
Licensed SEGGER software: emWin
License number:           GUI-00140
License model:            See Agreement, dated 20th April 2012
Licensed product:         - 
Licensed platform:        Cortex M3, Cortex M4F
Licensed number of seats: -
----------------------------------------------------------------------
File        : LCD_SIM.h
Purpose     : Declares LCD interface functions
----------------------------------------------------------------------
*/

#ifndef LCDSIM_H
#define LCDSIM_H

#include "LCD.h"

/************************************************************
*
*       Defines
*
*************************************************************
*/
#define LCDSIM_MAX_DISPLAYS GUI_NUM_LAYERS

#define GUI_TRANSMODE_PIXELALPHA 0
#define GUI_TRANSMODE_CHROMA     1
#define GUI_TRANSMODE_ZERO       2

/************************************************************
*
*       LCDSIM_      General declarations
*
*************************************************************
*/
void  LCDSIM_PreInit(void);
char* LCDSIM_Init(void);
void  LCDSIM_Exit(void);
int   LCDSIM_GetMouseState(LCD_tMouseState *pState);
void  LCDSIM_SetMouseState(int x, int y, int KeyStat, int LayerIndex);
void  LCDSIM_CheckMouseState(int LayerIndex);
int   LCDSIM_SaveSBMP  (const char * sFileName);
int   LCDSIM_SaveSBMPEx(const char * sFileName, int x0, int y0, int xSize, int ySize);
void  LCDSIM_SetRGBOrder(unsigned RGBOrder);

/************************************************************
*
*       LCDSIM_     Functions for each display
*
*************************************************************
*/
void LCDSIM_FillRect(int x0, int y0, int x1, int y1, int Index, int LayerIndex);
int  LCDSIM_GetModifyCnt(int LayerIndex);
int  LCDSIM_GetModifyCntInfo(int LayerIndex);
int  LCDSIM_GetPixelColor(int x, int y, int LayerIndex);
int  LCDSIM_GetPixelIndex(int x, int y, int LayerIndex);
int  LCDSIM_Index2Color(int Index, int LayerIndex);
int  LCDSIM_RLUT_GetPixelIndex(int x, int y, int LayerIndex);
void LCDSIM_RLUT_SetPixelIndex(int x, int y, int Index, int LayerIndex);
void LCDSIM_SetLUTEntry(U8 Pos, LCD_COLOR color, int LayerIndex);
void LCDSIM_SetPixelIndex(int x, int y, int Index, int LayerIndex);
void LCDSIM_SetPixelColor(int x, int y, LCD_COLOR PixelColor, int LayerIndex);
void LCDSIM_SetSubPixel(int x, int y, U8 Value, int LayerIndex);
void LCDSIM_SetPixelPhys(int x, int y, int Index, int LayerIndex);
int  LCDSIM_GetPixelPhys(int xPhys, int yPhys, int LayerIndex);
void LCDSIM_FillRectPhys(int x0Phys, int y0Phys, int x1Phys, int y1Phys, int Index, int LayerIndex);
void LCDSIM_SetOrg(int x, int y, int LayerIndex);
void LCDSIM_SetAlpha(int Alpha, int LayerIndex);
int  LCDSIM_GetAlpha(int LayerIndex);
void LCDSIM_SetLayerPos(int xPos, int yPos, int LayerIndex);
void LCDSIM_SetLayerVis(int OnOff, int LayerIndex);
void LCDSIM_SetSize(int LayerIndex, int xSize, int ySize);
void LCDSIM_SetTransMode(int LayerIndex, int TransMode);
void LCDSIM_SetChroma(int LayerIndex, LCD_COLOR ChromaMin, LCD_COLOR ChromaMax);
void LCDSIM_SetCompositeColor(U32 Color);
void LCDSIM_SetCompositeSize(int xSize, int ySize);
void LCDSIM_CopyBuffer(int LayerIndex, int IndexSrc, int IndexDst);
void LCDSIM_Invalidate(int LayerIndex);

/********************************************************************
*
*       Publics for LCD
*
*********************************************************************
*/
void SIM_GUI_SetCompositeSize(int xSize, int ySize);
void SIM_GUI_SetCompositeColor(U32 Color);
U32  SIM_GUI_GetCompositeColor(void);
void SIM_GUI_SetLCDPos(int xPos, int yPos);
int  SIM_GUI_SaveBMP(const char * sFileName);
int  SIM_GUI_SaveBMPEx(const char * sFileName, int x0, int y0, int xSize, int ySize);
int  SIM_GUI_SetTransColor(int Color);
int  SIM_GUI_SetLCDColorBlack (unsigned int Index, int Color);
int  SIM_GUI_SetLCDColorWhite (unsigned int Index, int Color);
void SIM_GUI_SetMag(int MagX, int MagY);
int  SIM_GUI_GetMagX(void);
int  SIM_GUI_GetMagY(void);
int  SIM_GUI_GetForwardRButton(void);
void SIM_GUI_SetForwardRButton(int OnOff);
void SIM_GUI_SetTransMode(int LayerIndex, int TransMode);
void SIM_GUI_SetChroma(int LayerIndex, unsigned long ChromaMin, unsigned long ChromaMax);
void SIM_GUI_UseCustomBitmaps(void);
void SIM_GUI_SetAccellerator(int Accellerator);
void SIM_GUI_SetMainScreenOffset(int x, int y);
void SIM_GUI_SetCompositeTouch(int LayerIndex);
int  SIM_GUI_GetCompositeTouch(void);

/********************************************************************
*
*       Routine(s) in user application
*
*********************************************************************
*/
void SIM_X_Config(void);   /* Allow init before application starts ... Use it to set LCD offset etc */

/********************************************************************
*
*       Publics used by GUI_X module
*
*********************************************************************
*/
void SIM_GUI_Delay (int ms);
void SIM_GUI_ExecIdle(void);
int  SIM_GUI_GetTime(void);
int  SIM_GUI_GetKey(void);
int  SIM_GUI_WaitKey(void);
void SIM_GUI_StoreKey(int);

/********************************************************************
*
*       Publics for logging, warning, errorout
*
*********************************************************************
*/
void SIM_GUI_Log(const char *s);
void SIM_GUI_Log1(const char *s, int p0);
void SIM_GUI_Log2(const char *s, int p0, int p1);
void SIM_GUI_Log3(const char *s, int p0, int p1, int p2);
void SIM_GUI_Log4(const char *s, int p0, int p1, int p2,int p3);
void SIM_GUI_Warn(const char *s);
void SIM_GUI_Warn1(const char *s, int p0);
void SIM_GUI_Warn2(const char *s, int p0, int p1);
void SIM_GUI_Warn3(const char *s, int p0, int p1, int p2);
void SIM_GUI_Warn4(const char *s, int p0, int p1, int p2, int p3);
void SIM_GUI_ErrorOut(const char *s);
void SIM_GUI_ErrorOut1(const char *s, int p0);
void SIM_GUI_ErrorOut2(const char *s, int p0, int p1);
void SIM_GUI_ErrorOut3(const char *s, int p0, int p1, int p2);
void SIM_GUI_ErrorOut4(const char *s, int p0, int p1, int p2, int p3);
void SIM_GUI_EnableMessageBoxOnError(int Status);

/********************************************************************
*
*       Commandline support
*
*********************************************************************
*/
const char *SIM_GUI_GetCmdLine(void);

/********************************************************************
*
*       Multitasking support
*
*********************************************************************
*/
void SIM_GUI_CreateTask(char * pName, void * pFunc);
void SIM_GUI_Start(void);
unsigned long SIM_GUI_GetTaskID(void);
void SIM_GUI_Lock(void);
void SIM_GUI_Unlock(void);
void SIM_GUI_InitOS(void);

#endif /* LCD_H */




