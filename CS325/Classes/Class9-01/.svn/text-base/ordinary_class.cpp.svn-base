Class Pair{
	int x;
	int y;
public:
	Pair(int a, int b): x(a),y(b){};
	void print(){
		cout << "(" << x << "," << y << ")" << endl;
	}
	Pair plus (Pair other)
	{
		return Pair(x + other.x, y + other.y);
	}
}

Pair3 = Pair1.plus(Pair2);




int main(){
	Pair pair1(3,4);
	Pair pair2(5,6);
	Pair pair3 = pair1.plus(pair2);
	pair3.print();		//output: (8,10)
}
