#include <iostream>
class Pen {
private:
	int x = 0;
	int y = 0;
	int status = 0;
public:
	Pen(int init_x, int init_y) : x(init_x), y(init_y) {}
	void set_status(int s) { status = s; }
	void set_location(int set_x, int set_y) { x = set_x, y = set_y; }
};
class ColorPen : public Pen {
private:
	int color;
public:
	ColorPen(int init_x, int init_y, int init_c) : x(init_x), y(init_y),
		color(init_c) {}
	void set_color(int c) {
		color = c;
	}
};
void draw(const Pen& p) {
	p.set_status(1);	
}
int main() {
	ColorPen pen[3];
	pen[0].set_color(1);
	pen[1].set_color(2);
	pen[2].set_color(3);
	draw(pen[0]);
	ColorPen this(5, 5, 1), that(10, 10, 2);
	draw(this);
	return 0;
}