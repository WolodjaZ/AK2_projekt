import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class main {

    public static void main(String[] args) {

        int petla = 0;
        do {
            Scanner scanner = new Scanner(System.in);
            System.out.println("*** AK2 - PROJEKT ***");
            System.out.println("*** 1. Suma tablic\n");
            System.out.println("*** 2. Suma tablicy\n");
            System.out.println("*** 3. Sito Erastotenesa\n");
            System.out.println("*** 4. Mnozenie macierzy\n");
            System.out.println("*** 5. Koniec\n");

            int wybor = scanner.nextInt();
            switch(wybor) {
                case 1:
                    petla=0;
                    sumowanieTablic();
                    break;
                case 2:
                    petla=0;
                    sumowanie();
                    break;
                case 3:
                    petla=0;
                    sitoErastotenesa();
                    break;
                case 4:
                    petla=0;
                    mnozenieMacierzy();
                    break;
                case 5: petla = 1;
                    break;
                default:
                    System.out.println("ERROR!\n");
                    break;
            }
        }while(petla==0);
    }

    public static void sumowanieTablic(){
        AddingTables a = new AddingTables();
        int koniec=0;
        do {
            Scanner scanner = new Scanner(System.in);
            System.out.println("*** 1. Stworz tablice\n");
            System.out.println("*** 2. Pokazowy wynik\n");
            System.out.println("*** 3. Zrob badania\n");
            System.out.println("*** 4. Stworz plik wynikowy\n");
            System.out.println("*** 5. Koniec\n");

            int wybor = scanner.nextInt();
            System.out.println("\n");
            switch (wybor) {
                case 1:
                    System.out.println("Ilu elementowa tablica: ");
                    int size = scanner.nextInt();
                    System.out.println("Ile tablic: ");
                    int liczbaTablic = scanner.nextInt();
                    System.out.println("Ile watkow: ");
                    int liczbaWatkow = scanner.nextInt();
                    a = new AddingTables(size, liczbaTablic, liczbaWatkow);
                    a.printTables();
                    System.out.println("\n");
                    break;
                case 2:
                    a.start();
                    a.printResult();
                    break;
                case 3:
                    System.out.println("Badania dla zakresu 1000 na 1000 i dla każdej liczby watków " +
                            ",oraz średniej ze 100 prób\n");
                    for(int i = 1; i <= 1000; i++){
                        double wynik = 0;
                        for(int j = 0; j < 100; j++){
                            a = new AddingTables(1000, 1000, i);
                            a.start();
                            wynik += a.time();
                        }
                        System.out.println("Czas dla liczby wątków: "+i+" ,wynosi: "+wynik+" [ms]\n");
                    }
                    break;
                case 4:
                    System.out.println("ROZPOCZYNAM ZAPIS");
                    try {
                        FileWriter fileWriter = new FileWriter("Dodawanie_tablic.txt");
                        for (int i = 1; i <= 1000; i++) {
                            double wynik = 0;
                            for (int j = 0; j < 100; j++) {
                                a = new AddingTables(1000, 1000, i);
                                a.start();
                                wynik += a.time();
                            }
                            fileWriter.write(wynik*10 + "\n");
                        }
                        fileWriter.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }finally {
                        System.out.println("ZAPISWYANIE ZAKONCZONE");
                    }
                    break;
                case 5:
                    koniec=1;
                    break;
            }
        }while(koniec==0);
    }

    public static void sumowanie() {
        Addition ad = new Addition();
        int koniec=0;
        do {
            Scanner scanner = new Scanner(System.in);
            System.out.println("*** 1. Stworz tablice\n");
            System.out.println("*** 2. Pokazowy wynik\n");
            System.out.println("*** 3. Zrob badania\n");
            System.out.println("*** 4. Stworz plik wynikowy\n");
            System.out.println("*** 5. Koniec\n");

            int wybor = scanner.nextInt();
            System.out.println("\n");
            switch (wybor) {
                case 1:
                    System.out.println("Ilu elementowa tablica: ");
                    int size = scanner.nextInt();
                    System.out.println("Ile watkow: ");
                    int liczbaWatkow = scanner.nextInt();
                    ad = new Addition(size, liczbaWatkow);
                    ad.print();
                    System.out.println("\n");
                    break;
                case 2:
                    ad.start();
                    ad.printResult();
                    break;
                case 3:
                    System.out.println("Badania dla zakresu 10 000 i dla każdej liczby watków, " +
                            "oraz średniej ze 100 prób\n");
                    for(int i = 1; i <= 10000; i++){
                        double wynik = 0;
                        for(int j = 0; j < 100; j++){
                            ad = new Addition(10000,i);
                            ad.start();
                            wynik += ad.time();
                        }
                        System.out.println("Czas dla liczby wątków: "+i+" ,wynosi: "+wynik+" [ms]\n");
                    }
                    break;
                case 4:
                    System.out.println("ROZPOCZYNAM ZAPIS");
                    try {
                        FileWriter fileWriter = new FileWriter("Dodawania_tablicy.txt");
                        for(int i = 1; i <= 1000; i++){
                            double wynik = 0;
                            for(int j = 0; j < 100; j++){
                                ad = new Addition(1000,i);
                                ad.start();
                                wynik += ad.time();
                            }
                            fileWriter.write(wynik*10+"\n");
                        }
                        fileWriter.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }finally {
                        System.out.println("ZAPISWYANIE ZAKONCZONE");
                    }
                    break;
                case 5:
                    koniec=1;
                    break;
            }
        }while(koniec==0);
    }

    public static void sitoErastotenesa() {

        ErastothenesSieve e = new ErastothenesSieve(10,10);
        int koniec = 0;
        do {
            Scanner scanner = new Scanner(System.in);
            System.out.println("*** 1. Zakres szukania liczb pierwszych\n");
            System.out.println("*** 2. Pokazowy wynik\n");
            System.out.println("*** 3. Zrob badania\n");
            System.out.println("*** 4. Stworz plik wynikowy\n");
            System.out.println("*** 5. Koniec\n");

            int wybor = scanner.nextInt();
            switch(wybor){
                case 1:
                    System.out.println(">Zakres badania: ");
                    int size = scanner.nextInt();
                    System.out.println(">Ile watkow: ");
                    int liczbaWatkow = scanner.nextInt();
                    e.change(size,liczbaWatkow);
                    System.out.println("\n");
                    break;
                case 2:
                    e.start();
                    e.print();
                    break;
                case 3:
                    System.out.println("Badania dla zakresu 1000 i dla każdej liczby watkow" +
                            "oraz sredniej ze 100 prob\n");
                    for(int i=0; i<=1000; i++) {
                        double wynik = 0;
                        for(int j=0; j<100; j++) {
                            e.change(1000,i);
                            e.start();
                            wynik += e.time();
                        }
                        System.out.println("Czas dla liczby watkow: "+i+" ,wynosi: "+wynik+" [ms]\n");
                    }
                    break;
                case 4:
                    System.out.println("ROZPOCZYNAM ZAPIS");
                    try {
                        FileWriter fileWriter = new FileWriter("Liczby_pierwsze.txt");
                        for(int i=0; i<=1000; i++) {
                            double wynik = 0;
                            for(int j=0; j<100; j++) {
                                e.change(1000,i);
                                e.start();
                                wynik += e.time();
                            }
                            fileWriter.write(wynik*10+"\n");
                        }
                        fileWriter.close();
                    } catch (IOException exe) {
                        exe.printStackTrace();
                    }finally {
                        System.out.println("ZAPISWYANIE ZAKONCZONE");
                    }
                    break;
                case 5:
                    koniec=1;
                    break;
            }
        }while(koniec==0);
    }

    public static void mnozenieMacierzy() {
        Matrix m = new Matrix();
        int koniec = 0;
        do {
            Scanner scanner = new Scanner(System.in);
            System.out.println("*** 1. Stworz tablice\n");
            System.out.println("*** 2. Pokazowy wynik\n");
            System.out.println("*** 3. Zrob badania\n");
            System.out.println("*** 4. Stworz plik wynikowy\n");
            System.out.println("*** 5. Zakoncz\n");

            int wybor = scanner.nextInt();
            switch(wybor){
                case 1:
                    System.out.println(">Wysokosc macierzy: ");
                    int wysokosc = scanner.nextInt();
                    System.out.println(">Szerokosc macierzy: ");
                    int szerokosc = scanner.nextInt();
                    System.out.println(">Liczba watkow: ");
                    int liczbawatkow = scanner.nextInt();
                    m = new Matrix(szerokosc,wysokosc,wysokosc,szerokosc,liczbawatkow);
                    m.printMatrixes();
                    System.out.println("\n");
                    break;
                case 2:
                    try {
                        m.start();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    m.printResult();
                    break;
                case 3:
                    System.out.println("Badania dla 10 000 na 1000 macierzy i dla kazdego watku" +
                            "po kolei, oraz sredniej ze 100 prob\n");
                    for(int i=1; i<=1000; i++){
                        double wynik=0;
                        for(int j=0; j<100; j++){
                            m = new Matrix(1000,1000,1000,1000,i);
                            try {
                                m.start();
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                            wynik = wynik + m.time();
                        }
                        System.out.println("Czas dla liczby watkow: "+i+", wynosi: "+wynik+" [ms]\n");
                    }
                    break;
                case 4:
                    System.out.println("ROZPOCZYNAM ZAPIS");
                    try {
                        FileWriter fileWriter = new FileWriter("Dodawanie_macierzy.txt");
                        for(int i=1; i<=1000; i++){
                            double wynik=0;
                            for(int j=0; j<100; j++){
                                m = new Matrix(100,1000,1000,100,i);
                                try {
                                    m.start();
                                } catch (InterruptedException e) {
                                    e.printStackTrace();
                                }
                                wynik += m.time();
                            }
                            fileWriter.write(wynik*10+"\n");
                        }
                        fileWriter.close();
                    } catch (IOException exe) {
                        exe.printStackTrace();
                    }finally {
                        System.out.println("ZAPISWYANIE ZAKONCZONE");
                    }
                    break;
                case 5:
                    koniec=1;
                    break;
            }
        }while(koniec==0);
    }

}
