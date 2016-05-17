#include STM32_HAL_H

void STM32F4BADGE_board_early_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pin = (1<<4);
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	GPIO_InitTypeDef GPIO_InitStructure2;

    GPIO_InitStructure2.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure2.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure2.Pin = (1<<6) | (1<<7) | (1<<13);
	GPIO_InitStructure2.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure2);
	
	GPIO_InitTypeDef GPIO_InitStructure2a;

    GPIO_InitStructure2a.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure2a.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure2a.Pin = (1<<13);
	GPIO_InitStructure2a.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure2a);
	
	GPIO_InitTypeDef GPIO_InitStructure3;

    GPIO_InitStructure3.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure3.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure3.Pin = (1<<3);
	GPIO_InitStructure3.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure3);
	
	GPIO_InitTypeDef GPIO_InitStructure4;

    GPIO_InitStructure4.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure4.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure4.Pin = (1<<4);
	GPIO_InitStructure4.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure4);
	

	
	//enable mco1
//	RCC->CFGR &= ~((1<<26) | (1<<21));
//	RCC->CFGR |= (1<<21);
/*
	__PWR_CLK_ENABLE();
	HAL_PWR_EnableBkUpAccess();
	uint32_t tickstart = HAL_GetTick();
	// Enable write access to Backup domain
	//PWR->CR |= PWR_CR_DBP;
	// Wait for Backup domain Write protection disable
	while ((PWR->CR & PWR_CR_DBP) == RESET) {
		if (HAL_GetTick() - tickstart > DBP_TIMEOUT_VALUE) {
			break;
		}
	}
	__HAL_RCC_LSE_CONFIG(RCC_LSE_ON);
	*/
	GPIO_InitTypeDef GPIO_InitStructure1;

    GPIO_InitStructure1.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure1.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure1.Pin = (1<<8);
	GPIO_InitStructure1.Pull = GPIO_NOPULL;
	GPIO_InitStructure1.Alternate = GPIO_AF0_MCO;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure1);
	
	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_LSE, RCC_MCODIV_1);

	
	
	
}
