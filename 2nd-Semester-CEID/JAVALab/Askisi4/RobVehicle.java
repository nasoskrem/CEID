public class RobVehicle extends Robot{
    private int miles;
    
    public RobVehicle(String name, String manufacturer, int days_of_usage, float costs, int miles, int condition){
        super(name, manufacturer, days_of_usage, true, costs, condition);
        this.miles = miles;
    }    
    
    public int getMiles() {return miles;}
    
    public void printinfo(){
        super.printinfo(); 
        if (this.getMiles() > 0){
            System.out.print(" with traveled distance " + this.getMiles() + " miles");
        }
        else{
            System.out.print(" with 0 miles traveled distance");
        }
    }
    
    @Override
    public void setOnline(boolean online) {
        System.out.println("\nWarning: Cannot change online status of RobVehicle.");
    }
    
    public void setDays_of_usage(RobVehicle rob) {
        if (this.getCondition() == NON_FLAWED && rob.getCondition() == NON_FLAWED) {
            int maxDays = Math.max(this.getDays_of_usage(), rob.getDays_of_usage());
            this.setDays_of_usage(maxDays);
            rob.setDays_of_usage(maxDays);
            System.out.println("\nUpdated days of usage to " + maxDays + " for both vehicles.");
        } else {
            System.out.println("\nOne or both vehicles are flawed. No changes made.");
    }
}
}