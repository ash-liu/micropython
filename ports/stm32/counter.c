#include <stdint.h>
#include <string.h>

#include "py/runtime.h"
#include "py/gc.h"
#include "counter.h"
#include "servo.h"
#include "pin.h"
#include "irq.h"

// the counte value
int tim_cnt_1;
int tim_cnt_2;

TIM_HandleTypeDef TIM2_Handle;
TIM_HandleTypeDef TIM3_Handle;
TIM_HandleTypeDef TIM4_Handle;


// handle error function
void Error_Handler()
{
	// Do nothing
}


/* TIM2 init function */
void MX_TIM2_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_SlaveConfigTypeDef sSlaveConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_TIM2_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  TIM2_Handle.Instance = TIM2;
  TIM2_Handle.Init.Prescaler = 0;
  TIM2_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  TIM2_Handle.Init.Period = 4294967295;
  TIM2_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM2_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&TIM2_Handle) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_ETRMODE2;
  sClockSourceConfig.ClockPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
  sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV2;
  sClockSourceConfig.ClockFilter = 0;
  if (HAL_TIM_ConfigClockSource(&TIM2_Handle, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_TRIGGER;
  sSlaveConfig.InputTrigger = TIM_TS_ITR2;
  if (HAL_TIM_SlaveConfigSynchro(&TIM2_Handle, &sSlaveConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&TIM2_Handle, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

}


/* TIM3 init function */
void MX_TIM3_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  __HAL_RCC_TIM3_CLK_ENABLE();

  TIM3_Handle.Instance = TIM3;
  TIM3_Handle.Init.Prescaler = 399;
  TIM3_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  TIM3_Handle.Init.Period = 1000;
  TIM3_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM3_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&TIM3_Handle) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&TIM3_Handle, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_ENABLE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&TIM3_Handle, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

}


/* TIM4 init function */
void MX_TIM4_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_SlaveConfigTypeDef sSlaveConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_TIM4_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  TIM4_Handle.Instance = TIM4;
  TIM4_Handle.Init.Prescaler = 0;
  TIM4_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  TIM4_Handle.Init.Period = 65535;
  TIM4_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM4_Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&TIM4_Handle) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_ETRMODE2;
  sClockSourceConfig.ClockPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
  sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV2;
  sClockSourceConfig.ClockFilter = 0;
  if (HAL_TIM_ConfigClockSource(&TIM4_Handle, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_TRIGGER;
  sSlaveConfig.InputTrigger = TIM_TS_ITR2;
  if (HAL_TIM_SlaveConfigSynchro(&TIM4_Handle, &sSlaveConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&TIM4_Handle, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

}


// 
void counter_init()
{
	  // init TIM3,2,4
	  MX_TIM3_Init();
    MX_TIM2_Init();
    MX_TIM4_Init();

    HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
	  // start counter
	  HAL_TIM_Base_Start_IT(&TIM3_Handle);
}


// irq handler
void counter_TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */
  HAL_TIM_Base_Stop(&TIM2_Handle);
  HAL_TIM_Base_Stop(&TIM4_Handle);
  tim_cnt_1 = __HAL_TIM_GET_COUNTER(&TIM2_Handle);
  tim_cnt_2 = __HAL_TIM_GET_COUNTER(&TIM4_Handle);
  __HAL_TIM_SET_COUNTER(&TIM2_Handle, 0);
  __HAL_TIM_SET_COUNTER(&TIM4_Handle, 0);

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&TIM3_Handle);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  // restart tim3 to tigger tim2
  HAL_TIM_Base_Stop_IT(&TIM3_Handle);
  __HAL_TIM_SET_COUNTER(&TIM3_Handle, 0);
  HAL_TIM_Base_Start_IT(&TIM3_Handle);
  /* USER CODE END TIM3_IRQn 1 */
}


//------------------------------------------------------------------------------
// For python side

STATIC inline mp_obj_t get_cnt1()
{
	return mp_obj_new_int(tim_cnt_1);
}

//为上面的函数定义一个Python引用
STATIC MP_DEFINE_CONST_FUN_OBJ_0(get_cnt1_obj, get_cnt1);

STATIC inline mp_obj_t get_cnt2()
{
	return mp_obj_new_int(tim_cnt_2);
}

//为上面的函数定义一个Python引用
STATIC MP_DEFINE_CONST_FUN_OBJ_0(get_cnt2_obj, get_cnt2);

STATIC const mp_rom_map_elem_t pyb_counter_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_counter) },
	  { MP_ROM_QSTR(MP_QSTR_get_cnt1), MP_ROM_PTR(&get_cnt1_obj) },
	  { MP_ROM_QSTR(MP_QSTR_get_cnt2), MP_ROM_PTR(&get_cnt2_obj) },
};
STATIC MP_DEFINE_CONST_DICT(pyb_counter_locals_dict, pyb_counter_locals_dict_table);

const mp_obj_type_t pyb_counter_type = {
    { &mp_type_type },
    .name = MP_QSTR_Counter,
    .locals_dict = (mp_obj_dict_t *)&pyb_counter_locals_dict,
};