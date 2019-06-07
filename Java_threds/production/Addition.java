import java.util.ArrayList;
import java.util.Random;

public class Addition {

    private int [] tab;
    private int size;
    private double time1;

    private ArrayList<Thread> threadVect = new ArrayList<>();
    private Thread[] threads;
    private int threads_size;

    public Addition(){}

    public Addition(int size, int threads_size){
        this.size=size;
        this.threads_size=threads_size;
        this.tab=new int [size];

        Random random = new Random();
        for(int a = 0; a < size; a++){
            tab[a] = random.nextInt(101);
        }

        threads = new Thread[threads_size];
    }

    public void print(){
        System.out.print("Tablica:");
        for(int a = 0; a < size; a++){
            System.out.print(" "+tab[a]);
        }
        System.out.print("\n");
    }

    public void printResult(){
        System.out.print("Wynik: "+tab[0]+"\n");
        System.out.print("Time: "+time1+"\n");
    }

    public double time(){
        return time1;
    }

    public void add(int index, int length) {
        if(index >= size)
            return;
        int wynik = 0;
        for(int a = index; a < index+length; ){
            if(a >= size) break;
            wynik += tab[a];
            tab[a] = 0;
            a += length/10;
        }
        tab[index] = wynik;
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        add(index + length*threads_size, length);
    }

    public void start() {
        long start = System.currentTimeMillis();
        int max = Math.toIntExact(Math.round(Math.log10(size)+1));
        int length = 10;
        for(int b = 0; b < max; b++){
            for(int a = 0; a < threads_size; a++) {
                final int st = length;
                final int d = a;
                threads[a] = new Thread(() -> add(d*st,st));
                threads[a].start();
                //threadVect[a] = std::thread(&Sume::add, this, a*length, length);
            }
            for(int a = 0; a < threads_size; a++){
                try {
                    threads[a].join();
                    //threadVect.get(a).join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            length = length*10;
        }
        long end = System.currentTimeMillis();
        long period = end-start;
        time1 = period;
    }


}
