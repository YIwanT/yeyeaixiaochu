#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
//键盘监听宏
#define KEY_DOWN(vk_c)(GetAsyncKeyState(vk_c)&0x8000)
#define _CRT_SECURE_NO_WARNINGS

typedef struct position
{
	int x;
	int y;
}position;//定义一个结构体，存放坐标

void init(void); //初始化界面
void gamebegin(void);//游戏开始界面
void gameplay(void);//游戏逻辑
void close(void);//释放资源
void drowcircle(int, int, COLORREF);//绘制小球
void drowcursor(position, COLORREF);//绘制光标
void drowscore(int);//绘制分数
void drowtime(int);//绘制时间
void getSameColorBalls(position, COLORREF);//获得同色小球
int isValid(position, COLORREF);//判读坐标是否同色且有效
void ballsfall();//小球下落


COLORREF ballcolor[6] = { RGB(200,0,0),RGB(200,200,0),RGB(200,0,200),
RGB(0,200,0),RGB(0,0,200),RGB(0,200,200), }; // 小球颜色

position cursorpos; //光标位置
position ballArr[150];//同色小球的坐标
int index;//同色小球的个数
int Score = 0;//分数