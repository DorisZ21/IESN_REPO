package librairie;
// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        // Etudiant

        Etudiant premierEtudiant = new Etudiant("Dorian Michaux","chimie","bac", 2,true);
        System.out.println(premierEtudiant);
        premierEtudiant.setFaculte("physique");
        System.out.println(premierEtudiant);
        Etudiant secondEtudiant = new Etudiant("GianLuca Petronio","math","bac",3);
        System.out.println(secondEtudiant);

        // Editeur

        Editeur premierEditeur = new Editeur("La foire à la saucisse", "Nouvelles tendances");
        System.out.println(premierEditeur);

        Editeur secondEditeur = new Editeur("OE c'est GREG","universitaire");

        // Livre

        Livre premierLivre = new Livre("120-458-954-512-8","Martine boit une CARA","Anglais",20,20.5,5.50,premierEditeur);
        System.out.println(premierLivre);

        System.out.println("Ce livre " + (premierLivre.publicationAcademique() ? "est" : "n'est pas") + " une publication académique." );

        Livre secondLivre = new Livre("120-1245-5648-5512","Martine passe à la JUP",20,20,5,premierEditeur);
        System.out.println(secondLivre);

        secondLivre.setEditeur(secondEditeur);

        System.out.println(secondLivre);

        // Commande


    }
}