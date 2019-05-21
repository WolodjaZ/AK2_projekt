//
// Created by vladimir on 06.05.19.
//

#include "menu.h"

using namespace std;

menu::menu() {
    int petla=0;
    do {
        int x;
        cout << "POJEKT AK" << endl;
        cout << "1 - Suma tablic" << endl;
        cout << "2 - Suma tablicy" << endl;
        cout << "3 - Liczby pierwsze" << endl;
        cout << "4 - Dodawanie macierzy" << endl;
        cout << "5 - Koniec"<<endl;

        cin >> x;
        switch (x) {
            case 1:
                sume_tables();
                petla=0;
                break;
            case 2:
                sume();
                petla=0;
                break;
            case 3:
                first_numbers();
                petla=0;
                break;
            case 4:
                sume_matrix();
                petla=0;
                break;
            case 5:
                petla=1;
                break;
            default: {
                cout << "Error"<<endl;
                break;

            }
        }
    }while(petla==0);

}


menu::~menu() {

}


void menu::sume_tables() {
    Sum_table* s = nullptr;
    ofstream myfile ("Dodawnia_tablic.txt");
    int koniec=0;
    do {
        int x;
        cout << "1 - Stwórz tablicy" << endl;
        cout << "2 - Pokazowy wynik" << endl;
        cout << "3 - Zrób badania" << endl;
        cout << "4 - Stwórz plik wynikowy" << endl;
        cout << "5 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                delete s;
                int size;
                int liczbatablic;
                int liczbawatkow;
                cout << "Ilu elementowa ma być tablica?" << endl;
                cin >> size;
                cout << "Ile ma być tablic?" << endl;
                cin >> liczbatablic;
                cout << "Ile ma byc wątków?" << endl;
                cin >> liczbawatkow;
                s = new Sum_table(size, liczbatablic, liczbawatkow);
                s->print();
                cout << endl;
                break;
            case 2:
                s->start();
                s->print_result();
                break;
            case 3:
                cout<<"Badania dla zakresu 1000 na 1000 i dla każdej liczby watków oraz średniej ze 100 prób"<<endl;
                for(int a = 1; a <= 1000; a++){
                    double wynik = 0;
                    for(int b = 0; b < 100; b++){
                        delete s;
                        s = new Sum_table(1000, 1000, a);
                        s->start();
                        wynik += s->time();
                    }
                    std::cout << "Czas dla liczby wątków: " << a << " wynosi w mikorsekundy " <<  wynik*10 << std::endl;
                }
                break;
            case 4:
                if (myfile.is_open())
                {
                    std::cout << "ROZPOCZYNAM ZAPISYWANIE" << std::endl;
                    for(int a = 1; a <= 1000; a++){
                        double wynik = 0;
                        for(int b = 0; b < 100; b++){
                            delete s;
                            s = new Sum_table(1000, 1000, a);
                            s->start();
                            wynik += s->time();
                        }
                        myfile << wynik*10 << "\n";
                    }
                    cout << "ZAPISYWANIE ZAKOŃCZONE" << endl;
                    myfile.close();
                }
                else cout << "Unable to open file";
                break;
            case 5:
                delete s;
                koniec=1;
                break;
        }
    }while(koniec==0);
}

void menu::sume() {
    ofstream myfile ("Dodawnia_tablicy.txt");
    Sume* s = nullptr;
    int koniec=0;
    do {
        int x;
        cout << "1 - Stwórz tablice" << endl;
        cout << "2 - Pokazowy wynik" << endl;
        cout << "3 - Zrób badania" << endl;
        cout << "4 - Stwórz plik wynikowy" << endl;
        cout << "5 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                delete s;
                int size;
                int liczbawatkow;
                cout << "Ilu elementowa ma być tablica?" << endl;
                cin >> size;
                cout << "Ile ma byc wątków?" << endl;
                cin >> liczbawatkow;
                s = new Sume(size, liczbawatkow);
                s->print();
                cout << endl;
                break;
            case 2:
                s->start();
                s->pirnt_result();
                break;
            case 3:
                cout<<"Badania dla zakresu 10000 i dla każdej liczby watków oraz średniej ze 100 prób"<<endl;
                for(int a = 1; a <= 10000; a++){
                    double wynik = 0;
                    for(int b = 0; b < 100; b++){
                        delete s;
                        s = new Sume(10000, a);
                        s->start();
                        wynik += s->time();
                    }
                    std::cout << "Czas dla liczby wątków: " << a << " wynosi w mikorsekundy " <<  wynik*10 << std::endl;
                }
                break;
            case 4:
                if (myfile.is_open())
                {
                    std::cout << "ROZPOCZYNAM ZAPISYWANIE" << std::endl;
                    for(int a = 1; a <= 10000; a++){
                        double wynik = 0;
                        for(int b = 0; b < 100; b++){
                            delete s;
                            s = new Sume(10000, a);
                            s->start();
                            wynik += s->time();
                        }
                        myfile << wynik*10 << "\n";
                    }
                    cout << "ZAPISYWANIE ZAKOŃCZONE" << endl;
                    myfile.close();
                }
                else cout << "Unable to open file";
                break;
            case 5:
                delete s;
                koniec=1;
                break;
        }
    }while(koniec==0);
}

