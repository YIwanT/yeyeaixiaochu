#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
//���̼�����
#define KEY_DOWN(vk_c)(GetAsyncKeyState(vk_c)&0x8000)
#define _CRT_SECURE_NO_WARNINGS

typedef struct position
{
	int x;
	int y;
}position;//����һ���ṹ�壬�������

void init(void); //��ʼ������
void gamebegin(void);//��Ϸ��ʼ����
void gameplay(void);//��Ϸ�߼�
void close(void);//�ͷ���Դ
void drowcircle(int, int, COLORREF);//����С��
void drowcursor(position, COLORREF);//���ƹ��
void drowscore(int);//���Ʒ���
void drowtime(int);//����ʱ��
void getSameColorBalls(position, COLORREF);//���ͬɫС��
int isValid(position, COLORREF);//�ж������Ƿ�ͬɫ����Ч
void ballsfall();//С������


COLORREF ballcolor[6] = { RGB(200,0,0),RGB(200,200,0),RGB(200,0,200),
RGB(0,200,0),RGB(0,0,200),RGB(0,200,200), }; // С����ɫ

position cursorpos; //���λ��
position ballArr[150];//ͬɫС�������
int index;//ͬɫС��ĸ���
int Score = 0;//����