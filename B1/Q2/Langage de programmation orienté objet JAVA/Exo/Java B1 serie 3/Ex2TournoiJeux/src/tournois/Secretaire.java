package tournois;

public class Secretaire {
    private String prenom;
    private String nom;
    private String telephone;

    Secretaire(String prenom, String nom, String telephone){
        this.prenom = prenom;
        this.nom = nom;
        this.telephone = telephone;
    }

    public String toString(){
        return this.nom + " " + this.prenom;
    }
}
