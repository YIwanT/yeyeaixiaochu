#include "game.h"

void main()
{
	init();
	gamebegin();
	gameplay();
	close();
}

void init()
{
	initgraph(1000,700);

}

void gamebegin()
{
	//���Ʊ߿�
	setlinecolor(RGB(150, 150, 150));
	setlinestyle(PS_SOLID, 10);
	rectangle(295, 45, 705, 655);
	//����С��
	setlinestyle(PS_SOLID,1);
	srand((unsigned int)time(NULL));
	for (int i = 320; i < 700; i += 40)
	{
		for (int j = 70; j < 650; j += 40)
		{
			COLORREF cl = ballcolor[rand() % 6];
			drowcircle(i, j, cl);
		}
	}
	//���ƹ��
	cursorpos.x = 480;
	cursorpos.y = 350;
	drowcursor(cursorpos, RGB(255,255,255));
	//���Ʒ���
	drowscore(Score);
	//����ʱ��
	drowtime(30);

}


void drowcircle(int x, int y, COLORREF cl)
{
	setlinecolor(cl);
	setfillcolor(cl);
	fillcircle(x, y, 18);
}

void drowcursor(position pos, COLORREF cl)
{
	setlinecolor(cl);
	rectangle(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
}

void drowscore(int Score)
{
	TCHAR score[20];
	settextcolor(RGB(255, 0, 255));
	settextstyle(30, 0, _T("����"));
	_stprintf_s(score, _T("������%d"), Score);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(30, 600, score);
}

void drowtime(int sec)
{
	TCHAR Time[20];
	settextcolor(RGB(255, 255, 0));
	settextstyle(30, 0, _T("����"));
	_stprintf_s(Time, _T("ʣ��ʱ�䣺%2d s"), sec);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(30, 50, Time);
}

void gameplay()
{

	for (int i = 300 ; i > -1 ; i--)
	{
		if ((i % 10) == 0)
		{
			drowtime(i / 10);
		}
		if (KEY_DOWN(VK_UP) && cursorpos.y > 70)
		{
			drowcursor(cursorpos, RGB(0, 0, 0));
			cursorpos.y -= 40;
			drowcursor(cursorpos, RGB(255, 255, 255));
		}
		else if (KEY_DOWN(VK_DOWN) && cursorpos.y < 600)
		{

			drowcursor(cursorpos, RGB(0, 0, 0));
			cursorpos.y += 40;
			drowcursor(cursorpos, RGB(255, 255, 255));
		}
		else if (KEY_DOWN(VK_LEFT) && cursorpos.x > 350)
		{
			drowcursor(cursorpos, RGB(0, 0, 0));
			cursorpos.x -= 40;
			drowcursor(cursorpos, RGB(255, 255, 255));
		}
		else if (KEY_DOWN(VK_RIGHT) && cursorpos.x < 650 )
		{

			drowcursor(cursorpos, RGB(0, 0, 0));
			cursorpos.x += 40;
			drowcursor(cursorpos, RGB(255, 255, 255));
		}
		else if (KEY_DOWN(VK_RETURN) || KEY_DOWN(VK_SPACE))
		{
			//С����ʧ
			//��ȡͬɫС��
			getSameColorBalls(cursorpos, getpixel(cursorpos.x, cursorpos.y));
			//��ͬɫС��Ϳ��

			if (index > 1)
			{	
				for (int k = 0; k < index; k++)
				{
					drowcircle(ballArr[k].x, ballArr[k].y, RGB(0, 0, 0));
					
				}
				//С������
				Sleep(300);
				i -= 3;
				ballsfall();
				Score += (index % 6 ) * index;
				drowscore(Score);
			}

			index = 0;

		}

		Sleep(100);

	}
	cleardevice();
	settextcolor(RGB(200, 0, 0));
	settextstyle(100, 0, _T("����"));
	outtextxy(300, 300, _T("��Ϸ������"));
	drowscore(Score);

}

void close()
{
	system("pause");
	closegraph();
}

void getSameColorBalls(position pos, COLORREF cl)
{
	ballArr[index].x = pos.x;
	ballArr[index].y = pos.y;
	index++;
	
	position nextpos;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:nextpos.x = pos.x; nextpos.y = pos.y - 40; break; //��
		case 1:nextpos.x = pos.x; nextpos.y = pos.y + 40; break; //��
		case 2:nextpos.x = pos.x - 40; nextpos.y = pos.y; break; //��
		case 3:nextpos.x = pos.x + 40; nextpos.y = pos.y; break; //��
		}
		if (isValid(nextpos,cl))
		{
			getSameColorBalls(nextpos, cl);
		}
			
	}
}
int isValid(position pos, COLORREF cl)
{
	if (getpixel(pos.x, pos.y) != cl)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			if (ballArr[i].x == pos.x && ballArr[i].y == pos.y)
			{
				return 0;
			}
		}
		return 1;
	}
}

void ballsfall()
{

	for (int k = 0; k < index; k++)
	{
		for (int i = 0; i < index; i++)
		{
			if (0 != getpixel(ballArr[i].x, i - 40) && ballArr[i].y > 70)
			{
				for (int j = ballArr[i].y; j >70; j -= 40)
				{
					COLORREF cl = getpixel(ballArr[i].x, j - 40);
					drowcircle(ballArr[i].x, j, cl);
				}
				COLORREF cl = ballcolor[rand() % 6];
				drowcircle(ballArr[i].x, 70, cl);
			}
			else if (ballArr[i].y == 70)
			{
				COLORREF cl = ballcolor[rand() % 6];
				drowcircle(ballArr[i].x, 70, cl);
			}
		}
	}




}