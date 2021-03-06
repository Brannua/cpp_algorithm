/**
 * @desc 例 5-5 将 例 5-4 中的函数 showCount 变为 static
 * 使之不依赖于具体的对象，通过类名就能调用，达到直接访问静态数据的目的
 */
#include <iostream>
using namespace std;

class Point
{
public:
    Point(int newX = 0, int newY = 0) : x(newX), y(newY)
    {
        count++;
    };
    Point(Point &p) : x(p.x), y(p.y)
    {
        count++;
    };
    ~Point()
    {
        count--;
    }
    static void showCount()
    {
        cout << count << endl;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
private:
    int x, y;
    static int count;
};

int Point::count = 0;

int main()
{
    Point a(4, 5);
    cout << "Point A: " << a.getX() << ", " << a.getY() << endl; // 4   5
    Point::showCount(); // 1
    Point b(a);
    cout << "Point B: " << b.getX() << ", " << b.getY() << endl; // 4   5
    Point::showCount(); // 2
    return 0;
}

