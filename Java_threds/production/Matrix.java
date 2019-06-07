import java.time.Clock;
import java.util.Random;
import java.util.concurrent.Executor;

public class Matrix {

    private int height_first;
    private int height_second;
    private double time1;

    private int [][] first;
    private int [][] second;
    private int [][] result;

    private Thread [] threadVect;
    private int threads_size;

    public Matrix(int first_width, int first_height, int second_width, int second_height, int number_of_threads) {

        this.height_first=first_height;
        this.height_second=second_height;
        this.threads_size=number_of_threads;

        first = new int [first_height][first_width];
        second = new int [second_height][second_width];
        result = new int [first_height][second_width];
        threadVect = new Thread[number_of_threads];

        Random random = new Random();

        for(int i=0; i<first_height; i++){
            for(int j=0; j<first_width; j++){
                this.first[i][j] = random.nextInt(101);
            }
        }

        for(int i=0; i<second_height; i++){
            for(int j=0; j<second_width; j++){
                this.second[i][j] = random.nextInt(101);
            }
        }

        for(int i=0; i<first_height; i++){
            for(int j=0; j<second_width; j++){
                this.result[i][j] = 0;
            }
        }
    }

    public Matrix(){

    }

    public void add(int index) throws InterruptedException {
        if(index>=height_first) {
            return;
        }
        for(int i=0; i<height_first; i++){
            int wynik =0;
            for(int j=0; j<height_second; j++){
                wynik = wynik + first[index][j]*second[j][i];
            }
            result[index][i] = wynik;
        }

        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        add(index+threads_size);
    }

    public void printMatrixes(){
        System.out.print("*** First matrix ***\n");

        for(int i = 0; i< height_first; i++){
            for(int j = 0; j < height_second; j++) {
                System.out.print(first[i][j] + " ");
            }
            System.out.print("\n");
        }

        System.out.println("*** Second matrix ***\n");
        for(int i = 0; i < height_second; i++){
            for(int j = 0; j < height_first; j++){
                System.out.print(second[i][j]+" ");
            }
            System.out.print("\n");
        }
    }

    public void printResult() {
        System.out.print("*** Result matrix ***\n");

        for(int i=0; i<height_first; i++){
            for(int j=0; i<height_first; j++){
                System.out.print(result[i][j]+" ");
            }
            System.out.print("\n");
        }
        System.out.print("Time: "+time1+"\n");
    }

    public double time(){
        return time1;
    }

    public void start() throws InterruptedException {

        long start = System.currentTimeMillis();

        for(int i=0; i<threads_size; i++){
            final int a = i;

            threadVect[i] = new Thread(() -> {try {
                add(a);
            }catch (InterruptedException e){
                e.printStackTrace();
            }
            });
            threadVect[i].start();
        }
        for(int i=0; i<threads_size; i++){
            threadVect[i].join();
        }

        long end = System.currentTimeMillis();
        long period = end-start;
        time1 = period;
    }

}
