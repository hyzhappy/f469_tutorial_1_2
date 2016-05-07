/*点亮多个LED灯吧
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"
int
main(int argc, char* argv[])
{
	//开启GPIOD的时钟
	__HAL_RCC_GPIOD_CLK_ENABLE();
	//开启GPIOG的时钟
	__HAL_RCC_GPIOG_CLK_ENABLE();
	//开启GPIOK的时钟
	__HAL_RCC_GPIOK_CLK_ENABLE();

	//声明一个GPIO初始化结构体变量，然后开始给这个变量配置
	GPIO_InitTypeDef GPIO_InitStructure;

	//要配置的GPIO引脚为第6引脚
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	//GPIO输出模式为推挽输出
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	//GPIO上拉模式（内接上拉电阻）
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	//GPIO的速度为快速（最高速度）
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	//将配置应用到GPIOG中
	HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

	//要配置的GPIO引脚为第4引脚和第5引脚
	GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
	//因为模式、拉电阻、速度都已经配置过了，无需再次配置
	//将配置应用到GPIOD中
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);


	GPIO_InitStructure.Pin = GPIO_PIN_3;
	//将这个配置应用到GPIOK中
	HAL_GPIO_Init(GPIOK, &GPIO_InitStructure);

	//至此就配置好了G6，D4，D5，K3这四个GPIO引脚

	//把所有的引脚都设置为低电平吧，所有的LED就都亮了
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);

	while (1)
    {

    }
}
