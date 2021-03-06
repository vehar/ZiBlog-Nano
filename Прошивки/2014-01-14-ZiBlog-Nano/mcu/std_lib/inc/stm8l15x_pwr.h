/**
  ******************************************************************************
  * @file    stm8l15x_pwr.h
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    13-May-2011
  * @brief   This file contains all the functions prototypes for the PWR firmware
  *          library.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************  
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8L15x_PWR_H
#define __STM8L15x_PWR_H

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"

/** @addtogroup STM8L15x_StdPeriph_Driver
  * @{
  */

/** @addtogroup PWR
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup PWR_Exported_Types
  * @{
  */

/** @defgroup PVD_detection_level 
  * @{
  */

typedef enum {
  PWR_PVDLevel_1V85  = (uint8_t)0x00, /*!< PVD threshold = 1.85 V */
  PWR_PVDLevel_2V05  = (uint8_t)0x02, /*!< PVD threshold = 2.05 V */
  PWR_PVDLevel_2V26  = (uint8_t)0x04, /*!< PVD threshold = 2.26 V */
  PWR_PVDLevel_2V45  = (uint8_t)0x06, /*!< PVD threshold = 2.45 V */
  PWR_PVDLevel_2V65  = (uint8_t)0x08, /*!< PVD threshold = 2.65 V */
  PWR_PVDLevel_2V85  = (uint8_t)0x0A, /*!< PVD threshold = 2.85 V */
  PWR_PVDLevel_3V05  = (uint8_t)0x0C, /*!< PVD threshold = 3.05 V */
  PWR_PVDLevel_PVDIn = (uint8_t)0x0E  /*!< PVD threshold = PVD_IN input pin */
} PWR_PVDLevel_TypeDef;

#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLevel_1V85) || \
                                 ((LEVEL) == PWR_PVDLevel_2V05) || \
                                 ((LEVEL) == PWR_PVDLevel_2V26) || \
                                 ((LEVEL) == PWR_PVDLevel_2V45) || \
                                 ((LEVEL) == PWR_PVDLevel_2V65) || \
                                 ((LEVEL) == PWR_PVDLevel_2V85) || \
                                 ((LEVEL) == PWR_PVDLevel_3V05) || \
                                 ((LEVEL) == PWR_PVDLevel_PVDIn))
/**
  * @}
  */
  
/** @defgroup PWR_Flag 
  * @{
  */
  
typedef enum {
  PWR_FLAG_PVDOF    = (uint8_t)0x40,/*!< PVD output flag */
  PWR_FLAG_PVDIF    = (uint8_t)0x20, /*!< PVD Interrupt flag */
  PWR_FLAG_VREFINTF = (uint8_t)0x01  /*!< Internal reference voltage status flag */
} PWR_FLAG_TypeDef;

#define IS_PWR_FLAG(FLAG)   (((FLAG) == PWR_FLAG_PVDOF) || \
                             ((FLAG) == PWR_FLAG_PVDIF) || \
                             ((FLAG) == PWR_FLAG_VREFINTF))

/**
  * @}
  */
  
/**
  * @}
  */
  
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Function used to set the PWR configuration to the default reset state ******/ 
void PWR_DeInit(void);

/* PVD configuration functions ************************************************/ 
void PWR_PVDLevelConfig(PWR_PVDLevel_TypeDef PWR_PVDLevel);
void PWR_PVDCmd(FunctionalState NewState);

/* Ultra Low Power mode configuration functions *******************************/ 
void PWR_FastWakeUpCmd(FunctionalState NewState);
void PWR_UltraLowPowerCmd(FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
void PWR_PVDITConfig(FunctionalState NewState);
ITStatus PWR_PVDGetITStatus(void);
FlagStatus PWR_GetFlagStatus(PWR_FLAG_TypeDef PWR_FLAG);
void PWR_PVDClearFlag(void);
void PWR_PVDClearITPendingBit(void);

#endif /* __STM8L15x_PWR_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
