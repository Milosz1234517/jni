public class Lab11 {
    static {
        System.loadLibrary("native");
    }

    Double[] a;
    Double[] b;
    Boolean order;
    
    public static void main(String[] args) {
        Lab11 l = new Lab11();
        Double[] d = l.sort01(new Double[]{1.5, 4.5, 3.5}, true);
        System.out.println(d[0] + " " + d[1] + " " + d[2]);

        Double[] d1 = l.sort01(new Double[]{1.5, 4.5, 3.5}, false);
        System.out.println(d1[0] + " " + d1[1] + " " + d1[2]);

        l.order = true;
        Double[] d3 = l.sort02(new Double[]{1.5, 4.5, 3.5});
        System.out.println(d3[0] + " " + d3[1] + " " + d3[2]);

        l.order = false;
        Double[] d4 = l.sort02(new Double[]{1.5, 4.5, 3.5});
        System.out.println(d4[0] + " " + d4[1] + " " + d4[2]);

        l.a = new Double[4];
        l.sort03();
        for (Double double1 : l.a) {
            System.out.println(double1);
        }
        System.out.println(l.order);
    }

    private native Double[] sort01(Double[] a, Boolean order);

    private native Double[] sort02(Double[] a);

    private native void sort03();
}