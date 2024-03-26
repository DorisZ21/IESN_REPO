package premierPackage;
import java.util.Scanner;

public class Principale {
    public static void main(String[] args) {

        Scanner clavier = new Scanner(System.in);
        int x;
        int y = 3;
        String mot;

        System.out.println("Entrez un nombre.");
        x = clavier.nextInt();
        System.out.println(x);
        System.out.println("Entrez un mot :");
        mot = clavier.next();
        System.out.println(mot);

        Rectangle premierRectangle = new Rectangle(1,2,10,4);
        premierRectangle.deplacerEn(0,3);
        premierRectangle.modifierHauteur(6);
        premierRectangle.modifierLargeur(5);


        System.out.println(premierRectangle.getCoordonneeX() + " " +  premierRectangle.getCoordonneeY());
        System.out.println(premierRectangle.getHauteur() + " " + premierRectangle.getLargeur());
    }
}
