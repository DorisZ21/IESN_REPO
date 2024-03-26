package musique;

public class GroupeMusical {
    private String nom;
    private String nomChanteur;
    private int nbMusiciens;

    GroupeMusical(String nom, String nomChanteur,int nbMusiciens){
        this.nom = nom;
        this.nomChanteur = nomChanteur;
        setNbMusiciens(nbMusiciens);
    }

    public void setNbMusiciens(int nbMusiciens){

        if(nbMusiciens < 0){
            this.nbMusiciens = 1;
        }else{
            this.nbMusiciens = nbMusiciens;
        }
    }

    public String getNomChanteur(){
        return this.nomChanteur;
    }

    public String toString(){
        return this.nom + " (interprétation : " + this.nomChanteur + " - accompagnement : " + this.nbMusiciens + " musiciens)";
    }
}
