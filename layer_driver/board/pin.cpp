#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

/*
�`���p���W�[�ł��킩��I
ichigoplus��h���C�o�̍���I

�����������H
�P�A�s���̔z�u��ς������@��15�s�ڂ�
�Q�A�V�����s����ǉ��������@���@���s�ڂ�
�R�A�s�������������@���@���s�ڂ�
�S�A��̖��O���ς�����@���@���s�ڂ�

�P�A�s���̔z�u��ς�����
�@�P�A�f�W�^���s�����A�i���O�s���̏ꍇ
�@�@��)#define D0_PIN		  GPIOE,GPIO_Pin_4
�@�@D0_PIN��D0�Ƃ������O�̃N���X�̃s���̖��O���L����define�ł��B
�@�@����D1�Ȃ�D1_PIN�ƂȂ�܂��B
�@�@����GPIOE,GPIO_Pin_4�̓s���̖��O�ŁA�f�[�^�V�[�g��PC4���w���܂�
�@�@�Ⴆ��PA0���w�肵������΂�����GPIOA,GPIO_Pin_0���͂��Ă��������B

�@�@�A�i���O�s���ł����A0_PIN�݂����Ȗ��O�ɂȂ��Ă���͂��ł��B
�@�@�����A0�Ƃ������O�̃N���X�̃s���̖��O���L����define�ł��B
�@�@����A1�Ȃ�A1_PIN�ƂȂ�܂��B
�@�@����GPIOE,GPIO_Pin_4�̓f�[�^�V�[�g��PC4���w���܂�
�@�@�Ⴆ��PA0���w�肵������΂�����GPIOA,GPIO_Pin_0���͂��Ă��������B

�@�Q�C�G���R�[�_�̏ꍇ
�@�@��)
�@�@#define ENC0TIM TIM5
�@�@#define ENC0		GPIOA,GPIO_Pin_0 | GPIO_Pin_1

�@�@ENC0TIM��Enc0�Ƃ������O�̃N���X���g���^�C�}�[���L����define�ł��B
�@�@����Enc1�Ȃ�ENC1TIM�ƂȂ�܂��B
�@�@����TIM5�̓^�C�}�[�̖��O�ŁA�f�[�^�V�[�g��TIM5���w���܂��B
�@�@�Ⴆ��TIM4���w�肵������΂�����TIM4���͂��Ă��������B

�@�@ENC0��Enc0�Ƃ������O�̃N���X���g���s�����L����define�ł��B
�@�@����Enc1�Ȃ�ENC1�ƂȂ�܂��B
�@�@����GPIOA,GPIO_Pin_0 | GPIO_Pin_1�͎g���s���̖��O�ŁA�f�[�^�V�[�g��PA0,PA1���w���܂��B
�@�@�Ⴆ�΁APE1,PE2���w���������GPIOE, GPIO_Pin_0 | GPIO_Pin_1 �Ɠ�͂��Ă��������B

�@�R�CPWM�̏ꍇ
�@�@��)
�@�@#define PWM0		    GPIOB,GPIO_Pin_14
�@�@#define PWM0SET			TIM12,PWM0
�@�@#define PWM0TIMCH		TIM12,1
�@�@PWM0��Pwm0�Ƃ������O�̃N���X���g���s�����L����define�ł��B
�@�@�f�W�^���Ɠ����ł��B
�@�@PWM0SET��Pwm0�Ƃ������O�̃N���X���g���^�C�}�[���L����define�ł��B
�@�@����Pwm1�Ȃ�PWM1SET�ƂȂ�܂��B
�@�@����TIM12�͎g���^�C�}�[�̖��O�ŁA�f�[�^�V�[�g��TIM12���w���܂��B
�@�@PWM0�͏�ŉ������define�ł��B����PWM1SET�Ȃ�PWM1�Ƃ��Ă��������B
�@�@PWM0TIMCH�@�̓^�C�}�[�ƃ`�����l�����L����define�ł��B
�@�@����Pwm1�Ȃ�PWM1TIMCH�ƂȂ�܂��B
�@�@���� TIM12,1�� TIM12��CH1���w���܂��B�@����TIM8��CH3���w���������TIM8,3�Ɠ�͂��Ă��������B

�@�S�CCAN�̏ꍇ
�@�@��)
�@�@#define CAN0_PORT GPIOB,GPIO_Pin_9,GPIOB,GPIO_Pin_8
�@�@#define CAN0_NUMBER 1
�@�@CAN0_PORT��Can0�Ƃ������O�̃N���X���g���s�����L����define�ł��B
�@�@�f�W�^���Ɠ����ł��B
�@�@CAN0_NUMBER��CAN���W���[���̔ԍ����w���܂��BCAN1�Ȃ�1���ACAN2�Ȃ�2����ĉ�����

�@�T�C�V���A���̏ꍇ
�@�@��)
�@�@#define SERIAL0TxRx GPIOB,GPIO_Pin_10,GPIOB,GPIO_Pin_11
�@�@#define SERIAL0CH USART3
�@�@SERIAL0TxRx��Serial0�Ƃ������O�̃N���X���g���s�����L����define�ł��B
�@�@�f�W�^���Ɠ����ł�
�@�@SERIAL0CH��Serial0�Ƃ������O�̃N���X���g���V���A�����W���[�����L����define�ł��B
�@�@USART3�Ȃ�USART3���AUART6�Ȃ�USART6����ĉ�����
�@  �V���A���ł͊��荞�݃n���h���̖��O���ύX����K�v������܂��B
�@�@extern "C" void USART6_IRQHandler(void)��USART6�̕����𗘗p���郂�W���[���̖��O�ɒu�������Ă��������B

�Q�C�V�����s����ǉ�������
�@���pin.hpp��ǂ�ŉ�����

�@�ǂ�ł��܂����H
�@��ɏ�����Ă�����̂Ɠ�����ނ̃N���X�������ăR�s�[���܂��B
�@A0�Ƃ�Pwm0�Ƃ��ɂ͂������炱���܂ł��N���X�������Ă���Ƃ���Ƃ����󂪂���܂��B�������炻���܂ł��R�s�[���Ă��������BSerial������Serial1���g���ĉ������B

�@���ꂪ�I�������R�s�[���ē\��t���������̃N���X����define��S���V���ȃN���X����define�ɏ��������Ă��������B�S���ł��B�ꕶ�����ԈႦ�Ȃ��ŉ������B

�R�A�s������������
�@���������N���X���܂邲�Ə����ĉ������B
�@�N���X��::�֐����@�Ƃ������O�Ŋ֐����錾����Ă��܂��B�����N���X���̂��̂�S�������Ă��܂��܂��悤�B
�@pin.hpp�̂ق������ĉ������B

�S�A��̖��O���ς����
�@char* board_name()�Ƃ����֐�������܂��B���̒��Ɋ�̖��O�������Ă��������B
 */

extern "C" {
#include "config_usart.h"
#include "config_encoder.h"
#include "config_systick.h"
#include "config_usart.h"
#include "config_pwm.h"
#include "config_port.h"
#include "config_adc.h"
#include "config_can.h"
#include "config_usb.h"
#include "config_i2c.h"
#include "config_iwdg.h"
#include "config_spi.h"
#include "config_tim_interrupt.h"
}

#include "pin.hpp"

char* board_name() {
	return (char*)"STM32F4 Centaurus";
}

//=== define

//--- EMERGENCY
#define SWITCH_PIN	GPIOE,GPIO_Pin_15	//�ً}��~���|����p�̃s��
#define READ_PIN	GPIOB,GPIO_Pin_11	//�ً}��~���|�����Ă��邩�ǂޗp�̃s��

//--- LED
#define RESETLED_PIN	GPIOE,GPIO_Pin_12	//���Z�b�g�{�^��������LED.
#define LED0_PIN		GPIOD,GPIO_Pin_10
#define LED1_PIN		GPIOD,GPIO_Pin_11
#define LED2_PIN		GPIOD,GPIO_Pin_14
#define LED3_PIN		GPIOD,GPIO_Pin_15
#define LED4_PIN		GPIOA,GPIO_Pin_8
#define LED5_PIN		GPIOD,GPIO_Pin_0

//--- FULL COLOR
#define RED 		 GPIOB,GPIO_Pin_15
#define REDSET       TIM12,RED
#define REDTIMCH	 TIM12,2
#define GREEN		 GPIOC,GPIO_Pin_8
#define GREENSET     TIM8,GREEN
#define GREENTIMCH   TIM8,3
#define BLUE 		 GPIOC,GPIO_Pin_9
#define BLUESET      TIM8,BLUE
#define BLUETIMCH    TIM8,4

//--- ANALOG
#define A0_PIN      GPIOB,GPIO_Pin_1
#define A1_PIN      GPIOC,GPIO_Pin_5
#define A2_PIN      GPIOC,GPIO_Pin_4
#define A3_PIN      GPIOA,GPIO_Pin_6
#define A4_PIN      GPIOA,GPIO_Pin_5
#define A5_PIN      GPIOA,GPIO_Pin_4
#define A6_PIN      GPIOA,GPIO_Pin_3
#define A7_PIN      GPIOA,GPIO_Pin_2
#define A8_PIN      GPIOC,GPIO_Pin_1
#define A9_PIN      GPIOC,GPIO_Pin_0

//--- 5V IO
#define D5V0_PIN      GPIOC,GPIO_Pin_15
#define D5V1_PIN      GPIOC,GPIO_Pin_14
#define D5V2_PIN      GPIOC,GPIO_Pin_13
#define D5V3_PIN      GPIOE,GPIO_Pin_4

//--- Variable IO
#define D0_PIN      GPIOE,GPIO_Pin_3
#define D1_PIN      GPIOE,GPIO_Pin_2
#define D2_PIN      GPIOE,GPIO_Pin_1
#define D3_PIN      GPIOE,GPIO_Pin_0

//--- SW
#define SW0_PIN      GPIOD,GPIO_Pin_1
#define SW1_PIN      GPIOD,GPIO_Pin_3
#define SW2_PIN      GPIOD,GPIO_Pin_4
#define SW3_PIN      GPIOD,GPIO_Pin_7

//--- PWM
#define PWM0        GPIOE,GPIO_Pin_14
#define PWM0SET     TIM1,PWM0
#define PWM0TIMCH   TIM1,4
#define PWM1        GPIOE,GPIO_Pin_13
#define PWM1SET     TIM1,PWM1
#define PWM1TIMCH   TIM1,3
#define PWM2        GPIOE,GPIO_Pin_11
#define PWM2SET     TIM1,PWM2
#define PWM2TIMCH   TIM1,2
#define PWM3        GPIOE,GPIO_Pin_9
#define PWM3SET     TIM1,PWM3
#define PWM3TIMCH   TIM1,1
#define PWM4        GPIOB,GPIO_Pin_0
#define PWM4SET     TIM8,PWM4
#define PWM4TIMCH   TIM8,2
#define PWM5        GPIOA,GPIO_Pin_7
#define PWM5SET     TIM8,PWM5
#define PWM5TIMCH   TIM8,1
#define PWM6        GPIOE,GPIO_Pin_6
#define PWM6SET     TIM9,PWM6
#define PWM6TIMCH   TIM9,2
#define PWM7        GPIOE,GPIO_Pin_5
#define PWM7SET     TIM9,PWM7
#define PWM7TIMCH   TIM9,1
#define PWM8        GPIOB,GPIO_Pin_9
#define PWM8SET     TIM11,PWM8
#define PWM8TIMCH   TIM11,1
#define PWM9        GPIOB,GPIO_Pin_8
#define PWM9SET     TIM10,PWM9
#define PWM9TIMCH   TIM10,1

