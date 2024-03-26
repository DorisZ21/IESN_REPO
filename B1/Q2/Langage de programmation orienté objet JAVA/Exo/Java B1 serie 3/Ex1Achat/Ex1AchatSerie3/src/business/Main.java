package business;

public class Main {
    public static void main(String[] args) {
        // Déclaration et initialisation
        Client premierClient = new Client("Dorian","Michaux");
        Article premierArticle = new Article("Pomme",1.02);
        Achat premierAchat = new Achat(3,premierClient,premierArticle);

        // Affichage
        System.out.println(premierAchat);
        System.out.println(premierAchat.coutTotal());
        System.out.println("Nb exemplaires : " + premierAchat.getNbExemplaires());
        System.out.println("Nom client : " + premierAchat.getClient().getNom());
        System.out.println("Libelle article : " + premierAchat.getArticle().getLibelle());

        // modification
        premierAchat.setNbExemplaires(10);

        // Déclaration et initialisation d'un second client
        Client secondClient = new Client("Marie","Lambillotte");

        premierAchat.setClient(secondClient);

        System.out.println(premierAchat);

        Achat secondAchat = new Achat(secondClient,premierArticle);

        System.out.println(secondAchat);

    }
}