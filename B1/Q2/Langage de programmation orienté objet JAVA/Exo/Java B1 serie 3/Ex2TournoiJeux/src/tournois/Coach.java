package tournois;
import java.time.LocalDate;


public class Coach {
    private String prenom;
    private String nom;
    private int anneeDebut;

    Coach(String prenom,String nom, int anneeDebut){
        this.prenom = prenom;
        this.nom = nom;
        setAnneeDebut(anneeDebut);
    }

    public void setAnneeDebut(int anneeDebut){
        LocalDate dateDuJour = LocalDate.now();
        int anneeAujourdhui = dateDuJour.getYear();
        if(anneeDebut > anneeAujourdhui){
            this.anneeDebut = anneeAujourdhui;
        }else{
            this.anneeDebut = anneeDebut;
        }
    }

    public String toString(){
        return "Coach " + this.prenom + " " + this.nom + " " + nbAnneesExperience() + " années d'expérience";
    }

    public int nbAnneesExperience(){
        LocalDate dateDuJour = LocalDate.now();
        int anneeAujourdhui = dateDuJour.getYear();

        return anneeAujourdhui - this.anneeDebut;
    }
}