//--- BUZZER PWM
#define BUZZER        GPIOB,GPIO_Pin_14
#define BUZZERSET     TIM12,BUZZER
#define BUZZERTIMCH   TIM12,1

//--- ENCODER
#define ENC0TIM TIM2	//advancedEncoder���|���ė~����.(encoder0�͓���)
#define ENC0    GPIOA,GPIO_Pin_15, GPIOB,GPIO_Pin_3
#define ENC1TIM TIM4
#define ENC1    GPIOD,GPIO_Pin_12, GPIOD,GPIO_Pin_13
#define ENC2TIM TIM3
#define ENC2    GPIOB,GPIO_Pin_4, GPIOB,GPIO_Pin_5
#define ENC3TIM TIM5
#define ENC3    GPIOA,GPIO_Pin_0, GPIOA,GPIO_Pin_1

//--- CAN
#define CAN0_PORT GPIOA,GPIO_Pin_12,GPIOA,GPIO_Pin_11
#define CAN0_NUMBER 1
#define CAN1_PORT GPIOB,GPIO_Pin_13,GPIOB,GPIO_Pin_12
#define CAN1_NUMBER 2

//--- USART / UART
#define SERIAL0TxRx GPIOA,GPIO_Pin_9,GPIOA,GPIO_Pin_10
#define SERIAL0CH USART1
#define SERIAL1TxRx GPIOD,GPIO_Pin_8,GPIOD,GPIO_Pin_9
#define SERIAL1CH USART3
#define SERIAL2TxRx GPIOC,GPIO_Pin_6,GPIOC,GPIO_Pin_7
#define SERIAL2CH USART6
#define SERIAL3TxRx GPIOC,GPIO_Pin_10,GPIOC,GPIO_Pin_11
#define SERIAL3CH UART4
#define SERIAL4TxRx GPIOC,GPIO_Pin_12,GPIOD,GPIO_Pin_2
#define SERIAL4CH UART5

//--- SBDBT�p
#define SERIAL5TxRx GPIOD,GPIO_Pin_5,GPIOD,GPIO_Pin_6
#define SERIAL5CH USART2

//--- I2C LCD�p
#define I2C_PORT_SCL_SDA	GPIOB,GPIO_Pin_6,GPIOB,GPIO_Pin_7
#define I2CMODE I2C1

//--- LCD Back Light�p
#define LCD_BL_PIN	GPIOB,GPIO_Pin_2

//--- SPI EEPROM�p
#define SPI2_PORT_CLK_MOSI_MISO	GPIOB,GPIO_Pin_10,GPIOC,GPIO_Pin_2,GPIOC,GPIO_Pin_3
#define SPIMODE SPI2

//--- EEPROM �f�[�^�֘A
#define HOLD_PIN			GPIOE,GPIO_Pin_7
#define WRITEPROTECT_PIN	GPIOE,GPIO_Pin_10
#define CHIPSELECT_PIN      GPIOE,GPIO_Pin_8

bool DigitalInterrupt0::handlerMap[16];
DigitalInterruptHandler *DigitalInterrupt0::digitalInterruptHander[16];

//--- EmergencySwitch start
int EmergencySwitch::_digitalWrite(){
	return GPIO_ReadOutputDataBit(SWITCH_PIN);
}

void EmergencySwitch::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(SWITCH_PIN);
	else GPIO_SetBits(SWITCH_PIN);
}

int EmergencySwitch::_digitalRead(){
	return GPIO_ReadInputDataBit(SWITCH_PIN);
}

int EmergencySwitch::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, SWITCH_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int EmergencySwitch::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, SWITCH_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int EmergencySwitch::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, SWITCH_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int EmergencySwitch::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, SWITCH_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- EmergencySwitch End
//--- EmergencyRead start
int EmergencyRead::_digitalWrite(){
	return GPIO_ReadOutputDataBit(READ_PIN);
}

void EmergencyRead::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(READ_PIN);
	else GPIO_SetBits(READ_PIN);
}

int EmergencyRead::_digitalRead(){
	return GPIO_ReadInputDataBit(READ_PIN);
}

int EmergencyRead::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, READ_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int EmergencyRead::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, READ_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int EmergencyRead::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, READ_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int EmergencyRead::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, READ_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- EmergencyRead End
//--- LCD Back Light start
int LCDBackLight::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LCD_BL_PIN);
}

void LCDBackLight::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LCD_BL_PIN);
	else GPIO_SetBits(LCD_BL_PIN);
}

int LCDBackLight::_digitalRead(){
	return GPIO_ReadInputDataBit(LCD_BL_PIN);
}

int LCDBackLight::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LCD_BL_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int LCDBackLight::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LCD_BL_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int LCDBackLight::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LCD_BL_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int LCDBackLight::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LCD_BL_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- LCD Back Light end
//--- ResetLed start
int ResetLed::_digitalWrite(){
	return GPIO_ReadOutputDataBit(RESETLED_PIN);
}

void ResetLed::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(RESETLED_PIN);
	else GPIO_SetBits(RESETLED_PIN);
}

int ResetLed::_digitalRead(){
	return GPIO_ReadInputDataBit(RESETLED_PIN);
}

int ResetLed::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, RESETLED_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int ResetLed::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, RESETLED_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int ResetLed::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, RESETLED_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int ResetLed::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, RESETLED_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- ResetLed End
//--- A0 start
int A0::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A0_PIN);
}

void A0::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A0_PIN);
	else GPIO_SetBits(A0_PIN);
}

int A0::_digitalRead(){
	return GPIO_ReadInputDataBit(A0_PIN);
}

int A0::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A0::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A0::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A0_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A0::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A0_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A0::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A0_PIN);
	return 0;
}

float A0::_analogRead(){
	return (get_ADC1_value(A0_PIN) / analogResolution());
}
//--- A0 end
//--- A1 start
int A1::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A1_PIN);
}

void A1::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A1_PIN);
	else GPIO_SetBits(A1_PIN);
}

int A1::_digitalRead(){
	return GPIO_ReadInputDataBit(A1_PIN);
}

int A1::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A1::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A1::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A1_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A1::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A1_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A1::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A1_PIN);
	return 0;
}

float A1::_analogRead(){
	return (get_ADC1_value(A1_PIN) / analogResolution());
}
//--- A1 end
//--- A2 start
int A2::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A2_PIN);
}

void A2::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A2_PIN);
	else GPIO_SetBits(A2_PIN);
}

int A2::_digitalRead(){
	return GPIO_ReadInputDataBit(A2_PIN);
}

int A2::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A2::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A2::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A2_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A2::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A2_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A2::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A2_PIN);
	return 0;
}

float A2::_analogRead(){
	return (get_ADC1_value(A2_PIN) / analogResolution());
}
//--- A2 end
//--- A3 start
int A3::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A3_PIN);
}

void A3::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A3_PIN);
	else GPIO_SetBits(A3_PIN);
}

int A3::_digitalRead(){
	return GPIO_ReadInputDataBit(A3_PIN);
}

int A3::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A3::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A3::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A3_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A3::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A3_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A3::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A3_PIN);
	return 0;
}

float A3::_analogRead(){
	return (get_ADC1_value(A3_PIN) / analogResolution());
}
//--- A3 end
//--- A4 start
int A4::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A4_PIN);
}

void A4::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A4_PIN);
	else GPIO_SetBits(A4_PIN);
}

int A4::_digitalRead(){
	return GPIO_ReadInputDataBit(A4_PIN);
}

int A4::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A4_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A4::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A4_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A4::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A4_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A4::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A4_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A4::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A4_PIN);
	return 0;
}

float A4::_analogRead(){
	return (get_ADC1_value(A4_PIN) / analogResolution());
}
//--- A4 end
//--- A5 start
int A5::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A5_PIN);
}

void A5::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A5_PIN);
	else GPIO_SetBits(A5_PIN);
}

int A5::_digitalRead(){
	return GPIO_ReadInputDataBit(A5_PIN);
}

int A5::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A5_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A5::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A5_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A5::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A5_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A5::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A5_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A5::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A5_PIN);
	return 0;
}

float A5::_analogRead(){
	return (get_ADC1_value(A5_PIN) / analogResolution());
}
//--- A5 end
//--- A6 start
int A6::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A6_PIN);
}

void A6::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A6_PIN);
	else GPIO_SetBits(A6_PIN);
}

int A6::_digitalRead(){
	return GPIO_ReadInputDataBit(A6_PIN);
}

int A6::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A6_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A6::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A6_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A6::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A6_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A6::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A6_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A6::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A6_PIN);
	return 0;
}

float A6::_analogRead(){
	return (get_ADC1_value(A6_PIN) / analogResolution());
}
//--- A6 end
//--- A7 start
int A7::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A7_PIN);
}

void A7::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A7_PIN);
	else GPIO_SetBits(A7_PIN);
}

int A7::_digitalRead(){
	return GPIO_ReadInputDataBit(A7_PIN);
}

int A7::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A7_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A7::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A7_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A7::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A7_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A7::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A7_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A7::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A7_PIN);
	return 0;
}

float A7::_analogRead(){
	return (get_ADC1_value(A7_PIN) / analogResolution());
}
//--- A7 end
//--- A8 start
int A8::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A8_PIN);
}

void A8::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A8_PIN);
	else GPIO_SetBits(A8_PIN);
}

int A8::_digitalRead(){
	return GPIO_ReadInputDataBit(A8_PIN);
}

int A8::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A8_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A8::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A8_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A8::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A8_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A8::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A8_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A8::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A8_PIN);
	return 0;
}

float A8::_analogRead(){
	return (get_ADC1_value(A8_PIN) / analogResolution());
}
//--- A8 end
//--- A9 start
int A9::_digitalWrite(){
	return GPIO_ReadOutputDataBit(A9_PIN);
}

void A9::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(A9_PIN);
	else GPIO_SetBits(A9_PIN);
}

int A9::_digitalRead(){
	return GPIO_ReadInputDataBit(A9_PIN);
}

int A9::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, A9_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A9::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, A9_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int A9::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, A9_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int A9::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, A9_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int A9::_setupAnalogIn(){
	mode = MODE_ANALOG;
	Init_ADC1(A9_PIN);
	return 0;
}

float A9::_analogRead(){
	return (get_ADC1_value(A9_PIN) / analogResolution());
}
//--- A9 end
//---D5v0 start
D5v0::D5v0(){
	line=Pin_source(D5V0_PIN);
}

int D5v0::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D5V0_PIN);
}

void D5v0::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D5V0_PIN);
	}
	else {
		GPIO_SetBits(D5V0_PIN);
	}
}

int D5v0::_digitalRead()
{
	return GPIO_ReadInputDataBit(D5V0_PIN);
}

int D5v0::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D5V0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v0::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D5V0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v0::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D5V0_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D5v0::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D5V0_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D5v0::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D5V0_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D5V0_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D5V0_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void D5v0::stopInterrupt(){
	Deinit_gpio_interrupt(D5V0_PIN);
}

int D5v0::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//---D5v0 start
//---D5v1 end
D5v1::D5v1(){
	line=Pin_source(D5V1_PIN);
}

int D5v1::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D5V1_PIN);
}

void D5v1::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D5V1_PIN);
	}
	else {
		GPIO_SetBits(D5V1_PIN);
	}
}

int D5v1::_digitalRead()
{
	return GPIO_ReadInputDataBit(D5V1_PIN);
}

int D5v1::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D5V1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v1::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D5V1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v1::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D5V1_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D5v1::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D5V1_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D5v1::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D5V1_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D5V1_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D5V1_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D5v1::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D5v1::stopInterrupt(){
	Deinit_gpio_interrupt(D5V1_PIN);
};
//--- D5v1 end
//--- D5v2 start
D5v2::D5v2(){
	line=Pin_source(D5V2_PIN);
}

