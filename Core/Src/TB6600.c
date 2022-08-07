//
// Created by 24963 on 2022/8/6.
//
#include "TB6600.h"
#include "tim.h"

#define Tim1_Pulse 500 //中断500次一次脉冲

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){
    if (htim == & htim1)
    {
        __IO  uint16_t cout = 0;
        cout = __HAL_TIM_GetCounter(&htim1);  //得到计数
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, cout + Tim1_Pulse);  //设置比较计数器，反转在原来的基础上延后500
    }

}
//void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
//{
//    uint16_t count = 0;
//    if(htim == &htim1)
//    {
//        if(count <1000)
//        {
//            count++;
//        }
//        else
//        {
//            HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
//            count = 0;
//        }
//    }
//}
