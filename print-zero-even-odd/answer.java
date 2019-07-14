import java.util.function.IntConsumer;

class ZeroEvenOdd {
    private int n;
    private int m;
    private Mutex mutex;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.m = 0;
        this.mutex = new Mutex(0, 4);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (m <= n) {
            mutex.waitForMyTurn(0, 2);
            if (m < n)
                printNumber.accept(0);
            mutex.switchTurns();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (m <= n) {
            mutex.waitForMyTurn(3, 3);
            if (++m <= n)
                printNumber.accept(m);
            mutex.switchTurns();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (m <= n) {
            mutex.waitForMyTurn(1, 1);
            if (++m <= n)
                printNumber.accept(m);
            mutex.switchTurns();
        }
    }

    class Mutex {
        private int whoGoes;
        private int howMany;

        public Mutex(int first, int max) {
            whoGoes = first;
            howMany = max;
        }

        public synchronized int getWhoGoes() {
            return whoGoes;
        }

        public synchronized void switchTurns() {
            whoGoes = (whoGoes + 1) % howMany;
            notifyAll();
        }

        public synchronized void waitForMyTurn(int id, int id2) throws InterruptedException {
            while (whoGoes != id && whoGoes != id2)
                wait();
        }
    }
}