int D5v2::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D5V2_PIN);
}

void D5v2::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D5V2_PIN);
	}
	else {
		GPIO_SetBits(D5V2_PIN);
	}
}

int D5v2::_digitalRead()
{
	return GPIO_ReadInputDataBit(D5V2_PIN);
}

int D5v2::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D5V2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v2::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D5V2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v2::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D5V2_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D5v2::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D5V2_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
int D5v2::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D5V2_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D5V2_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D5V2_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D5v2::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D5v2::stopInterrupt(){
	Deinit_gpio_interrupt(D5V2_PIN);
};
//--- D5v2 end
//---D5v3 start
D5v3::D5v3(){
	line=Pin_source(D5V3_PIN);
}

int D5v3::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D5V3_PIN);
}

void D5v3::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D5V3_PIN);
	}
	else {
		GPIO_SetBits(D5V3_PIN);
	}
}

int D5v3::_digitalRead()
{
	return GPIO_ReadInputDataBit(D5V3_PIN);
}

int D5v3::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D5V3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v3::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D5V3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D5v3::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D5V3_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D5v3::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D5V3_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
int D5v3::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D5V3_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D5V3_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D5V3_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D5v3::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D5v3::stopInterrupt(){
	Deinit_gpio_interrupt(D5V3_PIN);
};
//--- D5v3 end
//--- D0 start
D0::D0(){
	line=Pin_source(D0_PIN);
}

int D0::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D0_PIN);
}

void D0::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D0_PIN);
	}
	else {
		GPIO_SetBits(D0_PIN);
	}
}

int D0::_digitalRead()
{
	return GPIO_ReadInputDataBit(D0_PIN);
}

int D0::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D0::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D0::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D0_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D0::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D0_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D0::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D0_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D0_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D0_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D0::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D0::stopInterrupt(){
	Deinit_gpio_interrupt(D0_PIN);
};
//--- D0 end
//--- D1 start
D1::D1(){
	line=Pin_source(D1_PIN);
}

int D1::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D1_PIN);
}

void D1::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D1_PIN);
	}
	else {
		GPIO_SetBits(D1_PIN);
	}
}

int D1::_digitalRead()
{
	return GPIO_ReadInputDataBit(D1_PIN);
}

int D1::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D1::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D1::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D1_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D1::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D1_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D1::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D1_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D1_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D1_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D1::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D1::stopInterrupt(){
	Deinit_gpio_interrupt(D1_PIN);
};
//--- D1 end
//--- D2 start
D2::D2(){
	line=Pin_source(D2_PIN);
}

int D2::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D2_PIN);
}

void D2::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D2_PIN);
	}
	else {
		GPIO_SetBits(D2_PIN);
	}
}

int D2::_digitalRead()
{
	return GPIO_ReadInputDataBit(D2_PIN);
}

int D2::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D2::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D2::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D2_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D2::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D2_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D2::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D2_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D2_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D2_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D2::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D2::stopInterrupt(){
	Deinit_gpio_interrupt(D2_PIN);
};
//--- D2 end
//--- D3 start
D3::D3(){
	line=Pin_source(D3_PIN);
}

int D3::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(D3_PIN);
}

void D3::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(D3_PIN);
	}
	else {
		GPIO_SetBits(D3_PIN);
	}
}

int D3::_digitalRead()
{
	return GPIO_ReadInputDataBit(D3_PIN);
}

int D3::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, D3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D3::_setupDigitalOut()
{
	Init_port(GPIO_Mode_OUT, D3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int D3::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, D3_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int D3::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, D3_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int D3::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(D3_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(D3_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(D3_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

int D3::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}

void D3::stopInterrupt(){
	Deinit_gpio_interrupt(D3_PIN);
};
//--- D3 end
//--- DataHold start
int DataHold::_digitalWrite(){
	return GPIO_ReadOutputDataBit(HOLD_PIN);
}

void DataHold::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(HOLD_PIN);
	else GPIO_SetBits(HOLD_PIN);
}

int DataHold::_digitalRead(){
	return GPIO_ReadInputDataBit(HOLD_PIN);
}

int DataHold::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, HOLD_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int DataHold::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, HOLD_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int DataHold::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, HOLD_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int DataHold::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, HOLD_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- DataHold End
//--- WritePeotect start
int WriteProtect::_digitalWrite(){
	return GPIO_ReadOutputDataBit(WRITEPROTECT_PIN);
}

void WriteProtect::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(WRITEPROTECT_PIN);
	else GPIO_SetBits(WRITEPROTECT_PIN);
}

int WriteProtect::_digitalRead(){
	return GPIO_ReadInputDataBit(WRITEPROTECT_PIN);
}

int WriteProtect::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, WRITEPROTECT_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int WriteProtect::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, WRITEPROTECT_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int WriteProtect::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, WRITEPROTECT_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int WriteProtect::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, WRITEPROTECT_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- WriteProtect End
//--- ChipSelect start
int ChipSelect::_digitalWrite(){
	return GPIO_ReadOutputDataBit(CHIPSELECT_PIN);
}

void ChipSelect::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(CHIPSELECT_PIN);
	else GPIO_SetBits(CHIPSELECT_PIN);
}

int ChipSelect::_digitalRead(){
	return GPIO_ReadInputDataBit(CHIPSELECT_PIN);
}

int ChipSelect::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, CHIPSELECT_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int ChipSelect::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, CHIPSELECT_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int ChipSelect::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, CHIPSELECT_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int ChipSelect::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, CHIPSELECT_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- ChipSelect End
//--- Pwm0 start
int Pwm0::_digitalWrite(){
	return GPIO_ReadOutputDataBit(PWM0);
}

void Pwm0::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(PWM0);
	else GPIO_SetBits(PWM0);
}

int Pwm0::_digitalRead(){
	return GPIO_ReadInputDataBit(PWM0);
}

int Pwm0::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, PWM0, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm0::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM0, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm0::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, PWM0, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm0::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, PWM0, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm0::_setupPwmOut(float frequency, float duty){
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM0SET, frequency);
	Set_duty(PWM0TIMCH, duty);
	return i;
}

void Pwm0::_pwmWrite(float duty){
	Set_duty(PWM0TIMCH, duty);
}

float Pwm0::_pwmWrite(){
	return Read_duty(PWM0TIMCH);
}
//--- Pwm0 end
//***Pwm1�͂��܂�***
int Pwm1::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM1);
}

void Pwm1::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM1);
	}
	else {
		GPIO_SetBits(PWM1);
	}
}

int Pwm1::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM1);
}

int Pwm1::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM1, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm1::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM1, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm1::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM1, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm1::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM1, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm1::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM1SET, frequency);
	Set_duty(PWM0TIMCH, duty);
	return i;
}

void Pwm1::_pwmWrite(float duty)
{
	Set_duty(PWM1TIMCH, duty);
}

float Pwm1::_pwmWrite()
{
	return Read_duty(PWM1TIMCH);
}
//***Pwm1�����***
//***Pwm2�͂��܂�***
int Pwm2::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM2);
}

void Pwm2::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM2);
	}
	else {
		GPIO_SetBits(PWM2);
	}
}

int Pwm2::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM2);
}

int Pwm2::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM2, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm2::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM2, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm2::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM2, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm2::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM2, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm2::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM2SET, frequency);
	Set_duty(PWM2TIMCH, duty);
	return i;
}

void Pwm2::_pwmWrite(float duty)
{
	Set_duty(PWM2TIMCH, duty);
}

float Pwm2::_pwmWrite()
{
	return Read_duty(PWM2TIMCH);
}
//***Pwm2�����***
//***Pwm3�͂��܂�***
int Pwm3::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM3);
}

void Pwm3::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM3);
	}
	else {
		GPIO_SetBits(PWM3);
	}
}

int Pwm3::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM3);
}

int Pwm3::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM3, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm3::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM3, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm3::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM3, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm3::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM3, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm3::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM3SET, frequency);
	Set_duty(PWM3TIMCH, duty);
	return i;
}

void Pwm3::_pwmWrite(float duty)
{
	Set_duty(PWM3TIMCH, duty);
}

float Pwm3::_pwmWrite()
{
	return Read_duty(PWM3TIMCH);
}
//***Pwm3�����***
//***Pwm4�͂��܂�***
int Pwm4::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM4);
}

void Pwm4::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM4);
	}
	else {
		GPIO_SetBits(PWM4);
	}
}

int Pwm4::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM4);
}

int Pwm4::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM4, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm4::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM4, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm4::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM4, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm4::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM4, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm4::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM4SET, frequency);
	Set_duty(PWM4TIMCH, duty);
	return i;
}

void Pwm4::_pwmWrite(float duty)
{
	Set_duty(PWM4TIMCH, duty);
}

float Pwm4::_pwmWrite()
{
	return Read_duty(PWM4TIMCH);
}
//***Pwm4�����***
//***Pwm5�͂��܂�***
int Pwm5::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM5);
}

void Pwm5::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM5);
	}
	else {
		GPIO_SetBits(PWM5);
	}
}

int Pwm5::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM5);
}

int Pwm5::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM5, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm5::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM5, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm5::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM5, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm5::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM5, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm5::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM5SET, frequency);
	Set_duty(PWM5TIMCH, duty);
	return i;
}

void Pwm5::_pwmWrite(float duty)
{
	Set_duty(PWM5TIMCH, duty);
}

float Pwm5::_pwmWrite(){
	return Read_duty(PWM5TIMCH);
}
//***Pwm5�����***
//***Pwm6�͂��܂�***
int Pwm6::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM6);
}

void Pwm6::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM6);
	}
	else {
		GPIO_SetBits(PWM6);
	}
}

int Pwm6::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM6);
}

int Pwm6::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM6, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm6::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM6, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm6::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM6, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm6::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM6, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm6::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM6SET, frequency);
	Set_duty(PWM6TIMCH, duty);
	return i;
}

void Pwm6::_pwmWrite(float duty)
{
	Set_duty(PWM6TIMCH, duty);
}

float Pwm6::_pwmWrite()
{
	return Read_duty(PWM6TIMCH);
}
//***Pwm6�����***
//***Pwm7�͂��܂�***
int Pwm7::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM7);
}

void Pwm7::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM7);
	}
	else {
		GPIO_SetBits(PWM7);
	}
}

int Pwm7::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM7);
}

int Pwm7::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM7, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm7::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM7, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm7::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM7, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm7::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM7, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm7::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM7SET, frequency);
	Set_duty(PWM7TIMCH, duty);
	return i;
}

void Pwm7::_pwmWrite(float duty)
{
	Set_duty(PWM7TIMCH, duty);
}

float Pwm7::_pwmWrite()
{
	return Read_duty(PWM7TIMCH);
}
//***Pwm7�����***
//***Pwm8�͂��܂�***
int Pwm8::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM8);
}

void Pwm8::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM8);
	}
	else {
		GPIO_SetBits(PWM8);
	}
}

int Pwm8::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM8);
}

int Pwm8::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM8, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm8::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM8, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm8::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM8, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm8::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM8, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm8::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM8SET, frequency);
	Set_duty(PWM8TIMCH, duty);
	return i;
}

void Pwm8::_pwmWrite(float duty)
{
	Set_duty(PWM8TIMCH, duty);
}

float Pwm8::_pwmWrite()
{
	return Read_duty(PWM8TIMCH);
}
//***Pwm8�����***
//***Pwm9�͂��܂�***
int Pwm9::_digitalWrite()
{
	return GPIO_ReadOutputDataBit(PWM9);
}

void Pwm9::_digitalWrite(int value)
{
	if (value == 0) {
		GPIO_ResetBits(PWM9);
	}
	else {
		GPIO_SetBits(PWM9);
	}
}

