/***************************************************************************************
 *                                  File Description                                   *
 *  Name: IntCtrl_Cfg.h                                                                *
 *  Brief: Nested Vector Interrupt Controller Driver                                   *
 *  Author: Ahmed M. Rizk                                                              *
 *  Date: 14th of January 2023                                                         *
 *                                                                                     *
 * Details: ~Prebuild configurations selection                                         *                                                          *
 *                                                                                     *
 ****************************************************************************************/
#ifndef INTCTRL_CFG_H_
#define INTCTRL_CFG_H_

/***************************************************************************************
 *                                       Includes                                      *
****************************************************************************************/
#include "Platform_Types.h"
#include "IntCtrl_Types.h"

/***************************************************************************************
 *                                Configuration Macros                                 *
****************************************************************************************/
/****************************************************************/
/** !comment : Please Select the Interrupt Priority				*/
/** 		   Interrupt Priority can be : 						*/
/*					    			XXX 					    */
/*						    		XXY 					    */
/*							    	XYY			            	*/
/*								    YYY                         */
/*                    Where X denotes Group Priority and Y      */
/*                    and Y denotes Sub-Group Priority.         */ 
/****************************************************************/
#define Int_Priority YYY




#endif /*INTCTRL_CFG_H_ */
/***************************************************************************************
 *                               End of File: IntCtrl_Cfg.h                            *
 ****************************************************************************************/
