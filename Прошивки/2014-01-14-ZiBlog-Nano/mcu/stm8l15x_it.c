/*
 *
 */

#include "main.h"

#ifdef _COSMIC_
INTERRUPT_HANDLER(NonHandledInterrupt)
{
}
#endif

INTERRUPT_HANDLER_TRAP( TRAP_IRQHandler)
{
}

INTERRUPT_HANDLER( FLASH_IRQHandler)
{
}

INTERRUPT_HANDLER( DMA1_CHANNEL0_1_IRQHandler)
{
}

INTERRUPT_HANDLER( DMA1_CHANNEL2_3_IRQHandler)
{
}

INTERRUPT_HANDLER( RTC_CSSLSE_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTIE_F_PVD_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTIB_G_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTID_H_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI0_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI1_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI2_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI3_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI4_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI5_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI6_IRQHandler)
{
}

INTERRUPT_HANDLER( EXTI7_IRQHandler)
{
}

INTERRUPT_HANDLER( LCD_AES_IRQHandler)
{
}

INTERRUPT_HANDLER( SWITCH_CSS_BREAK_DAC_IRQHandler)
{
}

INTERRUPT_HANDLER( ADC1_COMP_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM2_UPD_OVF_TRG_BRK_USART2_TX_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM2_CC_USART2_RX_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM3_UPD_OVF_TRG_BRK_USART3_TX_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM3_CC_USART3_RX_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM1_UPD_OVF_TRG_COM_IRQHandler)
{
	if (device.mcu_load_counter != 255)
		device.mcu_load_counter++;

	TIM1->SR1 = (uint8_t) (~TIM1_SR1_UIF);
}

INTERRUPT_HANDLER( TIM1_CC_IRQHandler)
{
}

INTERRUPT_HANDLER( TIM4_UPD_OVF_TRG_IRQHandler)
{
	synchronization_10ms_refresh();

	delay_ms_refresh();

	TIM4->SR1 = (uint8_t) (~TIM4_IT_Update);
}

INTERRUPT_HANDLER( SPI1_IRQHandler)
{
}

INTERRUPT_HANDLER( USART1_TX_TIM5_UPD_OVF_TRG_BRK_IRQHandler)
{
	mcu_usart_fifo_tx_handler();
}

INTERRUPT_HANDLER( USART1_RX_TIM5_CC_IRQHandler)
{
	mcu_usart_fifo_rx_handler();
}

INTERRUPT_HANDLER( I2C1_SPI2_IRQHandler)
{
}