int Pwm9::_digitalRead()
{
	return GPIO_ReadInputDataBit(PWM9);
}

int Pwm9::_setupDigitalIn()
{
	Init_port(GPIO_Mode_IN, PWM9, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm9::_setupDigitalOut()
{
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, PWM9, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Pwm9::_setupDigitalInPullUp()
{
	Init_port(GPIO_Mode_IN, PWM9, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Pwm9::_setupDigitalInPullDown()
{
	Init_port(GPIO_Mode_IN, PWM9, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Pwm9::_setupPwmOut(float frequency, float duty)
{
	int i;
	mode = MODE_PWM;
	i = Init_PWM(PWM9SET, frequency);
	Set_duty(PWM9TIMCH, duty);
	return i;
}

void Pwm9::_pwmWrite(float duty)
{
	Set_duty(PWM9TIMCH, duty);
}

float Pwm9::_pwmWrite()
{
	return Read_duty(PWM9TIMCH);
}
//***Pwm9�����***
//--- Buzzer start
int Buzzer::_digitalWrite(){
	return GPIO_ReadOutputDataBit(BUZZER);
}

void Buzzer::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(BUZZER);
	else GPIO_SetBits(BUZZER);
}

int Buzzer::_digitalRead(){
	return GPIO_ReadInputDataBit(BUZZER);
}

int Buzzer::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, BUZZER, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Buzzer::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, BUZZER, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Buzzer::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, BUZZER, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Buzzer::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, BUZZER, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Buzzer::_setupPwmOut(float frequency, float duty){
	int i;
	mode = MODE_PWM;
	i = Init_PWM(BUZZERSET, frequency);
	Set_duty(BUZZERTIMCH, duty);
	return i;
}

void Buzzer::_pwmWrite(float duty){
	Set_duty(BUZZERTIMCH, duty);
}

float Buzzer::_pwmWrite(){
	return Read_duty(BUZZERTIMCH);
}
//--- Buzzer end
//***RED�͂��܂�***
int Red::_digitalWrite(){
	return GPIO_ReadOutputDataBit(RED);
}

void Red::_digitalWrite(int value){
	if (value == 0) {
		GPIO_ResetBits(RED);
	} else {
		GPIO_SetBits(RED);
	}
}

int Red::_digitalRead()
{
	return GPIO_ReadInputDataBit(RED);
}

int Red::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, RED, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Red::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, RED, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Red::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, RED, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Red::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, RED, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Red::_setupPwmOut(float frequency, float duty){
	int i;
	mode = MODE_PWM;
	i = Init_PWM(REDSET, frequency);
	Set_duty(REDTIMCH, duty);
	return i;
}

void Red::_pwmWrite(float duty){
	Set_duty(REDTIMCH, duty);
}

float Red::_pwmWrite(){
	return Read_duty(REDTIMCH);
}
//***RED�����***
//***GREEN�͂��܂�***
int Green::_digitalWrite(){
	return GPIO_ReadOutputDataBit(GREEN);
}

void Green::_digitalWrite(int value){
	if (value == 0) {
		GPIO_ResetBits(GREEN);
	} else {
		GPIO_SetBits(GREEN);
	}
}

int Green::_digitalRead(){
	return GPIO_ReadInputDataBit(GREEN);
}

int Green::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, GREEN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Green::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, GREEN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Green::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, GREEN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Green::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, GREEN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Green::_setupPwmOut(float frequency, float duty){
	int i;
	mode = MODE_PWM;
	i = Init_PWM(GREENSET, frequency);
	Set_duty(GREENTIMCH, duty);
	return i;
}

void Green::_pwmWrite(float duty){
	Set_duty(GREENTIMCH, duty);
}

float Green::_pwmWrite(){
	return Read_duty(GREENTIMCH);
}
//***GREEN�����***
//***BLUE�͂��܂�***
int Blue::_digitalWrite(){
	return GPIO_ReadOutputDataBit(BLUE);
}

void Blue::_digitalWrite(int value){
	if (value == 0) {
		GPIO_ResetBits(BLUE);
	} else {
		GPIO_SetBits(BLUE);
	}
}

int Blue::_digitalRead(){
	return GPIO_ReadInputDataBit(BLUE);
}

int Blue::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, BLUE, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Blue::_setupDigitalOut(){
	mode = MODE_DIGITAL;
	Init_port(GPIO_Mode_OUT, BLUE, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Blue::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, BLUE, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Blue::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, BLUE, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Blue::_setupPwmOut(float frequency, float duty){
	int i;
	mode = MODE_PWM;
	i = Init_PWM(BLUESET, frequency);
	Set_duty(BLUETIMCH, duty);
	return i;
}

void Blue::_pwmWrite(float duty){
	Set_duty(BLUETIMCH, duty);
}

float Blue::_pwmWrite(){
	return Read_duty(BLUETIMCH);
}
//***BLUE�����***
//--- Led0 start
Led0::Led0(){
	line=Pin_source(LED0_PIN);
}

int Led0::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED0_PIN);
}

void Led0::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED0_PIN);
	else GPIO_SetBits(LED0_PIN);
}

int Led0::_digitalRead(){
	return GPIO_ReadInputDataBit(LED0_PIN);
}

int Led0::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led0::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led0::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED0_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led0::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED0_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Led0::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED0_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED0_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED0_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led0::stopInterrupt(){
	Deinit_gpio_interrupt(LED0_PIN);
}

int Led0::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led0 end
//--- Led1 start
Led1::Led1(){
	line=Pin_source(LED1_PIN);
}

int Led1::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED1_PIN);
}

void Led1::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED1_PIN);
	else GPIO_SetBits(LED1_PIN);
}

int Led1::_digitalRead(){
	return GPIO_ReadInputDataBit(LED1_PIN);
}

int Led1::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led1::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led1::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED1_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led1::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED1_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Led1::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED1_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED1_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED1_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led1::stopInterrupt(){
	Deinit_gpio_interrupt(LED1_PIN);
}

int Led1::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led1 end
//--- Led2 start
Led2::Led2(){
	line=Pin_source(LED2_PIN);
}

int Led2::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED2_PIN);
}

void Led2::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED2_PIN);
	else GPIO_SetBits(LED2_PIN);
}

int Led2::_digitalRead(){
	return GPIO_ReadInputDataBit(LED2_PIN);
}

int Led2::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led2::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led2::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED2_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led2::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED2_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Led2::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED2_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED2_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED2_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led2::stopInterrupt(){
	Deinit_gpio_interrupt(LED2_PIN);
}

int Led2::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led2 end
//--- Led3 start
Led3::Led3(){
	line=Pin_source(LED3_PIN);
}

int Led3::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED3_PIN);
}

void Led3::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED3_PIN);
	else GPIO_SetBits(LED3_PIN);
}

int Led3::_digitalRead(){
	return GPIO_ReadInputDataBit(LED3_PIN);
}

int Led3::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led3::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led3::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED3_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led3::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED3_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Led3::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED3_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED3_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED3_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led3::stopInterrupt(){
	Deinit_gpio_interrupt(LED3_PIN);
}

int Led3::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led3 end
//--- Led4 start
Led4::Led4(){
	line=Pin_source(LED4_PIN);
}
int Led4::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED4_PIN);
}

void Led4::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED4_PIN);
	else GPIO_SetBits(LED4_PIN);
}

int Led4::_digitalRead(){
	return GPIO_ReadInputDataBit(LED4_PIN);
}

int Led4::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED4_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led4::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED4_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led4::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED4_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led4::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED4_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
int Led4::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED4_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED4_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED4_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led4::stopInterrupt(){
	Deinit_gpio_interrupt(LED4_PIN);
}

int Led4::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led4 End
//--- Led5 start
Led5::Led5(){
	line=Pin_source(LED5_PIN);
}
int Led5::_digitalWrite(){
	return GPIO_ReadOutputDataBit(LED5_PIN);
}

void Led5::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(LED5_PIN);
	else GPIO_SetBits(LED5_PIN);
}

int Led5::_digitalRead(){
	return GPIO_ReadInputDataBit(LED5_PIN);
}

int Led5::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, LED5_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led5::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, LED5_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Led5::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, LED5_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Led5::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, LED5_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}

int Led5::_setupDigitalInterrupt(int interruptMode){
	if(interruptMode==INTERRUPT_RISING)
		Init_gpio_interrupt(LED5_PIN,EXTI_Trigger_Rising);
	else if(interruptMode==INTERRUPT_FALLING)
		Init_gpio_interrupt(LED5_PIN,EXTI_Trigger_Falling);
	else if(interruptMode==INTERRUPT_RISING_FALLING)
		Init_gpio_interrupt(LED5_PIN,EXTI_Trigger_Rising_Falling);
	return 0;
}

void Led5::stopInterrupt(){
	Deinit_gpio_interrupt(LED5_PIN);
}

int Led5::addInterruptHandler(DigitalInterruptHandler &handler){
	DigitalInterrupt0::handlerMap[line]=true;
	DigitalInterrupt0::digitalInterruptHander[line]=&handler;
	return 0;
}
//--- Led5 End
//--- Sw0 start
Sw0::Sw0(){
	line=Pin_source(SW0_PIN);
}

int Sw0::_digitalWrite(){
	return GPIO_ReadOutputDataBit(SW0_PIN);
}

void Sw0::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(SW0_PIN);
	else GPIO_SetBits(SW0_PIN);
}

int Sw0::_digitalRead(){
	return GPIO_ReadInputDataBit(SW0_PIN);
}

int Sw0::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, SW0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw0::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, SW0_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw0::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, SW0_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Sw0::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, SW0_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- Sw0 end
//--- Sw1 start
Sw1::Sw1(){
	line=Pin_source(SW1_PIN);
}

int Sw1::_digitalWrite(){
	return GPIO_ReadOutputDataBit(SW1_PIN);
}

void Sw1::_digitalWrite(int value){
	if (value == 0)GPIO_ResetBits(SW1_PIN);
	else GPIO_SetBits(SW1_PIN);
}

int Sw1::_digitalRead(){
	return GPIO_ReadInputDataBit(SW1_PIN);
}

int Sw1::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, SW1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw1::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, SW1_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw1::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, SW1_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Sw1::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, SW1_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//--- Sw1 end
//***SW2�͂��܂�***
Sw2::Sw2(){
	line=Pin_source(SW2_PIN);
}
int Sw2::_digitalWrite(){
	return GPIO_ReadOutputDataBit(SW2_PIN);
}

void Sw2::_digitalWrite(int value){
	if (value == 0) {
		GPIO_ResetBits(SW2_PIN);
	} else {
		GPIO_SetBits(SW2_PIN);
	}
}

int Sw2::_digitalRead(){
	return GPIO_ReadInputDataBit(SW2_PIN);
}

int Sw2::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, SW2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw2::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, SW2_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw2::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, SW2_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Sw2::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, SW2_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//***SW2�����***
//***SW3�͂��܂�***
Sw3::Sw3(){
	line=Pin_source(SW3_PIN);
}
int Sw3::_digitalWrite(){
	return GPIO_ReadOutputDataBit(SW3_PIN);
}

void Sw3::_digitalWrite(int value){
	if (value == 0) {
		GPIO_ResetBits(SW3_PIN);
	} else {
		GPIO_SetBits(SW3_PIN);
	}
}

int Sw3::_digitalRead(){
	return GPIO_ReadInputDataBit(SW3_PIN);
}

