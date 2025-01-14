/*******************************************************************************
* File Name: T_CLK.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_T_CLK_H) /* Pins T_CLK_H */
#define CY_PINS_T_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "T_CLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 T_CLK__PORT == 15 && ((T_CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    T_CLK_Write(uint8 value);
void    T_CLK_SetDriveMode(uint8 mode);
uint8   T_CLK_ReadDataReg(void);
uint8   T_CLK_Read(void);
void    T_CLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   T_CLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the T_CLK_SetDriveMode() function.
     *  @{
     */
        #define T_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define T_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define T_CLK_DM_RES_UP          PIN_DM_RES_UP
        #define T_CLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define T_CLK_DM_OD_LO           PIN_DM_OD_LO
        #define T_CLK_DM_OD_HI           PIN_DM_OD_HI
        #define T_CLK_DM_STRONG          PIN_DM_STRONG
        #define T_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define T_CLK_MASK               T_CLK__MASK
#define T_CLK_SHIFT              T_CLK__SHIFT
#define T_CLK_WIDTH              1u

/* Interrupt constants */
#if defined(T_CLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in T_CLK_SetInterruptMode() function.
     *  @{
     */
        #define T_CLK_INTR_NONE      (uint16)(0x0000u)
        #define T_CLK_INTR_RISING    (uint16)(0x0001u)
        #define T_CLK_INTR_FALLING   (uint16)(0x0002u)
        #define T_CLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define T_CLK_INTR_MASK      (0x01u) 
#endif /* (T_CLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define T_CLK_PS                     (* (reg8 *) T_CLK__PS)
/* Data Register */
#define T_CLK_DR                     (* (reg8 *) T_CLK__DR)
/* Port Number */
#define T_CLK_PRT_NUM                (* (reg8 *) T_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define T_CLK_AG                     (* (reg8 *) T_CLK__AG)                       
/* Analog MUX bux enable */
#define T_CLK_AMUX                   (* (reg8 *) T_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define T_CLK_BIE                    (* (reg8 *) T_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define T_CLK_BIT_MASK               (* (reg8 *) T_CLK__BIT_MASK)
/* Bypass Enable */
#define T_CLK_BYP                    (* (reg8 *) T_CLK__BYP)
/* Port wide control signals */                                                   
#define T_CLK_CTL                    (* (reg8 *) T_CLK__CTL)
/* Drive Modes */
#define T_CLK_DM0                    (* (reg8 *) T_CLK__DM0) 
#define T_CLK_DM1                    (* (reg8 *) T_CLK__DM1)
#define T_CLK_DM2                    (* (reg8 *) T_CLK__DM2) 
/* Input Buffer Disable Override */
#define T_CLK_INP_DIS                (* (reg8 *) T_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define T_CLK_LCD_COM_SEG            (* (reg8 *) T_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define T_CLK_LCD_EN                 (* (reg8 *) T_CLK__LCD_EN)
/* Slew Rate Control */
#define T_CLK_SLW                    (* (reg8 *) T_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define T_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) T_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define T_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) T_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define T_CLK_PRTDSI__OE_SEL0        (* (reg8 *) T_CLK__PRTDSI__OE_SEL0) 
#define T_CLK_PRTDSI__OE_SEL1        (* (reg8 *) T_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define T_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) T_CLK__PRTDSI__OUT_SEL0) 
#define T_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) T_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define T_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) T_CLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(T_CLK__SIO_CFG)
    #define T_CLK_SIO_HYST_EN        (* (reg8 *) T_CLK__SIO_HYST_EN)
    #define T_CLK_SIO_REG_HIFREQ     (* (reg8 *) T_CLK__SIO_REG_HIFREQ)
    #define T_CLK_SIO_CFG            (* (reg8 *) T_CLK__SIO_CFG)
    #define T_CLK_SIO_DIFF           (* (reg8 *) T_CLK__SIO_DIFF)
#endif /* (T_CLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(T_CLK__INTSTAT)
    #define T_CLK_INTSTAT            (* (reg8 *) T_CLK__INTSTAT)
    #define T_CLK_SNAP               (* (reg8 *) T_CLK__SNAP)
    
	#define T_CLK_0_INTTYPE_REG 		(* (reg8 *) T_CLK__0__INTTYPE)
#endif /* (T_CLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_T_CLK_H */


/* [] END OF FILE */
