package business;

public class Article {
    private String libelle;
    private double prix;

    Article(String libelle, double prix){
        this.libelle = libelle;
        setPrix(prix);
    }

    public String getLibelle(){
        return this.libelle;
    }

    public double getPrix(){
        return this.prix;
    }

    public void setLibelle(String libelle){
        this.libelle = libelle;
    }

    public void setPrix(double prix){
        if(prix >= 0){
            this.prix = prix;
        }else{
            this.prix = 0;
        }
    }

    public String toString(){
        return this.libelle + " " + "( " + this.prix +" )";
    }
}
