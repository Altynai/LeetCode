class Foo {

    private boolean[] executed;

    public Foo() {
        executed = new boolean[3];
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        executed[0] = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!executed[0])
            Thread.sleep(1);
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        executed[1] = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!executed[1])
            Thread.sleep(1);
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
