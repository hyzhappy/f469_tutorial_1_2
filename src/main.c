/*�������LED�ư�
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"
int
main(int argc, char* argv[])
{
	//����GPIOD��ʱ��
	__HAL_RCC_GPIOD_CLK_ENABLE();
	//����GPIOG��ʱ��
	__HAL_RCC_GPIOG_CLK_ENABLE();
	//����GPIOK��ʱ��
	__HAL_RCC_GPIOK_CLK_ENABLE();

	//����һ��GPIO��ʼ���ṹ�������Ȼ��ʼ�������������
	GPIO_InitTypeDef GPIO_InitStructure;

	//Ҫ���õ�GPIO����Ϊ��6����
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	//GPIO���ģʽΪ�������
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	//GPIO����ģʽ���ڽ��������裩
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	//GPIO���ٶ�Ϊ���٣�����ٶȣ�
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	//������Ӧ�õ�GPIOG��
	HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

	//Ҫ���õ�GPIO����Ϊ��4���ź͵�5����
	GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
	//��Ϊģʽ�������衢�ٶȶ��Ѿ����ù��ˣ������ٴ�����
	//������Ӧ�õ�GPIOD��
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);


	GPIO_InitStructure.Pin = GPIO_PIN_3;
	//���������Ӧ�õ�GPIOK��
	HAL_GPIO_Init(GPIOK, &GPIO_InitStructure);

	//���˾����ú���G6��D4��D5��K3���ĸ�GPIO����

	//�����е����Ŷ�����Ϊ�͵�ƽ�ɣ����е�LED�Ͷ�����
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);

	while (1)
    {

    }
}
