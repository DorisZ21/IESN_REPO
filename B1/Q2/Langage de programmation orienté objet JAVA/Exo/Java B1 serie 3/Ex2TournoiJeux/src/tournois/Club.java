package tournois;

public class Club {
    private String nom;
    private String adresse;
    private Secretaire secretaire;

    Club(String nom, String adresse, Secretaire secretaire){
        this.nom = nom;
        this.adresse = adresse;
        this.secretaire = secretaire;
    }

    public String toString(){
        return "club " + "( " + nom + " )" + "( secrétaire : " + secretaire + " )";
    }
}
