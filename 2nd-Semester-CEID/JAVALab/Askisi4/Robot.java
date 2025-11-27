public class Robot{
    private String name;
    private String manufacturer;
    private int days_of_usage;
    private boolean online;
    private float costs;
    public static final int FLAWED = 0;
    public static final int NON_FLAWED = 1;
    private int condition;
    
    public Robot(String name, String manufacturer, int days_of_usage, boolean online, float costs, int condition){
        this.name = new String(name);
        this.manufacturer = new String(manufacturer);
        this.days_of_usage = days_of_usage;
        this.online = online;
        this.costs = costs;
        this.condition = condition;
    }
    
    public String getName() {return name;}
    public String getManufacturer() {return manufacturer;}
    public int getDays_of_usage() {return days_of_usage;}
    public boolean isOnline() {return online;}
    public float getCosts() {return costs;}
    public int getCondition() {return condition;}
    
    public void setName(String name) {this.name = name;}
    public void setManufacturer(String manufacturer) {this.manufacturer = manufacturer;}
    public void setDays_of_usage(int days_of_usage) {this.days_of_usage = days_of_usage;}
    public void setOnline(boolean online) {this.online = online;}
    public void setCosts(float costs) {this.costs = costs;}
    public void setCondition(int condition) {this.condition = condition;}
    
    public void printinfo(){
        System.out.print("Robot " + this.getName() + " of " + this.getManufacturer() + " is " +
                      ((this.condition == 1) ? "working without any flaws" : "faulty") + 
                      (!isOnline() ? " and is not online" : 
                      (" and is online for " + this.getDays_of_usage() + " days")));
    
        
}
}
