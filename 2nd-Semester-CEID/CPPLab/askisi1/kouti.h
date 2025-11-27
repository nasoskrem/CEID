#ifndef KOUTI.H
#define KOUTI.H

class Kouti{

public:
    Kouti(double = 0, double = 0, double = 0);
    double calculateOgkos();
    void setMikos(double);
    void setPlatos(double);
    void setYpsos(double);
    Kouti operator+(const Kouti& b){
        Kouti kouti;
        kouti.length = this -> length + b.length;
        kouti.breadth = this -> breadth + b.breadth;
        kouti.height = this -> height + b.height;
        return kouti;
    }

private:
    double breadth;
    double length;
    double height;
};

#endif // KOUTI
