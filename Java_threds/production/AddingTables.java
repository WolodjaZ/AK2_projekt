import java.util.ArrayList;
import java.util.Random;

public class AddingTables {

    private int [][] tab;
    private double time1;
    private int size;
    private int numberOfTables;

    private ArrayList<Thread> threadVect = new ArrayList<>();
    private Thread[] threds;
    private int threads_size;

    public AddingTables(){}

    public AddingTables(int size, int numberOfTables, int threads_size){
        this.size=size;
        this.numberOfTables=numberOfTables;
        this.threads_size=threads_size;

        Random random = new Random();
        this.tab = new int [numberOfTables+1][];

        for(int i=0; i<numberOfTables+1; i++) {
            this.tab[i] = new int[size];
            for(int j=0; j<size; j++){
                if(i==numberOfTables)
                    tab[i][j]=0;
                tab[i][j] = random.nextInt(11);
            }
        }

        threds = new Thread[threads_size];
    }

    public void printTables() {
        System.out.println("Sumowane tablice\n");
        for(int i=0; i<numberOfTables; i++){
            System.out.print("Tablica nr "+(i+1)+" :");
            for(int j=0; j<size; j++) {
                System.out.print(" "+tab[i][j]);
            }
            System.out.print("\n");
        }
    }

    public void printResult() {
        System.out.println("Wynik\n");
        for(int i = 0; i < size; i++){
            System.out.print(" "+tab[numberOfTables][i]);
        }
        System.out.println("\n");
        System.out.println("Time: "+time1+"\n");
    }

    public double time() {
        return time1;
    }

    public void add(int start, int end) {
        for(int i = start; i < end; i++){
            int wynik = 0;
            for(int j = 0; j < numberOfTables; j++) {
                wynik += tab[j][i];
            }
            tab[numberOfTables][i] = wynik;
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void start() {
        long start = System.currentTimeMillis();
        int start2 = 0;
        int threadSpread = size / threads_size;
        int end2 = start2 + threadSpread;
        for(int a = 0; a < threads_size; a++) {
            if(a+1 == threads_size){
                final int st = start2;
                threds[a] = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        add(st, size);
                    }
                });
                threds[a].run();
                //threadVect[a] = std::thread(&Sum_table::add, this, start2, size);
            } else{
                final int st = start2;
                final int en = end2;
                threds[a] = new Thread(() -> add(st,en));
                threds[a].start();
                //threadVect[a] = std::thread(&Sum_table::add, this, start2, end2);

            }
            start2 = end2;
            end2 += threadSpread;
        }
        for(int a = 0; a < threads_size; a++){
            try {
                //threadVect.get(a).join();
                threds[a].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        long end = System.currentTimeMillis();
        long period = end-start;
        time1 = period;
    }

}
