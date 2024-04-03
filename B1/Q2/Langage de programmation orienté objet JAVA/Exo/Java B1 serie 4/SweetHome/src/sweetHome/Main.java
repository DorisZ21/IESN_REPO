package sweetHome;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
      Villa bungalow = new Villa("17 Rue Cuvelier 5300 Andenne", 2,110.5,100);
      Villa maisonCampagne = new Villa("25 Rue Cuvelier 5300 Andenne",6,2,130.5,90.8,212.18);
      System.out.println(bungalow);
      System.out.println(maisonCampagne);

      VillaAvecCave manoir = new VillaAvecCave("35 Rue des bois",12,4,350.89,340.8,8000,310,true);
        System.out.println(manoir);
      System.out.println(manoir.nbNiveaux());
    }
}