int Sw3::_setupDigitalIn(){
	Init_port(GPIO_Mode_IN, SW3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw3::_setupDigitalOut(){
	Init_port(GPIO_Mode_OUT, SW3_PIN, GPIO_PuPd_NOPULL, GPIO_OType_PP);
	return 0;
}

int Sw3::_setupDigitalInPullUp(){
	Init_port(GPIO_Mode_IN, SW3_PIN, GPIO_PuPd_UP, GPIO_OType_PP);
	return 0;
}

int Sw3::_setupDigitalInPullDown(){
	Init_port(GPIO_Mode_IN, SW3_PIN, GPIO_PuPd_DOWN, GPIO_OType_PP);
	return 0;
}
//***SW3�����***
//--- Enc0 start
int Enc0::setup()
{
	Init_encoder(ENC0TIM, ENC0);
	return 0;
}

int Enc0::count()
{
	if (revFlag) return -Select_encoder_count(ENC0TIM);
	else return Select_encoder_count(ENC0TIM);
}
//--- Enc0 end
//--- Enc1 start
int Enc1::setup()
{
	Init_encoder(ENC1TIM, ENC1);
	return 0;
}

int Enc1::count()
{
	if (revFlag) return -Select_encoder_count(ENC1TIM);
	else return Select_encoder_count(ENC1TIM);
}
//--- Enc1 end
//--- Enc2 start
int Enc2::setup()
{
	Init_encoder(ENC2TIM, ENC2);
	return 0;
}

int Enc2::count()
{
	if (revFlag) return -Select_encoder_count(ENC2TIM);
	else return Select_encoder_count(ENC2TIM);
}
//--- Enc2 end
//--- Enc3 start
int Enc3::setup()
{
	Init_encoder(ENC3TIM, ENC3);
	return 0;
}

int Enc3::count()
{
	if (revFlag) return -Select_encoder_count(ENC3TIM);
	else return Select_encoder_count(ENC3TIM);
}
//--- Enc3 end
//--- Serial0 start
int serialParitySelect(int parity){
	if(parity==Serial::SERIAL_PARITY_EVEN){
		return USART_Parity_Even;
	}else if(parity==Serial::SERIAL_PARITY_ODD){
		return USART_Parity_Odd;
	}else
		return USART_Parity_No;
}

int serialLengthSelect(int wordLength){
	if(wordLength==9){
		return USART_WordLength_9b;
	}else
		return USART_WordLength_8b;
}

SerialHandler *Serial0::Handler;
RingBuffer<char,256> Serial0::txBuf;
int Serial0::isTransmitting=0;

int Serial0::readNewLine=Serial0::SERIAL0_NEWLINE_NULL;
int Serial0::writeNewLine=Serial0::SERIAL0_NEWLINE_NULL;
char Serial0::oldWriteChar=0;
char Serial0::oldReadChar=0;
#define SERIAL0_TXINT

int Serial0::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL0_TXINT
	Init_USARTi(SERIAL0CH,baudrate,SERIAL0TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL0CH,baudrate,SERIAL0TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler=&HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial0::writeChar(char value)
{
	transmit(value);
}

void serial0_rxInterrupt(){
	char value=USART_ReceiveData(SERIAL0CH);
	//char value1=0;
	/*		if(Serial0::writeNewLine==Serial0::SERIAL0_NEWLINE_LF){
			if(value=='\r'){
				if(Serial0::oldWriteChar!='\n')value='\n';
			}
			Serial0::oldWriteChar=value;
		}
		if(Serial0::writeNewLine==Serial0::SERIAL0_NEWLINE_CR){
			if(value=='\n'){
				if(Serial0::oldWriteChar!='\r')value='\r';
			}
			Serial0::oldWriteChar=value;
		}
		if(Serial0::writeNewLine==Serial0::SERIAL0_NEWLINE_CRLF){
			if(value=='\n'||value=='\r'){
				if(Serial0::oldWriteChar!='\n'||Serial0::oldWriteChar!='\r'){
					Serial0::oldWriteChar=value;
					value='\r';
					value1='\n';
				}
			}else{
				Serial0::oldWriteChar=value;
			}
		}*/
	Serial0::Handler->serialReadChar(value);
	//	if(value1)Serial0::Handler->serialReadChar(value1);
	//USART_ClearFlag(SERIAL0CH,USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL0CH,USART_IT_RXNE);

}

void serial0_txInterrupt(){
#ifdef SERIAL0_TXINT
	if(Serial0::txBuf.isEmpty()==0) USART_SendData(SERIAL0CH,Serial0::txBuf.read());
	if(Serial0::txBuf.isEmpty()==1) Serial0::isTransmitting=0;
	//USART_ClearFlag(SERIAL0CH,USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL0CH,USART_IT_TC);
#endif
}
void Serial0::transmit(char value){
#ifdef SERIAL0_TXINT
	char value1=0;
	if(writeNewLine==SERIAL0_NEWLINE_LF){
		if(value=='\r'){
			if(oldWriteChar!='\n')value='\n';
		}
		oldWriteChar=value;
	}
	if(writeNewLine==SERIAL0_NEWLINE_CR){
		if(value=='\n'){
			if(oldWriteChar!='\r')value='\r';
		}
		oldWriteChar=value;
	}
	if(writeNewLine==SERIAL0_NEWLINE_CRLF){
		if(value=='\n'||value=='\r'){
			if(oldWriteChar!='\n'||oldWriteChar!='\r'){
				oldWriteChar=value;
				value='\r';
				value1='\n';
			}
		}else{
			oldWriteChar=value;
		}
	}
	if(isTransmitting==0){
		USART_SendData(SERIAL0CH, value);
		//if(value1)USART_SendData(SERIAL0CH, value1);
		if(value1)while(txBuf.write(value1));
		isTransmitting=1;
	}else{
		while(txBuf.write(value));
		if(value1)while(txBuf.write(value1));
	}
#if 0
	if(isTransmitting==0){
		USART_SendData(SERIAL0CH, value);
		if(value=='\n')txBuf.write('\r');
		if(value=='\r')txBuf.write('\n');
		isTransmitting=1;
	}else{
		while(txBuf.write(value));
		if(value=='\n')while(txBuf.write('\r'));
		if(value=='\r')while(txBuf.write('\n'));
	}
#endif

#else
	while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL0CH, value);
	if(value=='\n'){
		while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
		USART_SendData(SERIAL0CH, '\r');
	}
	if(value=='\r'){
		while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
		USART_SendData(SERIAL0CH, '\n');
	}
#endif
}

void Serial0::setReadNewLineLF(){readNewLine=SERIAL0_NEWLINE_LF;}
void Serial0::setReadNewLineCR(){readNewLine=SERIAL0_NEWLINE_CR;}
void Serial0::setReadNewLineCRLF(){readNewLine=SERIAL0_NEWLINE_CRLF;}
void Serial0::setWriteNewLineLF(){writeNewLine=SERIAL0_NEWLINE_LF;}
void Serial0::setWriteNewLineCR(){writeNewLine=SERIAL0_NEWLINE_CR;}
void Serial0::setWriteNewLineCRLF(){writeNewLine=SERIAL0_NEWLINE_CRLF;}


extern "C" void USART1_IRQHandler(void) {
	//serial0_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TC) == SET)serial0_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL0CH, USART_IT_RXNE) == SET)serial0_rxInterrupt();
	if (USART_GetITStatus(SERIAL0CH, USART_IT_TC) == SET)serial0_txInterrupt();
	if (USART_GetITStatus(SERIAL0CH, USART_IT_RXNE) == SET)serial0_rxInterrupt();
}

void std_char_out(char value) {
	//	while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
	//	USART_SendData(SERIAL0CH, value);
	Serial0::transmit(value);
}

void std_char_out_with_flush(char value){
	while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL0CH, value);
	while(USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
}

int std_char_out_setup() {
	Serial0::Handler = new SerialHandler();
#ifdef SERIAL0_TXINT
	Init_USARTi(SERIAL0CH, 9600, SERIAL0TxRx, 0, 8);
#else
	Init_USART(SERIAL0CH, 9600, SERIAL0TxRx, 0, 8);
#endif
	return 0;
}

SerialHandler *Serial1::Handler;
RingBuffer<char, 256> Serial1::txBuf;
int Serial1::isTransmitting = 0;
#define SERIAL1_TXINT
// ---Serial0 end
//***Serial1�͂��܂�***
int Serial1::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL1_TXINT
	Init_USARTi(SERIAL1CH, baudrate, SERIAL1TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL1CH, baudrate, SERIAL1TxRx,serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler = &HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial1::writeChar(char value)
{
	transmit(value);
}

void serial1_rxInterrupt() {
	Serial1::Handler->serialReadChar(USART_ReceiveData(SERIAL1CH));
	//USART_ClearFlag(SERIAL1CH, USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL1CH,USART_IT_RXNE);
}

void serial1_txInterrupt() {
#ifdef SERIAL1_TXINT
	if (Serial1::txBuf.isEmpty() == 0) USART_SendData(SERIAL1CH, Serial1::txBuf.read());
	if (Serial1::txBuf.isEmpty() == 1) Serial1::isTransmitting = 0;
	//USART_ClearFlag(SERIAL1CH, USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL1CH,USART_IT_TC);
#endif
}

void Serial1::transmit(char value) {
#ifdef SERIAL1_TXINT
	if (isTransmitting == 0) {
		USART_SendData(SERIAL1CH, value);
		isTransmitting = 1;
	}
	else {
		while (txBuf.write(value));
	}
#else
	while (USART_GetFlagStatus(SERIAL1CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL1CH, value);
#endif
}


extern "C" void USART3_IRQHandler(void) {
	//serial1_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL1CH, USART_FLAG_TC) == SET)serial1_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL1CH, USART_IT_RXNE) == SET)serial1_rxInterrupt();
	if (USART_GetITStatus(SERIAL1CH, USART_IT_TC) == SET)serial1_txInterrupt();
	if (USART_GetITStatus(SERIAL1CH, USART_IT_RXNE) == SET)serial1_rxInterrupt();
}
//***Serial1�����***

SerialHandler *Serial2::Handler;
//RingBuffer<char, 256> Serial2::txBuf;
RingBuffer<char, 128> Serial2::txBuf;
int Serial2::isTransmitting = 0;

#define SERIAL2_TXINT


int Serial2::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL2_TXINT
	Init_USARTi(SERIAL2CH, baudrate, SERIAL2TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL2CH, baudrate, SERIAL2TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler = &HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial2::writeChar(char value)
{
	transmit(value);
}

void serial2_rxInterrupt() {
	Serial2::Handler->serialReadChar(USART_ReceiveData(SERIAL2CH));
	//USART_ClearFlag(SERIAL2CH, USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL2CH,USART_IT_RXNE);
}

void serial2_txInterrupt() {
#ifdef SERIAL2_TXINT
	if (Serial2::txBuf.isEmpty() == 0) USART_SendData(SERIAL2CH, Serial2::txBuf.read());
	if (Serial2::txBuf.isEmpty() == 1) Serial2::isTransmitting = 0;
	//USART_ClearFlag(SERIAL2CH, USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL2CH,USART_IT_TC);
#endif
}

void Serial2::transmit(char value) {
#ifdef SERIAL2_TXINT
	if (isTransmitting == 0) {
		USART_SendData(SERIAL2CH, value);
		isTransmitting = 1;
	}
	else {
		while (txBuf.write(value));
	}
#else
	while (USART_GetFlagStatus(SERIAL2CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL2CH, value);
#endif
}


extern "C" void USART6_IRQHandler(void) {
	//serial2_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL2CH, USART_FLAG_TC) == SET)serial2_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL2CH, USART_IT_RXNE) == SET)serial2_rxInterrupt();
	if (USART_GetITStatus(SERIAL2CH, USART_IT_TC) == SET)serial2_txInterrupt();
	if (USART_GetITStatus(SERIAL2CH, USART_IT_RXNE) == SET)serial2_rxInterrupt();
}


SerialHandler *Serial3::Handler;
RingBuffer<char, 256> Serial3::txBuf;
int Serial3::isTransmitting = 0;

#define SERIAL3_TXINT


int Serial3::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL3_TXINT
	Init_USARTi(SERIAL3CH, baudrate, SERIAL3TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL3CH, baudrate, SERIAL3TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler = &HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial3::writeChar(char value)
{
	transmit(value);
}

void serial3_rxInterrupt() {
	Serial3::Handler->serialReadChar(USART_ReceiveData(SERIAL3CH));
	//USART_ClearFlag(SERIAL3CH, USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL3CH,USART_IT_RXNE);
}

void serial3_txInterrupt() {
#ifdef SERIAL3_TXINT
	if (Serial3::txBuf.isEmpty() == 0) USART_SendData(SERIAL3CH, Serial3::txBuf.read());
	if (Serial3::txBuf.isEmpty() == 1) Serial3::isTransmitting = 0;
	//USART_ClearFlag(SERIAL3CH, USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL3CH,USART_IT_TC);
#endif
}
void Serial3::transmit(char value) {
#ifdef SERIAL3_TXINT
	if (isTransmitting == 0) {
		USART_SendData(SERIAL3CH, value);
		isTransmitting = 1;
	}
	else {
		while (txBuf.write(value));
	}
#else
	while (USART_GetFlagStatus(SERIAL3CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL3CH, value);
#endif
}

//#define STACK_SIZE       0x00005ffe
//extern unsigned long pulStack[STACK_SIZE];

extern "C" void UART4_IRQHandler(void) {
	//serial3_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL3CH, USART_FLAG_TC) == SET)serial3_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL3CH, USART_IT_RXNE) == SET)serial3_rxInterrupt();
	if (USART_GetITStatus(SERIAL3CH, USART_IT_TC) == SET)serial3_txInterrupt();
	else if (USART_GetITStatus(SERIAL3CH, USART_IT_RXNE) == SET)serial3_rxInterrupt();
	else{
		if(USART_GetITStatus(SERIAL3CH,USART_IT_TXE)){
			USART_ITConfig(SERIAL3CH,USART_IT_TXE,DISABLE);
			//			printf("TXE");
		}
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_IDLE)){}//printf("IDLE");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_LBD)){}//printf("LBD");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_ORE_RX)){
			USART_SendData(SERIAL0CH, 'e');
			USART_ReceiveData(SERIAL3CH);
			//			USART_ClearITPendingBit(SERIAL3CH,USART_IT_ORE_RX);
			//			USART_ClearITPendingBit(SERIAL3CH,USART_IT_RXNE);
		}//printf("ORE_RX");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_ORE_ER)){}//printf("ORE_RE");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_NE)){}//printf("NE");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_FE)){}//printf("FE");
		else if(USART_GetITStatus(SERIAL3CH,USART_IT_PE)){}//printf("PE");
		else{
			USART_SendData(SERIAL0CH, 'i');
			while (USART_GetFlagStatus(SERIAL0CH, USART_FLAG_TXE) == RESET);
		}// printf("ERROR");
	}
	/*	if(pulStack[STACK_SIZE-0x4000]!=123){
		printf("S");
	}*/
}


SerialHandler *Serial4::Handler;
RingBuffer<char, 256> Serial4::txBuf;
int Serial4::isTransmitting = 0;
#define SERIAL4_TXINT
//***Serial1�͂��܂�***
int Serial4::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL4_TXINT
	Init_USARTi(SERIAL4CH, baudrate, SERIAL4TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL4CH, baudrate, SERIAL4TxRx,serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler = &HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial4::writeChar(char value)
{
	transmit(value);
}

void serial4_rxInterrupt() {
	Serial4::Handler->serialReadChar(USART_ReceiveData(SERIAL4CH));
	//USART_ClearFlag(SERIAL4CH, USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL4CH,USART_IT_RXNE);
}

void serial4_txInterrupt() {
#ifdef SERIAL4_TXINT
	if (Serial4::txBuf.isEmpty() == 0) USART_SendData(SERIAL4CH, Serial4::txBuf.read());
	if (Serial4::txBuf.isEmpty() == 1) Serial4::isTransmitting = 0;
	//USART_ClearFlag(SERIAL4CH, USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL4CH,USART_IT_TC);
#endif
}

void Serial4::transmit(char value) {
#ifdef SERIAL4_TXINT
	if (isTransmitting == 0) {
		USART_SendData(SERIAL4CH, value);
		isTransmitting = 1;
	}
	else {
		while (txBuf.write(value));
	}
#else
	while (USART_GetFlagStatus(SERIAL4CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL4CH, value);
#endif
}


extern "C" void UART5_IRQHandler(void) {
	//serial1_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL1CH, USART_FLAG_TC) == SET)serial1_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL1CH, USART_IT_RXNE) == SET)serial1_rxInterrupt();
	if (USART_GetITStatus(SERIAL4CH, USART_IT_TC) == SET)serial4_txInterrupt();
	if (USART_GetITStatus(SERIAL4CH, USART_IT_RXNE) == SET)serial4_rxInterrupt();
}
//***Serial4�����***

//--- Serial5 start
SerialHandler *Serial5::Handler;
RingBuffer<char, 256> Serial5::txBuf;
int Serial5::isTransmitting = 0;

#define SERIAL5_TXINT


int Serial5::_setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength)
{
#ifdef SERIAL5_TXINT
	Init_USARTi(SERIAL5CH, baudrate, SERIAL5TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#else
	Init_USART(SERIAL5CH, baudrate, SERIAL5TxRx, serialParitySelect(parity), serialLengthSelect(wordLength));
#endif
	Handler = &HandlerArg;
	Handler->serialHandlerSetup(this);
	return 0;
}

void Serial5::writeChar(char value)
{
	transmit(value);
}

void serial5_rxInterrupt() {
	Serial5::Handler->serialReadChar(USART_ReceiveData(SERIAL5CH));
	//USART_ClearFlag(SERIAL3CH, USART_FLAG_RXNE);
	USART_ClearITPendingBit(SERIAL5CH,USART_IT_RXNE);
}

void serial5_txInterrupt() {
#ifdef SERIAL5_TXINT
	if (Serial5::txBuf.isEmpty() == 0) USART_SendData(SERIAL5CH, Serial5::txBuf.read());
	if (Serial5::txBuf.isEmpty() == 1) Serial5::isTransmitting = 0;
	//USART_ClearFlag(SERIAL5CH, USART_FLAG_TC);
	USART_ClearITPendingBit(SERIAL5CH,USART_IT_TC);
#endif
}
void Serial5::transmit(char value) {
#ifdef SERIAL5_TXINT
	if (isTransmitting == 0) {
		USART_SendData(SERIAL5CH, value);
		isTransmitting = 1;
	}
	else {
		while (txBuf.write(value));
	}
#else
	while (USART_GetFlagStatus(SERIAL5CH, USART_FLAG_TXE) == RESET);
	USART_SendData(SERIAL5CH, value);
#endif
}

//#define STACK_SIZE       0x00005ffe
//extern unsigned long pulStack[STACK_SIZE];

extern "C" void USART2_IRQHandler(void) {
	//serial5_rxInterrupt();
	//if (USART_GetFlagStatus(SERIAL5CH, USART_FLAG_TC) == SET)serial5_txInterrupt();
	//if (USART_GetFlagStatus(SERIAL5CH, USART_IT_RXNE) == SET)serial5_rxInterrupt();
	if (USART_GetITStatus(SERIAL5CH, USART_IT_TC) == SET)serial5_txInterrupt();
	else if (USART_GetITStatus(SERIAL5CH, USART_IT_RXNE) == SET)serial5_rxInterrupt();
	else{
		if(USART_GetITStatus(SERIAL5CH,USART_IT_TXE)){
			USART_ITConfig(SERIAL5CH,USART_IT_TXE,DISABLE);
			//			printf("TXE");
		}
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_IDLE)){}//printf("IDLE");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_LBD)){}//printf("LBD");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_ORE_RX)){
			USART_SendData(SERIAL5CH, 'e');
			USART_ReceiveData(SERIAL5CH);
			//			USART_ClearITPendingBit(SERIAL5CH,USART_IT_ORE_RX);
			//			USART_ClearITPendingBit(SERIAL5CH,USART_IT_RXNE);
		}//printf("ORE_RX");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_ORE_ER)){}//printf("ORE_RE");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_NE)){}//printf("NE");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_FE)){}//printf("FE");
		else if(USART_GetITStatus(SERIAL5CH,USART_IT_PE)){}//printf("PE");
		else{
			USART_SendData(SERIAL0CH, 'i');
			while (USART_GetFlagStatus(SERIAL5CH, USART_FLAG_TXE) == RESET);
		}// printf("ERROR");
	}
	/*	if(pulStack[STACK_SIZE-0x4000]!=123){
		printf("S");
	}*/
}
//--- Serial5 end

int WatchDog::setup() {
	return Init_watchdog();
}

void WatchDog::cycle() {
	watchdog_reset();
}

//***Can0�͂��܂�***
#define CAN0_TX_INIT
CanHandler *Can0::canHandler[NUMBER_OF_CAN_Handler];
int Can0::canHandlerCursor = 0;
int64_t Can0::txTimer=0;
CanTxMsger Can0::canTxMs;
int Can0::isTransmitting = 0;

Can0::Can0() {
	setuped = false;
	filter_number = 4;
}

int  Can0::setup(){
	int returnValue = 0;
	if (!setuped){
#ifdef CAN0_TX_INIT
		Init_CANi(CAN0_NUMBER, CAN_Mode_Normal, CAN0_PORT); returnValue = 0;
#else
		Init_CAN(CAN0_NUMBER, CAN_Mode_Normal, CAN0_PORT); returnValue = 0;
#endif
		if (returnValue == 0) setuped = true;
	}
	else{
		returnValue = 0;
	}
	return returnValue;
}

int Can0::setupLoopBack() {
	int returnValue = 0;
	if (!setuped) {
#ifdef CAN0_TX_INIT
		Init_CANi(CAN0_NUMBER, CAN_Mode_LoopBack, CAN0_PORT); returnValue = 0;
#else
		Init_CAN(CAN0_NUMBER, CAN_Mode_LoopBack, CAN0_PORT); returnValue = 0;
#endif
		if (returnValue == 0) setuped = true;
	}
	else {
		returnValue = 0;
	}
	return returnValue;
}

int Can0::addHandler(CanHandler &HandlerArg) {
	if (canHandlerCursor >= NUMBER_OF_CAN_Handler) return 1;
	canHandler[canHandlerCursor++] = &HandlerArg;
	HandlerArg.canHandlerSetup(this);
	return 0;
}

int Can0::setId(int id) {
	int row = filter_number / 4;
	filter[filter_number] = (short)id;
	////printf("%s,set id:%x\n",__func__,id);
	Init_CANfilter(row, CAN_LIST, filter[row * 4 + 0], CAN_DATA, filter[row * 4 + 1], CAN_DATA, filter[row * 4 + 2], CAN_DATA, filter[row * 4 + 3], CAN_DATA);
	filter_number++;
	return 0;
}
int Can0::setIdAll() {
	Init_CANfilter(10, CAN_MASK, 0, CAN_DATA, 0, CAN_DATA, 0, CAN_DATA, 0, CAN_DATA);
	return 0;
}

int Can0::read(int id, int number, unsigned char data[8]) {
	//Serial3 ss;
	//printf("%0x%x\n",id);
///	if(id==0x1c1||id==0x1c2)ss.printf("id:%2x length:%2x data:%x,%x,%x,%x,%x,%x,%x,%x\n\r",id,number,data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7]);
	int i;
	bool re=false;
	for (i = 0; i<canHandlerCursor; i++){
		if (canHandler[i]->canId(id)){
			re=true;
			canHandler[i]->canRead(id, number, data);
		}
	}
	return 0;
}

int Can0::write(int id, int number, unsigned char data[8]) {
	//printf("0x%x\n",id);
//	for(int i=0;i<number;i++)printf(",%x",data[i]);
//	printf("\n");
	CanTxMsg can_tx_frame;
	can_tx_frame.StdId = id;
	can_tx_frame.ExtId = 0;
	can_tx_frame.IDE = CAN_Id_Standard;
	if (number != 0)can_tx_frame.RTR = CAN_RTR_Data;
	else can_tx_frame.RTR = CAN_RTR_Remote;
	can_tx_frame.DLC = (uint8_t)number;
	can_tx_frame.Data[0] = data[0];
	can_tx_frame.Data[1] = data[1];
	can_tx_frame.Data[2] = data[2];
	can_tx_frame.Data[3] = data[3];
	can_tx_frame.Data[4] = data[4];
	can_tx_frame.Data[5] = data[5];
	can_tx_frame.Data[6] = data[6];
	can_tx_frame.Data[7] = data[7];
#ifdef CAN0_TX_INIT
	if(Can0::isTransmitting==1){
		while(canTxMs.write(can_tx_frame));
		//printf("buff hzn\r\n");
	}else{
		isTransmitting=1;
		txTimer=millis();
		//printf("write htu\r\n");
		send_can1(&can_tx_frame);
	}
#else
	send_can1(&can_tx_frame);
	while(CANTXOK != CAN_TransmitStatus(CAN1,0));
#endif
	return (int)(millis()-txTimer>=canTxMs.timeOut());
}

CanRxMsg can0_rx_frame;
void Can0_rx_Interrupt() {
	if (CAN_GetITStatus(CAN1, CAN_IT_FMP0)) {
		CAN_Receive(CAN1, CAN_FIFO0, &can0_rx_frame);
		Can0::read((int)can0_rx_frame.StdId, (int)can0_rx_frame.DLC, can0_rx_frame.Data);
	}
}

extern "C" void CAN1_RX0_IRQHandler(void)
{
	Can0_rx_Interrupt();
}

#ifdef CAN0_TX_INIT
void Can0_tx_Interrupt() {
	if(Can0::canTxMs.isEmpty()==0){
		Can0::txTimer=millis();
		//printf("write buf\r\n");
		send_can1(Can0::canTxMs.read());
		Can0::isTransmitting=1;
	}else{
		//printf("\r\nbuff kar\r\n");
		Can0::isTransmitting=0;
	}
	CAN_ClearFlag(CAN1,CAN_FLAG_RQCP0);	//onry maybe...
	//CAN_ClearFlag(CAN1,CAN_FLAG_RQCP1);
	//CAN_ClearFlag(CAN1,CAN_FLAG_RQCP2);
}

extern "C" void CAN1_TX_IRQHandler(void)
{
	Can0_tx_Interrupt();
}
#endif

int Can0::receiveErrorCounter(){
	return CAN_GetReceiveErrorCounter(CAN1);
}

int Can0::transmitErrorCounter(){
	return CAN_GetLSBTransmitErrorCounter(CAN1);
}

//***Can0�����***
//***Can1�͂��܂�***
#define CAN1_TX_INIT
CanHandler *Can1::canHandler[NUMBER_OF_CAN_Handler];
int Can1::canHandlerCursor = 0;
CanTxMsger Can1::canTxMs;
int64_t Can1::txTimer=0;
int Can1::isTransmitting = 0;

Can1::Can1() {
	isTransmitting=0;
	//txBuf=0;
	setuped = false;
	filter_number = 4;
}

int  Can1::setup() {
	int returnValue = 0;
	if (!setuped) {
#ifdef CAN1_TX_INIT
		Init_CANi(CAN1_NUMBER, CAN_Mode_Normal, CAN1_PORT); returnValue = 0;
#else
		Init_CAN(CAN1_NUMBER, CAN_Mode_Normal, CAN1_PORT); returnValue = 0;
#endif
		if (returnValue == 0) setuped = true;
	}
	else {
		returnValue = 0;
	}
	return returnValue;
}

int Can1::setupLoopBack() {
	int returnValue = 0;
	if (!setuped) {
#ifdef CAN1_TX_INIT
		Init_CANi(CAN1_NUMBER, CAN_Mode_LoopBack, CAN1_PORT); returnValue = 0;
#else
		Init_CAN(CAN1_NUMBER, CAN_Mode_LoopBack, CAN1_PORT); returnValue = 0;
#endif
		if (returnValue == 0) setuped = true;
	}
	else {
		returnValue = 0;
	}
	return returnValue;
}

int Can1::addHandler(CanHandler &HandlerArg) {
	if (canHandlerCursor >= NUMBER_OF_CAN_Handler) return 1;
	canHandler[canHandlerCursor++] = &HandlerArg;
	HandlerArg.canHandlerSetup(this);
	return 0;
}

int Can1::setId(int id) {
	int row = filter_number / 4;
	filter[filter_number] = (short)id;
	////printf("%s,set id:%x\n",__func__,id);
	Init_CANfilter(row+15, CAN_LIST, filter[row * 4 + 0], CAN_DATA, filter[row * 4 + 1], CAN_DATA, filter[row * 4 + 2], CAN_DATA, filter[row * 4 + 3], CAN_DATA);
	filter_number++;
	return 0;
}

int Can1::setIdAll() {
	Init_CANfilter(27, CAN_MASK, 0, CAN_DATA, 0, CAN_DATA, 0, CAN_DATA, 0, CAN_DATA);
	return 0;
}

int Can1::read(int id, int number, unsigned char data[8]) {
	/*Serial1 s;
	if(id==0x452){
		s.printf("a\n");
	}*/
	//	Serial3 sss;
	//if(id!=0x443)sss.printf("id:%x length:%x data:%x,%x,%x,%x,%x,%x,%x,%x\n\r", id, number, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
	for (int i = 0; i<canHandlerCursor; i++) if (canHandler[i]->canId(id)) canHandler[i]->canRead(id, number, data);
	return 0;
}

int Can1::write(int id, int number, unsigned char data[8]) {
	CanTxMsg can_tx_frame;
	can_tx_frame.StdId = id;
	can_tx_frame.ExtId = 0;
	can_tx_frame.IDE = CAN_Id_Standard;
	if (number != 0)can_tx_frame.RTR = CAN_RTR_Data;
	else can_tx_frame.RTR = CAN_RTR_Remote;
	can_tx_frame.DLC = (uint8_t)number;
	can_tx_frame.Data[0] = data[0];
	can_tx_frame.Data[1] = data[1];
	can_tx_frame.Data[2] = data[2];
	can_tx_frame.Data[3] = data[3];
	can_tx_frame.Data[4] = data[4];
	can_tx_frame.Data[5] = data[5];
	can_tx_frame.Data[6] = data[6];
	can_tx_frame.Data[7] = data[7];
#ifdef CAN1_TX_INIT
	if(isTransmitting){
		while(canTxMs.write(can_tx_frame));
	}else{
		txTimer=millis();
		send_can2(&can_tx_frame);
		isTransmitting=1;
	}
#else
	send_can2(&can_tx_frame);
	while(CANTXOK != CAN_TransmitStatus(CAN2,0));
#endif
	return (int)(millis()-txTimer>=canTxMs.timeOut());
}

CanRxMsg can1_rx_frame;

void Can1_rx_Interrupt() {
	if (CAN_GetITStatus(CAN2, CAN_IT_FMP0)) {
		CAN_Receive(CAN2, CAN_FIFO0, &can1_rx_frame);
		Can1::read((int)can1_rx_frame.StdId, (int)can1_rx_frame.DLC, can1_rx_frame.Data);
	}
}

extern "C" void CAN2_RX0_IRQHandler(void)
{
	Can1_rx_Interrupt();
}

#ifdef CAN1_TX_INIT
void Can1_tx_Interrupt() {
	if(Can1::canTxMs.isEmpty()==0){
		Can1::txTimer=millis();
		send_can2(Can1::canTxMs.read());
		Can1::isTransmitting=1;
	}
	if(Can1::canTxMs.isEmpty()==1){
		Can1::isTransmitting=0;
	}
	CAN_ClearFlag(CAN2,CAN_FLAG_RQCP0);
	CAN_ClearFlag(CAN2,CAN_FLAG_RQCP1);
	CAN_ClearFlag(CAN2,CAN_FLAG_RQCP2);
}

extern "C" void CAN2_TX_IRQHandler(void)
{
	Can1_tx_Interrupt();
}
#endif
//***Can1�����***

TimerInterruptHandler *TimerInterrupt0::handler[5];
int TimerInterrupt0::count=0;
TimerInterrupt0::TimerInterrupt0(){
}

int TimerInterrupt0::setup(float frequency){
	return Init_TIM_interrupt(TIM2,(int)frequency);
	return 0;
}

int TimerInterrupt0::addHandler(TimerInterruptHandler &handler){
	if(count>=5)return 1;
	this->handler[count++]=&handler;
	return 0;
}

void TimerInterrupt0_timerCycle(){
	for(int i=0;i<TimerInterrupt0::count;i++){
		TimerInterrupt0::handler[i]->timerInterrupt();
	}
}
/*
extern "C" void TIM2_IRQHandler(void){
	TimerInterrupt0_timerCycle();
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}
*/

DigitalInterrupt0::DigitalInterrupt0(){
	for(int i=0;i<16;i++){
		handlerMap[i]=false;
	}
};

void GpioInterrupt0_cycle(int line){
	if(DigitalInterrupt0::handlerMap[line]==true)
		DigitalInterrupt0::digitalInterruptHander[line]->digitalInterrupt();
	/*for(int i=0;i<GpioInterrupt0::count;i++){
		if(GpioInterrupt0::gpioInterruptHander[i]->gpioLine(line))
			GpioInterrupt0::gpioInterruptHander[i]->gpioInterrupt();
	}*/
};

#if 1

extern "C" void EXTI1_IRQHandler(void){
	/* Make sure that interrupt flag is set */
	if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
		GpioInterrupt0_cycle(1);
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

extern "C" void EXTI2_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line2) != RESET){
		GpioInterrupt0_cycle(2);
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}

extern "C" void EXTI3_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
		GpioInterrupt0_cycle(3);
		EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

extern "C" void EXTI4_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
		GpioInterrupt0_cycle(4);
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
}

extern "C" void EXTI9_5_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line5) != RESET) {
		GpioInterrupt0_cycle(5);
		EXTI_ClearITPendingBit(EXTI_Line5);
	}else if(EXTI_GetITStatus(EXTI_Line6) != RESET) {
		GpioInterrupt0_cycle(6);
		EXTI_ClearITPendingBit(EXTI_Line6);
	}else if(EXTI_GetITStatus(EXTI_Line7) != RESET) {
		GpioInterrupt0_cycle(7);
		EXTI_ClearITPendingBit(EXTI_Line7);
	}else if(EXTI_GetITStatus(EXTI_Line8) != RESET) {
		GpioInterrupt0_cycle(8);
		EXTI_ClearITPendingBit(EXTI_Line8);
	}else if(EXTI_GetITStatus(EXTI_Line9) != RESET) {
		GpioInterrupt0_cycle(9);
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}
#endif

