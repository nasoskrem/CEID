public class Window
{
    private int size = 5;
    public Window(){}
    public Window(int size){
        this.size = size;
    }
    
    public int getSize(){
        return this.size;
    }
    
    public static void main(String args[]){
        Window w1 = new Window();
        Window w2 = new Window(4);
        System.out.println("The size of window w1 is :" + w1.getSize());
        System.out.println("The size of window w2 is :" + w2.getSize());
    }
}
