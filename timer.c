#include "timer.h"
#include "led.h"
void TIM3_Int_Init(u16 arr,u16 psc)
{
	NVIC_InitTypeDef NVIC_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; 
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);	
	TIM_TimeBaseInitStrue.TIM_Period=arr;
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc;
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;
	 TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStrue);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	TIM_Cmd(TIM3,ENABLE);
	
}
    void TIM3_IRQHandler(void)
	{
		if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
		{
			LED1=!LED1;
			TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		}
	}		