package tournois;

public class Main {
    public static void main(String[] args) {
        Secretaire premierSecretaire = new Secretaire("Dorian","Michaux","0493378771");
        Secretaire secondSecretaire = new Secretaire("Marie","Lambillotte","0493378771");

        System.out.println(premierSecretaire);
        System.out.println(secondSecretaire);

        Club premierClub = new Club("Doris","17 Rue cuvelier 5300 Andenne", premierSecretaire);
        Club secondClub = new Club("Dodo","17 Rue cuvelier 5300 Andenne", secondSecretaire);

        System.out.println(premierClub);
        System.out.println(secondClub);

        Coach premierCoach = new Coach("DorianCoach","Michaux",2023);
        Coach secondCoach = new Coach("TestCoach","Test",2100);

        System.out.println(premierCoach);
        System.out.println(secondCoach);

        Equipe premierEquipe = new Equipe("LesResta", "Les poufs d'été", premierClub, premierCoach);
        Equipe secondeEquipe = new Equipe("LesResta2", "Les poufs d'été 2", secondClub, secondCoach);

        System.out.println(premierEquipe);
        System.out.println(secondeEquipe);

        Arbitre premierArbitre = new Arbitre("Paul","LeReuf","abcd", 2008);

        System.out.println(premierArbitre);

        Rencontre challenge = new Rencontre(premierEquipe,secondeEquipe,1,1,1,1,premierArbitre);

        challenge.ajouterPointsAuxLocaux();
        challenge.ajouterPointsAuxLocaux();
        challenge.ajouterPointsAuxLocaux();
        challenge.ajouterPointsAuxLocaux();
        challenge.ajouterPointsAuxVisiteurs();
        challenge.ajouterFauteAuxLocaux();
        challenge.ajouterFauteAuxVisiteurs();
        challenge.ajouterFauteAuxVisiteurs();
        challenge.ajouterFauteAuxVisiteurs();
        challenge.ajouterFauteAuxVisiteurs();

        System.out.println(challenge.vainqueur());
        System.out.println(challenge.equipeFairPlay());
    }
}