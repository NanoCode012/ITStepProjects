#pragma once
class Circle
{
private:
	int x, y, r;
public:
	Circle(int x = 0, int y = 0, int r = 0);
	~Circle();

	bool operator == (const Circle &other);
	bool operator > (const Circle &other);
	void operator ++ (int k);
	void operator -- (int k);


	int GetX();
	int GetY();
	int GetR();

	void SetX(int x);
	void SetY(int y);
	void SetR(int r);
};

void Draw(Circle circle, HDC hdc);

