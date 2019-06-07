import java.util.ArrayList;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class ErastothenesSieve {

    private int [] tab;
    private double time1;
    int size;

    private ArrayList<Thread> threadVect = new ArrayList<>();
    private Thread[] threads;
    private int threads_size;

    private boolean [] inUse;

    public ErastothenesSieve(int interval, int threads_size) {
        this.threads_size=threads_size;
        this.size = interval-2;
        this.tab = new int[size];
        this.inUse = new boolean[size];

        for(int i = 0; i < size; i++) {
            tab[i] = i+2;
            inUse[i] = false;
        }

        threads = new Thread[threads_size];
    }

    public void print() {
        System.out.println("Liczby pierwsze: ");
        for(int i=2; i<size; i++){
            if(tab[i-2]!=0)
                System.out.println(" "+tab[i-2]);
        }
        System.out.println("\n");
        System.out.println("Time: "+time1+"\n");
    }

    public double time(){
        return time1;
    }

    public void firstNumbers(int index) {
        if(index>=size) return;
        if(tab[index]!=0) {
            if(!inUse[index]) {
                inUse[index]=true;
                int a = index;
                while(a<size) {
                    if(tab[index]==0) break;
                    if(a!=index)
                        tab[a]=0;
                    a+=(index+2);
                }
            }
        }
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        firstNumbers(index+threads_size);

    }

    public void change(int interval, int threads_size) {
        threadVect.clear();
        this.threads_size=threads_size;
        size = interval-2;
        tab = new int[size];
        inUse = new boolean[size];
        for(int i=0; i<size; i++){
            tab[i]=i+2;
            inUse[i]=false;
        }
        time1=0;
    }

    public void start() {
        long start = System.currentTimeMillis();
        for(int i=0; i<threads_size; i++) {
            final int a = i;
            threads[i] = new Thread(new Runnable() {
                @Override
                public void run() {
                    firstNumbers(a);
                }
            });
            threads[i].run();
//            ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(1);
//            executor.submit(()->firstNumbers(i));
        }
        for (Thread t: threadVect) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        long end = System.currentTimeMillis();
        long period = end-start;
        time1 = period;
    }




}
