#include "../../headers/io.h"

class Poly{
    protected:
        int width;
        int height;
    
    public:
        Poly(int w, int h){
            set_size(w, h);
        }

        void set_size(int w, int h){
            width  = w;
            height = h;
        }

        int get_width(){
            return width;
        }

        int get_height(){
            return height;
        }
};

class Rectangle: public Poly{
    public:
        Rectangle(int w, int h): Poly(w, h){
        }

        int area(){
            return width*height;
        }
};

int main(){
    Rectangle x(10, 20);

    print("Area of rectangle with sides length", " ");
    print(x.get_width(), " and ");
    print(x.get_height(), " is: ");
    print(x.area());

    return 0;
}