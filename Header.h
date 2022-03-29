#pragma once
typedef struct turn
{
	int element = 0;
	turn* previous = 0;
} turn;

class clqueue
{
private:
	turn* last = 0;
protected:
	int size;
public:
	clqueue();
	~clqueue();
	turn* get_finish();
	int pop();
	void push(int el);
	void print();
	void fusion(clqueue& Q1);
	void copy(clqueue& Q);
	bool pustota();
};