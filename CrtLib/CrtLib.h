#pragma once

namespace crt
{
	// GotoXY - ������������� ������ � ������� x, y �������
	void GotoXY(int x, int y);

	void ShowCursor(bool visible);

	void SetTextColor(int color);

	void SetTextBackground(int color);
}