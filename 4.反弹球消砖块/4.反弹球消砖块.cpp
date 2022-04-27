#include<conio.h>
#include<graphics.h>

#define High 480
#define Width 640

int ball_x, ball_y;
int ball_vx, ball_vy;
int radius;
int bar_x, bar_y;
int bar_high, bar_width;
int bar_left, bar_right, bar_top, bar_bottom;

void startup()
{
	ball_x = Width / 2;
	ball_y = High / 2;
	ball_vx = 1;
	ball_vy = 1;
	radius = 20;

	bar_high = High / 20;
	bar_width = Width / 5;
	bar_x = Width / 2;
	bar_y = High - bar_high / 2;
	bar_left = bar_x - bar_width / 2;
	bar_right = bar_x + bar_width / 2;
	bar_top = bar_y - bar_high / 2;
	bar_bottom = bar_y + bar_high / 2;
	initgraph(Width, High);
	BeginBatchDraw();
}
void clean()
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball_x, ball_y, radius);
	bar(bar_left, bar_top, bar_right, bar_bottom);
}
void show()
{
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball_x, ball_y, radius);
	bar(bar_left, bar_top, bar_right, bar_bottom);
	FlushBatchDraw();
	Sleep(3);
}
void updateWithoutInput()
{
	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;
	if ((ball_x <= radius) || (ball_x >= Width - radius))
		ball_vx = -ball_vx;
	if ((ball_y <= radius) || (ball_y >= High - radius))
		ball_vy = -ball_vy;
}
void updateWithInput()
{

}
void gameover()
{
	EndBatchDraw();
	closegraph();
}
int main()
{
	startup();
	while (1)
	{
		clean();
		updateWithoutInput();
		updateWithInput();
		show();
	}
	gameover();
	return 0;
}