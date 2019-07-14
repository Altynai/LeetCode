class FooBar {
    private int n;
    private boolean fooIsReady;
    private boolean barIsReady;

    public FooBar(int n) {
        this.n = n;
        this.fooIsReady = true;
        this.barIsReady = false;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (!fooIsReady)
                Thread.sleep(1);
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            fooIsReady = false;
            barIsReady = true;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (!barIsReady)
                Thread.sleep(1);
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            fooIsReady = true;
            barIsReady = false;
        }
    }
}
