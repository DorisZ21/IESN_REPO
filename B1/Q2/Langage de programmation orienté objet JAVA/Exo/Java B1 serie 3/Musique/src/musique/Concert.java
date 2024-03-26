package musique;

public class Concert {
    private String libelle;
    private String date;
    private String lieu;
    private double prix;
    private GroupeMusical groupeMusical;

    Concert(String libelle, String date, String lieu, double prix, GroupeMusical groupeMusical){
        this.libelle = libelle;
        this.date = date;
        this.lieu = lieu;
        setPrix(prix);
        this.groupeMusical = groupeMusical;
    }

    public double getPrix(){
        return this.prix;
    }

    public void setPrix(double prix){
        if(prix < 0){
            this.prix = 0;
        }else {
            this.prix = prix;
        }
    }

    public GroupeMusical getGroupeMusical(){
        return this.groupeMusical;
    }

    public String toString(){
        return "Le concert intitulé " + this.libelle + " gu groupe dénommé " + groupeMusical + " prévu le " + this.date
                + " à " + this.lieu;
    }
}
