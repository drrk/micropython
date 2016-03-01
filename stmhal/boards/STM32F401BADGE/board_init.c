#include STM32_HAL_H

void STM32F4BADGE_board_early_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pin = (1<<4);
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

	
	//enable mco1
//	RCC->CFGR &= ~((1<<26) | (1<<21));
//	RCC->CFGR |= (1<<21);
	
	GPIO_InitTypeDef GPIO_InitStructure1;

    GPIO_InitStructure1.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure1.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure1.Pin = (1<<8);
	GPIO_InitStructure1.Pull = GPIO_NOPULL;
	GPIO_InitStructure1.Alternate = GPIO_AF0_MCO;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure1);
	
	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_LSE, RCC_MCODIV_1);

}