extern "C" void EXTI15_10_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line10) != RESET) {
		GpioInterrupt0_cycle(10);
		EXTI_ClearITPendingBit(EXTI_Line10);
	}
	else if (EXTI_GetITStatus(EXTI_Line11) != RESET) {
		GpioInterrupt0_cycle(11);
		EXTI_ClearITPendingBit(EXTI_Line11);
	}
	else if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
		GpioInterrupt0_cycle(12);
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
	else if (EXTI_GetITStatus(EXTI_Line13) != RESET) {
		GpioInterrupt0_cycle(13);
		EXTI_ClearITPendingBit(EXTI_Line13);
	}
	else if (EXTI_GetITStatus(EXTI_Line14) != RESET) {
		GpioInterrupt0_cycle(14);
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
	else if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
		GpioInterrupt0_cycle(15);
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

#if 1

bool I2c0::directionFlag;
int I2c0::rxSlaveAddress;
int I2c0::txSlaveAddress;
int I2c0::txBufferSize;
int I2c0::rxBufferSize;
unsigned char I2c0::sendData[20];
I2cHandler * I2c0::i2cHandler[10];
int I2c0::i2cHandlerCursor=0;
RingBuffer<I2c_t,512> I2c0::txBuf;

I2c0::I2c0(){
	directionFlag=true;
	rxSlaveAddress=0;
	txSlaveAddress=0;
	txBufferSize=0;
	rxBufferSize=0;
}

int I2c0::setup(){
	static bool flag=false;
	time=millis();
	if(!flag){
		Init_i2c(I2CMODE,I2C_PORT_SCL_SDA);delay_ms(10);
		flag=true;
		return 0;
	}
	return 1;
}

int I2c0::addHandler(I2cHandler &HandlerArg){
	if(i2cHandlerCursor>=10) return 1;
	i2cHandler[i2cHandlerCursor++]=&HandlerArg;
	HandlerArg.i2cHandlerSetup(this);
	return 0;
}

int I2c0::write(char address,unsigned char *value,char dataSize,bool txrx){
	I2c_t i2c;

	if(getBufferFlag()==0){
		if(txBuf.isEmpty()==1){
			txSlaveAddress=address;
			txBufferSize=dataSize;
			for(int i=0;i<dataSize;i++){
				sendData[i]=*(value+i);
			}
			directionFlag=txrx;
			I2C_GenerateSTART(I2CMODE,ENABLE);
			return 0;
		}
	}
	i2c.address=address;
	for(int i=0;i<dataSize;i++){
		i2c.data[i]=*(value+i);
	}
	i2c.dataSize=dataSize;
	i2c.txrxFlag=txrx;

	int i=0;
	while(txBuf.write(i2c)){
		cycle();
		if(i>100000){
			txBuf.clear();
		}
		i++;
	}
	return 0;
}

int I2c0::getBufferFlag(){
	return rxBufferSize+txBufferSize;
}

void I2c0_Interrupt(void){
	static int TxAddress=0;
	static int RxAddress=0;
	static int TxDataNum=0;
	static int RxDataNum=0;
	static unsigned char rxData[10]={0};
	switch (I2C_GetLastEvent(I2CMODE)){
	case I2C_EVENT_MASTER_MODE_SELECT:
		if(I2c0::directionFlag==TX){
			TxAddress=I2c0::txSlaveAddress;
			I2C_Send7bitAddress(I2CMODE, TxAddress, I2C_Direction_Transmitter);
		}else if(I2c0::directionFlag==RX){
			RxAddress=I2c0::rxSlaveAddress;
			I2C_Send7bitAddress(I2CMODE, RxAddress, I2C_Direction_Receiver);
		}
		break;
	case I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED:
		I2C_SendData(I2CMODE, I2c0::sendData[TxDataNum++]);
		break;
	case I2C_EVENT_MASTER_BYTE_TRANSMITTED:
		if(TxDataNum<I2c0::txBufferSize){
			I2C_SendData(I2CMODE, I2c0::sendData[TxDataNum++]);
			if(I2c0::txBufferSize-TxDataNum<1)
				I2C_GenerateSTOP(I2CMODE, ENABLE);
		}else{
			int i;
			for(i=0;i<I2c0::i2cHandlerCursor;i++){
				if(I2c0::i2cHandler[i]->i2cAddress(TxAddress)){
					I2c0::i2cHandler[i]->i2cReStartSend(I2c0::sendData[0]);
				}
			}
			TxDataNum=0;
			I2c0::txBufferSize=0;
		}
		break;
	case I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED:
		break;
	case I2C_EVENT_MASTER_BYTE_RECEIVED:
		rxData[RxDataNum++]=I2C_ReceiveData(I2CMODE);
		if(I2c0::rxBufferSize==RxDataNum+1){
			I2C_AcknowledgeConfig(I2CMODE, DISABLE);
			I2C_GenerateSTOP(I2CMODE, ENABLE);
		}
		if(I2c0::rxBufferSize-RxDataNum<1){
			RxDataNum=0;
			I2C_AcknowledgeConfig(I2CMODE, ENABLE);
			I2c0::rxBufferSize=0;
			int i;
			for(i=0;i<I2c0::i2cHandlerCursor;i++){
				if(I2c0::i2cHandler[i]->i2cAddress(RxAddress)){
					I2c0::i2cHandler[i]->i2cRead(rxData);
				}
			}
		}
		break;
	default:
		break;
	}
}

void I2c0::startI2c(){
	if(txBuf.isEmpty()==0){
		I2c_t i2c;i2c=txBuf.read();
		txSlaveAddress=i2c.address;
		txBufferSize=i2c.dataSize;
		for(int i=0;i<txBufferSize;i++){
			sendData[i]=i2c.data[i];
		}
		directionFlag=i2c.txrxFlag;
		I2C_GenerateSTART(I2CMODE,ENABLE);
	}
}

void I2c0::cycle(){
	if(millis()-time>=12){
		time=millis();
		if(getBufferFlag()==0){
			startI2c();
		}
	}
}

void I2c0::setRx(int rxBufferSize,int rxSlaveAddress){
	this->rxBufferSize=rxBufferSize;
	this->rxSlaveAddress=rxSlaveAddress;
	this->directionFlag=RX;
	I2C_GenerateSTART(I2CMODE, ENABLE);
}

extern "C" void I2C1_EV_IRQHandler(void){
	I2c0_Interrupt();
}

SpiHandler *Spi0::spiHandler[4];
SpiHandler *Spi0::handler;
RingBuffer<unsigned char,100> Spi0::txDataBuf;
RingBuffer<bool,10> Spi0::optionDigital;
RingBuffer<SpiHandler*,20> Spi0::handlerBuf;

Spi0::Status Spi0::SpiStatus;
Spi0::Direction Spi0::direction;
Spi0::Mode Spi0::mode;
bool Spi0::transferFlag=false;

Spi0::Spi0(Mode mode,Direction direction){
	this->mode=mode;
	this->direction=direction;
}

int Spi0::setup(){
	static bool flag=false;

	if(!flag){

		Init_spi(SPIMODE,SPI2_PORT_CLK_MOSI_MISO,mode,direction);
		flag=true;
		SpiStatus=SPI_START;
		return 0;
	}
	if(!flag)return 1;
	return 0;
}

int Spi0::optionPinSetup(){

	return 0;//spiHandler[0]->optionPin->setupDigitalOut();
}

int Spi0::addHandler(SpiHandler &HandlerArg){
	static int num =0;
	HandlerArg.spiHandlerSetup(this);
	if(num<4)spiHandler[num]=&HandlerArg,num++;
	else return 1;
	return 0;
}

int Spi0::write(int byteSize,unsigned char data[8],SpiHandler *HandlerArg,bool optionPin){

	txDataBuf.write(byteSize);
	for(int byte=0; byte<byteSize; byte++)txDataBuf.write(data[byte]);
	handlerBuf.write(HandlerArg);
	optionDigital.write(optionPin);

	SPI_I2S_ITConfig(SPIMODE,SPI_I2S_IT_TXE,ENABLE);

	return 0;

}
void Spi0::getHandlerPointer(){handler = handlerBuf.read();}

void Spi0_Interrupt(){

	static int i=0;
	static int txByte = 0;
	static unsigned char rxData[8];

	if(Spi0::direction==Spi0::FullDuplex){
		switch(Spi0::SpiStatus){
		case Spi0::SPI_START:
			if(SPI_I2S_GetFlagStatus(SPIMODE,SPI_I2S_FLAG_TXE)==SET){
				Spi0::getHandlerPointer();
				i=0;
				//if(Spi0::optionDigital.read())Spi0::handler->optionPin->digitalHigh();
				//else Spi0::handler->optionPin->digitalLow();
				txByte = Spi0::txDataBuf.read();

				Spi0::handler->cs->digitalLow();
				SPI_I2S_SendData(SPIMODE,Spi0::txDataBuf.read());

				if(txByte==1)Spi0::SpiStatus=Spi0::SPI_END;
				else Spi0::SpiStatus=Spi0::SPI_CONNECTING;

				SPI_I2S_ITConfig(SPIMODE,SPI_I2S_IT_RXNE,ENABLE);
			}
			break;

		case Spi0::SPI_CONNECTING:
			if(SPI_I2S_GetFlagStatus(SPIMODE,SPI_I2S_FLAG_RXNE)==SET){
				rxData[i] = SPI_I2S_ReceiveData(SPIMODE);i++;

			}else if(SPI_I2S_GetFlagStatus(SPIMODE,SPI_I2S_FLAG_TXE)==SET){
				SPI_I2S_SendData(SPIMODE,Spi0::txDataBuf.read());
				break;
			}

			if(i == (txByte-1) )Spi0::SpiStatus = Spi0::SPI_END;
			break;

		case Spi0::SPI_END:
			if(SPI_I2S_GetFlagStatus(SPIMODE,SPI_I2S_FLAG_RXNE)==SET){
				rxData[i] = SPI_I2S_ReceiveData(SPIMODE);
				Spi0::handler->cs->digitalHigh();
				Spi0::handler->spiRead(txByte,rxData);

				Spi0::SpiStatus = Spi0::SPI_START;
				SPI_I2S_ITConfig(SPIMODE,SPI_I2S_IT_RXNE,DISABLE);
				if(Spi0::txDataBuf.isEmpty())SPI_I2S_ITConfig(SPIMODE,SPI_I2S_IT_TXE,DISABLE);
			}
			break;
		}

	}else if(Spi0::direction==Spi0::TxOnly){
		switch(Spi0::SpiStatus){
			case Spi0::SPI_START:
				i=0;

				if(Spi0::optionDigital.read())Spi0::handler->optionPin->digitalHigh();
				else Spi0::handler->optionPin->digitalLow();

				txByte = Spi0::txDataBuf.read();
				Spi0::handler->cs->digitalLow();
				SPI_I2S_SendData(SPIMODE,Spi0::txDataBuf.read());

				if(txByte==1)Spi0::SpiStatus=Spi0::SPI_END;
				else Spi0::SpiStatus=Spi0::SPI_CONNECTING;
				break;

			case Spi0::SPI_CONNECTING:

				SPI_I2S_SendData(SPIMODE,Spi0::txDataBuf.read());
				i++;
				if(i == (txByte-1) )Spi0::SpiStatus = Spi0::SPI_END;
				break;

			case Spi0::SPI_END:

				Spi0::handler->cs->digitalHigh();
				Spi0::handler->optionPin->digitalLow();

				Spi0::SpiStatus = Spi0::SPI_START;

				if(Spi0::txDataBuf.isEmpty())SPI_I2S_ITConfig(SPIMODE,SPI_I2S_IT_TXE,DISABLE);
				break;
			}
	}
}

extern "C" void SPI2_IRQHandler(void){
	Spi0_Interrupt();
}

#endif
