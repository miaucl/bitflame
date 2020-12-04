/*******************
MdLep16X16.h

*******************/

#ifndef _MD_LEP24X24_H__
#define _MD_LEP24X24_H__

//导入Arduino核心头文件
#include"Arduino.h"

#define LEP_ROWS		(16)			//屏幕行数
#define LEP_COLS  	(16)			//屏幕列数
#define ROW_OCTS  	(16/8)		//每行占用字节数
#define DEVSN_OCTS  (4)       //设备号占用字节数

#define OPTION_OFF	0
#define OPTION_ON		1

#define MAX_PARAM_LEN	(LEP_ROWS * ROW_OCTS)	//参数最大长度，全屏载入最长。

#define MDLED_SERIAL Serial1

class MdLep16X16
{
     private:
     	    //1字节包长度，4字节设备号，1字节命令号，后跟参数区
     			byte cmdStr[1 + DEVSN_OCTS + 1 + MAX_PARAM_LEN];

     			void setHidden(byte flag);
     			void setInvert(byte flag);
     			void setMirror(byte flag);
     			void setTurn(byte flag);
     			void setPixel(byte x, byte y,byte flag);

     public:

          MdLep16X16(byte sn0,byte sn1,byte sn2,byte sn3);//构造函数，填入设备号
          ~MdLep16X16();          //析构函数

					void init();				// Init the serial connection
          void displayOn();		//打开显示
          void displayOff(); 	//关闭显示
					void invertOn();		//打开反显
					void invertOff();		//关闭反显
					void mirrorOn();		//开启镜像
					void mirrorOff();		//关闭镜像
					void turnOn();			//开启翻转
					void turnOff();			//关闭翻转

          void fillGram(byte val);//屏幕填充

          void drawPixel(byte x, byte y);			//点亮像素
					void clearPixel(byte x, byte y);    //擦除像素

          void showASCII(byte x, byte y,byte ascii);		//显示字符

          void loadScreen(byte logo[]);		//全屏载入
          void showIcon(byte x, byte y, byte w, byte h, byte len, byte icon[]);

};


#endif
