package business;

public class Client {
    private String prenom;
    private String nom;

    Client(String prenom,String nom){
        setPrenom(prenom);
        setNom(nom);
    }

    public String getPrenom(){
        return this.prenom;
    }

    public String getNom(){
        return this.nom;
    }

    public void setPrenom(String prenom){
        this.prenom = prenom;
    }

    public void setNom(String nom){
        this.nom = nom;
    }

    public String toString(){
        return  this.nom + " " + this.prenom;
    }
}
