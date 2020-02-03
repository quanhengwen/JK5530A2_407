/******************** (C) COPYRIGHT 2015 AVER ********************
 * �ļ���  ��CONT.C
 * ����    ������
 * ����    ���⺯����
 * ����    ��������ƺ���
 * Ӳ�����ӣ�
 * �޸����ڣ�2015-8-18
*********************************************************************/
#include "my_register.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

void MODE_CONT(void)
{
	/*********������λ�л�*************/
	if(LOAD_I_SW==1)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_11);//��������Ϊ�ߵ�λ
	}
	else
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_11);//��������Ϊ�͵�λ
	}
	if(LOAD_I_SW==0)
	{
		if(Current>10000)//�������������ڵ͵���ߵ���ʱ�Զ��л��ɸߵ�λ�����������ֶ��л����ܱ�ɵ͵�λ
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_11);//��������Ϊ�ߵ�λ
			LOAD_I_SW=1;//�Զ��л�Ϊ�ߵ�λ
		}
	}
	/*************��ѹ��λ�л�**************/
	if(LOAD_V_SW==0)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);//��ѹ��λΪ�͵� 0-12V
	}
	else
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_1);//��ѹ��λΪ�ߵ� 0-80V
	}
	if(LOAD_V_SW==0)
	{
		if(Voltage>12000)//��������ѹ���ڵ͵�������Ƶ�ѹ�ǵ�λ�Զ���ת���ߵ�
		{
			LOAD_V_SW=1;
			GPIO_SetBits(GPIOB,GPIO_Pin_1);//��ѹ��λΪ�ߵ�
		}
	}
	/***********���赵λ�л�**************/
	if(RCONT_SW==0)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);//
	}
	else
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);//
	}
	/**********����ģʽ�л�***************/
	if(LOAD_MODE==0)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_12);//CCģʽ
	}
	else if(LOAD_MODE==1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_12);//CVģʽ
	}
}