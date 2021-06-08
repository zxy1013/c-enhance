#include<iostream>
using namespace std;

//void myPrint(int a, int b);
void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)//函数重载
{
	cout << "调用的函数模板" << endl;
}

template<typename T>//函数模板也可以发生重载
void myPrint(T a, T b, T c)
{
	cout << "调用重载的函数模板" << endl;
}

void test07()
{
	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器，普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	int a = 10;
	int b = 20;
	myPrint(a, b); //调用普通函数

	//2、可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b); //调用的模板

	//3、函数模板也可以发生重载
	int c = 30;
	myPrint(a, b, c); //调用重载的函数模板

	//4、如果函数模板可以产生更好的匹配,优先调用函数模板 
	//普通函数可以：因为可以发生隐式类型转换，但是函数模板更好
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用函数模板
}

int main4() {
	test07();
	system("pause");
	return 0;
}