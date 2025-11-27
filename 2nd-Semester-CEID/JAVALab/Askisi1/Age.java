public class Age{
    public static void main(String args[]){
           if (args.length == 1){
               System.out.print("You are " + args[0] + " years old.\nYou forgot to give your name...");
           }
           else if (args.length == 0) System.out.println("You forgot to give your name and age.\nWho are you????");
           
           else {
               System.out.print(args[1] + " is " + args[0] + " years old.");               
           }
    }
}
