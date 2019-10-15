#include <stdio.h>

class Complex{
private:
	double real;	// 実数部
	double image;	// 虚数部
protected:
    // Constructor
    Complex();
	Complex(double r, double i);
	void print(void);
	Complex operator + (Complex x);
	Complex operator - (Complex x);
	Complex operator * (Complex x);
	Complex operator / (Complex x);
};

Complex::Complex(double r, double i = 0.0){   
    real = r;
	image = i;
}

void Complex::print(void){
    if (image < 0){
        printf("%lf%lfi\n" , real, image);
    }else{
        printf("%lf+%lfi\n", real, image);
    }
}

Complex Complex::operator + (Complex x){
	Complex temp(0.0, 0.0);
	temp.real = real + x.real;
	temp.image = image + x.image;
	return temp;
}

Complex Complex::operator - (Complex x){
	Complex temp(0.0, 0.0);
	temp.real = real - x.real;
	temp.image = image - x.image;
    return temp;
}

Complex Complex::operator * (Complex x){
	Complex temp(0.0, 0.0);
	temp.real = real * x.real - image * x.image;
	temp.image = real * x.image + image * x.real;
    return temp;
}

Complex Complex::operator / (Complex x){
	Complex temp(0.0, 0.0);
	temp.real = (real * x.real + image * x.image) / (x.real * x.real + x.image * x.image);
	temp.image = (image * x.real - real * x.image) / (x.real * x.real + x.image * x.image);
    return temp;
}



int main(void){
    Complex A(5.0, 10.0), B(3.0, 4.0);
    Complex C(0.0, 0.0), D(0.0, 0.0), E(0.0, 0.0), F(0.0, 0.0), G(0.0, 0.0);
    Complex H(3.0); // 実数部のみ
	
    // debug
	printf("A = ");
	A.print();
	printf("B = ");
	B.print();
	C = A + B;
	printf("A + B = ");
	C.print();
    D = A - B;
    printf("A - B = ");
    D.print();
    E = A * B;
    printf("A * B = ");
    E.print();
    F = A / B;
    printf("A / B = ");
    F.print();
    G = A + H;
    printf("A + H = ");
    G.print();
	return 1;
}