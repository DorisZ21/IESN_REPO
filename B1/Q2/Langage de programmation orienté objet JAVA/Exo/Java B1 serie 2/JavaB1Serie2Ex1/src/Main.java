import packageRectangle.Rectangle;
import packageIndividu.Individu;
public class Main {
    public static void main(String[] args) {
       // Rectangle r = new Rectangle(0, 0, 10, 20);
        Individu i = new Individu("Jean", -3,'R', "Bruxelles");
        System.out.println(i.getPrenom());
        System.out.println(i.getAge());
        System.out.println(i.getGenre());
        System.out.println(i.getLocalite());

        System.out.println(i.presentation());

    }
}