import java.util.ArrayList;
import java.util.Iterator;

abstract public class Tester {
    public static void main(String[] args) {
        Robot r1 = new Robot("CRX", "FANUC", 15, true, 12.2f, Robot.NON_FLAWED);
        RobVehicle rv1 = new RobVehicle("test1", "ABB", 2, 25.4f, 23, Robot.NON_FLAWED);
        RobVehicle rv2 = new RobVehicle("test2", "ABB", 150, 0.4f, 45, Robot.NON_FLAWED);
        
        

        System.out.println("=========Test-ArrayList=========\n");
        
        ArrayList<Robot> test = new ArrayList<>();
        
        test.add(r1);
        test.add(rv1);
        test.add(rv2);
        for (Robot obj : test) {
            obj.printinfo();
            System.out.println();
        }
        
        System.out.println("\n=========ArrayList=========\n");
        ArrayList<Robot> roblist = new ArrayList<Robot>();

        roblist.add(r1);
        roblist.add(rv1);
        roblist.add(rv2);
        
        System.out.println("======For-Loop======");
        for (int i = 0; i < roblist.size(); i ++) {
            roblist.get(i).printinfo();
            System.out.println(); 
        }
        
        System.out.println("======Iterator======");
        Iterator<Robot> iter = roblist.iterator();
        while (iter.hasNext()) {
            Robot rob = (Robot)iter.next();
            rob.printinfo();
            System.out.println();
        }

        
        System.out.println("\n=========Array=========\n");
        Robot[] robarray = {r1, rv1};
        
        System.out.println("======For-Loop======");
        for (Robot rob : robarray) {
           rob.printinfo();
           System.out.println(); 
        }
        
        System.out.println("\n======Classic-Way======");
        r1.printinfo();
        System.out.println();
        rv1.printinfo();
        
        r1.setOnline(false);
        rv1.setOnline(false);
        
        r1.printinfo();
        System.out.println();
        rv1.printinfo();
        
        rv1.setDays_of_usage(rv2);
        rv2.printinfo();
        System.out.println();
        rv1.printinfo();
    }
}