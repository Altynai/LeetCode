class H2O {

    private final Object lock;

    private int h;

    public H2O() {
        this.lock = new Object();
        this.h = 2;
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        synchronized (lock) {
            while (h == 0)
                lock.wait();
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            h--;
            lock.notifyAll();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (lock) {
            while (h != 0)
                lock.wait();
            // releaseOxygen.run() outputs "H". Do not change or remove this line.
            releaseOxygen.run();
            h = 2;
            lock.notifyAll();
        }
    }
}
