package librairie;

public class Editeur {
    private String nom;
    private String categorie;

    Editeur(String nom,String categorie){
        this.nom = nom;
        this.categorie = categorie;
    }

    public String getCategorie(){
        return this.categorie;
    }

    public String toString(){
        return "la maison d'édition " + this.nom + " (catégorie : " + this.categorie + ")";
    }


}
