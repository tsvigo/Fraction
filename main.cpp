#include <QCoreApplication>
#include <algorithm>
#include <string>

#include <fstream>
#include <iostream>
using namespace std;
int fract_nod(int a, int b) {
    if (b == 0) return a;
    return fract_nod(b, a % b);
}
class Fraction {
public:
    int numer, denom;
    Fraction(int n = 0, int d = 1) {
        numer = n;
        denom = d;
    }
    Fraction reduce() {
        int a = max(abs(numer), abs(denom)), b = min(abs(numer), abs(denom));
        int sgn;
        if (numer * denom >= 0) sgn = 1;
        else sgn = -1;
        int nod = fract_nod(a, b);
        return Fraction(sgn * (abs(numer) / nod), abs(denom) / nod);
    }
    void show() {
        cout << "\t" << numer;
        if (denom != 1) cout << "/" << denom;
    }
    Fraction operator + (Fraction& other) {
        return
            Fraction(
                numer * other.denom + denom * other.numer,
                denom * other.denom
                ).reduce();
    }
    Fraction operator - (Fraction& other) {
        return Fraction(numer, denom) + Fraction(-other.numer, other.denom);
    }
    Fraction operator * (Fraction& other) {
        return
            Fraction(
                numer * other.numer, denom * other.denom
                ).reduce();
    }
    Fraction operator / (Fraction& other) {
        return Fraction(numer, denom) * Fraction(other.denom, other.numer);
    }
};
Fraction input(string& s) {
    int n = 0, d = 0, deg = 0;
    int slash_pos = s.find('/');
    if (slash_pos != s.npos) {
        int i = slash_pos - 1;
        while (i > -1) {
            if (s[i] != '-')
                n += (s[i] - 48) * pow(10, deg++);
            else
                n = -n;
            i--;
        }
        deg = 0;
        i = s.size() - 1;
        while (i > slash_pos) {
            if (s[i] != '-')
                d += (s[i] - 48) * pow(10, deg++);
            else
                d = -d;
            i--;
        }
    } else {
        d = 1;
        int i = s.size() - 1;
        while (i > -1) {
            if (s[i] != '-')
                n += (s[i] - 48) * pow(10, deg++);
            else
                n = -n;
            i--;
        }
    }
    Fraction f;
    if (d) f = Fraction(n, d).reduce();
    else f = Fraction(n);
    return f;
}
//https://tlgg.ru/Selfinstallation

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
