package musique;

public class Personne {
    private String prenom;
    private String nom;
    private String telephone;
    private String adresseMail;

    Personne(String prenom,String nom,String telephone,String adresseMail){
        this.prenom = prenom;
        this.nom = nom;
        this.telephone = telephone;
        this.adresseMail = adresseMail;
    }

    public String toString(){
        return this.prenom + " " + this.nom + " (" + this.telephone + " - " + this.adresseMail + ")";
    }
}