void menu::first_numbers() {
    ofstream myfile ("Liczby_pierwsze.txt");
    Eratosthenes_sieve s(10,10);
    int koniec=0;
    do {
        int x;
        cout << "1 - Zakres szukania liczb pierwsych" << endl;
        cout << "2 - Pokazowy wynik" << endl;
        cout << "3 - Zrób badania" << endl;
        cout << "4 - Stwórz plik wynikowy" << endl;
        cout << "5 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int size;
                int liczbawatkow;
                cout << "Zakres badania?" << endl;
                cin >> size;
                cout << "Ile ma byc wątków?" << endl;
                cin >> liczbawatkow;
                s.change(size, liczbawatkow);
                cout << endl;
                break;
            case 2:
                s.start();
                s.print();
                break;
            case 3:
                cout<<"Badania dla zakresu 1000 i dla każdej liczby watków oraz średniej ze 100 prób"<<endl;
                for(int a = 1; a <= 1000; a++){
                    double wynik = 0;
                    for(int b = 0; b < 100; b++){
                        s.change(1000,a);
                        s.start();
                        wynik += s.time();
                    }
                    std::cout << "Czas dla liczby wątków: " << a << " wynosi w mikorsekundy " <<  wynik*10 << std::endl;
                }
                break;
            case 4:
                if (myfile.is_open())
                {
                    std::cout << "ROZPOCZYNAM ZAPISYWANIE" << std::endl;
                    for(int a = 1; a <= 1000; a++){
                        double wynik = 0;
                        for(int b = 0; b < 100; b++){
                            s.change(1000,a);
                            s.start();
                            wynik += s.time();
                        }
                        myfile << wynik*10 << "\n";
                    }
                    cout << "ZAPISYWANIE ZAKOŃCZONE" << endl;
                    myfile.close();
                }
                else cout << "Unable to open file";
                break;
            case 5:
                //delete s;
                koniec=1;
                break;
        }
    }while(koniec==0);
}


void menu::sume_matrix() {
    ofstream myfile ("Dodawnia_macierzy.txt");
    Matrix* s = nullptr;
    int koniec=0;
    do {
        int x;
        cout << "1 - Stwórz tablice" << endl;
        cout << "2 - Pokazowy wynik" << endl;
        cout << "3 - Zrób badania" << endl;
        cout << "4 - Stwórz plik wynikowy" << endl;
        cout << "5 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                delete s;
                int wysokosc;
                int szerokosc;
                int liczbawatkow;
                cout << "Wysokość macierzy?" << endl;
                cin >> wysokosc;
                cout << "Szerokosc macierzy?" << endl;
                cin >> szerokosc;
                cout << "Liczba wątków" << endl;
                cin >> liczbawatkow;
                s = new Matrix(szerokosc, wysokosc, wysokosc, szerokosc, liczbawatkow);
                s->print();
                cout << endl;
                break;
            case 2:
                s->start();
                s->print_result();
                break;
            case 3:
                cout<<"Badania dla 10000 na 1000 Macierzy i dla każdego wątku po koleji oraz srednije ze 100 prób"<<endl;
                for(int a = 1; a <= 1000; a++){
                    double wynik = 0;
                    for(int b = 0; b < 100; b++){
                        delete s;
                        s = new Matrix(1000, 1000, 1000, 1000, a);
                        s->start();
                        wynik += s->time();
                    }
                    std::cout << "Czas dla liczby wątków: " << a << " wynosi w mikorsekundy " <<  wynik*10 << std::endl;
                }
                break;
            case 4:
                if (myfile.is_open())
                {
                    std::cout << "ROZPOCZYNAM ZAPISYWANIE" << std::endl;
                    for(int a = 1; a <= 1000; a++){
                        double wynik = 0;
                        for(int b = 0; b < 100; b++){
                            delete s;
                            s = new Matrix(1000, 1000, 1000, 1000, a);
                            s->start();
                            wynik += s->time();
                        }
                        myfile << wynik*10 << "\n";
                    }
                    cout << "ZAPISYWANIE ZAKOŃCZONE" << endl;
                    myfile.close();
                }
                else cout << "Unable to open file";
                break;
            case 5:
                delete s;
                koniec=1;
                break;
        }
    }while(koniec==0);
}
