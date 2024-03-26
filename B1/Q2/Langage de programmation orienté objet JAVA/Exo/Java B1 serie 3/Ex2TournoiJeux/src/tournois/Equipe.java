package tournois;

public class Equipe {
    private String nom;
    private String categorie;
    private Club club;
    private Coach coach;

    Equipe(String nom,String categorie,Club club,Coach coach){
        this.nom = nom;
        this.categorie = categorie;
        this.club = club;
        this.coach = coach;
    }

    public String getNom(){
        return this.nom;
    }

    public String toString(){
        return "L'équipe " + this.nom + " de la catégorie " + this.categorie + " du " + this.club + " coaché par le "
                + this.coach;
    }
}
