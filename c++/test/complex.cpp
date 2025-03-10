#include <iostream>

class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex& operator=(const Complex& c);
  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
    (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}
// 디폴트 대입 연산자(default assignment operator)를 지원하기에 아래와 같이 정의하지 않아도 동작함
Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);
  Complex c(0.0, 0.0);
  c = a * b + a / b + a + b;
  c.println();
}