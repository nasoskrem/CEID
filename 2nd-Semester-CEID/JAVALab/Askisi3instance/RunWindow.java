public class RunWindow{
    public static void main (String[ ] ar) {
        Window test1 = new Window(); 
        MWindow test2 = new MWindow() ;
        System.out.println( "−−−−−Class Method Printing−−−−−" ); 
        test1.printtest();
        test2.printtest();
        System.out.println ("−−−−−−Instance Of Printing−−−−-") ;
        if (test1 instanceof Window){
            test1.printtest();
        }
        if (test1 instanceof MWindow){
            test1.printtest();
        }
        if (test2 instanceof Window){
            test2.printtest();
        }   
        if (test2 instanceof MWindow){
            test2.printtest();
        }
    }
}