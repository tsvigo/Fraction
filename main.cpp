#include <QCoreApplication>
#include <algorithm>
#include <string>
#include <limits>
#include <iostream>
using namespace std;
int fract_nod(int a, int b)
{
    if (b == 0) return a;
    return fract_nod(b, a % b);
}
class Fraction
{
public:
    int numer, denom;
    Fraction(int n = 0, int d = 1)
    {

        if (d == 0) {
            throw invalid_argument("Знаменатель не может быть равен нулю.");
            exit(0);
        }
        if (n > numeric_limits<int>::max() || n < numeric_limits<int>::min() ||
            d > numeric_limits<int>::max() || d < numeric_limits<int>::min()) {
            throw overflow_error("Значение дроби находится за пределами допустимых значений.");
            exit(0);
        }

        numer = n;
        denom = d;
    }
    Fraction reduce()
    {
        int a = max(abs(numer), abs(denom)), b = min(abs(numer), abs(denom));
        int sgn;
        if (numer * denom >= 0) sgn = 1;
        else sgn = -1;
        int nod = fract_nod(a, b);
        return Fraction(sgn * (abs(numer) / nod), abs(denom) / nod);
    }
    void show()
    {
        cout << "\t" << numer;
        if (denom != 1) cout << "/" << denom;
    }
    Fraction operator + (const Fraction& other)
    {
        return
            Fraction(
                numer * other.denom + denom * other.numer,
                denom * other.denom
                ).reduce();
    }
    Fraction operator - (Fraction& other)
    {
        return Fraction(numer, denom) + Fraction(-other.numer, other.denom);
    }
    Fraction operator * (const Fraction& other)
    {
        return
            Fraction(
                numer * other.numer, denom * other.denom
                ).reduce();
    }
    Fraction operator / (Fraction& other)
    {

        return Fraction(numer, denom) * Fraction(other.denom, other.numer);
        if (other.numer == 0)
        {
            throw invalid_argument("Не могу делить на 0.");
                        exit(0);
        }

        if (other.numer > numeric_limits<int>::max() || other.numer  < numeric_limits<int>::min() ||
            other.denom  > numeric_limits<int>::max() ||    other.denom < numeric_limits<int>::min())
        {
            throw overflow_error("Дробь вышла за границы.");
                        exit(0);
        }
        if (numer > numeric_limits<int>::max() || numer  < numeric_limits<int>::min() ||
            denom  > numeric_limits<int>::max() ||    denom < numeric_limits<int>::min())
        {
            throw overflow_error("Дробь вышла за границы.");
                        exit(0);
        }
    }
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Fraction& frac)
    {
        os << frac.numer << "/" << frac.denom;
        return os;
    }

    // Перегрузка операторов сравнения
    bool operator==(const Fraction& other) const
    {
        return numer == other.numer && denom == other.denom;
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return numer * other.denom < other.numer * denom;
    }

    bool operator>(const Fraction& other) const
    {
        return numer * other.denom > other.numer * denom;
    }

    bool operator<=(const Fraction& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const
    {
        return !(*this < other);
    }

 };



Fraction input(string& s) {
    int n = 0, d = 0, deg = 0;
  //  int
      size_t  slash_pos = s.find('/');
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // if (n > numeric_limits<int>::max() || n  < numeric_limits<int>::min() ||
    //     d  > numeric_limits<int>::max() ||   d < numeric_limits<int>::min())
    // {
    //     throw overflow_error("Дробь вышла за границы.");
    // }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Fraction f;
    if (d) f = Fraction(n, d).reduce();
    else f = Fraction(n);
    return f;


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Fraction input(string& s)
//  {
//     int n = 0, d = 0, deg = 0;
//     int slash_pos = s.find('/');
//     if (slash_pos != s.npos) {
//         int i = slash_pos - 1;
//         while (i > -1) {
//             if (s[i] != '-')
//                 n += (s[i] - 48) * pow(10, deg++);
//             else
//                 n = -n;
//             i--;
//         }
//         deg = 0;
//         i = s.size() - 1;
//         while (i > slash_pos) {
//             if (s[i] != '-')
//                 d += (s[i] - 48) * pow(10, deg++);
//             else
//                 d = -d;
//             i--;
//         }
//     } else {
//         d = 1;
//         int i = s.size() - 1;
//         while (i > -1) {
//             if (s[i] != '-')
//                 n += (s[i] - 48) * pow(10, deg++);
//             else
//                 n = -n;
//             i--;
//         }
//     }
//  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction inputFromConsole()
    {
    string inputStr;
    cout << "Enter fraction (e.g., 3/4): ";
    cin >> inputStr;


    return input(inputStr);
}
//https://tlgg.ru/Selfinstallation

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Fraction z=6.7,x= 77;
   Fraction k=z.denom;
    (k).show() ;    std::cout <<    "\n" <<  std::endl;
    (z/x).show() ;    std::cout << "\n" <<  std::endl;
    Fraction n=6/7, m=5/4, o; o=n/m; o.show();    std::cout <<  "\n" <<   std::endl;
    n.show();    std::cout <<   "\n" <<  std::endl;
    std::cout << "z = " <<   "\n" << std::endl;
    z.show() ; std::cout <<   "\n" <<  std::endl;

    Fraction f1(1, 7); // 1/2
    Fraction f2(3, 17); // 3/4

    Fraction result = f1 / f2;
    cout << "Результат деления: " << result << endl;
     cout << "f1 = " << f1 << endl;
       cout << "f2 = " << f2 << endl;

     if (f1>f2)  {
           cout << "f1>f2"  << endl;
     } else

     {
           cout << "f2>f1" << endl;
     }
             ;
     Fraction f4 = inputFromConsole();
     Fraction f5 = inputFromConsole();
     cout << "f4= "<< f4 << endl;
     Fraction quot = f4 / f5;
       cout << "Quotient: "; quot.show();cout << "\n";
       cout << "Quotient: "<< quot << endl;
  //   Fraction f3=999999999999999999999999;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return a.exec();
}
// видимо это такой класс - тип данных в котором числитель и знаменатель хранится по отдельности как целые
// надо видимо проверить крайние значения - что произойдёт если за диапазон выйти

 //};;;
